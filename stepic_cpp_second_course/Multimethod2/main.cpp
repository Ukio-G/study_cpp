#include <typeinfo>
#include <iostream>
#include <typeindex>
#include <functional>
#include <map>
#include <stddef.h>
#include <memory>

// базовый класс фигуры (полиморфный)
struct Shape { 
	virtual ~Shape() {};
};

// прямоугольник
struct Rectangle : Shape { 
	int i;
	~Rectangle(){};
};

// треугольник
struct Triangle : Shape { 
	float j;
	~Triangle(){};
 };

// функция для проверки пересечения двух прямоугольников
bool is_intersect_r_r(Shape * a, Shape * b)
{
	std::cout << "is_intersect_r_r" << std::endl;
	return true;
}

// функция для проверки пересечения прямоугольника и треугольника
bool is_intersect_r_t(Shape * a, Shape * b)
{
	std::cout << "is_intersect_r_t" << std::endl;
	return false;
}

// Base - базовый класс иерархии
// Result - тип возвращаемого значения мультиметода
// Commutative - флаг, который показывает, что
// мультиметод коммутативный (т.е. f(x,y) = f(y,x)).
template<class Base, class Result, bool Commutative>
struct Multimethod2
{

    // устанавливает реализацию мультиметода
    // для типов t1 и t2 заданных через typeid 
    // f - это функция или функциональный объект
    // принимающий два указателя на Base 
    // и возвращающий значение типа Result

	std::map<size_t,std::function<Result(Base *, Base *)>> implementation;

    void addImpl(const std::type_info & t1, const std::type_info & t2, std::function<Result(Base *, Base *)> f)
    {
    	size_t hash = t1.hash_code() ^ t2.hash_code();
    	implementation[hash] = f;

    	std::cout << "add implementation h1 = " << t1.hash_code() << ";h2 = " << t2.hash_code() << "; thier hash is "  << hash << std::endl;
    }

    // проверяет, есть ли реализация мультиметода
    // для типов объектов a и b
    bool hasImpl(Base * a, Base * b) const
    {
        // возвращает true, если реализация есть
        // если операция коммутативная, то нужно 
        // проверить есть ли реализация для b и а 
		size_t h1 = typeid(*a).hash_code();
        size_t h2 = typeid(*b).hash_code();
    	size_t hash = h1 ^ h2;

    	std::cout << "implementation h1 = " << h1 << ";h2 = " << h2 << " is "  << (implementation.find(hash) != implementation.end()) << std::endl;

        return (implementation.find(hash) != implementation.end()); 
    }

    // Применяет мультиметод к объектам
    // по указателям a и b
    Result call(Base * a, Base * b) const
    {
        // возвращает результат применения реализации
        // мультиметода к a и b
        size_t h1 = typeid(*a).hash_code();
        size_t h2 = typeid(*b).hash_code();
    	size_t hash = h1 ^ h2;

    	if (hasImpl(a,b))
        	return implementation.at(hash)(a,b);
        else
        	return false;
    }


};

    

int main() 
{
    // мультиметод для наследников Shape
    // возращающий bool и являющийся коммутативным 
    Multimethod2<Shape, bool, true> is_intersect;

    // добавляем реализацию мультиметода для двух прямоугольников
    is_intersect.addImpl(typeid(Rectangle), typeid(Rectangle), is_intersect_r_r);

    // добавляем реализацию мультиметода для прямоугольника и треугольника
    is_intersect.addImpl(typeid(Rectangle), typeid(Triangle), is_intersect_r_t);

    // создаём две фигуры    
   
    Shape * s1 = new Triangle();
    Shape * s2 = new Rectangle();

    // проверяем, что реализация для s1 и s2 есть
    if (is_intersect.hasImpl(s1, s2))
    {
         // вызывается функция is_intersect_r_t(s2, s1)
         bool res = is_intersect.call(s1, s2);
         std::cout << res << std::endl;

         res = is_intersect.call(s2,s1);
         std::cout << res << std::endl;

         res = is_intersect.call(s2,s2);
         std::cout << res << std::endl;
         // Замечание: is_intersect_r_t ожидает,
         // что первым аргументом будет прямоугольник
         // а вторым треугольник, а здесь аргументы
         // передаются в обратном порядке. 
         // ваша реализация должна самостоятельно 
         // об этом позаботиться
    }
}