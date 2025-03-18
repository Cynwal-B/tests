/*
** EPITECH PROJECT, 2025
** Rush2
** File description:
** tests_int
*/

#include <criterion/criterion.h>
#include "../point.h"
#include "../new.h"
#include "../int.h"

Test(Int_str, Int_sub)
{
    Object *p1 = new(Int, 4);
    Object *p2 = new(Int, 1);
    char *str = str(subtraction(p1, p2));

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "<Int (3)>");
    delete(p1);
    delete(p2);
    free(str);
}

Test(Int_str, Int_add)
{
    Object *p1 = new(Int, 4);
    Object *p2 = new(Int, 1);
    char *str = str(addition(p1, p2));

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "<Int (5)>");
    delete(p1);
    delete(p2);
    free(str);
}

Test(Int_str, Int_mul)
{
    Object *p1 = new(Int, 12);
    Object *p2 = new(Int, 2);
    char *str = str(multiplication(p1, p2));

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "<Int (24)>");
    delete(p1);
    delete(p2);
    free(str);
}

Test(Int_str, Int_div)
{
    Object *p1 = new(Int, 12);
    Object *p2 = new(Int, 2);
    char *str = str(division(p1, p2));

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "<Int (6)>");
    delete(p1);
    delete(p2);
    free(str);
}

Test(Int_str, Int_eq)
{
    Object *p1 = new(Int, 1);
    Object *p2 = new(Int, 1);

    cr_assert_eq(eq(p1, p2), true);
    delete(p1);
    delete(p2);
}

Test(Int_str, Int_gt)
{
    Object *p1 = new(Int, 2);
    Object *p2 = new(Int, 1);

    cr_assert_eq(gt(p1, p2), true);
    delete(p1);
    delete(p2);
}

Test(Int_str, Int_lt)
{
    Object *p1 = new(Int, 1);
    Object *p2 = new(Int, 2);

    cr_assert_eq(lt(p1, p2), true);
    delete(p1);
    delete(p2);
}
