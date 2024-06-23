#ifndef INORDERITERATOR_HPP
#define INORDERITERATOR_HPP

#include "Node.hpp"
#include <stack>

template <typename T>
class InorderIterator {
private:
    using NodePtr = Node<T>*;

    NodePtr current;
    std::stack<NodePtr> stack;

    // Push the leftmost path of the subtree starting from node
    void pushLeftMostPath(NodePtr node) {
        while (node != nullptr) {
            stack.push(node);
            node = getLeftChild(node); // Get the left child of the current node
        }
    }

    // Function to get the left child of a node
    NodePtr getLeftChild(NodePtr node) {
        if (node == nullptr || node->getChildren().empty()) {
            return nullptr;
        }
        return node->getChildren().front(); // Return the leftmost child
    }

    // Function to get the right child of a node
    NodePtr getRightChild(NodePtr node) {
        if (node == nullptr || node->getChildren().size() < 2) {
            return nullptr;
        }
        return node->getChildren().at(1); // Return the right child if it exists
    }

public:
    // Constructor initializes the iterator and moves to the first valid node
    explicit InorderIterator(NodePtr root) {
        current = nullptr;
        pushLeftMostPath(root); // Start from the leftmost path of the root
        ++(*this); // Move to the first valid node
    }

    // Dereference operator to get the value of the current node
    T operator*() const {
        return current->getValue();
    }

    // Inequality operator to compare iterators
    bool operator!=(const InorderIterator& other) const {
        return current != other.current;
    }

    // Pre-increment operator to move to the next node in the in-order traversal
    InorderIterator& operator++() {
        if (!stack.empty()) {
            NodePtr node = stack.top();
            stack.pop();
            current = node; // Set the current node

            // Push the leftmost path of the right subtree
            if (NodePtr rightChild = getRightChild(node)) {
                pushLeftMostPath(rightChild);
            }
        } else {
            current = nullptr; // If stack is empty, traversal is complete
        }
        return *this;
    }
};

#endif // INORDERITERATOR_HPP
