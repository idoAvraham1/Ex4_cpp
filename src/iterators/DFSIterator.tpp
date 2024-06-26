// written by Ido Avraham : 208699181
// EMAIL: idoavraham086@gmail.com
#include "../../include/iterators/DFSIterator.h"

// Constructor initializes the iterator with the root node
template<typename T, size_t k>
DFSIterator<T, k>::DFSIterator(Node<T> *root) : current(nullptr) {
    if (root) {
        stack.push(root);  // Push the root node onto the stack
    }
    ++(*this);  // Move to the first element
}

// Pre-increment operator to advance the iterator
template<typename T, size_t k>
DFSIterator<T, k>& DFSIterator<T, k>::operator++() {
    // If the stack is empty, the traversal is complete
    if (stack.empty()) {
        current = nullptr;  // Set current to nullptr indicating the end
        return *this;
    }

    // Pop the top node from the stack and set it as the current node
    current = stack.top();
    stack.pop();

    // Push all children of the current node onto the stack in reverse order
    const auto& children = current->get_children();
    for (int i = children.size() - 1; i >= 0; --i) {
        if (children[i]) {
            stack.push(children[i]);
        }
    }

    // Return the iterator itself
    return *this;
}

// Dereference operator to access the current node
template<typename T, size_t k>
Node<T>* DFSIterator<T, k>::operator*() {
    return current;
}

// Arrow operator to access members of the current node
template<typename T, size_t k>
Node<T> *DFSIterator<T, k>::operator->() {
    return current;
}

// Inequality operator to compare iterators
template<typename T, size_t k>
bool DFSIterator<T, k>::operator!=(const DFSIterator<T, k> &other) const {
    return current != other.current;
}

// Equality operator to compare iterators
template<typename T, size_t k>
bool DFSIterator<T, k>::operator==(const DFSIterator<T, k> &other) const {
    return current == other.current;
}
