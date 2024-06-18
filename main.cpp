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
  Tree<Complex> tree;
  tree.add_root(root_node_complex);
  tree.add_sub_node(root_node_complex, n1_complex);
  tree.add_sub_node(root_node_complex, n2_complex);
  tree.add_sub_node(n1_complex, n3_complex);

  /*
          Expected tree structure:
                                      (1 , 1i)
                                      /       \
                                   (2,2i)     (3 , 3i)
                                    /
                                  (4,4i)

       */

  for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
    cout << node->value << endl;
  }
}
