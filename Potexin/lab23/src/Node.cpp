#include "../include/Node.hpp"

template <typename T>
Node<T>::Node(T value) : data(value), left(nullptr), right(nullptr) {}
