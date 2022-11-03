#include <vector>
#include <cstddef>
#include <iostream>

template <typename T>
class Stack {
    private:
        int qsize;
        std::vector<T> container;
        int top;
    public:
        Stack(T sentinel, int size = 8);
        ~Stack();
        void resize();
        void push(T);
        T pop();
        T peek();
        int size();
        int capacity();
        T sentinel;
};

template <typename T>
Stack<T>::Stack(T sentinel, int size) 
    : qsize(size), container(std::vector<T>(size)), top(-1)
{}

template <typename T>
Stack<T>::~Stack(){}

template <typename T>
void Stack<T>::resize() {
    std::cout << "Old capacity: " << container.capacity();
    qsize *= 2;
    std::vector<T> new_container(qsize);
    for(size_t i = 0; i < top + 1; ++i) {
        new_container[i] = container[i];
    }
    container = new_container;
    std::cout << ", New capacity: " << container.capacity() << std::endl;
}

template <typename T>
void Stack<T>::push(T value) {
    if(size() == qsize) { resize(); }
    top += 1;
    container[top] = value;
}

template <typename T>
T Stack<T>::pop() {
    if(size() == 0) { return sentinel; }
    T popped = container[top];
    top -= 1;
    return popped;
}

template <typename T>
T Stack<T>::peek() {
    if(size() == 0) { return sentinel; }
    return container[top];
}

template <typename T>
int Stack<T>::size() {
    return top + 1;
}

template <typename T>
int Stack<T>::capacity() {
    return container.capacity();
}
