/*
** EPITECH PROJECT, 2025
** Rush2
** File description:
** tests_first_part
*/

#include <criterion/criterion.h>
#include <signal.h>
#include "../point.h"
#include "../new.h"
#include "../player.h"
#include "../vertex.h"
#include "../int.h"
#include "../array.h"

Test(point_str, valid_point)
{
    Object *point = new(Point, 10, 20);
    char *str = str(point);
    
    cr_assert_not_null(str);
    cr_assert_str_eq(str, "<Point (10, 20)>");
    delete(point);
    free(str);
}

Test(player_ctor, create_player)
{
    Object *player = new(Player);

    cr_assert_not_null(player);
    delete(player);
}

Test(point_str, point_add)
{
    Object *p1 = new(Point, 10, 20);
    Object *p2 = new(Point, 5, 5);
    char *str = str(addition(p1, p2));

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "<Point (15, 25)>");
    delete(p1);
    delete(p2);
    free(str);
}

Test(point_str, point_sub)
{
    Object *p1 = new(Point, 10, 20);
    Object *p2 = new(Point, 5, 5);
    char *str = str(subtraction(p1, p2));

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "<Point (5, 15)>");
    delete(p1);
    delete(p2);
    free(str);
}

Test(point_str, point_add_null, .signal = SIGABRT)
{
    Object *p1 = new(Point, 10, 20);
    addition(p1, NULL);
    delete(p1);
}

Test(point_str, point_sub_null, .signal = SIGABRT)
{
    Object *p1 = new(Point, 10, 20);
    subtraction(p1, NULL);
    delete(p1);
}

Test(vertex_str, vertex_add)
{
    Object *p1 = new(Vertex, 10, 20, 30);
    Object *p2 = new(Vertex, 5, 5, 5);
    char *str = str(addition(p1, p2));

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "<Vertex (15, 25, 35)>");
    delete(p1);
    delete(p2);
    free(str);
}

Test(point_str, Vertex_sub)
{
    Object *p1 = new(Vertex, 10, 20, 30);
    Object *p2 = new(Vertex, 5, 5, 5);
    char *str = str(subtraction(p1, p2));

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "<Vertex (5, 15, 25)>");
    delete(p1);
    delete(p2);
    free(str);
}

Test(array, array_creation)
{
    Object  *array = new(Array, 10, Int, 0);

    cr_assert_not_null(array);
    delete(array);
}

Test(array, array_add)
{
    Object  *array = new(Array, 10, Int, 0);
    setitem(array, 5, 12);
    delete(array);
}

Test(array, array_get)
{
    Object  *array = new(Array, 10, Int, 0);
    setitem(array, 5, 12);
    char *str = str(getitem(array, 5));
    cr_assert_not_null(str);
    cr_assert_str_eq(str, "<Int (12)>");
    free(str);
    delete(array);
}

Test(point_str, point_no_arg)
{
    Object *p1 = new(Point, NULL);
    delete(p1);
}