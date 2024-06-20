// written by Ido Avraham : 208699181
// EMAIL: idoavraham086@gmail.com
#include "../../include/iterators/PostOrderIterator.h"

template<typename T, size_t k>
PostOrderIterator<T, k>::PostOrderIterator(Node<T> *root) : current(nullptr) {
    if (root) {
        stack1.push(root);  // Push the root node onto stack1

        // Process all nodes and push them to stack2 in post-order
        while (!stack1.empty()) {
            Node<T>* node = stack1.top();  // Get the node on top of stack1
            stack1.pop();  // Remove the node from stack1
            stack2.push(node);  // Push the node onto stack2

            // Push all children of the node onto stack1
            for (auto child : node->children) {
                if (child) {
                    stack1.push(child);
                }
            }
        }
    }
    ++(*this);  // Move to the first element in stack2
}

template<typename T, size_t k>
PostOrderIterator<T, k>& PostOrderIterator<T, k>::operator++() {
    if (stack2.empty()) {
        current = nullptr;  // If empty, set current to nullptr (end of traversal)
        return *this;
    }
    current = stack2.top();  // Set current to the top node of stack2
    stack2.pop();
    return *this;
}

template<typename T, size_t k>
Node<T> *PostOrderIterator<T, k>::operator*() {
    return current;
}

template<typename T, size_t k>
Node<T> *PostOrderIterator<T, k>::operator->() {
    return current;
}

template<typename T, size_t k>
bool PostOrderIterator<T, k>::operator!=(const PostOrderIterator<T, k> &other) const {
    return current != other.current;
}

template<typename T, size_t k>
bool PostOrderIterator<T, k>::operator==(const PostOrderIterator<T, k> &other) const {
    return current == other.current;
}
