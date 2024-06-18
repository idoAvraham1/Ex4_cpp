#ifndef DFS_ITERATOR_H
#define DFS_ITERATOR_H

#include "../Node.h"
#include <stack>

template<typename T, size_t k = 2>
class DFSIterator {
private:
    Node<T> *current;             // Pointer to the current node in the traversal
    std::stack<Node<T> *> stack;  // Stack to manage the nodes for DFS traversal

public:
    // Constructor initializes the iterator with the root node
    explicit DFSIterator(Node<T> *root);

    // Pre-increment operator to advance the iterator
    DFSIterator<T, k>& operator++();

    // Dereference operator to access the current node
    Node<T>* operator*();

    // Arrow operator to access members of the current node
    Node<T> *operator->();

    // Inequality operator to compare iterators
    bool operator!=(const DFSIterator<T, k> &other) const;

    // Equality operator to compare iterators
    bool operator==(const DFSIterator<T, k> &other) const;
};

#include "../../src/iterators/DFSIterator.tpp" // Include the implementation file

#endif // DFS_ITERATOR_H
