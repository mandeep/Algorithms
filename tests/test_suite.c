#include "test_searches.c"
#include "test_sorts.c"
#include "test_statistics.c"
#include "test_euclidean.c"
#include "test_bst.c"


GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();
    RUN_SUITE(statistical_algorithms);
    RUN_SUITE(sorting_algorithms);
    RUN_SUITE(searching_algorithms);
    RUN_SUITE(euclidean_algorithms);
    RUN_SUITE(binary_search_tree);
    GREATEST_MAIN_END();
}
