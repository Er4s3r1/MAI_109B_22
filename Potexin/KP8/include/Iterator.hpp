#ifndef ITERATOR_HPP_INCLUDED
#define ITERATOR_HPP_INCLUDED

#include "Node.hpp"

template<typename T>
class Iterator {
private:

    Node<T> *node = nullptr;

public:

    Iterator() = default;
    ~Iterator() = default;
    Node<T> *get_node();
    explicit Iterator(Node<T> *_node);

    T &operator*();
    T &operator*() const;

    Iterator operator++();
    Iterator operator--();
    Iterator operator+(int64_t val);
    Iterator operator-(int64_t val);

    bool operator==(Iterator const &x) const;
    bool operator!=(Iterator const &x) const;

    friend class List<T>;
};

#include "../src/Iterator.cpp"

#endif
