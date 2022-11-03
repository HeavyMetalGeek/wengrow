#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>

template <typename T>
class Queue
{
    private:
        int qsize;
        T* container;
        int head;
        int tail;
        size_t count;
        void resize();
    public:
        Queue(T sentinel, int size = 8);
        ~Queue();
        void enqueue(T);
        T dequeue();
        T peek();
        int size();
        int capacity();
        T sentinel;
};

template <typename T>
Queue<T>::Queue(T sentinel, int size) 
    : qsize(size), head(0), tail(-1), count(0), sentinel(sentinel)
{
    container = new T[qsize];
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] container;
}

template <typename T>
void Queue<T>::resize() {
    size_t new_size = 2 * qsize;
    T* new_container = new T[new_size];
    for(size_t i = 0; i < count; ++i)
    {
        new_container[i] = container[(head + i) % qsize];
    }
    delete[] container;
    container = new_container;
    qsize = new_size;
}

template <typename T>
void Queue<T>::enqueue(T value) {
    if(size() == qsize) { resize(); }
    tail = (tail + 1) % qsize;
    container[tail] = value;
    count += 1;
}

template <typename T>
T Queue<T>::dequeue() {
    if(size() == 0) { return sentinel; }
    T pop = container[head];
    container[head] = sentinel;
    head = (head + 1) % qsize;
    count -= 1;
    return pop;
}

template <typename T>
T Queue<T>::peek() {
    if(size() == 0) { return sentinel; }
    return container[head];
}

template <typename T>
int Queue<T>::size() {
    return count;
}

template <typename T>
int Queue<T>::capacity() {
    return qsize;
}
#endif // QUEUE_H
