#ifndef KARYTREE_HPP
#define KARYTREE_HPP

#include <memory>
#include <vector>
#include <stdexcept>
#include <queue>
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

    void add_root(Node<int> * roots) {
        root =roots;
    }

    void add_sub_node(Node<int> *parent, Node<int>  *child) {
        if(parent->getChildren()==nullptr){

        }
        if (parent->getChildren()->size() < K) {
            parent->getChildren()->push_back(child);
        } else {
            throw std::runtime_error("Maximum children limit reached for parent node");
        }
        /*
        if (parent) {
            parent->addChild(child,K);
        } else {
            throw std::runtime_error("Not a Valid parent.");
        }
         */
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
        if (children) {
            for (const auto& child : *children) {
                treeToList(child, list);
            }
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

    PostorderIterator<int> begin_post_order() {
        return PostorderIterator<T>(root);
    }

    PostorderIterator<int> end_post_order() {
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
};
#endif // KARYTREE_HPP
