#include <deque>
#include <iostream>
#include <unordered_map>

struct Track;

struct Point
{
    int x = 0;
    int y = 0;
    Track * parent = nullptr;
    Point(int x, int y) : x(x), y(y) {
        std::cout << "Point has been created with args "<< x << " " << y << " " << this << std::endl;
    }
    Point(){
        std::cout << "Point has been created without args "  << this  << std::endl;
    }

    Point(const Point & p)
    {
        x = p.x;
        y = p.y;
        parent = p.parent;
        std::cout << "Point copy constructor "  << this << std::endl;
    }

    Point& operator=(const Point & p)
    {
        if (&p == this) return *this;
        std::cout << "Point operator = called" << std::endl;
        *this = Point(p);
        return *this;
    }

    ~Point()
    {
        std::cout << "Point has been destroyed "  << this  << std::endl;
    }
};

struct Track
{
    uint64_t id;
    std::deque<Point> points;
    void appendExistingPoint(Point & point)
    {
        point.parent = this;
        points.push_back(point);
    }

    void copyExistingPoint(Point point)
    {
        point.parent = this;
        this->points.push_back(point);
    }
};

std::unordered_map<uint64_t, Track> track_source;
std::unordered_map<uint64_t, Track> track_destination;

int main()
{

    track_source[0].id = 0;
    track_source[0].points.emplace_back(1,1);
    track_source[0].points.emplace_back(2,2);
    track_source[0].points.emplace_back(3,3);
    track_source[0].points.emplace_back(4,4);
    track_source[0].points.emplace_back(5,5);

    auto & points = track_source[0].points;
    for(auto & point : points)
        track_destination[0].appendExistingPoint(point);

    track_source.erase(0);

    //  Обращение к потенциально удаленному объекту ?
    std::cout << "parent " << track_destination[0].points.back().parent << std::endl;
    std::cout << "x " << track_destination[0].points.back().x << std::endl;
    std::cout << "y " << track_destination[0].points.back().y << std::endl;
    std::cout << "addr " << &track_destination[0].points.back() << std::endl;


    std::cout << "program end" << std::endl;
    return 0;

}
