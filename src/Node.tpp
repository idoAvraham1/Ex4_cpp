#include "../include/Node.h"

template<typename T>
Node<T>::Node(T val, size_t k) : value(val), k(k), children(k, nullptr) {}

template<typename T>
T Node<T>::get_value() {
    return value;
}
