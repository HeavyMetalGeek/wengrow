#include "node.h"
#include <iostream>

// Chapter 10 Exercise 4
int main() {
    Node<int> base_node;
    base_node.add_child(Node<int>{1});
    base_node.add_child(Node<int>{2});
    base_node.add_child(Node<int>{3});

    base_node.add_child(
        Node<int>(std::vector<Node<int>> {Node<int>{4}, Node<int>{5}, Node<int>{6}}, 0)
    );

    base_node.add_child(Node<int>{7});

    Node<int> node_b(std::vector<Node<int>> {Node<int>{8}}, 0);
    node_b.add_child(
        Node<int>(std::vector<Node<int>> {Node<int>{9}, Node<int>{10}, Node<int>{11}}, 0)
    );
    node_b.add_child(
        Node<int>(
            Node<int>(std::vector<Node<int>> {Node<int>{12}, Node<int>{13}, Node<int>{14}}, 0),
            0
        )
    );
    base_node.add_child(std::move(node_b));

    Node<int> node_c(std::vector<Node<int>> {
        Node<int>{15}, Node<int>{16}, Node<int>{17}, Node<int>{18}, Node<int>{19}},
        0
    );

    Node<int> node_cf(
        std::vector<Node<int>> {Node<int>{20}, Node<int>{21}, Node<int>{22}},
        0
    );

    Node<int> node_cfd(
        std::vector<Node<int>> {Node<int>{23}, Node<int>{24}, Node<int>{25}}, 
        0
    );

    // 28 was missing from the exercise
    Node<int> node_cfdc(
        std::vector<Node<int>> {Node<int>{26}, Node<int>{27}, Node<int>{29}}, 
        0
    );

    node_cfd.add_child(std::move(node_cfdc));
    node_cf.add_child(std::move(node_cfd));
    node_cf.add_children(std::vector<Node<int>> {Node<int>{30}, Node<int>{31}});
    node_c.add_child(std::move(node_cf));
    node_c.add_child(Node<int>{32});

    base_node.add_child(std::move(node_c));
    base_node.add_child(Node<int>{33});
    base_node.find_leaves();
}
