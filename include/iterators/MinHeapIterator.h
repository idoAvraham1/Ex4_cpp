// written by Ido Avraham : 208699181
// EMAIL: idoavraham086@gmail.com
#ifndef MIN_HEAP_ITERATOR_H
#define MIN_HEAP_ITERATOR_H

#include "../Node.h"
#include <functional>
#include <iostream>
#include <queue>
#include <vector>


template <typename T, size_t k = 2> class MinHeapIterator {
private:
  std::vector<Node<T> *> heap; // Vector to store heap elements
  size_t index;                // Current index in the heap
  bool is_end;                 // Flag to indicate the end iterator

  // helper struct to compare the node value
  struct CompareNodes {
    bool operator()(Node<T> *a, Node<T> *b) const {
      return a->value < b->value; // Min-heap comparison
    }
  };

  // Helper function to traverse the tree and collect nodes
  void traverse(Node<T> *node);

public:
  // Constructor initializes the iterator with the root node
  explicit MinHeapIterator(Node<T> *root);

  // Pre-increment operator to advance the iterator
  MinHeapIterator<T, k> &operator++();

  // Dereference operator to access the current node
  Node<T> *operator*();

  // Arrow operator to access members of the current node
  Node<T> *operator->();

  // Inequality operator to compare iterators
  bool operator!=(const MinHeapIterator<T, k> &other) const;

  // Equality operator to compare iterators
  bool operator==(const MinHeapIterator<T, k> &other) const;
};

#include "../../src/iterators/MinHeapIterator.tpp" // Include the implementation file

#endif // MIN_HEAP_ITERATOR_H
