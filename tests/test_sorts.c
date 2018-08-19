#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "greatest.h"

#include "../src/algorithms/sorting.c"


const int TEST_ARRAY_SIZE = 10;

int max(int array[], int length) {
    int maximum = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] > maximum) {
            maximum = array[i];
        }
    }
    return maximum;
}

int *create_random_array(int length) {
    srand(time(NULL));
    int *array = malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++) {
        array[i] = rand() % 1000;
    }
    return array;
}

TEST test_bubble_sort(void) {
    int *array = create_random_array(TEST_ARRAY_SIZE);

    bubble_sort(array, TEST_ARRAY_SIZE);

    for (int i = 0; i < TEST_ARRAY_SIZE-1; i++) {
        ASSERT(array[i] <= array[i+1]);
    }
    PASS();
}

TEST test_counting_sort(void) {
    int *array = create_random_array(TEST_ARRAY_SIZE);

    int sorted_array[TEST_ARRAY_SIZE];

    for (int i = 0; i < TEST_ARRAY_SIZE; i++) {
        sorted_array[i] = 0;
    }

    counting_sort(array, sorted_array, TEST_ARRAY_SIZE, max(array, TEST_ARRAY_SIZE));

    for (int i = 0; i < TEST_ARRAY_SIZE-1; i++) {
        ASSERT(sorted_array[i] <= sorted_array[i+1]);
    }
    PASS();
}

TEST test_heap_sort(void) {
    int *array = create_random_array(TEST_ARRAY_SIZE);

    heap_sort(array, TEST_ARRAY_SIZE);

    for (int i = 0; i < TEST_ARRAY_SIZE-1; i++) {
        ASSERT(array[i] <= array[i+1]);
    }
    PASS();
}


TEST test_insertion_sort(void) {
    int *array = create_random_array(TEST_ARRAY_SIZE);

    insertion_sort(array, TEST_ARRAY_SIZE);

    for (int i = 0; i < TEST_ARRAY_SIZE-1; i++) {
        ASSERT(array[i] <= array[i+1]);
    }
    PASS();
}

TEST test_merge_sort(void) {
    int *array = create_random_array(TEST_ARRAY_SIZE);

    merge_sort(array, 0, TEST_ARRAY_SIZE);

    for (int i = 0; i < TEST_ARRAY_SIZE-1; i++) {
        ASSERT(array[i] <= array[i+1]);
    }
    PASS();
}

TEST test_quick_sort(void) {
    int *array = create_random_array(TEST_ARRAY_SIZE);

    quick_sort(array, 0, TEST_ARRAY_SIZE);

    for (int i = 0; i < TEST_ARRAY_SIZE-1; i++) {
        ASSERT(array[i] <= array[i+1]);
    }
    PASS();
}

TEST test_selection_sort(void) {
    int *array = create_random_array(TEST_ARRAY_SIZE);

    selection_sort(array, TEST_ARRAY_SIZE);

    for (int i = 0; i < TEST_ARRAY_SIZE-1; i++) {
        ASSERT(array[i] <= array[i+1]);
    }
    PASS();
}


SUITE(sorting_algorithms) {
    RUN_TEST(test_bubble_sort);
    RUN_TEST(test_counting_sort);
    RUN_TEST(test_heap_sort);
    RUN_TEST(test_insertion_sort);
    RUN_TEST(test_merge_sort);
    RUN_TEST(test_quick_sort);
    RUN_TEST(test_selection_sort);
}
