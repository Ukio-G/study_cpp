#include <utility> // для std::move и std::forward

// реализация функции apply
template <typename T, typename Functor, typename ...Args>
T apply (Functor<Args&&...> functor, Args&&... args)
{
	functor(std::forward<Args>(args)...);
}