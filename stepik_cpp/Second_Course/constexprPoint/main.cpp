// определение структуры Point уже подключено
 struct Point
{
    constexpr Point(double x, double y) 
        : x(x), y(y) 
    {}

    double x = 0;
    double y = 0;
};


// сложение
constexpr Point operator+(Point a,Point b)
{
	return Point(a.x+b.y,a.y+b.y);
}

// вычитание
constexpr Point operator-(Point a,Point b)
{
	return Point(a.x-b.y,a.y-b.y);
}

// скалярное произведение
constexpr double operator*(Point a,Point b)
{
	return a.x * b.x + a.y * b.y;
}