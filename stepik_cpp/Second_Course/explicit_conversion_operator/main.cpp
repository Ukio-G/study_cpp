struct String
{
 	char * data; 
 	void operator=(char * data)
 	{
 		delete this->data;
 		this->data = new char();
 		this->data = data;
 	}
    // explicit operator char const *() const;	// 	Ошибки
    operator char const *() const;
};


int main(int argc, char const *argv[])
{
	String s;

delete s;    // 1

if (s) { }   // 2

char const * p1 = s;  // 3

char const * p2 = (char const*)s;  // 4

char const * p3 = static_cast<char const*>(s);  // 5

char const * s2 = s + 4;  // 6
	return 0;
}