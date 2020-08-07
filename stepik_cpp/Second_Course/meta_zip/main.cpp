#include <iostream>
#include <map>


template<int ... T>
struct IntList;

template<int H, int... T>
struct IntList<H, T...>
{
    static int const Head = H;
    using Tail = IntList<T...>;
};


template<>
struct IntList<>
{

};

template<int I, typename IList>
struct IntCons;

template<int I, int ... Ints>
struct IntCons<I, IntList<Ints...>>
{
    using type = IntList<I, Ints...>;
};

// бинарная метафункция
template<int a, int b>
struct Plus
{
    static int const value = a + b;
};


template <class A, class B, template<int, int> class MetaFunction>
struct Zip
{
    using type = typename IntCons<MetaFunction<A::Head, B::Head>::value, typename Zip<typename A::Tail, typename B::Tail, MetaFunction>::type>::type;
};

template <template<int, int> class MetaFunction>
struct Zip<IntList<>, IntList<>,MetaFunction>
{
    using type = IntList<>;
};

int main() {
    // два списка одной длины
    using L1 = IntList<1,6>;
    using L2 = IntList<23,5>;

// результат применения — список с поэлементными суммами
    using L3 = Zip<L1, L2, Plus>::type;  // IntList<2, 5, 10, 11, 7>
    return 0;
}
