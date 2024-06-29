/*
id:206698359    mail:shoamivgi1234@gmail.com
*/

#include <sstream>
#include "doctest.h"
#include "KaryTree.hpp"


TEST_CASE("Nodes Compare")
{
    Complex c1(3.5, 2.0);
    Complex c2(1.5, 1.0);
    Complex c3(5.3, 11.0);
    Complex c4(7.2, 2.1);
    Complex c5(8.8, 6.6);
    Complex c9(3.5, 2.0);

   CHECK(c1>c2);
   CHECK(c1<c5);
   CHECK(c1!=c2);
   CHECK(c1!=c2);
   CHECK(c1==c9);
}


TEST_CASE("k-ary tree iterators") {
    // Create complex number nodes
    Complex c1(3.5, 2.0);
    Complex c2(1.5, 1.0);
    Complex c3(5.3, 11.0);
    Complex c4(7.2, 2.1);
    Complex c5(8.8, 6.6);
    Complex c6(5.4, 8.5);
    Complex c7(11, 3.14);
    Complex c8(1.0, 9.9);

    // Create nodes for the tree
    Node<Complex> root(c1);
    Node<Complex> n1(c2);
    Node<Complex> n2(c3);
    Node<Complex> n3(c4);
    Node<Complex> n4(c5);
    Node<Complex> n5(c6);
    Node<Complex> n6(c7);
    Node<Complex> n7(c8);

    // Create the k-ary tree and add nodes
    KaryTree<Complex, 2> tree;
    tree.add_root(&root);
    tree.add_sub_node(&root, &n1);
    tree.add_sub_node(&root, &n2);
    tree.add_sub_node(&n1, &n6);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n3, &n4);
    tree.add_sub_node(&n2, &n5);
    tree.add_sub_node(&n2, &n7);

    std::string expected_inorder =
        "11 + 3.14i\n"
        "1.5 + 1i\n"
        "8.8 + 6.6i\n"
        "7.2 + 2.1i\n"
        "3.5 + 2i\n"
        "5.4 + 8.5i\n"
        "5.3 + 11i\n"
        "1 + 9.9i\n";
    std::string expected_bfs =
        "3.5 + 2i\n"
        "1.5 + 1i\n"
        "5.3 + 11i\n"        
        "11 + 3.14i\n"
        "7.2 + 2.1i\n"
        "5.4 + 8.5i\n"
        "1 + 9.9i\n"
        "8.8 + 6.6i\n";
    std::string expected_dfs =
        "3.5 + 2i\n"
        "1.5 + 1i\n"
        "11 + 3.14i\n"
        "7.2 + 2.1i\n"
        "8.8 + 6.6i\n"
        "5.3 + 11i\n" 
        "5.4 + 8.5i\n"
        "1 + 9.9i\n";

    std::string expected_preorder =
        "3.5 + 2i\n"
        "1.5 + 1i\n"
        "11 + 3.14i\n"
        "7.2 + 2.1i\n"
        "8.8 + 6.6i\n"
        "5.3 + 11i\n"
        "5.4 + 8.5i\n"
        "1 + 9.9i\n";

   std::string expected_postorder =
    "11 + 3.14i\n"
    "8.8 + 6.6i\n"
    "7.2 + 2.1i\n"
    "1.5 + 1i\n"
    "5.4 + 8.5i\n"
    "1 + 9.9i\n"
    "5.3 + 11i\n"
    "3.5 + 2i\n";
     
   std::string expected_heap =
    "1.5 + 1i\n"
    "3.5 + 2i\n"
    "11 + 3.14i\n"
    "7.2 + 2.1i\n"
    "8.8 + 6.6i\n"
    "5.3 + 11i\n"
    "5.4 + 8.5i\n"
    "1 + 9.9i\n";

    std::string actual_preorder;
    std::string actual_inorder;
    std::string actual_postorder;
    std::string actual_bfs;
    std::string actual_dfs;
    std::string actual_heap;

