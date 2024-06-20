# K-ary Tree Implementation

## Overview

This project implements a template-based k-ary tree in C++. The k-ary tree is a generalization of a binary tree where each node can have up to `k` children. The project includes several types of iterators for traversing the tree, as well as a method to visualize the tree using SFML (Simple and Fast Multimedia Library). Additionally, a `Complex` class is provided to demonstrate the use of custom objects within the tree.

## Features

- Template-based k-ary tree with adjustable arity (`k`).
- Multiple traversal methods:
  - Pre-order
  - Post-order
  - In-order
  - Breadth-First Search (BFS)
  - Depth-First Search (DFS)
  - Min-Heap traversal (for binary trees only)
- Tree visualization using SFML.
- Custom `Complex` class with overloaded operators and support for arithmetic and comparison operations.
- Example usage of the k-ary tree with various data types including `Complex`, `double`, and `std::string`.

## Files

### Headers

- `Tree.h`: Definition and implementation of the `Tree` class.
- `Node.h`: Definition of the `Node` class used in the tree.
- `Complex.h`: Definition of the `Complex` class.

### Source

- `Tree.cpp`: Implementation of the `Tree` class.
- `Node.cpp`: Implementation of the `Node` class.
- `Complex.cpp`: Implementation of the `Complex` class.
- `main.cpp`: Example usage of the k-ary tree with different data types.

## Usage

### Creating and Manipulating Trees

1. **Creating Complex Objects and Nodes:**

```cpp

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

//visualize the tree 
complex_tree.drawTree();

```

2. **Creating 3-ary strings tree:**
```cpp
 // create nodes
 Node<std::string> root_string("HOW");
 Node<std::string> n1_string("CAN");
 Node<std::string> n2_string("I");
 Node<std::string> n3_string("BE");

 // create tree and add nodes 
Tree<string, 3> three_ary_tree_strings;
three_ary_tree_strings.add_root(root_string);
three_ary_tree_strings.add_sub_node(root_string, n1_string);
three_ary_tree_strings.add_sub_node(root_string, n2_string)

 ```

 ## Running the Program:
 make rundemo 


### Run the Tests:
make runtests

### Use Valgrind on the Test File:
make testvalgrind

### Installation and Dependencies
## Prerequisites:
SFML (Simple and Fast Multimedia Library)