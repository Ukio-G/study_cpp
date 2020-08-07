#include "IntArray.h"
#include <algorithm>
IntArray::IntArray(size_t size) : size_(size), data_(new int[size]) {
  for (int i = 0; i < size; ++i) {
    data_[i] = 0;
  }
}

IntArray::IntArray(IntArray const& other)
    : size_(other.size_), data_(new int[other.size_]) {
  for (int i = 0; i < size_; ++i) {
    data_[i] = other.data_[i];
  }
}

IntArray::~IntArray() { delete[] data_; }

IntArray& IntArray::operator=(IntArray const& other) {
  if (this != &other) IntArray(other).swap(*this);
  return *this;
}

void IntArray::swap(IntArray& a) {
  std::swap(size_, a.size_);
  std::swap(data_, a.data_);
}

size_t IntArray::size() const { return size_; }

int& IntArray::get(size_t i) { return data_[i]; }

int IntArray::get(size_t i) const { return data_[i]; }

void IntArray::resize(size_t new_size){
	IntArray t(new_size);
	size_t copyElementsCount = new_size > size_ ? size_ : new_size;
	for (int i = 0; i < copyElementsCount; ++i)
		t.data_[i] = data_[i];
	swap(t);
}