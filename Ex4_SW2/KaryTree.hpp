#ifndef KARYTREE_HPP
#define KARYTREE_HPP

#include <memory>
#include <vector>
#include <stdexcept>
#include <queue>
#include <sstream>
#include <iostream>
#include "Node.hpp"
#include "PostorderIterator.hpp"
#include "PreorderIterator.hpp"
#include "InorderIterator.hpp"
#include "DfsIterator.hpp"
#include "BfsIterator.hpp"
#include "HeapIterator.hpp"

template <typename T>
class InorderIterator;
template <typename T>
class PreorderIterator;
template <typename T>
class PostorderIterator;
template <typename T>
class DFSIterator;
template <typename T>
class BFSIterator;
template <typename T>
class HeapIterator;

template <typename T, size_t K = 2>
class KaryTree {
private:
    Node<T> * root;
    std::vector<T> heap;
public:
    KaryTree() : root(nullptr) {}

    explicit KaryTree(const T &rootValue) {
        root = std::make_shared<Node<T>>(rootValue);
    }

    std::shared_ptr<Node<T>> getRoot() const {
        return root;
    }

    void add_root(Node<T> * roots) {
        root =roots;
    }

    void add_sub_node(Node<T> *parent, Node<T>  *child) {
        if(parent){
            parent->addChild(child,K);
        } else {
            throw std::runtime_error("Not a valid parent.");
        }
    
    }
    // Function to draw the tree level by level
    void draw_tree(std::ostream& out = std::cout) const {
        if (!root) return;

        std::queue<Node<T>*> q;
        q.push(root);

        while (!q.empty()) {
            int level_size = q.size();
            for (int i = 0; i < level_size; ++i) {
                auto node = q.front();
                q.pop();

                out << node->getValue() << " ";

                 const auto& children = node->getChildren();
                for (const auto& child : children) {
                    q.push(child);
                }
            }
            out << std::endl; // Move to the next level
        }
    }

    void treeToList(Node<T>* node, std::vector<T>& list) {
        if (node == nullptr) return;
        list.push_back(node->getValue());
        const auto& children = node->getChildren();
            for (const auto& child : children) {
                treeToList(child, list);

        }
    }

    std::vector<T>& getHeap() {
        if (heap.empty()) {
            heap = toHeap();
        }
        return heap;
    }

    std::vector<T> toHeap() {
        std::vector<T> heap1;
        treeToList(root, heap1);
        std::make_heap(heap1.begin(), heap1.end(), std::greater<T>());
        return heap1;
    }

    /*
     * Declaration of the iterator class
     */


    InorderIterator<T> begin_in_order() {
        return InorderIterator<T>(root);
    }

    InorderIterator<T> end_in_order() {
        return InorderIterator<T>(nullptr);
    }

    PreorderIterator<T> begin_pre_order() {
        return PreorderIterator<T>(root);
    }

    PreorderIterator<T> end_pre_order() {
        return PreorderIterator<T>(nullptr);
    }

    PostorderIterator<T> begin_post_order() {
        return PostorderIterator<T>(root);
    }

    PostorderIterator<T> end_post_order() {
        return PostorderIterator<T>(nullptr);
    }

    BFSIterator<T> begin_bfs_scan() {
        return BFSIterator<T>(root);
    }

    BFSIterator<T> end_bfs_scan() {
        return BFSIterator<T>(nullptr);
    }

    DFSIterator<T> begin_dfs_scan() {
        return DFSIterator<T>(root);
    }

    DFSIterator<T> end_dfs_scan() {
        return DFSIterator<T>(nullptr);
    }

    HeapIterator<T> begin_heap() {
        return HeapIterator<T>(getHeap());
    }

    HeapIterator<T> end_heap() {
        auto& heap = getHeap();
        return HeapIterator<T>(heap, heap.size());
    }

   void renderTree(sf::RenderWindow& window, Node<T>* node, sf::Font& font, float x, float y, float xOffset) {
    if (!node) return;

    // Draw the node as a circle
    sf::CircleShape circle(30);
    circle.setFillColor(sf::Color::White);
    circle.setOutlineThickness(2);
    circle.setOutlineColor(sf::Color::Black);
    circle.setPosition(x, y);
    window.draw(circle);

    T value = node->getValue();
    std::ostringstream oss;
    oss.precision(1);
    oss << std::fixed << value;
    std::string text = oss.str();
    // Draw the node value
    sf::Text obj(text, font, 20);
    obj.setFillColor(sf::Color::Black);
    sf::FloatRect textBounds = obj.getLocalBounds();
    obj.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    obj.setPosition(x + circle.getRadius(), y + circle.getRadius());
    window.draw(obj);

    // Calculate x offset for child nodes
    float childOffset = xOffset / (node->getChildren().size() + 1); // Space for each child
    float startX = x + circle.getRadius();
    float startY = y + circle.getRadius() * 2;

    float currX = startX - xOffset / 2; // Starting x position for children
    float currY = startY + 30; // Distance between parent and children in y axis

    int index = 0;
    //int child_y = y + 100;
    for (auto child : node->getChildren()) {
        currX = startX - (xOffset / 2) + index * (xOffset); // Calculate x position based on index

        // Draw edge
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(startX, startY), sf::Color::Black),
            sf::Vertex(sf::Vector2f(currX, currY), sf::Color::Black)
        };
        window.draw(line, 2, sf::Lines);

        // Recursively draw child node
        renderTree(window, child, font, currX - circle.getRadius(), currY, childOffset);

        index++;
    }
}


};
#endif // KARYTREE_HPP
