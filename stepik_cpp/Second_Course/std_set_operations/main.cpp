#include <iostream>
#include <algorithm>
#include <vector>

#define POINT_PUSH_BACK 1
#define POINT_PUSH_FRONT 0

#define OPERATOR_ASSIGMENT_DEBUG 0
#define CONSTRUCTORS_DEBUG 0
#define DESTRUCTOR_DEBUG 0
struct Track;

struct Point
{
    int x = 0;
    int y = 0;
    int object_id = 0;
    enum Type {
        Radar, Number, Undefined
    };
    Type type = Undefined;
    Track * parent = nullptr;

    Point(int x, int y, int object_id) : x(x), y(y), object_id(object_id) {
        if(CONSTRUCTORS_DEBUG) std::cout << "Point has been created with args "<< x << " " << y << " " << this << std::endl;
    }
    Point() {
        if(CONSTRUCTORS_DEBUG) std::cout << "Point has been created without args "  << this  << std::endl;
    }

    Point(const Point & p) : x(p.x), y(p.y), parent(p.parent), type(p.type), object_id(p.object_id) {
        if(CONSTRUCTORS_DEBUG) std::cout << "Point copy constructor "  << this << std::endl;
    }

    Point& operator=(const Point & p) = default;
    bool operator==(const Point & other) const {
        return (x == other.x) && (y == other.y) && (object_id == other.object_id) && (type == other.type) && (parent == other.parent);
    }

    bool operator<(const Point & other) const {
        return object_id < other.object_id;
    }

    ~Point() {
        if(DESTRUCTOR_DEBUG) std::cout << "Point has been destroyed "  << this  << std::endl;
    }
};

std::ostream & operator <<( std::ostream &os, const Point &point );

std::ostream & operator <<( std::ostream &os, const Point &point ) {
    os << "x:" << point.x << " y:" << point.y << std::endl;
    return os;
}

void set_intersection() {
    std::vector<Point> v_point1 = { {1, 1, 0}, {2, 2, 1}, {3, 3, 2},
                                    {4, 4, 3}, {5, 5, 4}, {6, 6, 5}};
    std::vector<Point> v_point2 = {                            {2, 2, 1},
                                    {4, 4, 3}, {5, 5, 4}                          };
    std::vector<Point> v_points_result;

    std::set_intersection(v_point1.begin(), v_point1.end(), v_point2.begin(), v_point2.end(), std::back_inserter(v_points_result));

    for (auto &result : v_points_result)
        std::cout << result << std::endl;
}

void set_difference()
{
    std::vector<Point> v_point1 = { {1, 1, 0}, {2, 2, 1}, {3, 3, 2},
                                    {4, 4, 3}, {5, 5, 4}, {6, 6, 5}};
    std::vector<Point> v_point2 = {                            {2, 2, 1},
                                    {4, 4, 3}, {5, 5, 4}                          };
    std::vector<Point> v_points_result;

    std::set_difference(v_point1.begin(), v_point1.end(), v_point2.begin(), v_point2.end(), std::back_inserter(v_points_result));

    for (auto &result : v_points_result)
        std::cout << result << std::endl;
}

void set_union()
{
    std::vector<Point> v_point1 = { {1, 1, 0}, {2, 2, 1}, {3, 3, 2},
                                    {4, 4, 3}, {5, 5, 4}, {6, 6, 5}};
    std::vector<Point> v_point2 = { {7, 7, 6}, {8, 8, 7} };
    std::vector<Point> v_points_result;

    std::set_union(v_point1.begin(), v_point1.end(), v_point2.begin(), v_point2.end(), std::back_inserter(v_points_result));

    for (auto &result : v_points_result)
        std::cout << result << std::endl;
}

void set_symmetric_difference()
{
    std::vector<Point> v_point1 = { {1, 1, 0}, {2, 2, 1}, {3, 3, 2},
                                    {4, 4, 3}, {5, 5, 4}, {6, 6, 5}};
    std::vector<Point> v_point2 = {                            {2, 2, 1},
                                    {4, 4, 3}, {5, 5, 4}, {7, 7, 6}, {8, 8, 7} };
    std::vector<Point> v_points_result;

    std::set_symmetric_difference(v_point1.begin(), v_point1.end(), v_point2.begin(), v_point2.end(), std::back_inserter(v_points_result));

    for (auto &result : v_points_result)
        std::cout << result << std::endl;
}

int main() {
    std::cout << "set intersection" << std::endl;
    set_intersection();

    std::cout << "set difference" << std::endl;
    set_difference();

    std::cout << "set union" << std::endl;
    set_union();

    std::cout << "set symmetric difference" << std::endl;
    set_symmetric_difference();

    return 0;
}
