#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "heap.h"
#include "memory.h"

static void newAndNewManuallyHeaps_void_zeroCount(void **state){
    heap_t * heap = heap_new(45);
    assert_int_equal(heap_getSize(heap), 100);
    assert_int_equal(heap_getstatus(heap), HEAP_OK);
    heap_free(heap);
    heap = heap_new_manually(4567, 1);
    assert_int_equal(heap_getSize(heap), 1);
    assert_int_equal(heap_getstatus(heap), HEAP_OK);
    heap_free(heap);
}

static void newMemory_overflowAndNormalSizesOfMemories_oneEmptyMemoryCount(void **state){
    heap_t * heap = heap_new(67);
    memory_t * memory = heap_newMemory(heap, 300);
    assert_int_equal(heap_getSize(heap), 100);
    assert_int_equal(heap_getstatus(heap), HEAP_OVERFLOW);
    assert_int_equal(memory_getstatus(memory), MEMORY_EMPTY);
    heap_newMemory(heap, 40);
    assert_int_equal(heap_getSize(heap), 60);
    assert_int_equal(heap_getstatus(heap), HEAP_OK);
    assert_int_equal(memory_getstatus(memory), MEMORY_EMPTY);
    heap_free(heap);
}

static void freeMemory_oneMemory_zeroCount(void **state){
    heap_t * heap = heap_new(23452);
    heap_t * heap2 = heap_new(1122);
    memory_t * memory = heap_newMemory(heap, 40);
    heap_freeMemory(memory, heap2);
    assert_int_equal(heap_getSize(heap), 60);
    assert_int_equal(memory_getstatus(memory), MEMORY_BADHEAP);
    heap_freeMemory(memory, heap);
    assert_int_equal(heap_getSize(heap), 100);
    heap_free(heap);
}

static void memoryEnter_EmptyNormalOverflowAndBaddataMemories_oneCount(void **state){
    heap_t * heap = heap_new(45);
    memory_t * memory = heap_newMemory(heap, 40);
    memory_enter(memory, "11 00 1101");
    assert_int_equal(memory_getstatus(memory), MEMORY_OK);
    memory_enter(memory, "");
    assert_int_equal(memory_getstatus(memory), MEMORY_EMPTY);
    heap_free(heap);
    heap = heap_new(45);
    memory = heap_newMemory(heap, 10);
    memory_enter(memory, "hdjfhdh");
    assert_int_equal(memory_getstatus(memory), MEMORY_BADDATA);
    memory_enter(memory, "01010010101010100101");
    assert_int_equal(memory_getstatus(memory), MEMORY_OVERFLOW);
    heap_free(heap);
}

static void memoryReadAndGetSize_oneMemory_textAndSizeFromStart(void **state){
    heap_t * heap = heap_new(45);
    memory_t * memory = heap_newMemory(heap, 40);
    memory_enter(memory, "11");
    assert_int_equal(strcmp(memory_read(memory), "11"), 0);
    assert_int_equal(memory_getSize(memory), 40);
    heap_free(heap);
}

int main(){
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(newAndNewManuallyHeaps_void_zeroCount),
        cmocka_unit_test(newMemory_overflowAndNormalSizesOfMemories_oneEmptyMemoryCount),
        cmocka_unit_test(freeMemory_oneMemory_zeroCount),
        cmocka_unit_test(memoryEnter_EmptyNormalOverflowAndBaddataMemories_oneCount),
        cmocka_unit_test(memoryReadAndGetSize_oneMemory_textAndSizeFromStart),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
