#include "include/Complex.h"
#include "include/Node.h"
#include "include/Tree.h"
#include <iostream>
#include <string>


using namespace std;

int main() {

  // Create Complex objects
  Complex c1(1, 1);
  Complex c2(2, 2);
  Complex c3(3, 3);
  Complex c4(4, 4);

  // Create nodes
  Node<Complex> root_node_complex(c1);
  Node<Complex> n1_complex(c2);
  Node<Complex> n2_complex(c3);
  Node<Complex> n3_complex(c4);

  // Create tree and add nodes
  Tree<Complex> complex_tree;
  complex_tree.add_root(root_node_complex);
  complex_tree.add_sub_node(root_node_complex, n1_complex);
  complex_tree.add_sub_node(root_node_complex, n2_complex);
  complex_tree.add_sub_node(n1_complex, n3_complex);

  /*
          Expected tree structure:
                                      (1 , 1i)
                                      /       \
                                   (2,2i)     (3 , 3i)
                                    /
                                  (4,4i)

       */

  for (auto node = complex_tree.begin_in_order(); node != complex_tree.end_in_order(); ++node) {
    cout << node->value << endl;
  }

 Node<double> root_node = Node(1.1);
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<double> n1 = Node(1.2);
    Node<double> n2 = Node(1.3);
    Node<double> n3 = Node(1.4);
    Node<double> n4 = Node(1.5);
    Node<double> n5 = Node(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
   
    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    for (auto node : tree)
    {
        cout << node->get_value() << endl;
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    //cout << tree; // Should print the graph using GUI.

    Tree<double,3> three_ary_tree; // 3-ary tree.
    three_ary_tree.add_root(root_node);
    three_ary_tree.add_sub_node(root_node, n1);
    three_ary_tree.add_sub_node(root_node, n2);
    three_ary_tree.add_sub_node(root_node, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);

     // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */
  
}
