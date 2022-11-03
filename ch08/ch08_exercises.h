#ifndef HASH_H
#define HASH_H

#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

template <typename T>
std::vector<T> find_intersection(std::vector<T> set1, std::vector<T> set2) {
    int len1 = set1.size();
    int len2 = set2.size();
    std::vector<T>* big;
    std::vector<T>* small;
    if(len1 > len2) {
        big = &set1;
        small = &set2;
    }
    else {
        small = &set1;
        big = &set2;
    }
    // create hashset
    std::unordered_map<T, bool> map;
    for(std::size_t i = 0; i < big->size(); ++i) {
        map[(*big)[i]] = true;
    }
    // find duplicates
    std::vector<T> out;
    for(std::size_t i = 0; i < small->size(); ++i) {
        T value = (*small)[i];
        auto found = map.find(value);
        if(found != map.end()) {
            out.push_back(value);
        }
    }
    return out;
}

template <typename T>
T find_first_duplicate(std::vector<T> set, T sentinel) {
    // create hashset
    std::unordered_set<T> unique;
    for(std::size_t i = 0; i < set.size(); ++i) {
        T value = set[i];
        auto found = unique.find(value);
        if(found == unique.end()) {
            unique.insert(value); 
        }
        else {
            return value;
        }
    }
    return sentinel;
}

char find_missing_letter(std::string str, char sentinel) {
    std::unordered_set<char> alpha;
    for(char& c: str) {
        alpha.insert(c);
    }
    // iterate through alphabet
    for(int ch = 'a'; ch <= 'z'; ++ch) {
        auto found = alpha.find(ch);
        if(found == alpha.end()) {
            return ch;
        }
    } 
    return sentinel;
}

char find_nonduplicate_letter(std::string str, char sentinel) {
    std::unordered_map<char, int> map;
    for(char& c: str) {
        auto found = map.find(c);
        if(found == map.end()) {
            std::pair<char, int> letter(c, 0);
            map.insert(letter);
        }
        else {
            map[c] += 1;
        }
    }
    // Find first duplicate letter
    for(char& c: str) {
        if(map[c] == 0) {
            return c;
        }
    }
    return sentinel;
}

#endif //HASH_H 
