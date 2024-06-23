#ifndef POSTORDERITERATOR_HPP
#define POSTORDERITERATOR_HPP

#include "Node.hpp"
#include <stack>
#include <utility> // for std::pair

template <typename T>
class PostorderIterator {
private:
    using NodePtr = Node<T>*;
    using StackElement = std::pair<NodePtr, bool>;

    NodePtr current;
    std::stack<StackElement> stack;

    // Push all nodes from the current path to the stack
    void pushPath(NodePtr node) {
        while (node != nullptr) {
            stack.push({node, false}); // Push node with visited flag as false
            node = getLeftChild(node);
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
    // Constructor initializes the iterator
    explicit PostorderIterator(NodePtr root) {
        current = nullptr;
        pushPath(root); // Start from the leftmost path of the root
        ++(*this); // Move to the first valid node
    }

    // Dereference operator to get the value of the current node
    T operator*() const {
        return current->getValue();
    }

    // Inequality operator to compare iterators
    bool operator!=(const PostorderIterator& other) const {
        return current != other.current;
    }

    // Pre-increment operator to move to the next node in the post-order traversal
    PostorderIterator& operator++() {
        while (!stack.empty()) {
            auto& [node, visited] = stack.top();
            if (!visited) {
                stack.top().second = true; // Mark node as visited
                if (NodePtr rightChild = getRightChild(node)) {
                    pushPath(rightChild);
                }
            } else {
                current = node; // Set the current node
                stack.pop(); // Remove from stack
                return *this;
            }
        }
        current = nullptr; // If stack is empty, traversal is complete
        return *this;
    }
};

#endif // POSTORDERITERATOR_HPP
