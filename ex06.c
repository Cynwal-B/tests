/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** List Test
*/

#include <stdio.h>
#include "int.h"
#include "new.h"
#include "list.h"
#include "raise.h"

int main(void)
{
    Object *list = new(List, 5, Int, 0);
    Object *it = begin(list);
    Object *it_end = end(list);

    printf("List size: %zu\n", len(list));
    printf("Initial values:\n");
    while (lt(it, it_end)) {
        printf("%s\n", str(getval(it)));
        incr(it);
    }
    printf("\nSetting new values:\n");
    setitem(list, 2, 42);
    setitem(list, 4, 99);
    delete(it);
    it = begin(list);
    while (lt(it, it_end)) {
        printf("%s\n", str(getval(it)));
        incr(it);
    }
    printf("\nTesting out-of-bounds access:\n");
    setitem(list, 10, 123);
    delete(it);
    delete(it_end);
    delete(list);
    return 0;
}
