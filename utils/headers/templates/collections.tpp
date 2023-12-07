namespace Ryo::Utils {

template<typename T>
List<T>::List(): _size(0), _capacity(0), _data(nullptr) {}

template<typename T>
List<T>::List(std::vector<T> &initializer): _size(initializer.size()), _capacity(initializer.capacity()), _data(nullptr) {
    _data = new T[_capacity];
    std::memcpy(_data, &initializer, _size * sizeof(T));
}

template<typename T>
void List<T>::_copy_and_reallocate(size_t new_capacity) {
    #ifndef RYO_DISABLE_SECUTRITY

    if (new_capacity < _capacity)
    {
        throw std::exception("List cannot have less capacity than its current capacity.");
    }

    #endif

    T* _new_loc = new T[new_capacity];
    std::memcpy(_new_loc, _data, new_capacity * sizeof(T));
}

template<typename T>
List<T>::~List() {
    delete[] _data;
}

};
