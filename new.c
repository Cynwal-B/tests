/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "new.h"
#include "object.h"

Object *va_new(const Class *class, va_list *ap)
{
    Object *new_object = malloc((class->__size__));

    if (new_object == NULL)
        raise("Out of memory");
    memcpy(new_object, class, class->__size__);
    if (class->__ctor__){
        class->__ctor__(new_object, ap);
    }
    return new_object;
}

Object *new(const Class *class, ...)
{
    Object *new_object = malloc((class->__size__));
    va_list new_list;

    if (new_object == NULL)
        raise("Out of memory");
    va_start(new_list, class);
    memcpy(new_object, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(new_object, &new_list);
    va_end(new_list);
    return new_object;
}

void delete(Object *ptr)
{
    Class *c = (Class *)ptr;

    if (c->__dtor__)
        c->__dtor__(ptr);  
    free(ptr);
}
