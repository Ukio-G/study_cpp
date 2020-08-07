#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <list>


template<class It>
size_t max_increasing_len(It p, It q)
{
	size_t result = (p != q);
	size_t tmp = 1;
	for(; p != q; p++) {
		if (q == std::next(p,1)) continue;
		tmp = (*p < *(std::next(p,1))) ? tmp + 1 : 1;
		result = (tmp > result) ? tmp : result;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	std::list<int> const l1 = {7,8,9,4,5,6,1,2,3,4};
	size_t len1 = max_increasing_len(l1.begin(), l1.end()); // 4, соответствует подотрезку 1,2,3,4

	std::vector<int> const l2 = {-3,-2,-1,0,0,1,2,3,4,5};
	size_t len2 = max_increasing_len(l2.begin(), l2.end()); // 6, соответствует подотрезку 0,1,2,3,4,5

	std::vector<int> const l3 = {-3,-2,-1,0};
	size_t len3 = max_increasing_len(l3.begin(), l3.end()); // 6, соответствует подотрезку 0,1,2,3,4,5

	std::deque<int> const l4 = {0};
	size_t len4 = max_increasing_len(l4.begin(), l4.end()); // 6, соответствует подотрезку 0,1,2,3,4,5

	std::vector<int> const l5;
	size_t len5 = max_increasing_len(l5.begin(), l5.end()); // 6, соответствует подотрезку 0,1,2,3,4,5

	std::vector<int> const l6 = {1, 2, 4 , 0,2,4,5,6};
	size_t len6 = max_increasing_len(l6.begin(), l6.end()); // 6, соответствует подотрезку 0,1,2,3,4,5

	std::vector<int> const l7 = {1, 1, 1};
	size_t len7 = max_increasing_len(l7.begin(), l7.end()); // 6, соответствует подотрезку 0,1,2,3,4,5

	std::cout << len1 << std::endl;
	std::cout << len2 << std::endl;
	std::cout << len3 << std::endl;
	std::cout << len4 << std::endl;
	std::cout << len5 << std::endl;
	std::cout << len6 << std::endl;
	std::cout << len7 << std::endl;

	return 0;
}
