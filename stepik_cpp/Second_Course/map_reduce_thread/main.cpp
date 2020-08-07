#include <iostream>
#include <thread>
#include <list>
#include <algorithm>
#include <vector>
#include <atomic>
#include <mutex>
#include <numeric>
#include <unordered_map>
#include <map>


// реализация функции mapreduce

std::mutex m;

template<class It, class BinaryFunctor, class UnaryFunctor>
auto map_reduce(It p, It q, UnaryFunctor f1, BinaryFunctor f2,  size_t threads) noexcept ->decltype(f2(f1(*p),f1(*p)))  {
    using return_type = decltype(f2(f1(*p),f1(*p)));
    auto size = std::distance(p, q);
    size_t elements_per_thread = size / threads;

    std::vector<std::thread> thread_list;
    std::vector<return_type> threads_result;
    std::vector<std::pair<It, It>> iterators;

    threads_result.reserve(size);
    for (int i = 0; i < threads; i++) {
        It start_it = p;
        if (i + 1 == threads)
            p = q;
        else
            for (int j = 0; j < elements_per_thread; j++)
                 p++;
        iterators.emplace_back(start_it, p);
    }

    thread_list.reserve(iterators.size());
    for (auto &item : iterators){
        thread_list.emplace_back([&f1, &f2, item, &threads_result]() {
            auto start = item.first;
            auto end = item.second;
            return_type res = f1(*start);
            while(++start != end)
                res = f2(res, f1(*start));
            std::lock_guard<std::mutex> lg(m);
            threads_result.push_back(std::move(res));
        });
    }

    for (auto & thread : thread_list)
        thread.join();

    return_type result = f1(*threads_result.begin());
    std::for_each(++threads_result.begin(), threads_result.end(),[&result, &f2, &f1](return_type & rt){
        result = f2(result, rt);
    });
    return result;
}

int bench() {
    auto now = std::chrono::system_clock::now;
    auto n = 1;
    auto data_n = 10000;
    std::vector<int> data;
    for (size_t i = 0; i < data_n; ++i) {
        data.push_back(i);
    }
    {
        std::vector<int> l(data.begin(), data.end());
        auto begin = now();
        auto last_res = 0;
        for (size_t i = 0; i < n; ++i) {
            last_res = map_reduce(l.begin(), l.end(), [](int i) { return i; }, std::plus<int>(), 2);
        }
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now() - begin).count();
        std::cout << "t: " << elapsed << " res list: " << last_res << std::endl;
    }
    {
        std::vector<int> l(data.begin(), data.end());
        auto begin = now();
        auto last_res = 0;
        for (size_t i = 0; i < n; ++i) {
            last_res = map_reduce(l.begin(), l.end(), [](int i) { return i; }, std::plus<int>(), 2);
        }
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now() - begin).count();
        std::cout << "t: " << elapsed << " res list: " << last_res << std::endl;
    }
    return 0;
}

int main() {

    bench();
    return 0;
}
