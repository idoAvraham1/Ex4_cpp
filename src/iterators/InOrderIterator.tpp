// written by Ido Avraham : 208699181
// EMAIL: idoavraham086@gmail.com
#include "../../include/iterators/InOrderIterator.h"

// Push all left children of a node onto the stack
template<typename T, size_t k>
void InOrderIterator<T, k>::pushLeftChildren(Node<T> *node) {
    while (node) {
        stack.push(node);
        node = (node->children.size() > 0) ? node->children[0] : nullptr;
    }
}

// Constructor initializes the iterator with the root node
template<typename T, size_t k>
InOrderIterator<T, k>::InOrderIterator(Node<T> *root) : current(nullptr) {
    if (root) {
        pushLeftChildren(root);
    }
    ++(*this);  // Move to the first element
}

// Pre-increment operator to advance the iterator
template<typename T, size_t k>
InOrderIterator<T, k>& InOrderIterator<T, k>::operator++() {
    // If the stack is empty, the traversal is complete
    if (stack.empty()) {
        current = nullptr;  // Set current to nullptr indicating the end
        return *this;
    }

    // Pop the top node from the stack and set it as the current node
    current = stack.top();
    stack.pop();

    // Check if the current node has a right child
    Node<T> *node = (current->children.size() > 1) ? current->children[1] : nullptr;

    // If there is a right child, push its left children onto the stack
    pushLeftChildren(node);

    // Return the iterator itself
    return *this;
}

// Dereference operator to access the current node
template<typename T, size_t k>
Node<T> *InOrderIterator<T, k>::operator*() {
    return current;
}

template<typename T, size_t k>
bool  InOrderIterator<T,k>::operator!=(const InOrderIterator <T, k> &other) const {
    return current != other.current;
}

template<typename T, size_t k>
bool InOrderIterator<T,k>::operator ==(const InOrderIterator<T , k>& other ) const{
    return current == other.current;
}

template<typename T, size_t k>
Node<T> *InOrderIterator<T, k>::operator->() {
    return current;
}


