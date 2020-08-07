#include <iostream>
#include <tuple>
#include <functional>


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

template<typename List>
struct Length
{
    static int const value = 1 + Length<typename List::Tail>::value;
};

template<>
struct Length<IntList<>>
{
    static int const value = 0;
};

template<int I, typename IList>
struct IntCons;

template<int I, int ... Ints>
struct IntCons<I, IntList<Ints...>>
{
    using type = IntList<I, Ints...>;
};


template<typename IList, int I>
struct IntConsRev;

template<int I, int ... Ints>
struct IntConsRev<IntList<Ints...>, I>
{
    using type = IntList<Ints..., I>;
};

template<int Seq>
struct Generate;

template<int Seq>
struct Generate
{
    using type = typename IntConsRev<typename Generate<Seq-1>::type, Seq-1>::type;
};

template<>
struct Generate<0>
{
    using type = IntList<>;
};



template <int ... Ns> struct sequence {};

template <int ... Ns> struct seq_gen;

template <int I, int ... Ns>
struct seq_gen<I, Ns...>
{
    using type = typename seq_gen<I - 1, I - 1, Ns...>::type;
};

template <int ... Ns>
struct seq_gen<0, Ns...>
{
    using type = sequence<Ns...>;
};


template <int N>
using sequence_t = typename seq_gen<N>::type;


template<typename Function, typename ... TupleValues, int ... Indexes>
auto apply_f(Function f, std::tuple<TupleValues...> t, sequence<Indexes...>) -> decltype(f(std::get<Indexes>(t)...))
{
    return f(std::get<Indexes>(t)...);
}

template<typename ... TupleValues, typename Function>
auto apply(Function f, std::tuple<TupleValues...> t) -> decltype(apply_f(f,t, sequence_t<sizeof...(TupleValues)>{}))
{
    return apply_f(f,t, sequence_t<sizeof...(TupleValues)>{});
}


int main() {
    auto f = [](int x, double y, double z) { return x + y + z; };
    auto t = std::make_tuple(30, 5.0, 1.6);  // std::tuple<int, double, double>
    std::cout << apply(f, t) << std::endl;
    return 0;
}
