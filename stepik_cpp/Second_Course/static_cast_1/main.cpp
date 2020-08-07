struct Number {};

struct BigInt : Number
{
	BigInt(int x);
};

struct String
{
    explicit String(char const * s);
};

int main(int argc, char const *argv[])
{
	int a = 3.5;

	double b = 7;

	BigInt c = 100500;

	String d = static_cast<String>("Stepic");

	// BigInt -> Number - upcast
	// Number -> BigInt  - downcast

	Number * e = &c;

	BigInt * f = static_cast<BigInt*>(e);

	void * g = f;

	BigInt * h = static_cast<BigInt*>(g);
	return 0;
}