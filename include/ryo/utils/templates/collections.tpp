template<typename T>
Ryo::Utils::List<T>::List(): _size(0), _capacity(0), _data(nullptr) {}

template<typename T>
Ryo::Utils::List<T>::List(std::array<T> &initializer): _size(0), _capacity(0), _data(nullptr) {}
