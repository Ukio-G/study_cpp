int main(int argc, char const *argv[])
{
	
	int a = 20;

	int const b = 412;



	int * ptrA = &a;
	int & c = a;

	int const d = a;

	int const * p1 = ptrA;

	int * const * p2;

	return 0;
}