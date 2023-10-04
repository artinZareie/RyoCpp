#pragma once
#include <vector>
#include <cstring>

namespace Ryo::Utils {

template <typename T>
struct List {
private:
    size_t _size;
    size_t _capacity;
    T* _data;
private:
    void _copy_and_reallocate(size_t new_capacity);
public:
    List();
    List(std::vector<T> &initializer);
    ~List();
};

}

#include "templates/collections.tpp"
