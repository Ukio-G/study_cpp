#include <iostream>

struct Foo {
    void say() const { std::cout << "Foo says: " << msg << "\n"; }
protected:
    Foo(const char *msg) : msg(msg) { }
private:
    const char *msg;
};

struct FooPublic : public Foo {
	FooPublic(const char *msg_public) : Foo(msg_public) {}
};

Foo get_foo(const char *msg) {
	FooPublic foo(msg);
	return foo;
}

void foo_says(const Foo& foo) { foo.say(); }

int main(int argc, char const *argv[])
{
	foo_says(get_foo("Hello!"));
	return 0;
}