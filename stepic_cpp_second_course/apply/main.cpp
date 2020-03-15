#include <string>
#include <iostream>
#include <utility> // для std::move и std::forward

// реализация функции apply
template <class FunctorType, class ... Args>
auto apply (FunctorType functor, Args&&... args) -> decltype(functor(std::forward<Args>(args)...))
{
	return functor(std::forward<Args>(args)...);
}

int main(int argc, char const* argv[]) {
  auto fun = [](std::string a, std::string const& b) { return a += b; };

  std::string s("world!");
  // s передаётся по lvalue ссылке,
  // а временный объект по rvalue ссылке
  s = apply(fun, std::string("Hello, "), s);
  return 0;
}