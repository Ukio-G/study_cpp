#include <utility>
#include <cstddef>
#include <iostream>
#include <tuple>
#include <stdexcept>


template<size_t T1,size_t T2, typename... Ts>
auto to_pair(std::tuple<Ts...>  t) ->decltype(std::make_pair(std::get<T1>(t),std::get<T2>(t)))
{
	return std::make_pair(std::get<T1>(t),std::get<T2>(t));
}


int main(int argc, char const *argv[])
{
auto t = std::make_tuple(0, 3.5, "Hello");
auto p = to_pair<0,2>(t); 	

std::cout << p.first << " " << p.second << std::endl;
	return 0;
}


