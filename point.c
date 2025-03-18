/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    int x;
    int y;

    if (!args)
        raise("No arguments");
    x = va_arg(*args, int);
    if (x)
        this->x = x;
    y = va_arg(*args, int);
    if (y)
        this->y = y;
}

static void Point_dtor(PointClass *this)
{
    /* Fill this function for exercice 02 */
}

char *Point_str(PointClass *this)
{
    int size;
    char *str;

    if (!this)
        raise("Null pointer");
    size = snprintf(NULL, 0, "<Point (%d, %d)>", this->x, this->y);
    str = malloc(sizeof(char) * (size + 1));
    if (str == NULL)
        raise("Out of memory");
    snprintf(str, size + 1, "<Point (%d, %d)>", this->x, this->y);
    return str;
}

// Create additional functions here

Object *Point_add(PointClass *this, PointClass *other)
{
    Object *result_add;
    int x = 0;
    int y = 0;

    if (!this || !other)
        raise("Null pointers");
    x = this->x + other->x;
    y = this->y + other->y;
    result_add = new(Point, x, y);
    return result_add;
}

Object *Point_sub(PointClass *this, PointClass *other)
{
    Object *result_sub;
    int x = 0;
    int y = 0;

    if (!this || !other)
        raise("Null pointers");
    x = this->x - other->x;
    y = this->y - other->y;
    result_sub = new(Point, x, y);
    return result_sub;
}

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Point_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Point_sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
