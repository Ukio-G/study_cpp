// struct Expression;
// struct Number;
// struct BinaryOperation;
struct Storage;
#include <iostream>
struct SharedPtr {
  // реализуйте следующие методы
  //
  explicit SharedPtr(int* ptr = 0);
  ~SharedPtr();
  SharedPtr(const SharedPtr&);
  SharedPtr& operator=(const SharedPtr&);
  int* get() const;
  void reset(int* ptr = 0);
  int& operator*() const;
  int* operator->() const;
  void decrementPtr();
  int* ptr_;
  Storage* storage_;
};

struct Storage {
  int count_ = 0;
};

SharedPtr::SharedPtr(int* ptr) : ptr_(ptr), storage_(new Storage()) {
  storage_->count_++;
}

SharedPtr::~SharedPtr() { decrementPtr(); }

void SharedPtr::decrementPtr() {
  storage_->count_--;
  if (storage_->count_ == 0) {
    delete storage_;
    if (ptr_ != 0 || ptr_ != NULL){
     delete ptr_;
  }
}
}

SharedPtr::SharedPtr(const SharedPtr& sp)
    : ptr_(sp.ptr_), storage_(sp.storage_) {
  storage_->count_++;
}

SharedPtr& SharedPtr::operator=(const SharedPtr& sp) {
  decrementPtr();
  ptr_ = sp.ptr_;
  storage_ = sp.storage_;
  storage_->count_++;
  return *this;
}

int* SharedPtr::get() const { return this->ptr_; }

void SharedPtr::reset(int* ptr) {
  decrementPtr();
  ptr_ = 0;
  storage_ = 0;
  storage_ = new Storage();
  storage_->count_++;
  ptr_ = ptr;
}

int& SharedPtr::operator*() const { return *ptr_; }

int* SharedPtr::operator->() const { return ptr_; }

int main(int argc, char const* argv[]) {
  int* i = new int;
  *i = 2;
  SharedPtr sp = SharedPtr(i);
  SharedPtr sp2;
  sp2 = sp;
  SharedPtr sp3(sp2);
  std::cout << *sp << std::endl;
  *sp2 = 5;
  std::cout << *sp3 << std::endl;
  return 0;
}