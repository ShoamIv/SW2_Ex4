/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
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
    int tree_order;
public:

 KaryTree() : root(nullptr), tree_order(K) {}

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
        if(parent && (find_node(root,parent)) && (!find_node(root,child))){
             parent->addChild(child,K);
        } else {
            throw std::runtime_error("Not a valid parent or child.");
        }
    
    }
   bool find_node(const Node<T>* current, const Node<T>* target) {
    if (current == target) {
        return true;
    }
    for (const auto& child : current->getChildren()) {
        if (find_node(child, target)) {
            return true;
        }
    }
    return false;
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


    auto begin_in_order() {
        if constexpr (K == 2) {
            return InorderIterator<T>(root);
        } else {
            return DFSIterator<T>(root);
        }
    }

    auto end_in_order() {
        if constexpr (K == 2) {
            return InorderIterator<T>(nullptr);
        } else {
            return DFSIterator<T>(nullptr);
        }
    }

    auto begin_pre_order() {
        if constexpr (K == 2) {
            return PreorderIterator<T>(root);
        } else {
            return DFSIterator<T>(root);
        }
    }

    auto end_pre_order() {
        if constexpr (K == 2) {
            return PreorderIterator<T>(nullptr);
        } else {
            return DFSIterator<T>(nullptr);
        }
    }

    auto begin_post_order() {
        if constexpr (K == 2) {
            return PostorderIterator<T>(root);
        } else {
            return DFSIterator<T>(root);
        }
    }

    auto end_post_order() {
        if constexpr (K == 2) {
            return PostorderIterator<T>(nullptr);
        } else {
            return DFSIterator<T>(nullptr);
        }
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

   void win() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Binary Tree Display");
        sf::Font font;
        if (!font.loadFromFile("./Lato-BlackItalic.ttf")) {
            std::cerr << "Failed to load font!" << std::endl;
            return;
        }
        window.clear(sf::Color::White);

        // Pass the root node pointer directly
        this->tree_paint(window, *this, root, 400, 50, 200, font);
        window.display();

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
        }
    
    }

void tree_paint(sf::RenderWindow& window, KaryTree<T, K>& tree, Node<T>* node, int x, int y, int horizontal_gap, sf::Font& font){
         if (!node) return;

        // Drawing circle and lines...
        sf::Color circleColor = sf::Color::Green; // Red color for circles
        sf::Color outlineColor = sf::Color::Black; // Black color for circle outline
        sf::Color textColor = sf::Color::Black; // Black color for text

        // Draw circle
        sf::CircleShape circle(30); // Circle radius
        circle.setFillColor(circleColor);
        circle.setOutlineThickness(2);
        circle.setOutlineColor(outlineColor);
        circle.setPosition(x, y);
        window.draw(circle);

        // Convert value to string with fixed precision
        T value = node->getValue();
        std::ostringstream oss;
        oss.precision(1);
        oss << std::fixed << value;
        std::string text = oss.str();

        // Draw text
        sf::Text textObject(text, font, 20);
        textObject.setFillColor(textColor);
        sf::FloatRect textBounds = textObject.getLocalBounds();
        textObject.setOrigin(textBounds.left + textBounds.width / 2.0f,
                            textBounds.top + textBounds.height / 2.0f);
        textObject.setPosition(x + circle.getRadius(), y + circle.getRadius());
        window.draw(textObject);

        // Draw lines to children
        auto children = node->getChildren();
        int num_children = (int)children.size();
        if (num_children > 0) {
            for (int i = 0; i < num_children; ++i) {
                int child_x = x - horizontal_gap / 2 + i * horizontal_gap;
                int child_y = y + 100;

                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(x + circle.getRadius(), y + 2 * circle.getRadius())),
                    sf::Vertex(sf::Vector2f(child_x + circle.getRadius(), child_y))
                };
                line[0].color = sf::Color::Black;
                line[1].color = sf::Color::Black;
                window.draw(line, 2, sf::Lines);

                tree_paint(window, tree, children[i], child_x, child_y, horizontal_gap / 2, font);
            }
        }
    }


};
#endif // KARYTREE_HPP
