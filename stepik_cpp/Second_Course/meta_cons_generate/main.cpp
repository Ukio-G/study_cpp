#include <iostream>


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

int main() {



    using L1 = IntList<2,3,4>;


    using L2 = IntCons<1, L1>::type;   // IntList<1,2,3,4>



    using L3 = Generate<5>::type;      // IntList<0,1,2,3,4>

    std::cout << L3::Head;




    return 0;
}
