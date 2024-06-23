    #ifndef PreorderIteartor_HPP
    #define PreorderIteartor_HPP

    #include "Node.hpp"
    #include <stack>
    #include <memory>

    template <typename T>
    class PreorderIterator {
    private:
        using NodePtr = Node<T>*;

        NodePtr current;
        std::stack<NodePtr> stack_Pre;

        // Pushes children onto the stack in reverse order
        void pushChildren( NodePtr node) {
            if (node) {
                const auto& children = node->getChildren();
                // Push children from right to left so that left-most is on top
                for (auto it = children->rbegin(); it != children->rend(); ++it) {
                    stack_Pre.push(*it);
                }
            }
        }

    public:
        explicit PreorderIterator( NodePtr node) : current(node) {
            if (node) {
                stack_Pre.push(node); // Start with the root node
            }
        }

        T operator*() const {
            return current->getValue();
        }

        bool operator!=(const PreorderIterator& other) const {
            return current != other.current;
        }

        PreorderIterator& operator++() {
            if (!stack_Pre.empty()) {
                current = stack_Pre.top();
                stack_Pre.pop();
                pushChildren(current);
                if (!stack_Pre.empty()) {
                    current = stack_Pre.top();
                } else {
                    current = nullptr;
                }
            }
            return *this;
        }
    };

    #endif // PreorderIteartor_HPP
