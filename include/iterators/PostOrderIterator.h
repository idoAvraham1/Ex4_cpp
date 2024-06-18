#ifndef POST_ORDER_ITERATOR_H
#define POST_ORDER_ITERATOR_H

#include "../Node.h"
#include <stack>

template<typename T, size_t k = 2>
class PostOrderIterator {
private:
    Node<T>* current;              // Pointer to the current node in the traversal
    std::stack<Node<T>*> stack1;   // Stack to manage the nodes for traversal (processing)
    std::stack<Node<T>*> stack2;   // Stack to store the nodes in post-order

public:
    explicit PostOrderIterator(Node<T> *root);
    PostOrderIterator<T, k>& operator++();
    Node<T> *operator*();
    Node<T> *operator->();
    bool operator!=(const PostOrderIterator<T, k> &other) const;
    bool operator==(const PostOrderIterator<T, k> &other) const;
};

#include "../../src/iterators/PostOrderIterator.tpp" // Include the implementation file

#endif // POST_ORDER_ITERATOR_H
