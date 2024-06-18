#ifndef BFS_ITERATOR_H
#define BFS_ITERATOR_H

#include "../Node.h"
#include <queue>

template<typename T, size_t k = 2>
class BFSIterator {
private:
    Node<T> *current;              // Pointer to the current node in the traversal
    std::queue<Node<T> *> queue;   // Queue to manage the nodes for BFS traversal

public:
    // Constructor initializes the iterator with the root node
    explicit BFSIterator(Node<T> *root);

    // Pre-increment operator to advance the iterator
    BFSIterator<T, k>& operator++();

    // Dereference operator to access the current node
    Node<T> *operator*();

    // Arrow operator to access members of the current node
    Node<T> *operator->();

    // Inequality operator to compare iterators
    bool operator!=(const BFSIterator<T, k> &other) const;

    // Equality operator to compare iterators
    bool operator==(const BFSIterator<T, k> &other) const;
};

#include "../../src/iterators/BFSIterator.tpp" // Include the implementation file

#endif // BFS_ITERATOR_H
