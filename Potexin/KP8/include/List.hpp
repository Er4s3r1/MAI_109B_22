#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED
#include "Iterator.hpp"

template <typename T>
class List {
private:
    Node<T>* head = nullptr;
    size_t sz = 0;

public:
    List() = default;

    Iterator<T> begin();
    Iterator<T> end();

    void push_back(const T& value);
    void push_front(const T& value);
    void pop_back();
    void pop_front();
    Iterator<T> insert(const Iterator<T>& pos, const T& value);
    Iterator<T> erase(const Iterator<T>& pos);
    Iterator<T> erase(const Iterator<T>& begin_pos, const Iterator<T>& end_pos);
    void clear();
    void shift_cyclically();

    template<typename U>
    friend std::ostream &operator<<(std::ostream &out, List<U> &x);

    void emplace_back();
    template<typename... Args>
    void emplace_back(const T &First, const Args &...args);

    size_t size() const;
    bool empty() const;

    ~List();
    List(List<T> &x);
    List<T>& operator=(const List<T> &x);

};


#include "../src/List.cpp"
#endif
