/*
** EPITECH PROJECT, 2025
** Rush2
** File description:
** tests_char
*/

#include <criterion/criterion.h>
#include "../point.h"
#include "../new.h"
#include "../char.h"

Test(char_str, Char_sub)
{
    Object *p1 = new(Char, 'b');
    Object *p2 = new(Char, 1);
    char *str = str(subtraction(p1, p2));

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "<Char (a)>");
    delete(p1);
    delete(p2);
    free(str);
}

Test(char_str, Char_add)
{
    Object *p1 = new(Char, 'b');
    Object *p2 = new(Char, 1);
    char *str = str(addition(p1, p2));

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "<Char (c)>");
    delete(p1);
    delete(p2);
    free(str);
}

Test(char_str, Char_mul)
{
    Object *p1 = new(Char, '2');
    Object *p2 = new(Char, 2);
    char *str = str(multiplication(p1, p2));

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "<Char (d)>");
    delete(p1);
    delete(p2);
    free(str);
}

Test(char_str, Char_div)
{
    Object *p1 = new(Char, 'd');
    Object *p2 = new(Char, 2);
    char *str = str(division(p1, p2));

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "<Char (2)>");
    delete(p1);
    delete(p2);
    free(str);
}

Test(char_str, Char_eq)
{
    Object *p1 = new(Char, 'd');
    Object *p2 = new(Char, 'd');

    cr_assert_eq(eq(p1, p2), true);
    delete(p1);
    delete(p2);
}

Test(char_str, Char_gt)
{
    Object *p1 = new(Char, 'e');
    Object *p2 = new(Char, 'd');

    cr_assert_eq(gt(p1, p2), true);
    delete(p1);
    delete(p2);
}

Test(char_str, Char_lt)
{
    Object *p1 = new(Char, 'c');
    Object *p2 = new(Char, 'd');

    cr_assert_eq(lt(p1, p2), true);
    delete(p1);
    delete(p2);
}
