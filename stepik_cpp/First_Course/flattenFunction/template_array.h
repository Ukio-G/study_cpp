#ifndef TEMPLATE_ARRAY_H
#define TEMPLATE_ARRAY_H

#include <cstddef>
#include <algorithm>
template <typename T>
class Array {
 public:

  explicit Array(size_t size, const T& value = T()) : size_(size) {
    data_ = (T*)::operator new[](size * sizeof(T));
    for (int i = 0; i < size; ++i) new (data_ + i) T(value);
  }

  // explicit Array(size_t size) : size_(size), data_(new T[size]) {}
  Array() : size_(0), data_(0) {}

  Array(const Array& other) : size_(other.size()) {
    data_ = (T*)::operator new[](size_ * sizeof(T));
    for (int i = 0; i < size_; ++i) new (data_ + i) T(other[i]);
  }

  ~Array() {
    for (int i = 0; i < size_; i++) {
      data_[i].~T();
    }
    operator delete[](data_);
  };

  Array& operator=(Array const& other) {
    if (this != &other) Array<T>(other).swap(*this);
    return *this;
  };

  T& operator[](size_t i) { return data_[i]; }

  const T& operator[](size_t i) const { return data_[i]; }
  void swap(Array& array) {
    std::swap(size_, array.size_);
    std::swap(data_, array.data_);
  };
  size_t size() const { return size_; }

  void resize(size_t new_size) {
    Array<T> t(new_size);
    size_t copyElementsCount = new_size > size_ ? size_ : new_size;
    for (int i = 0; i < copyElementsCount; ++i) t.data_[i] = data_[i];
    swap(t);
  }

 private:
  size_t size_;
  T* data_;
};

#endif  // TEMPLATE_ARRAY_H