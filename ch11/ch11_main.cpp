#include "ch11_exercises.h"
#include <vector>
#include <string>
#include <iostream>
#include <cassert>

int main() {
    std::vector<std::string> strings{"ab", "c", "def", "ghij"};
    int count = count_chars(strings, strings.begin());
    assert(count == 10);
    std::cout << "[PASS] Character count: " << count << std::endl;

    std::vector<int> nums{1, 3, 6, 10, 15, 21};
    std::vector<int> evens;
    std::vector<int> evens_res{6, 10};
    just_evens(nums, nums.begin(), evens);
    for(size_t i = 0; i < evens.size(); ++i)
    {
        assert(evens[i] == evens_res[i]);
    }
    std::cout << "[PASS] Evens: " << evens[0] << ", " << evens[1] << std::endl;

    int tri = triangular_numbers(7);
    assert(tri == 28);
    std::cout << "[PASS] Tri: " << tri << std::endl;
    
    std::string alpha = "abcdefghijklmnopqrstuvwxyz";
    int idx = x_index(alpha, alpha.begin());
    std::cout << "[PASS] x-index: " << idx << std::endl;
    assert(idx == 23);

    int paths = unique_paths(3, 7);
    assert(paths == 28);
    std::cout << "[PASS] Number of paths: " << paths << std::endl;
}

