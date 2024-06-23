#include <iostream>
#include "KaryTree.hpp"

int main() {

    auto root1 =Node<int>(1);
    auto n1 = Node<int>(2);
    auto n2 = Node<int>(3);
    auto n3 = Node<int>(4);
    auto n4 = Node<int>(5);
    auto n5 = Node<int>(6);

    KaryTree<int> tree;
    tree.add_root(&root1);

    tree.add_sub_node(&root1,&n1);
    tree.add_sub_node(&root1,&n2);
    tree.add_sub_node(&n1,&n3);
    tree.add_sub_node(&n1,&n4);
    tree.add_sub_node(&n2,&n5);


    std::cout <<"PreOrder: \n";
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        std::cout << *node << std::endl;
    }
// prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

std::cout <<"PostOrder: \n";
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        std::cout << *node << std::endl;

    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

    std::cout <<"InOrder: \n";
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {

        std::cout << *node << std::endl;

    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    std::cout <<"InOrder: \n";
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {

        std::cout << *node << std::endl;
    }
    std::cout <<"BFS: \n";
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        std::cout << *node << std::endl;
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    std::cout <<"DFS: \n";
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
    {
        std::cout << *node << std::endl;
    }

    HeapIterator<int> it = tree.begin_heap();
    HeapIterator<int> end = tree.end_heap();
    std::cout <<"Heap: \n";
    for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node) {
        std::cout << *node << std::endl;
    }

      //tree.draw_tree();
    return 0;
}
