#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

int main()
{
    list_t * example = list_new();
    assert(list_getstatus(example) == LIST_OK);
    assert(list_getcount(example) == 0);

    list_add(example, 67, 56, "Kyiv", -8);
    list_add(example, 45, 12, "Lvov", 89);
    list_add(example, 34, 6, "Antananarivu", 1);
    assert(list_getstatus(example) == LIST_BADNAME);
    list_add(example, 34, 6, "Kharkov", 1);
    assert(list_getstatus(example) == LIST_OK);
    assert(list_getcount(example) == 3);
    list_view(example);
    puts("");

    printf("Distance is %i\n\n", list_distance(example, 0, 1));
    list_distance(example, 12, 89);
    assert(list_getstatus(example) == LIST_BADINDEXES);
    list_distance(example, 0, 900);
    assert(list_getstatus(example) == LIST_BADINDEXES);

    list_sub(example, 1);
    assert(list_getstatus(example) == LIST_OK);
    assert(list_getcount(example) == 2);
    list_view(example);
    puts("");

    list_sub(example, 5);
    list_sub(example, -88);
    list_sub(example, -5);
    assert(list_getstatus(example) == LIST_UNDERFLOW);
    assert(list_getcount(example) == 0);

    list_free(example);

    printf("SUCCESS!\n");
    return 0;
}
