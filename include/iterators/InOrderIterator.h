// written by Ido Avraham : 208699181
// EMAIL: idoavraham086@gmail.com
#ifndef IN_ORDER_ITERATOR_H
#define IN_ORDER_ITERATOR_H

#include "../Node.h"
#include <stack>

template<typename T, size_t k = 2>
class InOrderIterator {
private:
    Node<T> *current;             // Pointer to the current node in the traversal
    std::stack<Node<T> *> stack;  // Stack to manage the nodes for traversal

    // Push all left children of a node onto the stack
    void pushLeftChildren(Node<T> *node);

public:
    // Constructor initializes the iterator with the root node
    explicit InOrderIterator(Node<T> *root);

    // Pre-increment operator to advance the iterator
    InOrderIterator<T, k>& operator++();

    // Dereference operator to access the current node
    Node<T> *operator*();

    // Arrow operator to access members of the current node
    Node<T> *operator->();

    // Inequality operator to compare iterators
    bool operator!=(const InOrderIterator<T, k> &other) const;

    // Equality operator to compare iterators
    bool operator==(const InOrderIterator<T, k> &other) const;
};



#include "../../src/iterators/InOrderIterator.tpp" // Include the implementation file

#endif // IN_ORDER_ITERATOR_H
