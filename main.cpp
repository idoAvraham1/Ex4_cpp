#include "include/Complex.h"
#include "include/Node.h"
#include "include/Tree.h"
#include <iostream>
#include <string>
#include <unistd.h>

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
 
  complex_tree.drawTree();
  /*
          Expected tree structure:
                                      (1 , 1i)
                                      /       \
                                   (2,2i)     (3 , 3i)
                                    /
                                  (4,4i)

       */

  for (auto node = complex_tree.begin_in_order(); node != complex_tree.end_in_order(); ++node) {
    cout << node->get_value() <<", ";
  }
   cout<<""<<endl;

 

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
    tree.drawTree();
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << node->get_value() <<", ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
     cout<<""<<endl;

    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << node->get_value() <<", ";
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
     cout<<""<<endl;

    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
         cout << node->get_value() <<", ";
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
     cout<<""<<endl;

    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
         cout << node->get_value() <<", ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
     cout<<""<<endl;

    for (auto node : tree)
    {
        cout << node->get_value() <<", ";
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout<<""<<endl;
    
    Tree<double,3> three_ary_tree; // 3-ary tree.
    three_ary_tree.add_root(root_node);
    three_ary_tree.add_sub_node(root_node, n1);
    three_ary_tree.add_sub_node(root_node, n2);
    three_ary_tree.add_sub_node(root_node, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);
    three_ary_tree.drawTree();
     // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */


    string s1 = "HOW";
    string s2 = "CAN";
    string s3 = "I";
    string s4 = "BE";
    string s5 = "HOMO!?";
    string s6 = "SHLOMI";
    string s7 = "GAY";
    //string s9 = "SHLOMI-GAY!";

    Node<string> root_string(s1);
    Node<string> n1_string(s2);
    Node<string> n2_string(s3);
    Node<string> n3_string(s4);
    Node<string> n4_string(s5);
    Node<string> n5_string(s6);
    Node<string> n6_string(s7);
   // Node<string> n8_string(s9);
    

    Tree<string,3> three_ary_tree_strings; // 3-ary tree.
    three_ary_tree_strings.add_root(root_string);
    three_ary_tree_strings.add_sub_node(root_string, n1_string);
    three_ary_tree_strings.add_sub_node(root_string, n2_string);
    three_ary_tree_strings.add_sub_node(root_string, n3_string);
    three_ary_tree_strings.add_sub_node(n1_string, n4_string);
    three_ary_tree_strings.add_sub_node(n2_string, n5_string);
    three_ary_tree_strings.add_sub_node(n3_string, n6_string);
    three_ary_tree_strings.drawTree();


  
  
}
