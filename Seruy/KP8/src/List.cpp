#include "../include/List.hpp"

template <typename T, typename Allocator>
List<T, Allocator>::Node::Node(const T& value) : value(value), next(nullptr) {}

template <typename T, typename Allocator>
List<T, Allocator>::Node::Node(const T& value, Node* next) : value(value), next(next) {}

template <typename T, typename Allocator>
List<T, Allocator>::Iterator::Iterator(Node& node) : current_node_ptr(std::addressof(node)) {}

template <typename T, typename Allocator>
typename List<T, Allocator>::Iterator& List<T, Allocator>::Iterator::operator=(Node* node_ptr) {
    current_node_ptr = node_ptr;
    return *this;
}

template <typename T, typename Allocator>
typename List<T, Allocator>::Iterator& List<T, Allocator>::Iterator::operator++() {
    if (current_node_ptr) {
        current_node_ptr = current_node_ptr->next;
    }
    return *this;
}

template <typename T, typename Allocator>
T& List<T, Allocator>::Iterator::operator*() {
    return current_node_ptr->value;
}

template <typename T, typename Allocator>
const T& List<T, Allocator>::Iterator::operator*() const {
    return current_node_ptr->value;
}

template <typename T, typename Allocator>
bool List<T, Allocator>::Iterator::operator!=(const Iterator& iterator) const {
    return current_node_ptr != iterator.current_node_ptr;
}

template <typename T, typename Allocator>
bool List<T, Allocator>::Iterator::operator==(const Iterator& iterator) const {
    return current_node_ptr == iterator.current_node_ptr;
}

template <typename T, typename Allocator>
std::ostream& List<T, Allocator>::operator<<(std::ostream& stream) {
    for (Iterator it = begin(); it != end(); ++it) {
        stream << *it;
    }

    return stream;
}

template <typename T, typename Allocator>
typename List<T, Allocator>::Iterator List<T, Allocator>::begin() const {
    Iterator iter(*head_ptr);
    return iter;
}

template <typename T, typename Allocator>
typename List<T, Allocator>::Iterator List<T, Allocator>::end() const {
    Iterator iter(*block_element_ptr);
    return iter;
}

template <typename T, typename Allocator>
size_t List<T, Allocator>::get_size() const {
    return size;
}

template <typename T, typename Allocator>
List<T, Allocator>::List(const T& value) {
    Node* ptr = AllocTraits::allocate(alloc, 1);
    AllocTraits::construct(alloc, ptr, value);
    head_ptr = ptr;
    head_ptr->next = block_element_ptr;
    ++size;
}

template <typename T, typename Allocator>
List<T, Allocator>::~List() {
    while (head_ptr) {
        if (head_ptr == block_element_ptr) {
            AllocTraits::deallocate(alloc, head_ptr, 1);
            return;
        }

        Node* new_head = head_ptr->next;
        AllocTraits::destroy(alloc, head_ptr);
        AllocTraits::deallocate(alloc, head_ptr, 1);
        head_ptr = new_head;
    }
}

template <typename T, typename Allocator>
void List<T, Allocator>::push_front(const T& value) {
    Node* swap_ptr = nullptr;
    Node* ptr = AllocTraits::allocate(alloc, 1);
    AllocTraits::construct(alloc, ptr, value);

    if (head_ptr == nullptr) {
        head_ptr = ptr;
        ptr->next = block_element_ptr;
    } else {
        swap_ptr = head_ptr;
        this->head_ptr = ptr;
        this->head_ptr->next = swap_ptr;
    }
    ++size;
}

template <typename T, typename Allocator>
void List<T, Allocator>::pop_front() {
    if (head_ptr == nullptr) {
        return;
    }

    Node* temp_ptr = nullptr;
    temp_ptr = head_ptr;
    head_ptr = head_ptr->next;
    --size;

    if (head_ptr == block_element_ptr) {
        head_ptr = nullptr;
    }

    AllocTraits::destroy(alloc, temp_ptr);
    AllocTraits::deallocate(alloc, temp_ptr, 1);
}

template <typename T, typename Allocator>
void List<T, Allocator>::insert(const T& value, Iterator& it) {
    if (it.current_node_ptr == block_element_ptr) {
        return;
    }

    Node* ptr = it.current_node_ptr->next;
    Node* new_object = AllocTraits::allocate(alloc, 1);
    AllocTraits::construct(alloc, new_object, value);

    it.current_node_ptr->next = new_object;
    new_object->next = ptr;

    ++size;
}

template <typename T, typename Allocator>
void List<T, Allocator>::erase(Iterator& iter) {
    if (size == 0) {
        return;
    }

    Iterator it = this->begin();

    while (it.current_node_ptr->next != iter.current_node_ptr) {
        ++it;
    }

    Node* temp_ptr = iter.current_node_ptr->next;
    AllocTraits::destroy(alloc, temp_ptr);
    AllocTraits::deallocate(alloc, temp_ptr, 1);
    it.current_node_ptr->next = temp_ptr;
    iter.current_node_ptr = temp_ptr;
}

template <typename T, typename Allocator>
void List<T, Allocator>::erase(Iterator& first_iter, Iterator& second_iter) {
    Iterator it = first_iter;
    while (it != second_iter) {
        Iterator temp = it;
        ++it;
        erase(temp);
    }
}
