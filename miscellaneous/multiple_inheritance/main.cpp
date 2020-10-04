#include <iostream>

class A {
    public:
        virtual void method() {
            std::cout << "A" << std::endl;
        }
};

class B : public A {
    public:
        void method() override {
            std::cout << "B" << std::endl;
        }
};

class C : public A {
    public:
        void method() override {
            std::cout << "C" << std::endl;
        }
};

class D : public virtual B, public virtual C {

};


int main() {
    
    A a;
    A * b = new B();
    A * c = new C();
    D d;

    a.method();
    b->method();
    c->method();
 //   d.method();       Undefined Implementation
    ((B*)(&d))->method();
    ((C*)(&d))->method();
    return 0;
}
