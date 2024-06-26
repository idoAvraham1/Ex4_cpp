// written by Ido Avraham : 208699181
// EMAIL: idoavraham086@gmail.com
#include "../../include/iterators/BFSIterator.h"

// Constructor initializes the iterator with the root node
template<typename T, size_t k>
BFSIterator<T, k>::BFSIterator(Node<T> *root) : current(nullptr) {
    if (root) {
        queue.push(root);  // Push the root node onto the queue
    }
    ++(*this);  // Move to the first element
}

// Pre-increment operator to advance the iterator
template<typename T, size_t k>
BFSIterator<T, k>& BFSIterator<T, k>::operator++() {
    // If the queue is empty, the traversal is complete
    if (queue.empty()) {
        current = nullptr;  // Set current to nullptr indicating the end
        return *this;
    }

    // Dequeue the front node and set it as the current node
    current = queue.front();
    queue.pop();

    // Enqueue all the children of the current node
    for (auto child: current->get_children()) {
        if (child) {
            queue.push(child);
        }
    }

    // Return the iterator itself
    return *this;
}

// Dereference operator to access the current node
template<typename T, size_t k>
Node<T> *BFSIterator<T, k>::operator*() {
    return current;
}

// Arrow operator to access members of the current node
template<typename T, size_t k>
Node<T> *BFSIterator<T, k>::operator->() {
    return current;
}

// Inequality operator to compare iterators
template<typename T, size_t k>
bool BFSIterator<T, k>::operator!=(const BFSIterator<T, k> &other) const {
    return current != other.current;
}

// Equality operator to compare iterators
template<typename T, size_t k>
bool BFSIterator<T, k>::operator==(const BFSIterator<T, k> &other) const {
    return current == other.current;
}