for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
    std::ostringstream oss;
    oss << *node; // Assuming *node gives you a Complex object
    actual_preorder += oss.str() + "\n";
}
for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
    std::ostringstream oss;
    oss << *node; // Assuming *node gives you a Complex object
    actual_inorder += oss.str() + "\n";
}
for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
    std::ostringstream oss;
    oss << *node; // Assuming *node gives you a Complex object
    actual_postorder += oss.str() + "\n";
}
for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
    std::ostringstream oss;
    oss << *node; // Assuming *node gives you a Complex object
    actual_dfs += oss.str() + "\n";
}
for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
    std::ostringstream oss;
    oss << *node; // Assuming *node gives you a Complex object
    actual_bfs += oss.str() + "\n";
}
for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node) {
    std::ostringstream oss;
    oss << *node; // Assuming *node gives you a Complex object
    actual_heap += oss.str() + "\n";
}
CHECK(expected_inorder==actual_inorder);
CHECK(expected_postorder==actual_postorder);
CHECK(expected_preorder==actual_preorder);
CHECK(expected_dfs==actual_dfs);
CHECK(expected_bfs==actual_bfs);
CHECK(expected_heap==actual_heap);

}


TEST_CASE("Nodes childrens"){

    KaryTree<Complex, 2> tree;

    Complex c1(3.5, 2.0);
    Complex c2(1.5, 1.0);
    Complex c3(5.3, 11.0);
    Complex c4(7.2, 2.1);
    Complex c5(8.8, 6.6);
    Complex c6(5.4, 8.5);
    Complex c7(11, 3.14);
    Complex c8(1.0, 9.9);

    Node<Complex> root(c1);
    Node<Complex> n1(c2);
    Node<Complex> n2(c3);
    Node<Complex> n3(c4);
    Node<Complex> n4(c5);
    Node<Complex> n5(c6);
    Node<Complex> n6(c7);
    Node<Complex> n7(c8);

    tree.add_root(&root);
    tree.add_sub_node(&root, &n1);
    tree.add_sub_node(&root, &n2);
    tree.add_sub_node(&n1, &n6);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n3, &n4);
    tree.add_sub_node(&n2, &n5);
    tree.add_sub_node(&n2, &n7);

    CHECK(root.getChildren().at(0)->getValue()==n1.getValue());
    CHECK(root.getChildren().at(1)->getValue()==n2.getValue());
    CHECK(n1.getChildren().at(0)->getValue()==n6.getValue());
    CHECK(n1.getChildren().at(1)->getValue()==n3.getValue());
    CHECK(n2.getChildren().at(0)->getValue()==n5.getValue());
    CHECK(n2.getChildren().at(1)->getValue()==n7.getValue());

    
    KaryTree<double,3> second_tree;

    Node<double> root2(2);
    Node<double> d1(3.5);
    Node<double> d2(12.2);
    Node<double> d3(1);
    Node<double> d4(0.2);
    Node<double> d5(22.6);
    Node<double> d6(5);
    Node<double> d7(6);

    second_tree.add_root(&root2);
    second_tree.add_sub_node(&root2,&d1);
    second_tree.add_sub_node(&root2,&d2);
    second_tree.add_sub_node(&root2,&d3);
    second_tree.add_sub_node(&d1,&d4);
    second_tree.add_sub_node(&d1,&d5);
    second_tree.add_sub_node(&d2,&d6);
    second_tree.add_sub_node(&d6,&d7);

    CHECK(root2.getChildren().at(0)->getValue()==d1.getValue());
    CHECK(root2.getChildren().at(1)->getValue()==d2.getValue());
    CHECK(root2.getChildren().at(2)->getValue()==d3.getValue());

    CHECK(d1.getChildren().at(0)->getValue()==d4.getValue());
    CHECK(d1.getChildren().at(1)->getValue()==d5.getValue());
    CHECK(d2.getChildren().at(0)->getValue()==d6.getValue());
    CHECK(d6.getChildren().at(0)->getValue()==d7.getValue());

    //adding self

      SUBCASE("Adding self as child should throw exception") {
         CHECK_THROWS_AS(root.addChild(&root, 2), std::out_of_range);
     }
    //adding more children than permit
        CHECK_THROWS_AS(tree.add_sub_node(&root, &n7), std::runtime_error); 
        CHECK_THROWS_AS(second_tree.add_sub_node(&root2, &d4), std::runtime_error); 
    
    //adding children that alerdy exists

     CHECK_THROWS_AS(second_tree.add_sub_node(&d6, &d2), std::runtime_error);

}