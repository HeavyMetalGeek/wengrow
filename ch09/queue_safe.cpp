#include "assert.h"
#include "queue.h"
#include "safe_queue.h"
#include "iostream"

int main(int argc, char** argv) {
    SafeQueue<int> q(-1, 8);
    q.enqueue(0);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(14);
    q.enqueue(15);
    q.enqueue(99);

    std::cout << "Queue capacity: " << q.capacity() << std::endl;
    std::cout << "Queue size: " << q.size() << std::endl;
    std::cout << "Pop: " << q.dequeue() << std::endl;
    std::cout << "Pop: " << q.dequeue() << std::endl;
    std::cout << "Pop: " << q.dequeue() << std::endl;
    std::cout << "Pop: " << q.dequeue() << std::endl;
    std::cout << "Pop: " << q.dequeue() << std::endl;
    std::cout << "Pop: " << q.dequeue() << std::endl;
    std::cout << "Pop: " << q.dequeue() << std::endl;
    std::cout << "Pop: " << q.dequeue() << std::endl;
    std::cout << "Pop: " << q.dequeue() << std::endl;
    std::cout << "Pop: " << q.dequeue() << std::endl;
    std::cout << "Pop: " << q.dequeue() << std::endl;
    std::cout << "Pop: " << q.dequeue() << std::endl;
    std::cout << "Pop: " << q.dequeue() << std::endl;
    std::cout << "Pop: " << q.dequeue() << std::endl;
    std::cout << "Pop: " << q.dequeue() << std::endl;
    std::cout << "Pop: " << q.dequeue() << std::endl;
    std::cout << "Pop: " << q.dequeue() << std::endl;
}
