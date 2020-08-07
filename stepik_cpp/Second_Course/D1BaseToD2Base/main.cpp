#include <iostream>

struct Base { 
	int i;
}; 

struct D1 : Base { 
	int j;
};

struct D2 : Base { 
	double k;
}; 

struct D3 : D1, D2 { 

};


// base указывает на экземпляр Base, соответствующий D1
// нужно вернуть указатель на экземпляр Base, соответствующий D2
Base const * D1BaseToD2Base( Base const * base )
{
	D1 * d1 = (D1*) base;
	D3 * d3 = (D3*) d1;
	D2 * d2 = (D2*) d3;
	Base const * db2 = (Base*) d2;
    return db2;
}

int main(int argc, char const *argv[])
{
	D3 * d3 = new D3(); 

	D1 * d1 = d3;
	D2 * d2 = d3;
	Base * db1 = d1;

	d1->i = 1;
	d2->i = 2;

	Base const * db2 = D1BaseToD2Base(db1);
	
	std::cout << db2->i << std::endl;
	std::cout << db1->i << std::endl;
	std::cout << "Base D1 = " << d1->i << std::endl;
	std::cout << "Base D2 = " << d2->i << std::endl;
	return 0;
}
