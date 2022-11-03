#ifndef SAFE_QUEUE_H
#define SAFE_QUEUE_H

#include <cstddef>
#include <vector>

template <typename T>
class SafeQueue
{
    private:
        int qsize;
        std::vector<T> container;
        int head;
        int tail;
        size_t count;
        void resize();
    public:
        SafeQueue(T sentinel, int size = 8);
        ~SafeQueue();
        void enqueue(T);
        T dequeue();
        T peek();
        int size();
        int capacity();
        T sentinel;
};

template <typename T>
SafeQueue<T>::SafeQueue(T sentinel, int size) 
    : qsize(size), container(std::vector<T>(size)), head(0), tail(-1), count(0), sentinel(sentinel) 
{
}

template <typename T>
SafeQueue<T>::~SafeQueue()
{
}

template <typename T>
void SafeQueue<T>::resize() {
    qsize *= 2;
    std::vector<T> new_container(qsize);
    for(size_t i = 0; i < count; ++i)
    {
        new_container[i] = container[(head + i) % qsize];
    }
    container = new_container;
}

template <typename T>
void SafeQueue<T>::enqueue(T value) {
    if(size() == qsize) { resize(); }
    tail = (tail + 1) % qsize;
    container[tail] = value;
    count += 1;
}

template <typename T>
T SafeQueue<T>::dequeue() {
    if(size() == 0) { return sentinel; }
    T pop = container[head];
    container[head] = sentinel;
    head = (head + 1) % qsize;
    count -= 1;
    return pop;
}

template <typename T>
T SafeQueue<T>::peek() {
    if(size() == 0) { return sentinel; }
    return container[head];
}

template <typename T>
int SafeQueue<T>::size() {
    return count;
}

template <typename T>
int SafeQueue<T>::capacity() {
    return container.capacity();
}
#endif // SAFE_QUEUE_H
