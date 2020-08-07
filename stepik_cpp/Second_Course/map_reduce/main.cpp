#include <iostream>
#include <future>
#include <list>
#include <algorithm>


// реализация функции mapreduce

template<class It,class BinaryFunctor, class UnaryFunctor>
auto map_reduce(It p, It q, UnaryFunctor f1, BinaryFunctor f2,  size_t threads) ->decltype(f2(f1(*p),f1(*p))) {
    using return_type = decltype(f2(f1(*p),f1(*p)));
    auto size = std::distance(p,q);
    size_t elements_per_thread = size / threads;

    std::list<std::future<return_type>> thread_list;

    for (int i = 0; i < threads; i++) {
        It start_it = p;
        if (i+1 == threads){
            p = q;
        }else {
            for (int j = 0; j < elements_per_thread; j++) {
                if (p != q) p++;
                else break;
            }
        }
        std::future<return_type> f = std::async(std::launch::async, [f1, f2](It start, It end) -> return_type{
            decltype(f1(*start)) res = f1(*start);
            while(++start != end)
                res = f2(res, f1(*start));
            return res;
        }, start_it, p );
        thread_list.push_back(std::move(f));
    }

    return_type result = thread_list.front().get();
    std::for_each(++thread_list.begin(), thread_list.end(),[&](decltype(thread_list.front()) & thread){result = f2(result, thread.get());});

    return result;
}

int main() {
    std::list<int> l = {1,2,3,4,5  ,6,7,8,9, 10};

    auto const sum = map_reduce(l.cbegin(), l.cend(), [](int i){return i;}, std::plus<int>(), 3);

    std::cout << sum << std::endl;

    auto has_even = map_reduce(l.begin(), l.end(), [](int i){return i % 2 == 0;}, std::logical_or<bool>(), 4);

    std::cout << has_even << std::endl;
    return 0;
}
