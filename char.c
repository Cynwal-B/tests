/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "char.h"
#include "new.h"

typedef struct
{
    Class   base;
    char     x;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    int x;

    if (!args)
        raise("No arguments");
    x = va_arg(*args, int);
    if (x)
        this->x = x;
}

static void Char_dtor(CharClass *this)
{
}

CharClass *char_add(const CharClass *this, const CharClass *other)
{
    if(!this || !other)
        raise("Null pointer");
    return (new(Char, this->x + other->x));
}

CharClass *char_sub(const CharClass *this, const CharClass *other)
{
    if(!this || !other)
        raise("Null pointer");
    return (new(Char, this->x - other->x));
}

CharClass *Char_mul(const CharClass *this, const CharClass *other)
{
    if(!this || !other)
        raise("Null pointer");
    return (new(Char, this->x * other->x));
}

CharClass *Char_div(const CharClass *this, const CharClass *other)
{
    if (other->x == 0)
        raise("Zero Division Error");
    return(new(Char, this->x / other->x));
}

bool Char_equal(const CharClass *this, const CharClass *other)
{
    if(!this || !other)
        raise("Null pointer");
    return(this->x == other->x);
}

bool Char_lt(const CharClass *this, const CharClass *other)
{
    if(!this || !other)
        raise("Null pointer");
    return(this->x < other->x);
}

bool Char_gt(const CharClass *this, const CharClass *other)
{
    if(!this || !other)
        raise("Null pointer");
    return(this->x > other->x);
}

char *Char_str(CharClass *this)
{
    int size;
    char *str;

    if (!this)
        raise("Null pointer");
    size = snprintf(NULL, 0, "<Char (%c)>", this->x);
    str = malloc(sizeof(char) * (size + 1));
    if (str == NULL)
        raise("Out of memory");
    snprintf(str, size + 1, "<Char (%c)>", this->x);
    return str;
}

static const CharClass    _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&char_add,
        .__sub__ = (binary_operator_t)&char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_equal,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .x = 0,
};

const Class   *Char = (const Class *)&_description;