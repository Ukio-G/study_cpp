#include <iostream>

struct Basic
{
	virtual void virtual_method(){std::cout << "Basic virtual method" << std::endl;}
	virtual void virtual_method_const() const {std::cout << "Basic virtual const method" << std::endl;}
	virtual void virtual_method_call_non_virtual_method(){non_virtual_method();}
	void non_virtual_method(){std::cout << "non_virtual_method" << std::endl;}
	void non_virtual_method_call_virtual(){virtual_method();}
};


int main(int argc, char const *argv[])
{

	// Виртуальные методы могут вызывать невиртуальные методы.
	// Могут
	Basic b;
	b.virtual_method_call_non_virtual_method();


	// Виртуальный метод можно вызвать только через указатель на объект.
	// Как видно - нет
	b.virtual_method();


	// Виртуальные методы могут быть константными.
	// Могут
	b.virtual_method_const();


	// Обращение к объекту по ссылке не позволяет вызывать виртуальные методы.
	// Ложь
	Basic & b_link = b;
	b_link.virtual_method();


	//  Для того, чтобы вызвать виртуальный метод, объект должен быть создан через new.
	//  Nope
	b.virtual_method();


	//  Невиртуальные методы не могут вызывать виртуальные методы.
	//  Ложь
	b.non_virtual_method_call_virtual();
	return 0;
}