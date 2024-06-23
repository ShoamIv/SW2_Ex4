#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <stdexcept>

template <typename T>
class Node {
private:
    using NodePtr = Node<T>*;
    T value;
    std::vector<NodePtr> children;

public:
    explicit Node(T val) : value(val) {}

    T getValue() const { return value; }

    void addChild(NodePtr child,int size) {

        if (children.size() < size) {
            children.push_back(child);
        } else {
            throw std::out_of_range("Maximum children limit reached for parent node");
        }
    }

    const std::vector<NodePtr>& getChildren() const {
        return children;
    }
};

#endif // NODE_HPP
