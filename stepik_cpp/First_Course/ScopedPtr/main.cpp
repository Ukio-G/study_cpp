struct Expression;
struct Number;
struct BinaryOperation;

#include <iostream>

struct Expression {
  virtual double evaluate() const = 0;
  virtual ~Expression();
};

Expression::~Expression(){}

struct Number : Expression {
  Number(double value) : value(value) {}
  double evaluate() const { return value; }
  ~Number();

 private:
  double value;
};

struct BinaryOperation : Expression {
  BinaryOperation(Expression const *left, char op, Expression const *right)
      : left(left), op(op), right(right) {}
  double evaluate() const {
    if (op == '*') return left->evaluate() * right->evaluate();
    if (op == '/') return left->evaluate() / right->evaluate();
    if (op == '+') return left->evaluate() + right->evaluate();
    if (op == '-') return left->evaluate() - right->evaluate();
  }

  ~BinaryOperation();

 private:
  Expression const *left;
  Expression const *right;
  char op;
};

BinaryOperation::~BinaryOperation() {
  delete left;
  delete right;
}

Number::~Number(){}


struct ScopedPtr
{
    // реализуйте следующие методы:
    //
    explicit ScopedPtr(Expression *ptr = 0);
    ~ScopedPtr();
    Expression* get() const;
    Expression* release();
    void reset(Expression *ptr = 0);
    Expression& operator*() const;
    Expression* operator->() const;


private:
    // запрещаем копирование ScopedPtr
    ScopedPtr(const ScopedPtr&) {}
    ScopedPtr& operator=(const ScopedPtr&) {}

    Expression *ptr_;
};

Expression* ScopedPtr::operator->() const{
return ptr_;
}

Expression& ScopedPtr::operator*() const{
return *ptr_;
}

void ScopedPtr::reset(Expression *ptr)
{
    delete this->ptr_;
    this->ptr_=ptr;
}

Expression * ScopedPtr::release()
{
  Expression *ptr = this->ptr_;  
  this->ptr_ = 0;
  return ptr;
}

Expression * ScopedPtr::get() const
{
    return ptr_;
}

ScopedPtr::ScopedPtr(Expression *ptr) : ptr_(ptr){}

ScopedPtr::~ScopedPtr()
{
    if (ptr_!= 0 || ptr_!= NULL) delete ptr_;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}