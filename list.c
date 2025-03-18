/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 05
*/

#include <stdlib.h>
#include <stdarg.h>
#include "raise.h"
#include "array.h"
#include "new.h"

typedef struct node_s {
    Object *elem;
    struct node_s *next;
} Node;

typedef struct {
    Container base;
    Class *_type;
    size_t _size;
    Node **_head;
} ListClass;

typedef struct {
    Iterator base;
    ListClass *_list;
    Node *_current;
    size_t _idx;
} ListIteratorClass;

static void ListIterator_ctor(ListIteratorClass *this, va_list *args)
{
    this->_list = va_arg(*args, ListClass *);
    this->_current = *(this->_list->_head);
    this->_idx = va_arg(*args, int);
    for (size_t i = 0; i < this->_idx && this->_current != NULL; i++) {
        this->_current = this->_current->next;
    }
}

static bool ListIterator_eq(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_current == other->_current);
}

static bool ListIterator_gt(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_idx > other->_idx);
}

static bool ListIterator_lt(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_idx < other->_idx);
}

static void ListIterator_incr(ListIteratorClass *this)
{
    if (this->_current != NULL) {
        this->_current = this->_current->next;
        this->_idx++;
    }
}

static Object *ListIterator_getval(ListIteratorClass *this)
{
    if (this->_current == NULL)
        raise("Out of range");
    return this->_current->elem;
}

static void ListIterator_setval(ListIteratorClass *this, ...)
{
    va_list new_list;

    if (this->_current == NULL)
        raise("Out of range");
    va_start(new_list, this);
    delete(this->_current->elem);
    this->_current->elem = va_new(this->_list->_type, &new_list);
    va_end(new_list);
}

static const ListIteratorClass ListIteratorDescr = {
    {
        {
            .__size__ = sizeof(ListIteratorClass),
            .__name__ = "ListIterator",
            .__ctor__ = (ctor_t)&ListIterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&ListIterator_eq,
            .__gt__ = (binary_comparator_t)&ListIterator_gt,
            .__lt__ = (binary_comparator_t)&ListIterator_lt,
        },
        .__incr__ = (incr_t)&ListIterator_incr,
        .__getval__ = (getval_t)&ListIterator_getval,
        .__setval__ = (setval_t)&ListIterator_setval,
    },
    ._list = NULL,
    ._idx = 0
};

static const Class *ListIterator = (const Class *)&ListIteratorDescr;

static bool list_add_elem_at_back(Node **front_ptr, void *elem)
{
    Node *node = *front_ptr;
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL)
        return false;
    new_node->elem = elem;
    new_node->next = NULL;
    if (!*front_ptr) {
        *front_ptr = new_node;
        return true;
    }
    while (node->next != NULL)
        node = node->next;
    node->next = new_node;
    return true;
}

static void List_ctor(ListClass *this, va_list *args)
{
    Node **list = NULL;
    size_t size;
    Class *type;

    list = calloc(1, sizeof(Node *));
    if (!list)
        raise("Out of memory");
    size = va_arg(*args, size_t);
    type = va_arg(*args, Class *);
    this->_size = size;
    this->_type = type;
    this->_head = list;
    for (size_t i = 0; i < size; i++) {
        va_list args_copy;
        va_copy(args_copy, *args);
        Object *new_elem = va_new(type, &args_copy);
        if (!new_elem)
            raise("Out of memory");
        list_add_elem_at_back(list, new_elem);
        va_end(args_copy);
    }
}

static void List_dtor(ListClass *this)
{
    Node *current = *this->_head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        delete(current->elem);
        free(current);
        current = next;
    }
    free(this->_head);
}

static size_t List_len(ListClass *this)
{
    return this->_size;
}

static Iterator *List_begin(ListClass *this)
{
    return new(ListIterator, this, 0);
}

static Iterator *List_end(ListClass *this)
{
    return new(ListIterator, this, this->_size);
}

static Object *List_getitem(ListClass *this, ...)
{
    va_list new_list;
    size_t index;
    Node *current = *this->_head;

    va_start(new_list, this);
    index = va_arg(new_list, size_t);
    va_end(new_list);
    if (index >= this->_size || index < 0)
        raise("Out of range");
    for (size_t i = 0; i < index; ++i) {
        if (current == NULL)
            raise("Out of range");
        current = current->next;
    }
    return current->elem;
}

static void List_setitem(ListClass *this, ...)
{
    va_list new_list;
    size_t index;
    Node *current = *this->_head;

    va_start(new_list, this);
    index = va_arg(new_list, size_t);
    if (index >= this->_size) {
        va_end(new_list);
        raise("Out of range");
    }
    for (size_t i = 0; i < index; ++i)
        current = current->next;
    delete(current->elem);
    current->elem = va_new(this->_type, &new_list);
    va_end(new_list);
}

static const ListClass _descr = {
    {
        {
            .__size__ = sizeof(ListClass),
            .__name__ = "List",
            .__ctor__ = (ctor_t)&List_ctor,
            .__dtor__ = (dtor_t)&List_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&List_len,
        .__begin__ = (iter_t)&List_begin,
        .__end__ = (iter_t)&List_end,
        .__getitem__ = (getitem_t)&List_getitem,
        .__setitem__ = (setitem_t)&List_setitem,
    },
    ._type = NULL,
    ._size = 0,
    ._head = NULL
};

const Class *List = (const Class *)&_descr;
