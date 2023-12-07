#pragma once
#include <vector>
#include <array>

namespace Ryo::Utils {

template <typename T>
struct List {
private:
    size_t _size;
    size_t _capacity;
    T* _data;
private:
    void copy_and_reallocate(size_t new_size);
public:
    List();
    List(std::array<T> &initializer);

};

}

#include "templates/collections.tpp"
