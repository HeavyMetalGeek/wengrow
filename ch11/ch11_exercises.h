#ifndef C11_EXERCISES_H
#define C11_EXERCISES_H

#include <string>
#include <vector>

int count_chars(std::vector<std::string>& strings, std::vector<std::string>::iterator it)
{
    // base case
    if(it == strings.end()) { return 0; }
    // recurse
    return (*it).length() + count_chars(strings, ++it);
}

void just_evens(std::vector<int>& nums, std::vector<int>::iterator it, std::vector<int>& evens)
{
    // base case
    if(it == nums.end()) { return; }
    // recurse
    if(*it % 2 == 0) { evens.push_back(*it); }
    just_evens(nums, ++it, evens);
}

int triangular_numbers(int n)
{
    // base case
    if(n == 1) { return 1; }
    // base case
    return n + triangular_numbers(n - 1);
}

int x_index(std::string& str, std::string::iterator it)
{
    if(it == str.end()) { return -1; }
    if(*it == 'x') 
    { 
        return std::distance(str.begin(), it); 
    }
    return x_index(str, ++it);
}

int unique_paths(int rows, int cols)
{
    if(rows == 1 || cols == 1) 
    { 
        return 1; 
    }

    int res = unique_paths(rows - 1, cols) + unique_paths(rows, cols - 1); 
    return res;
}
#endif // C11_EXERCISES_H

