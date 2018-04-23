#include <stdio.h>
#include "minunit.h"

#include "../src/algorithms/bubble_sort.c"

int tests_run = 0;

char *test_bubble_sort(void) {
    int array0[] = {4, 3, 2, 1, 0};
    bubble_sort(array0, sizeof(array0) / sizeof(int));

    for (size_t i = 0; i < sizeof(array0) / sizeof(int); i++) {
        mu_assert("Error, array not bubble sorted.", array0[i] == (int) i);
    }

    int array1[] = {-40897, 84, 0, 3029, 92, 1904, 3498, -3924, -32, 1};
    int array2[] = {-40897, -3924, -32, 0, 1, 84, 92, 1904, 3029, 3498};
    bubble_sort(array1, sizeof(array1) / sizeof(int));

    for (size_t i = 0; i < sizeof(array1) / sizeof(int); i++) {
        mu_assert("Error, array not bubble sorted.", array1[i] == array2[i]);
    }

    return 0;
}

char *all_tests(void) {
    mu_run_test(test_bubble_sort);

    return 0;
}

int main(void) {
     char *result = all_tests();
     if (result != 0) {
         printf("%s\n", result);
     }
     else {
         printf("ALL TESTS PASSED\n");
     }
     printf("Tests run: %d\n", tests_run);

     return result != 0;
}
