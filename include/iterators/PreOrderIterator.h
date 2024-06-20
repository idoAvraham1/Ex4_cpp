// written by Ido Avraham : 208699181
// EMAIL: idoavraham086@gmail.com
#ifndef CPP_EX4_PREORDERITERATOR_H
#define CPP_EX4_PREORDERITERATOR_H
#include "../Node.h"
#include "stack"

template<typename T, size_t k = 2>
class PreOrderIterator {
private:
    Node<T>* current;           // Pointer to the current node in the traversal
    std::stack<Node<T>*> stack; // Stack to manage the nodes for traversal

public:
    explicit PreOrderIterator(Node<T>* root);
    PreOrderIterator<T, k>& operator++();
    Node<T>* operator*();
    Node<T>* operator->();
    bool operator!=(const PreOrderIterator<T, k>& other) const;
    bool operator==(const PreOrderIterator<T, k>& other) const;
};

#include "../../src/iterators/PreOrderIterator.tpp" // Include the implementation file


#endif //CPP_EX4_PREORDERITERATOR_H
