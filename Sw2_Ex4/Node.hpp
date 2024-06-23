#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <memory>

template <typename T>
class Node {
private:
    T value;
    std::vector<Node<T>*>* children={};

public:
    explicit Node(T val){value=val;  children = new std::vector<Node<int>*>(); }

    T getValue() const { return value; }

    void addChild(const Node<T> * child,size_t size) {
        if (this->children->size() < size) {
            children->push_back(child);
        } else {
            throw std::runtime_error("Maximum children limit reached for parent node");
        }
    }

    std::vector<Node<T>*>* getChildren() const {return children;}
};

#endif // NODE_HPP
