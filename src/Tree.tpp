#include "../include/Tree.h"

template <typename T, size_t k>
Tree<T, k>::Tree() : root(nullptr) { // Constructor with default arity
  if (k <= 0) {
    throw std::runtime_error("Arity of the tree must be greater than 0");
  }
}

template <typename T, size_t k> Tree<T, k>::~Tree() { clear(root); }

template <typename T, size_t k> void Tree<T, k>::clear(Node<T> *node) {
  if (node) {
    for (auto child : node->children) {
      clear(child);
    }
    delete node;
  }
}

template <typename T, size_t k> void Tree<T, k>::add_root(Node<T> &root_node) {
  root =
      new Node<T>(root_node.value, k); // Initialize root with the correct arity
}

template <typename T, size_t k>
bool Tree<T, k>::add_sub_node(Node<T> &parent_node, Node<T> &sub_node) {
  Node<T> *parent = find_node(root, parent_node.value);
  if (parent) {
    for (size_t i = 0; i < parent->k; ++i) {
      if (!parent->children[i]) {
        parent->children[i] = new Node<T>(
            sub_node.value, k); // Initialize sub_node with the correct arity
        return true;
      }
    }
  }
  return false;
}

template <typename T, size_t k>
Node<T> *Tree<T, k>::find_node(Node<T> *node, T value) {
  if (!node)
    return nullptr;

  if (node->value == value)
    return node;

  for (auto child : node->children) {
    Node<T> *result = find_node(child, value);
    if (result)
      return result;
  }

  return nullptr;
}

// Iterator methods
template <typename T, size_t k>
typename IteratorType<T, k>::PreOrder Tree<T, k>::begin_pre_order() {
  return typename IteratorType<T, k>::PreOrder(root);
}

template <typename T, size_t k>
typename IteratorType<T, k>::PreOrder Tree<T, k>::end_pre_order() {
  return typename IteratorType<T, k>::PreOrder(nullptr);
}

template <typename T, size_t k>
typename IteratorType<T, k>::PostOrder Tree<T, k>::begin_post_order() {
  return typename IteratorType<T, k>::PostOrder(root);
}

template <typename T, size_t k>
typename IteratorType<T, k>::PostOrder Tree<T, k>::end_post_order() {
  return typename IteratorType<T, k>::PostOrder(nullptr);
}

template <typename T, size_t k>
typename IteratorType<T, k>::InOrder Tree<T, k>::begin_in_order() {
  return typename IteratorType<T, k>::InOrder(root);
}

template <typename T, size_t k>
typename IteratorType<T, k>::InOrder Tree<T, k>::end_in_order() {
  return typename IteratorType<T, k>::InOrder(nullptr);
}

template <typename T, size_t k> BFSIterator<T, k> Tree<T, k>::begin_bfs_scan() {
  return BFSIterator<T, k>(root);
}

template <typename T, size_t k> BFSIterator<T, k> Tree<T, k>::end_bfs_scan() {
  return BFSIterator<T, k>(nullptr);
}

template <typename T, size_t k> DFSIterator<T, k> Tree<T, k>::begin_dfs() {
  return DFSIterator<T, k>(root);
}

template <typename T, size_t k> DFSIterator<T, k> Tree<T, k>::end_dfs() {
  return DFSIterator<T, k>(nullptr);
}

template <typename T, size_t k> BFSIterator<T, k> Tree<T, k>::begin() {
  return BFSIterator<T, k>(root);
}

template <typename T, size_t k> BFSIterator<T, k> Tree<T, k>::end() {
  return BFSIterator<T, k>(nullptr);
}

// Method to get the beginning of the min-heap iterator
template <typename T, size_t k>
MinHeapIterator<T, k> Tree<T, k>::begin_min_heap() {
  if (k == 2)
    return MinHeapIterator<T, k>(root);
  else
    throw std::runtime_error("The tree isn't binary tree!");
}

// Method to get the end of the min-heap iterator
template <typename T, size_t k>
MinHeapIterator<T, k> Tree<T, k>::end_min_heap() {
  if (k == 2)
    return MinHeapIterator<T, k>(nullptr); // End iterator
  else
    throw std::runtime_error("The tree isn't binary tree!");
}