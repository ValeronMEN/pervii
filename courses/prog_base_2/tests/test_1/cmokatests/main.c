#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../liblibrary/library.h"

static void new_void_zeroCount(void **state){
    library_t * mylib = library_new();
    assert_int_equal(library_getStatus(mylib), LIBRARY_OK);
    library_free(mylib);
}

static void libAddIndex_newBook_oneCount(void **state){
    library_t * mylib = library_new();
    book_t * mybook = book_new("Babenko", "Sea", 8);
    library_addIndex(mylib, mybook, 9);
    assert_int_equal(library_getCount(mylib), 1);
    library_free(mylib);
}

int main(){
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(new_void_zeroCount),
        cmocka_unit_test(libAddIndex_newBook_oneCount),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
