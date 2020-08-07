#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

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

void PrintMemory(const unsigned char memory[], unsigned int byteCount, const char label[] = "contents") {
  std::cout << "Memory " << label << ": " << std::endl;
  for (size_t i = 0; i < byteCount;) {
    std::cout << setw(2) << setfill('0') << std::uppercase << std::hex << static_cast<int>(memory[i]) << " ";
    if (++i % 8 == 0) std::cout << std::endl;
  }
  std::cout << std::endl;
}

struct BinaryOperation : Expression {
  /*
    Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих
    операциям, которые вам нужно реализовать.
   */
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
  // delete left;
  // delete right;
}

Number::~Number(){


}

bool check_equals(Expression const *left, Expression const *right)
{
    for (int i = 0; i < 8; ++i)
      if (reinterpret_cast<char const *>(left)[i] != reinterpret_cast<char const *>(right)[i]) return false;
    return true;
}


int main(int argc, char const *argv[])
{
  Number * n = new Number(1);
  Number * n2 = new Number(1);


std::cout <<check_equals(n,n2)  << std::endl;

  // BinaryOperation * bo1 = new BinaryOperation(n,'+',n2);
  // std::cout << n << " " << n2 << " " << &(bo1) << std::endl;
  // unsigned char vptr1[8];
  // for (int i = 0; i < 8; ++i)
  //   vptr1[i] = reinterpret_cast<char *>(n)[i];
  
  // unsigned char vptr2[8];
  // for (int i = 0; i < 8; ++i)
  //   vptr2[i] = reinterpret_cast<char *>(n2)[i];
  

  
  // PrintMemory(vptr1,8, "before placement new");
  // PrintMemory(vptr2,8, "before placement new");

  // unsigned char memory[32];
  // memset(memory, 0x11, 32 * sizeof(unsigned char));
  // PrintMemory(memory,32, "before placement new");
  // new (memory) Number(1);
  // PrintMemory(memory,32, "after placement new");


  // unsigned char memory2[32];
  // memset(memory2, 0x11, 32 * sizeof(unsigned char));
  // PrintMemory(memory2,32, "before placement new");
  // Number const * nnn = new (memory2) Number(2);
  // PrintMemory(memory2,32, "after placement new");
  // char const * char_n= reinterpret_cast<char const * >(nnn);
  // std::cout <<  << std::endl;

  // unsigned char memory3[32];
  // memset(memory3, 0x11, 32 * sizeof(unsigned char));
  // PrintMemory(memory3,32, "before placement new");
  // new (memory3) BinaryOperation(new Number(2),'+',new Number(3));
  // PrintMemory(memory3,32, "after placement new");
  

  // reinterpret_cast<Number *>(memory)->~Number();
  return 0;
}