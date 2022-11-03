#include <string>
#include <iostream>
#include <vector>
#include "assert.h"
#include "ch08_exercises.h"

static const char sentinel_char = '0';
static const std::string sentinel("NONE");

int main(int argc, char** argv) {
    std::vector<int> set1 {1, 2, 3, 4, 5};
    std::vector<int> set2 {0, 2, 4, 6, 8};
    std::vector<int> out {2, 4};
    std::vector<int> res = find_intersection(set1, set2);
    for(size_t i = 0; i < out.size(); ++i) {
        assert(res[i] == out[i]);
    }

    std::cout << "find_intersection: Pass" << std::endl;
    std::vector<std::string> set {"a", "b", "c", "d", "c", "e", "f"};
    std::string dup = "c";
    std::string dup_res = find_first_duplicate(set, sentinel);
    assert(dup_res == dup);
    std::cout << "find_first_duplicate: Pass" << std::endl;

    std::string sentance {"the quick brown box jumps over a lazy dog"};
    char missing = 'f';
    char missing_res = find_missing_letter(sentance, sentinel_char);
    assert(missing_res == missing);
    std::cout << "find_missing_letter: Pass" << std::endl;

    std::string word {"minimum"};
    char dup_char = 'n';
    char dup_char_res = find_nonduplicate_letter(word, sentinel_char);
    assert(dup_char_res == dup_char);
    std::cout << "find_nonduplicate_letter: Pass" << std::endl;

    return 0;
}
