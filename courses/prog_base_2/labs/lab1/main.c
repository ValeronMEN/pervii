#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "heap.h"
#include "memory.h"

static void new_void_zeroCount(void **state){
    heap_t * heap = heap_new(45);
    assert_int_equal(heap_getSize(heap), MAX_HEAP_SIZE);
    assert_int_equal(heap_getstatus(heap), HEAP_OK);
    heap_free(heap);
}

static void newManually_void_zeroCount(void **state){
    heap_t * heap = heap_new_manually(4567, 1);
    assert_int_equal(heap_getSize(heap), 1);
    assert_int_equal(heap_getstatus(heap), HEAP_OK);
    heap_free(heap);
}

static void newMemory_normalSizeOfMemory_onePassed(void **state){
    heap_t * heap = heap_new(67);
    memory_t * memory = heap_newMemory(heap, 40);
    assert_int_equal(heap_getSize(heap), 60);
    assert_int_equal(heap_getstatus(heap), HEAP_OK);
    assert_int_equal(memory_getstatus(memory), MEMORY_EMPTY);
    heap_free(heap);
}

static void newMemory_heapOverflow_nothingPassed(void **state){
    heap_t * heap = heap_new(67);
    memory_t * memory = heap_newMemory(heap, 300);
    assert_int_equal(heap_getSize(heap), 100);
    assert_int_equal(heap_getstatus(heap), HEAP_OVERFLOW);
    assert_int_equal(memory_getstatus(memory), MEMORY_EMPTY);
    heap_free(heap);
}

static void freeMemory_oneMemory_zeroCount(void **state){
    heap_t * heap = heap_new(23452);
    memory_t * memory = heap_newMemory(heap, 40);
    heap_freeMemory(memory, heap);
    assert_int_equal(heap_getSize(heap), 100);
    heap_free(heap);
}

static void freeMemory_oneMemoryBadHeap_nothingPassed(void **state){
    heap_t * heap = heap_new(23452);
    heap_t * heap2 = heap_new(1122);
    memory_t * memory = heap_newMemory(heap, 40);
    heap_freeMemory(memory, heap2);
    assert_int_equal(heap_getSize(heap), 60);
    assert_int_equal(memory_getstatus(memory), MEMORY_BADHEAP);
    heap_free(heap);
    heap_free(heap2);
}

static void memoryEnter_emptyMemory_nothingPassed(void **state){
    heap_t * heap = heap_new(45);
    memory_t * memory = heap_newMemory(heap, 40);
    memory_enter(memory, "");
    assert_int_equal(memory_getstatus(memory), MEMORY_EMPTY);
    heap_free(heap);
}

static void memoryEnter_oneNormalMemory_onePassed(void **state){
    heap_t * heap = heap_new(45);
    memory_t * memory = heap_newMemory(heap, 40);
    memory_enter(memory, "11 00 1101");
    assert_int_equal(memory_getstatus(memory), MEMORY_OK);
    heap_free(heap);
}

static void memoryEnter_overflowMemory_nothingPassed(void **state){
    heap_t * heap = heap_new(46);
    memory_t * memory = heap_newMemory(heap, 10);
    memory_enter(memory, "01010010101010100101");
    assert_int_equal(memory_getstatus(memory), MEMORY_OVERFLOW);
    heap_free(heap);
}

static void memoryEnter_baddataMemory_nothingPassed(void **state){
    heap_t * heap = heap_new(46);
    memory_t * memory = heap_newMemory(heap, 10);
    memory_enter(memory, "hdjfhdh");
    assert_int_equal(memory_getstatus(memory), MEMORY_BADDATA);
    heap_free(heap);
}

static void memoryRead_oneMemory_oneRead(void **state){
    heap_t * heap = heap_new(45);
    memory_t * memory = heap_newMemory(heap, 40);
    memory_enter(memory, "11");
    assert_int_equal(strcmp(memory_read(memory), "11"), 0);
    heap_free(heap);
}

static void memoryGetSize_oneMemory_sizePassed(void **state){
    heap_t * heap = heap_new(45);
    memory_t * memory = heap_newMemory(heap, 40);
    assert_int_equal(memory_getSize(memory), 40);
    heap_free(heap);
}

int main(){
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(new_void_zeroCount),
        cmocka_unit_test(newManually_void_zeroCount),
        cmocka_unit_test(newMemory_normalSizeOfMemory_onePassed),
        cmocka_unit_test(newMemory_heapOverflow_nothingPassed),
        cmocka_unit_test(freeMemory_oneMemory_zeroCount),
        cmocka_unit_test(freeMemory_oneMemoryBadHeap_nothingPassed),
        cmocka_unit_test(memoryEnter_emptyMemory_nothingPassed),
        cmocka_unit_test(memoryEnter_oneNormalMemory_onePassed),
        cmocka_unit_test(memoryEnter_overflowMemory_nothingPassed),
        cmocka_unit_test(memoryEnter_baddataMemory_nothingPassed),
        cmocka_unit_test(memoryRead_oneMemory_oneRead),
        cmocka_unit_test(memoryGetSize_oneMemory_sizePassed),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
