#include <string>
#include <iostream>
#include <vector>
#include "sorting.h"
#include "assert.h"

int main(int argc, char** argv) {
    int result[] = {1, 2, 4, 5, 7};

    int foo[] = {4, 2, 5, 7, 1};
    int foo_len = sizeof(foo)/sizeof(foo[0]);
    bubble_sort(foo, foo_len);
    for(int i = 0; i < foo_len; ++i) {
        assert(foo[i] == result[i]);
    }
    std::cout << "bubble_sort: Pass" << std::endl;
    

    int bar[] = {4, 2, 5, 7, 1};
    int bar_len = sizeof(bar)/sizeof(bar[0]);
    selection_sort(bar, bar_len);
    for(int i = 0; i < bar_len; ++i) {
        assert(bar[i] == result[i]);
    }
    std::cout << "selection_sort: Pass" << std::endl;

    int baz[] = {4, 2, 5, 7, 1};
    int baz_len = sizeof(baz)/sizeof(baz[0]);
    insertion_sort(baz, baz_len);
    for(int i = 0; i < baz_len; ++i) {
        assert(baz[i] == result[i]);
    }
    std::cout << "insertion_sort: Pass" << std::endl;

    return 0;
}
