#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include "iterators/BFSIterator.h"
#include "iterators/DFSIterator.h"
#include "iterators/InOrderIterator.h"
#include "iterators/IteratorType.h"
#include "iterators/MinHeapIterator.h"
#include "iterators/PostOrderIterator.h"
#include "iterators/PreOrderIterator.h"
#include <iostream>
#include <queue>

template <typename T, size_t k = 2> class Tree {
private:
  Node<T> *root;

  void clear(Node<T> *node);

  Node<T> *find_node(Node<T> *node, T value);

public:
  Tree(); // Constructor with default arity
  ~Tree();

  void add_root(Node<T> &root_node);

  bool add_sub_node(Node<T> &parent_node, Node<T> &sub_node);

  // Iterator methods
  typename IteratorType<T, k>::PreOrder begin_pre_order();
  typename IteratorType<T, k>::PreOrder end_pre_order();

  typename IteratorType<T, k>::PostOrder begin_post_order();
  typename IteratorType<T, k>::PostOrder end_post_order();

  typename IteratorType<T, k>::InOrder begin_in_order();
  typename IteratorType<T, k>::InOrder end_in_order();

  BFSIterator<T, k> begin_bfs_scan();

  BFSIterator<T, k> end_bfs_scan();

  DFSIterator<T, k> begin_dfs();

  DFSIterator<T, k> end_dfs();

  BFSIterator<T, k> begin();

  BFSIterator<T, k> end();

  MinHeapIterator<T, k> begin_min_heap();
  MinHeapIterator<T, k> end_min_heap();

  // Make the TreeWidget class a friend to access private members
  template <typename U, size_t m> friend class TreeWidget;

  // Override the << operator to use Qt for graphical output
  template <typename U, size_t m>
  friend std::ostream &operator<<(std::ostream &os, const Tree<U, m> &tree);
};

#include "../src/Tree.tpp" // Include the implementation file

#endif // TREE_H
