#ifndef RECURSION_H
#define RECURSION_H

#include <vector>
#include <iostream>

template <typename T>
class Node {
    private:
        T value;
        std::vector<Node<T>> children;
    public:
        Node();
        Node(T);
        Node(Node<T>&&, T);
        Node(std::vector<T>&&, T);
        Node(std::vector<Node<T>>&&, T);
        void add_child(Node<T>&&);
        void add_children(std::vector<Node<T>>&&);
        bool is_container();
        void find_leaves();
};

template <typename T>
Node<T>::Node() 
    : children(std::vector<Node<T>>()) 
{}

template <typename T>
Node<T>::Node(T value) 
    : value(value), children(std::vector<Node<T>>())
{}

template <typename T>
Node<T>::Node(Node<T>&& node, T sentinel) 
    : value(sentinel), children(std::move(std::vector<Node<T>>{node}))
{}

template <typename T>
Node<T>::Node(std::vector<T>&& values, T sentinel) 
    : value(sentinel), children(std::move(std::vector<Node<T>>()))
{
    for(int i = 0; i < values.size(); ++i) 
    {
        add_child(Node<T>{values[i]});
    }
}

template <typename T>
Node<T>::Node(std::vector<Node<T>>&& nodes, T sentinel) 
    : value(sentinel), children(std::move(nodes))
{}

template <typename T>
void Node<T>::add_child(Node<T>&& node) 
{
    children.push_back(node);
}

template <typename T>
void Node<T>::add_children(std::vector<Node<T>>&& nodes) 
{
    for(size_t i = 0; i < nodes.size(); ++i) 
    {
        children.push_back(nodes[i]);
    }
}

template <typename T>
bool Node<T>::is_container() 
{
    return children.size() > 0;
}

template <typename T>
void Node<T>::find_leaves() {
    for(size_t i = 0; i < children.size(); ++i) 
    {
        if(children[i].is_container()) 
        {
            children[i].find_leaves();
        }
        else 
        {
            std::cout << "Leaf: " << children[i].value << std::endl;
        }
    }
}
#endif //RECURSION_H
