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

// бинарная метафункция
template<int a, int b>
struct Multiply
{
    static int const value = a + b;
};

// бинарная метафункция
template<int a, int b>
struct Division
{
    static int const value = a - b;
};



// бинарная метафункция
template<int a, int b>
struct Substract
{
    static int const value = a - b;
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

template<int m = 0, int kg = 0, int s = 0, int A = 0, int K = 0, int mol = 0, int cd = 0>
using Dimension = IntList<m, kg, s, A, K, mol, cd>;

template<int... Ints>
using Negate = Zip<typename Zip<IntList<Ints...>,IntList<Ints...>, Substract>::type,IntList<Ints...>, Substract>;

template<class A>
struct Quantity
{ };

template<int... Args>
class Quantity<IntList<Args...>>
{
public:
    Quantity() = default;
    explicit Quantity(double value) : m_value(value) {};
    double value() const {
        return m_value;
    }

    Quantity<IntList<Args...>> operator +(Quantity<IntList<Args...>> other) {
        using return_type = Quantity<IntList<Args...>>;
        return return_type{m_value + other.value()};
    }

    Quantity<IntList<Args...>> operator -(Quantity<IntList<Args...>> other) {
        using return_type = Quantity<IntList<Args...>>;
        return return_type{m_value - other.value()};
    }

    template<int ... ArgsOther>
    Quantity<typename Zip<IntList<Args...>, IntList<ArgsOther...>, Division>::type> operator /(Quantity<IntList<ArgsOther...>>  other) {
        using return_type = Quantity<typename Zip<IntList<Args...>, IntList<ArgsOther...>, Division>::type>;
        return return_type{m_value / other.value()};
    }

    template<int ... ArgsOther>
    Quantity<typename Zip<IntList<Args...>, IntList<ArgsOther...>, Multiply>::type> operator *(Quantity<IntList<ArgsOther...>>  other) {
        using return_type = Quantity<typename Zip<IntList<Args...>, IntList<ArgsOther...>, Multiply>::type>;
        return return_type{m_value * other.value()};
    }

    Quantity<IntList<Args...>> operator/(double arg) {
        using return_type = Quantity<IntList<Args...>>;
        return return_type{m_value / arg};
    }

    Quantity<IntList<Args...>> operator*(double arg) {
        using return_type = Quantity<IntList<Args...>>;
        return return_type{m_value * arg};
    }

    double m_value;
};

template<int ... Args>
Quantity<typename Negate<Args...>::type> operator/(double factor, Quantity<IntList<Args...>> quantity)
{
    using return_type = Quantity<typename Negate<Args...>::type>;
    return return_type{factor/quantity.value()};
}

template<int ... Args>
Quantity<IntList<Args...>> operator*(double factor, Quantity<IntList<Args...>> quantity)
{
    using return_type = Quantity<IntList<Args...>>;
    return return_type{factor*quantity.value()};
}


int main() {

    using NumberQ   = Quantity<Dimension<>>;          // число без размерности
    using LengthQ   = Quantity<Dimension<1>>;          // метры
    using LengthQNeg   = Quantity<Dimension<-1>>;          // метры
    using TimeQ     = Quantity<Dimension<0, 0, 1>>;    // секунды
    using VelocityQ = Quantity<Dimension<1, 0, -1>>;   // метры в секунду

    using MassQ     = Quantity<Dimension<0, 1>>;       // килограммы
    using AccelQ    = Quantity<Dimension<1, 0, -2>>;   // ускорение, метры в секунду в квадрате
    using ForceQ    = Quantity<Dimension<1, 1, -2>>;   // сила в ньютонах
//
    LengthQ   l{30000};      // 30 км
    LengthQ   l2{50000};      // 30 км
    LengthQ   l3 = l2 - l;
    LengthQ   l4 = l2 + l;
    LengthQ   l5 = l2 * 2;
    LengthQ   l6 = 2 * l2;

    LengthQNeg   l7 = 50000 / l2;
    LengthQ   l8 = l2 / 50000;

    std::cout << l3.value() << std::endl;
    std::cout << l4.value() << std::endl;
    std::cout << l5.value() << std::endl;
    std::cout << l6.value() << std::endl;
    std::cout << l7.value() << std::endl;
    std::cout << l8.value() << std::endl;

    TimeQ     t{10 * 60};    // 10 минут

    VelocityQ v = l / t;     // результат типа VelocityQ, 50 м/с
    std::cout << v.value() << std::endl;
    AccelQ    a{9.8};        // ускорение свободного падения
    MassQ     m{80};         // 80 кг
    ForceQ    f = m * a;     // результат типа ForceQ
    std::cout << f.value() << std::endl;
    return 0;
}

