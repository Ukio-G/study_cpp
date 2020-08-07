#include <iostream>
struct Number;
struct BinaryOperation;

struct Visitor {
  virtual void visitNumber(Number const *number) = 0;
  virtual void visitBinaryOperation(BinaryOperation const *operation) = 0;
  virtual ~Visitor() {}
};

struct Expression {
  virtual double evaluate() const = 0;
  virtual void visit(Visitor *visitor) const = 0;
  virtual ~Expression();
};

Expression::~Expression() {}

struct Number : Expression {
  Number(double value) : value(value) {}
  double evaluate() const { return value; }
  double get_value() const { return value; }
  ~Number();

  void visit(Visitor *visitor) const { visitor->visitNumber(this); }

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
  Expression const *get_left() const { return left; }
  Expression const *get_right() const { return right; }
  char get_op() const { return op; }
  double evaluate() const {
    if (op == '*') return left->evaluate() * right->evaluate();
    if (op == '/') return left->evaluate() / right->evaluate();
    if (op == '+') return left->evaluate() + right->evaluate();
    if (op == '-') return left->evaluate() - right->evaluate();
  }

  ~BinaryOperation();
  void visit(Visitor *visitor) const { visitor->visitBinaryOperation(this); }

 private:
  Expression const *left;
  Expression const *right;
  char op;
};

BinaryOperation::~BinaryOperation() {
  delete left;
  delete right;
}

Number::~Number() {}

struct PrintVisitor : Visitor {
  void visitNumber(Number const *number) {
    std::cout << number->get_value();
  }

  void visitBinaryOperation(BinaryOperation const *bop) {
    std::cout << bop->get_op() << "(";
    bop->get_left()->visit(this);
    std::cout << bop->get_op() << " ";
    bop->get_right()->visit(this);
    std::cout << bop->get_op() << ")";
  }
};

int main(int argc, char const *argv[]) {
  // сначала создаём объекты для подвыражения 4.5 * 5
Expression * sube = new BinaryOperation(new Number(4.5), '+', new Number(5));
Expression const * expr = new BinaryOperation(new Number(3), '*', sube);
  PrintVisitor pv;

  

  delete expr;
  return 0;
}
