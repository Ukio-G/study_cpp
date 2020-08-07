// #include <iostream>

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
  delete left;
  delete right;
}

Number::~Number(){

}

int main(int argc, char const *argv[])
{
    // сначала создаём объекты для подвыражения 4.5 * 5
Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
// потом используем его в выражении для +
Expression * expr = new BinaryOperation(new Number(3), '+', sube);

// вычисляем и выводим результат: 25.5
// std::cout << expr->evaluate() << std::endl;

// std::cout << expr << std::endl;

// тут освобождаются *все* выделенные объекты
// (например, sube будет правым операндом expr, поэтому его удалять не нужно)
    delete expr;
    return 0;
}