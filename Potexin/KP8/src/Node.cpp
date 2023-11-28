#include "../include/Node.hpp"

template <typename T>
Node<T>::Node(const T& _data): data(_data) {}

template <typename T>
Node<T>::Node(const T& _data, Node* _prev, Node* _next): data(_data), prev(_prev), next(_next) {}
