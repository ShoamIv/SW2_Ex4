/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#include <SFML/Graphics.hpp>
#include <iostream>
#include "KaryTree.hpp"
#include "Node.hpp"


int main() {
   

    Complex c1(3.5, 2.0);
    Complex c2(1.5, 1.0);
    Complex c3(5.3, 11.0);
    Complex c4(7.2, 2.1);
    Complex c5(8.8, 6.6);
    Complex c6(5.4, 8.5);
    Complex c7(11, 3.14);
    Complex c8(1, 9.9);

    Node<Complex> root(c1);
    Node<Complex> n1(c2);
    Node<Complex> n2(c3);
    Node<Complex> n3(c4);
    Node<Complex> n4(c5);
    Node<Complex> n5(c6);
    Node<Complex> n6(c7);
    Node<Complex> n7(c8);

    // Create the tree and add nodes
    KaryTree<Complex,3> tree;
    tree.add_root(&root);
    tree.add_sub_node(&root, &n1);
    tree.add_sub_node(&root, &n2);
    tree.add_sub_node(&root, &n6);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);
    tree.add_sub_node(&n2, &n7);

     
     tree.win();

    // Output tree traversals
    
    std::cout << "PreOrder:\n";
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        std::cout << *node << std::endl;
    }

    std::cout << "PostOrder:\n";
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        std::cout << *node << std::endl;
    }

    std::cout << "InOrder:\n";
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        std::cout << *node << std::endl;
    }

    std::cout << "BFS:\n";
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        std::cout << *node << std::endl;
    }

    std::cout << "DFS:\n";
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        std::cout << *node << std::endl;
    }

    std::cout << "Heap:\n";
    for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node) {
        std::cout << *node << std::endl;
    }


    return 0;
}
