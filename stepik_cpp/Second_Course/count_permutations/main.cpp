#include <algorithm>
#include <vector>
#include <array>
#include <iostream>

template<class Iterator>
size_t count_permutations(Iterator p, Iterator q) {
    size_t counter = 0;
    std::vector<typename std::iterator_traits<Iterator>::value_type> a(p,q);
    auto first = a.begin();
    auto last = a.end();
    std::sort(first, last);
    do {
        if (std::adjacent_find(first, last) == last)
            counter++;
    } while (std::next_permutation(first, last));
    return counter;
}

int main(int argc, char const *argv[])
{
    
    std::array<int, 3> a1 = {1,2,3};
    size_t c1 = count_permutations(a1.begin(), a1.end()); // 6
    std::cout << c1 << std::endl;

    std::array<int, 5> a2 = {1,2,3,4,4};
    size_t c2 = count_permutations(a2.begin(), a2.end()); // 36
    std::cout << c2 << std::endl;

    return 0;
}