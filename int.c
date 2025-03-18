/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "int.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    int x;

    if (!args)
        raise("No arguments");
    x = va_arg(*args, int);
    if (x)
        this->x = x;
}

static void Int_dtor(IntClass *this)
{
}

IntClass *Int_add(const IntClass *this, const IntClass *other)
{
    if(!this || !other)
        raise("Null pointer");
    return (new(Int, this->x + other->x));
}

IntClass *Int_sub(const IntClass *this, const IntClass *other)
{
    if(!this || !other)
        raise("Null pointer");
    return (new(Int, this->x - other->x));
}

IntClass *Int_mul(const IntClass *this, const IntClass *other)
{
    if(!this || !other)
        raise("Null pointer");
    return (new(Int, this->x * other->x));
}

IntClass *Int_div(const IntClass *this, const IntClass *other)
{
    if(!this || !other)
        raise("Null pointer");
    if (other->x == 0)
        raise("Zero Division Error");
    return(new(Int, this->x / other->x));
}

bool Int_equal(const IntClass *this, const IntClass *other)
{
    if(!this || !other)
        raise("Null pointer");
    return(this->x == other->x);
}

bool Int_lt(const IntClass *this, const IntClass *other)
{
    if(!this || !other)
        raise("Null pointer");
    return(this->x < other->x);
}
bool Int_gt(const IntClass *this, const IntClass *other)
{
    if(!this || !other)
        raise("Null pointer");
    return(this->x > other->x);
}

char *Int_str(IntClass *this)
{
    int size;
    char *str;

    if (!this)
        raise("Null pointer");
    size = snprintf(NULL, 0, "<Int (%d)>", this->x);
    str = malloc(sizeof(char) * (size + 1));
    if (str == NULL)
        raise("Out of memory");
    snprintf(str, size + 1, "<Int (%d)>", this->x);
    return str;
}

static const IntClass    _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_equal,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .x = 0,
};

const Class   *Int = (const Class *)&_description;