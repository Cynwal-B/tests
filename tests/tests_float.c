/*
** EPITECH PROJECT, 2025
** Rush2
** File description:
** tests_float
*/

#include <criterion/criterion.h>
#include "../point.h"
#include "../new.h"
#include "../float.h"

Test(Float_str, Float_sub)
{
    Object *p1 = new(Float, 6.5);
    Object *p2 = new(Float, 1.2);
    char *str = str(subtraction(p1, p2));

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "<Float (5.300000)>");
    delete(p1);
    delete(p2);
    free(str);
}

Test(Float_str, Float_add)
{
    Object *p1 = new(Float, 6.5);
    Object *p2 = new(Float, 1.2);
    char *str = str(addition(p1, p2));

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "<Float (7.700000)>");
    delete(p1);
    delete(p2);
    free(str);
}

Test(Float_str, Float_mul)
{
    Object *p1 = new(Float, 2.5);
    Object *p2 = new(Float, 3.3);
    char *str = str(multiplication(p1, p2));

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "<Float (8.250000)>");
    delete(p1);
    delete(p2);
    free(str);
}

Test(Float_str, Float_div)
{
    Object *p1 = new(Float, 2.4);
    Object *p2 = new(Float, 1.2);
    char *str = str(division(p1, p2));

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "<Float (2.000000)>");
    delete(p1);
    delete(p2);
    free(str);
}

Test(Float_str, Float_eq)
{
    Object *p1 = new(Float, 1.2);
    Object *p2 = new(Float, 1.2);

    cr_assert_eq(eq(p1, p2), true);
    delete(p1);
    delete(p2);
}

Test(Float_str, Float_gt)
{
    Object *p1 = new(Float, 3.5);
    Object *p2 = new(Float, 2.5);

    cr_assert_eq(gt(p1, p2), true);
    delete(p1);
    delete(p2);
}

Test(Float_str, Float_lt)
{
    Object *p1 = new(Float, 2.5);
    Object *p2 = new(Float, 3.5);

    cr_assert_eq(lt(p1, p2), true);
    delete(p1);
    delete(p2);
}
