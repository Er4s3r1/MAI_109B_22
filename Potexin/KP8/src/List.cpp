#include <memory>
#include "../include/List.hpp"

template<typename T>
void List<T>::push_back(const T &value) {
    if (head == nullptr) {
        head = new Node(value);
        head->next = head;
        head->prev = head;
        ++sz;
        return;
    }
    Node<T>* curr_last_node = head->prev;

    Node<T>* new_node = new Node(value, curr_last_node, head);
    curr_last_node->next = new_node;
    head->prev = new_node;
    ++sz;
}

template <typename T>
void List<T>::push_front(const T& value) {
    push_back(value);
    head = head->prev;
}

template <typename T>
void List<T>::pop_back() {
    if (sz >= 2) {
        Node<T>* curr_last = head->prev;
        Node<T>* new_last = curr_last->prev;

        new_last->next = head;
        head->prev = new_last;
        delete curr_last;
        --sz;
    } else if (sz == 1) {
        delete head;
        head = nullptr;
        --sz;
    }
}

template <typename T>
void List<T>::pop_front() {
    if (head == nullptr) {
        return;
    }
    head = head->next;
    pop_back();
}

template <typename T>
Iterator<T> List<T>::insert(const Iterator<T>& pos, const T& value) {
    if (pos != end()) {
        Node<T>* curr_node = pos.node;
        Node<T>* prev_node = curr_node->prev;

        Node<T>* new_node = new Node<T>(value, prev_node, curr_node);
        prev_node->next = new_node;
        curr_node->prev = new_node;

        if (head == pos.node) {
            head = new_node;
        }
        ++sz;
        return Iterator<T>(new_node);
    } else {
        std::cout << "You can't insert at this pos!" << std::endl;
        return end();
    }
}

template <typename T>
Iterator<T> List<T>::erase(const Iterator<T>& pos) {
    if (pos == end()) {
        std::cout << "You can't erase at this pos!" << std::endl;
        return end();
    }

    if (sz == 1) {
        delete head;
        head = nullptr;
        --sz;
        return end();
    }

    Node<T>* curr_node = pos.node;
    Node<T>* prev_node = curr_node->prev;
    Node<T>* next_node = curr_node->next;

    prev_node->next = next_node;
    next_node->prev = prev_node;
    if (head == curr_node) {
        head = next_node;
    }

    delete curr_node;
    curr_node = nullptr;
    --sz;
    return Iterator<T>(next_node);
}

template <typename T>
Iterator<T> List<T>::erase(const Iterator<T>& begin_pos, const Iterator<T>& end_pos) {
    Iterator<T> curr_node = begin_pos;
    while (curr_node != end_pos) {
        curr_node = erase(curr_node);
    }
    return curr_node;
}

template<typename T>
void List<T>::clear() {
    while (!empty()) {
        pop_back();
    }
}

template<typename T>
void List<T>::shift_cyclically() {
    head = head->prev;
}

template<typename T>
Iterator<T> List<T>::begin() {
    Iterator<T> temp(head);
    return temp;
}

template<typename T>
Iterator<T> List<T>::end() {
    Iterator<T> temp(nullptr);
    return temp;
}

template<typename T>
void List<T>::emplace_back(){}

template<typename T>
template<typename... Args>
void List<T>::emplace_back(const T &First, const Args &...args)
{
    push_back(First);
    emplace_back(args...);
}

template<typename U>
std::ostream &operator<<(std::ostream &out, List<U> &x) {
    if (x.head == nullptr)
        return out;

    Iterator<U> it;
    size_t i;
    for (it = x.begin(), i = 0; i < x.size(); ++it, ++i) {
        out << *it << "\t";
    }
    out << std::endl;

    return out;
}

template<typename T>
List<T>::~List() {
    if (head == nullptr)
        return;
    Node<T>* curr_node = head->next;
    while (curr_node != head) {
        Node<T>* tmp = curr_node;
        curr_node = curr_node->next;
        delete tmp;
    }
    delete head;
}

template<typename T>
List<T>::List(List<T> &x) {
    auto it = x.begin();
    for (int64_t i = 0; i < x.size() and it != x.end(); ++i, ++it) {
        push_back(it.node->data);
    }
}

template<typename T>
List<T>& List<T>::operator=(const List<T> &x) {
    if (this == x) {
        return *this;
    }
    auto it = x.begin();
    for (int64_t i = 0; i < x.size() and it != x.end(); ++i, ++it) {
        push_back(it.node->data);
    }
    return *this;
}

template<typename T>
size_t List<T>::size() const {
    return sz;
}

template<typename T>
bool List<T>::empty() const {
    return sz == 0;
}
