/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "float.h"
#include "new.h"

typedef struct
{
    Class   base;
    float     x;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    float x;

    if (!args)
        raise("No arguments");
    x = va_arg(*args, double);
    if (x)
        this->x = x;
}

static void Float_dtor(FloatClass *this)
{
}

FloatClass *Float_add(const FloatClass *this, const FloatClass *other)
{
    if(!this || !other)
        raise("Null pointer");
    return (new(Float, (this->x + other->x)));
}

FloatClass *Float_sub(const FloatClass *this, const FloatClass *other)
{
    if(!this || !other)
        raise("Null pointer");
    return (new(Float, (this->x - other->x)));
}

FloatClass *Float_mul(const FloatClass *this, const FloatClass *other)
{
    if(!this || !other)
        raise("Null pointer");
    return (new(Float, (this->x * other->x)));
}

FloatClass *Float_div(const FloatClass *this, const FloatClass *other)
{
    if(!this || !other)
        raise("Null pointer");
    if (other->x == 0)
        raise("Zero Division Error");
    return (new(Float, (this->x / other->x)));
}

bool Float_equal(const FloatClass *this, const FloatClass *other)
{
    if(!this || !other)
        raise("Null pointer");
    return (this->x == other->x);
}

bool Float_lt(const FloatClass *this, const FloatClass *other)
{
    if(!this || !other)
        raise("Null pointer");
    return (this->x < other->x);
}
bool Float_gt(const FloatClass *this, const FloatClass *other)
{
    if(!this || !other)
        raise("Null pointer");
    return (this->x > other->x);
}

char *Float_str(FloatClass *this)
{
    int size;
    char *str;

    if (!this)
        raise("Null pointer");
    size = snprintf(NULL, 0, "<Float (%f)>", this->x);
    str = malloc(sizeof(char) * (size + 1));
    if (str == NULL)
        raise("Out of memory");
    snprintf(str, size + 1, "<Float (%f)>", this->x);
    return str;
}

static const FloatClass    _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_equal,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .x = 0,
};

const Class   *Float = (const Class *)&_description;