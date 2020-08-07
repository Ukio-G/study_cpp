#include <iostream>


#include <utility> // std::declval

// внутри do_math объекты типа T
// - копируются
// - присваиваются
// - складываются оператором +
template<class T>
void do_math()      noexcept(
                            std::is_nothrow_copy_assignable<T>::value &&
                            noexcept( std::declval<T>() + std::declval<T>()) &&
                            std::is_nothrow_assignable<T&, T>::value &&
                            std::is_nothrow_move_assignable<T>::value &&
                            std::is_nothrow_move_constructible<T>::value
                            )
{
    
}

int main() {

    bool b1 = noexcept(do_math<int>()); // true

    bool b2 = noexcept(do_math<std::string>()); // false

    std::cout << std::boolalpha << b1 << std::endl;
    std::cout << std::boolalpha << b2 << std::endl;
    return 0;
}
