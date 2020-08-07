#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <cstddef>
// #include <cstdint>
#include <cstring>
#include <algorithm>
template <class T>
class Array {
public:

  explicit Array(size_t size = 0, const T& value = T()) : size_(size), data_(new T[size]){
  	for (int i = 0; i < size; ++i) data_[i] = value;
  }

  // explicit Array(size_t size) : size_(size), data_(new T[size]) {}

  Array(const Array & other)
      : size_(other.size()), data_(new T[other.size()]) {
    for (int i = 0; i < size_; ++i) data_[i] = other.data_[i];
  }
  ~Array() { delete[] data_; };
  Array& operator=(Array const& other){
	if (this != &other) Array<T>(other).swap(*this);
  return *this;
  };

  T & operator[](size_t i)
  {
  	return data_[i];
  }

  const T& operator[](size_t i) const
  {
  	return data_[i];
  }
  void swap(Array& array){
  std::swap(size_, array.size_);
  std::swap(data_, array.data_);
  };
  size_t size() const {return size_;}
 
  void resize(size_t new_size){
  	Array<T> t(new_size);
	size_t copyElementsCount = new_size > size_ ? size_ : new_size;
	for (int i = 0; i < copyElementsCount; ++i)
		t.data_[i] = data_[i];
	swap(t);
  }

 private:
  size_t size_;
  T* data_;
};

#endif  // TEMPLATE_H