/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <stdexcept>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Complex.hpp"

template <typename T>
class Node {
private:
    using NodePtr = Node<T>*;
    T value;

public:
    sf::Vector2f position;
    explicit Node(T val) : value(val) {}
    std::vector<NodePtr> children;


    T getValue() const { return value; }

    void addChild(NodePtr child,int size) {
    
        if(child==this){
         throw std::out_of_range("a node cannot add himself");
        }

        if (children.size() < (size_t)size) {
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
