#ifndef DFSITERATOR_HPP
#define DFSITERATOR_HPP

#include "Node.hpp"
#include <stack>

template <typename T>
class DFSIterator {
private:
    using NodePtr = Node<T>*;

    NodePtr current;
    std::stack<NodePtr> stack;

public:
    // Constructor initializes the iterator and pushes the root node
    explicit DFSIterator(NodePtr root) {
        current = nullptr;
        if (root != nullptr) {
            stack.push(root);
        }
        ++(*this); // Move to the first valid node
    }

    // Dereference operator to get the value of the current node
    T operator*() const {
        return current->getValue();
    }

    // Inequality operator to compare iterators
    bool operator!=(const DFSIterator& other) const {
        return current != other.current;
    }

    // Pre-increment operator to move to the next node in the DFS traversal
    DFSIterator& operator++() {
        if (!stack.empty()) {
            current = stack.top();
            stack.pop();

            // Push children of the current node onto the stack in reverse order
                auto& children = current->getChildren();
                for (auto it = children.rbegin(); it != children.rend(); ++it) {
                    stack.push(*it);
                }

        } else {
            current = nullptr; // If stack is empty, traversal is complete
        }
        return *this;
    }
};

#endif // DFSITERATOR_HPP
