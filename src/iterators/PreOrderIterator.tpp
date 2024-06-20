// written by Ido Avraham : 208699181
// EMAIL: idoavraham086@gmail.com
#include "../../include/iterators/PreOrderIterator.h"

template<typename T, size_t k>
PreOrderIterator<T, k>::PreOrderIterator(Node<T>* root) : current(nullptr) {
    if (root) {
        stack.push(root);  // Push the root node onto the stack
    }
    ++(*this);  // Move to the first element
}

template<typename T, size_t k>
PreOrderIterator<T, k>& PreOrderIterator<T, k>::operator++() {
    if (stack.empty()) {  // Check if the stack is empty
        current = nullptr;  // If empty, set current to nullptr (end of traversal)
        return *this;
    }
    current = stack.top();  // Set current to the node on top of the stack
    stack.pop();

    // Push children of the current node to the stack in reverse order
    for (int i = current->children.size() - 1; i >= 0; --i) {
        // Push each non-null child onto the stack
        if (current->children[i]) {
            stack.push(current->children[i]);
        }
    }
    return *this;  // Return the iterator
}

template<typename T, size_t k>
Node<T>* PreOrderIterator<T, k>::operator*() {
    return current;  // Return the current node
}

template<typename T, size_t k>
Node<T>* PreOrderIterator<T, k>::operator->() {
    return current;  // Return the current node
}

template<typename T, size_t k>
bool PreOrderIterator<T, k>::operator!=(const PreOrderIterator<T, k>& other) const {
    return current != other.current;  // Compare the current nodes of the iterators
}

template<typename T, size_t k>
bool PreOrderIterator<T, k>::operator==(const PreOrderIterator<T, k>& other) const {
    return current == other.current;
}
#include "../../include/iterators/PreOrderIterator.h"
