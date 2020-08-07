#include <iostream>

#include <algorithm>
#include <vector>

// алгоритм должен работать с forward итераторами
// и возвращать итератор, который потом будет передан
// в метод erase соответствующего контейнера
template<class FwdIt>
FwdIt remove_nth(FwdIt p, FwdIt q, size_t n)
{
    while (n-- != 0)
        if (++p == q)
            return q;
    return std::rotate(p++, p, q);
}

int main() {
    std::vector<int> v = {0,1,2,3,4,5,6,7,8,9,10};
    v.erase(remove_nth(v.begin(), v.end(), 5), v.end());

    for (auto &item : v)
        std::cout << item << std::endl;

    return 0;
}
