/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    int x;
    int y;
    int z;

    if (!args)
        raise("No arguments");
    x = va_arg(*args, int);
    if (x)
        this->x = x;
    y = va_arg(*args, int);
    if (y)
        this->y = y;
    z = va_arg(*args, int);
    if (z)
        this->z = z;
}

static void Vertex_dtor(VertexClass *this)
{
    /* Fill this function for exercice 02 */
}

char *Vertex_str(VertexClass *this)
{
    int size;
    char *str;

    if (!this)
        raise("Null pointer");
    size = snprintf(NULL, 0, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    str = malloc(sizeof(char) * (size + 1));
    if (str == NULL)
        raise("Out of memory");
    snprintf(str, size + 1, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return str;
}

// Create additional functions here

Object *Vertex_add(VertexClass *this, VertexClass *other)
{
    Object *result_add;
    int x = 0;
    int y = 0;
    int z = 0;

    if (!this || !other)
        raise("Null pointers");
    x = this->x + other->x;
    y = this->y + other->y;
    z = this->z + other->z;
    result_add = new(Vertex, x, y, z);
    return result_add;
}

Object *Vertex_sub(VertexClass *this, VertexClass *other)
{
    Object *result_sub;
    int x = 0;
    int y = 0;
    int z = 0;

    if (!this || !other)
        raise("Null pointers");
    x = this->x - other->x;
    y = this->y - other->y;
    z = this->z - other->z;
    result_sub = new(Vertex, x, y, z);
    return result_sub;
}

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Vertex_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Vertex_sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class   *Vertex = (const Class *)&_description;