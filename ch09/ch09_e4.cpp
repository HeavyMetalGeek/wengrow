#include "assert.h"
#include "stack.h"
#include "iostream"
#include <string>

// Chapter 9 Exercise 4
int main(int argc, char** argv) {
    Stack<char> q(' ', 8);

    std::string test = "abcde";
    for(char& c: test) {
        q.push(c);
    }
    
    int count = q.size();
    for(int i = 0; i < count; ++i) {
        std::cout << "Pop: " << q.pop() << std::endl;
    }

}
