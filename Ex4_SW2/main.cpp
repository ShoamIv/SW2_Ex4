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

    root.position = sf::Vector2f(400, 50);
    n1.position = sf::Vector2f(250, 200);
    n2.position = sf::Vector2f(550, 200);
    n3.position = sf::Vector2f(200, 350);
    n4.position = sf::Vector2f(300, 350);
    n5.position = sf::Vector2f(550, 350);

    
     sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Tree Example");
     
    // Load the font
    sf::Font font;
    if (!font.loadFromFile("./Lato-BlackItalic.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
        return 1;  // Exit if the font is not loaded
    }

     
        window.clear(sf::Color::White);
        // Render the tree
        tree.renderTree(window, &root, font, root.position.x, root.position.y, 400);
        window.display();
        while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

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

    std::cout << "Tree Drawing:\n";
    tree.draw_tree();

    return 0;
}
