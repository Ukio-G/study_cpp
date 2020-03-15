#include <typeinfo>
#include <iostream>
#include <typeindex>
#include <functional>
#include <map>
#include <stddef.h>
#include <memory>
#include <utility>

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

bool is_intersect_t_r(Shape * a, Shape * b)
{
    std::cout << "is_intersect_t_r" << std::endl;
    return false;
}

bool is_intersect_t_t(Shape * a, Shape * b)
{
    std::cout << "is_intersect_t_t" << std::endl;
    return false;
}

template<class Base, class Result, bool Commutative>
struct Multimethod2
{
	std::map<std::pair<std::type_index,std::type_index>,std::function<Result(Base *, Base *)>> implementation;

    void addImpl(const std::type_index & t1, const std::type_index & t2, std::function<Result(Base *, Base *)> f)
    {
       std::pair<std::type_index,std::type_index> pair(t1,t2);
   	   implementation[pair] = f;
    }

    bool hasImpl(Base * a, Base * b) const
    {
		std::type_index t1 = typeid(*a);
        std::type_index t2 = typeid(*b);

        if(Commutative)
        {
            std::pair<std::type_index,std::type_index> first_case_pair(t1,t2);
            std::pair<std::type_index,std::type_index> second_case_pair(t2,t1);

            if (implementation.find(first_case_pair) != implementation.end() || 
                implementation.find(second_case_pair) != implementation.end())
                return true;
            return false;
        }
        else
        {
            std::pair<std::type_index,std::type_index> first_case_pair(t1,t2);
            if (implementation.find(first_case_pair) != implementation.end())
                return true;
            return false;
        }
    }

    Result call(Base * a, Base * b) const
    {

        std::type_index t1 = typeid(*a);
        std::type_index t2 = typeid(*b);

         if(Commutative)
        {
            std::pair<std::type_index,std::type_index> first_case_pair(t1,t2);
            std::pair<std::type_index,std::type_index> second_case_pair(t2,t1);

            if (implementation.find(first_case_pair) != implementation.end())
                return implementation.at(first_case_pair)(a, b);
            if (implementation.find(second_case_pair) != implementation.end())
                return implementation.at(second_case_pair)(b, a);
        }
        else
        {
            std::pair<std::type_index,std::type_index> first_case_pair(t1,t2);
            if (implementation.find(first_case_pair) != implementation.end())
                return implementation.at(first_case_pair)(a, b);
        }
    }
};

    
int main() 
{
    Multimethod2<Shape, bool, true> is_intersect_comm;

    is_intersect_comm.addImpl(typeid(Rectangle), typeid(Rectangle), is_intersect_r_r);
    is_intersect_comm.addImpl(typeid(Rectangle), typeid(Triangle), is_intersect_r_t);
    is_intersect_comm.addImpl(typeid(Triangle), typeid(Triangle), is_intersect_t_t);
   
    Shape * t = new Triangle();
    Shape * r = new Rectangle();

    std::cout << is_intersect_comm.hasImpl(t, r) << std::endl;
    std::cout << is_intersect_comm.hasImpl(t, r) << std::endl;
    std::cout << is_intersect_comm.hasImpl(t, t) << std::endl;

    Multimethod2<Shape, bool, false> is_intersect_non_comm;
    is_intersect_non_comm.addImpl(typeid(Rectangle), typeid(Rectangle), is_intersect_r_r);
    is_intersect_non_comm.addImpl(typeid(Rectangle), typeid(Triangle), is_intersect_r_t);
    is_intersect_non_comm.addImpl(typeid(Triangle), typeid(Rectangle), is_intersect_t_r);
    is_intersect_non_comm.addImpl(typeid(Triangle), typeid(Triangle), is_intersect_t_t);

    std::cout << is_intersect_non_comm.hasImpl(r, r) << std::endl;
    std::cout << is_intersect_non_comm.hasImpl(t, r) << std::endl;
    std::cout << is_intersect_non_comm.hasImpl(r, t) << std::endl;
    std::cout << is_intersect_non_comm.hasImpl(t, t) << std::endl;

    is_intersect_comm.call(t, r);
    is_intersect_comm.call(r, t);
    is_intersect_comm.call(r, r);
    is_intersect_comm.call(t, t);

    is_intersect_non_comm.call(t, r);
    is_intersect_non_comm.call(r, t);
    is_intersect_non_comm.call(r, r);
    is_intersect_non_comm.call(t, t);

}

