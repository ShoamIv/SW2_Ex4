#ifndef BFSITERATOR_HPP
#define BFSITERATOR_HPP

#include "Node.hpp"
#include <queue>

template <typename T>
class BFSIterator {
private:
    using NodePtr = Node<T>*;

    NodePtr current;
    std::queue<NodePtr> queue;

public:
    // Constructor initializes the iterator and enqueues the root node
    explicit BFSIterator(NodePtr root) {
        current = nullptr;
        if (root != nullptr) {
            queue.push(root);
        }
        ++(*this); // Move to the first valid node
    }

    // Dereference operator to get the value of the current node
    T operator*() const {
        return current->getValue();
    }

    // Inequality operator to compare iterators
    bool operator!=(const BFSIterator& other) const {
        return current != other.current;
    }

    // Pre-increment operator to move to the next node in the BFS traversal
    BFSIterator& operator++() {
        if (!queue.empty()) {
            current = queue.front();
            queue.pop();

            const auto& children = current->getChildren();
            for (NodePtr child : children) {
                if (child) { // Ensure child is not null before pushing
                    queue.push(child);
                }
            }
        } else {
            current = nullptr; // If queue is empty, traversal is complete
        }
        return *this;
    }
};

#endif // BFSITERATOR_HPP
