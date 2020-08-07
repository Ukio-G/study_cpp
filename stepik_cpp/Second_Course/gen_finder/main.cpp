#include <iostream>
#include <functional>

template<class F>
int * find_if(int * p, int * q, F f)
{
    for ( ; p != q; ++p )
        if (f(*p))
            return p;
    return q;
}

int main(int argc, char const *argv[])
{
	auto gen_finder = [](int * start, int * end){
		return [start,end](int arg) -> bool {
			int * resultPtr =  find_if(start,end,[arg](int arg2)->bool{
				if (arg == arg2)
				{
					return true;
				}
				return false;
			});

			bool result = (*resultPtr < 1000) && (resultPtr != end);
			return result;
		};
	};

	int primes[5] = {2,3,5,7,11};

	int m[10] = {0,0,1,1,4,6,7,8,9,10};

	int * first_prime = find_if(m, m + 10, gen_finder(primes, primes + 5));

	std::cout << "first_prime: "<< *first_prime << std::endl;
	return 0;
}