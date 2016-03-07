#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "list.h"

static void new_void_zeroCount(void **state){
    list_t * list = list_new();
    assert_int_equal(list_getcount(list), 0);
    list_free(list);
}

static void add_threeValuesWithOrdinaryNamesRightIndexes_threeCount(void **state){
    list_t * list = list_new();
    list_add(list, 56, 108, "Kyiv", 0);
    list_add(list, -49, 67, "Shostka", 1);
    list_add(list, 8, -16, "Prypiat", 1);
    assert_int_equal(list_getcount(list), 3);
    list_free(list);
}

static void add_twoValuesWithOrdinaryNameBiggerThanExistIndexAndLowerThanZeroIndex_twoCount(void **state){
    list_t * list = list_new();
    list_add(list, -56, 108, "Lvov", 8);
    assert_int_equal(list_getcount(list), 1);
    list_add(list, 56, -108, "Kharkov", -45);
    assert_int_equal(list_getcount(list), 2);
    list_free(list);
}

static void add_oneValueWithNotOrdinaryNameRightIndex_zeroCount(void **state){
    list_t * list = list_new();
    list_add(list, 16, 3, "Monastyrska" /*name > MAX_NAME_SIZE*/, -3);
    assert_int_equal(list_getcount(list), 0);
    list_free(list);
}

static void add_110ValuesWithOrdinaryNameRightIndex_hundredCountGetOverflow(void **state){
    int i;
    list_t * list = list_new();
    for(i=0; i<110; i++){
        list_add(list, -8, -9, "Vinniza", -3);
    }
    assert_int_equal(list_getcount(list), 100);
    //cause 110 > MAX_LIST_SIZE
    list_free(list);
}

static void sub_hasTwoValues_oneCount(void **state){
    list_t * list = list_new();
    list_add(list, 56, 108, "Kyiv", 0);
    list_add(list, 76, 221, "Vienna", 1);
    list_sub(list, 0);
    assert_int_equal(list_getcount(list), 1);
    list_free(list);
}

static void sub_hasTwoValuesTryToDeleteTwoBadIndexes_zeroCount(void **state){
    list_t * list = list_new();
    list_add(list, 56, 108, "Kyiv", 0);
    list_add(list, 56, 108, "Lvov", 0);
    list_sub(list, 454);
    list_sub(list, -3434);
    assert_int_equal(list_getcount(list), 0);
    list_free(list);
}

static void sub_hasOneValueTryToDeleteTenTimes_zeroCountGetUnderflow(void **state){
    int i;
    list_t * list = list_new();
    list_add(list, 56, 108, "Kyiv", 0);
    for(i=0; i<10; i++){
        list_sub(list, 0);
    }
    assert_int_equal(list_getcount(list), 0);
    list_free(list);
}

static void distance_hasTwoValuesInputRightIndexes_distanceBetweenExistCities(void **state){
    list_t * list = list_new();
    list_add(list, 67, 56, "Kyiv", -8);
    list_add(list, 34, 6, "Kharkov", 1);
    assert_int_equal(59, list_distance(list, 0, 1));
    list_free(list);
}

static void distance_hasTwoValuesInputBadIndexes_zeroDistance(void **state){
    list_t * list = list_new();
    list_add(list, 67, 56, "Kyiv", -8);
    list_add(list, 34, 6, "Kharkov", 1);
    assert_int_equal(-1, list_distance(list, -1, 1));
    assert_int_equal(-1, list_distance(list, 0, -1));
    assert_int_equal(-1, list_distance(list, 2, 1));
    assert_int_equal(-1, list_distance(list, 0, 2));
    list_free(list);
}

int main(){
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(new_void_zeroCount),
        cmocka_unit_test(add_threeValuesWithOrdinaryNamesRightIndexes_threeCount),
        cmocka_unit_test(add_twoValuesWithOrdinaryNameBiggerThanExistIndexAndLowerThanZeroIndex_twoCount),
        cmocka_unit_test(add_oneValueWithNotOrdinaryNameRightIndex_zeroCount),
        cmocka_unit_test(add_110ValuesWithOrdinaryNameRightIndex_hundredCountGetOverflow),
        cmocka_unit_test(sub_hasTwoValues_oneCount),
        cmocka_unit_test(sub_hasTwoValuesTryToDeleteTwoBadIndexes_zeroCount),
        cmocka_unit_test(sub_hasOneValueTryToDeleteTenTimes_zeroCountGetUnderflow),
        cmocka_unit_test(distance_hasTwoValuesInputRightIndexes_distanceBetweenExistCities),
        cmocka_unit_test(distance_hasTwoValuesInputBadIndexes_zeroDistance)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
