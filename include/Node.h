#ifndef NODE_H
#define NODE_H

#include <cstddef>
#include <vector>

template <typename T> class Node {
public:
  T value;
  size_t k; // Number of children
  std::vector<Node<T> *> children;

  explicit Node(T val, size_t k = 2);

  T get_value();
};

#include "../src/Node.tpp" // Include the implementation file

#endif // NODE_H
