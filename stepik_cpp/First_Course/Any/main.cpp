#include <iostream>

struct ICloneable {
  virtual ICloneable *clone() const = 0;
  virtual ~ICloneable() {}
};

//
// Шаблон ValueHolder должен реализовывать
// интерфейс ICloneable, и возвращать указатель
// на копию объекта, созданную в куче, из метода
// clone.

template <typename T>
struct ValueHolder : public ICloneable {
 public:
  ValueHolder(const T &other) : data_(other) {}
  T data_;
  ValueHolder *clone() const { return new ValueHolder<T>(data_); }
};

// Это класс, который вам нужно реализовать
class Any {
 public:
  Any() {}

  template <typename T>
  Any(const T &value) {
    this->value = dynamic_cast<ValueHolder<T> *>(new ValueHolder<T>(value));
  }

  ICloneable *value = 0;

  Any(const Any &other) {
    if (other.value != 0) {
      delete value;
      value = other.value->clone();
    }
  }

  Any &operator=(const Any &other) {
    if (this != &other) {
      if (value != 0) delete value;
      if(other.value != 0) value = other.value->clone(); else value = 0;
    }

    return *this;
  }

  template <typename T>
  T *cast() {
    ValueHolder<T> *valuePtr = dynamic_cast<ValueHolder<T> *>(value);
    if (valuePtr == 0 || valuePtr == nullptr || value == 0) {
      return 0;
    }
    return &(valuePtr->data_);
  }

  ~Any() {
    if (value != 0) {
      delete value;
    }
  }
};

int main(int argc, char const *argv[]) {
  Any a(2);
  a.cast<char>();
  std::cout << "a " << a.cast<int>() << std::endl;

  Any b('c');
  std::cout << "b " << b.cast<char>() << std::endl;

  Any c(a);
  std::cout << "c " << c.cast<int>() << std::endl;

  Any d(1);
  d = c;
  std::cout << "d " << *d.cast<int>() << std::endl;

  Any empty;
  Any emplyAgain = empty;
  Any emptyEqual;
  emptyEqual = empty;
  d = empty;
  // d = c;
std::cout << "d " << *d.cast<int>() << std::endl;
  return 0;
}