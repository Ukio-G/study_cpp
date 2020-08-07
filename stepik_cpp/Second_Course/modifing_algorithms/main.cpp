#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <numeric>
#include <memory>

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

void shuffle()
{
    std::vector<Point> v_points = {{0, 0, 0},
                                   {1, 1, 1},
                                   {2, 2, 2},
                                   {3, 3, 3},
                                   {4, 4, 4}};
    std::shuffle(v_points.begin(), v_points.end(), std::mt19937(std::random_device()()));

    for (auto &item : v_points)
            std::cout << item;
}

void replace() {
    std::vector<Point> v_points = {{0, 0, 0},
                                   {1, 1, 1},
                                   {2, 2, 2},
                                   {3, 3, 3},
                                   {4, 4, 4},
                                   {1, 1, 1},
                                   {4, 4, 4},
                                   {1, 1, 1}
                                   };

    std::replace(v_points.begin(), v_points.end(), Point(1, 1, 1), Point(5, 5, 5));

    for (auto &item : v_points)
        std::cout << item;
}

void replace_copy() {
    std::vector<Point> v_points = {{0, 0, 0},
                                   {1, 1, 1},
                                   {2, 2, 2},
                                   {3, 3, 3},
                                   {4, 4, 4}};

    std::vector<Point> v_points_destination;

    std::replace_copy_if(v_points.begin(), v_points.end(), std::back_inserter(v_points_destination),
            [](Point & p){return p.object_id > 2;}, Point(5,5,5));

    for (auto &item : v_points_destination)
        std::cout << item;
}

void reverse() {
    std::vector<Point> v_points = {{0, 0, 0},
                                   {1, 1, 1},
                                   {2, 2, 2},
                                   {3, 3, 3},
                                   {4, 4, 4}};

    std::reverse(v_points.begin(), v_points.end());

    for (auto &item : v_points)
        std::cout << item;
}

void rotate()
{
    std::vector<Point> v_points = {{0, 0, 0},
                                   {1, 1, 1},
                                   {2, 2, 2},
                                   {3, 3, 3},
                                   {4, 4, 4}};

    std::rotate(v_points.begin()+1, v_points.begin() + 2, v_points.end() - 1);

    for (auto &item : v_points)
        std::cout << item << std::endl;

}

void swap_ranges()
{
    std::vector<Point> v_points = {{0, 0, 0},
                                   {1, 1, 1},
                                   {2, 2, 2},
                                   {3, 3, 3},
                                   {4, 4, 4}};

    std::swap_ranges(v_points.begin(), v_points.end() - 2, v_points.begin() + 2);

    for (auto &item : v_points)
        std::cout << item << std::endl;
}


void transform()
{
    std::vector<Point> v_points = {{0, 0, 0},
                                   {1, 1, 1},
                                   {2, 2, 2},
                                   {3, 3, 3},
                                   {4, 4, 4}};

    auto p_pow = [](Point point) -> Point{
        point.x *= point.x;
        point.y *= point.y;
        return point;
    };

    std::vector<Point> v_result;
    std::transform(v_points.begin(), v_points.end(), std::back_inserter(v_result), p_pow);

    for (auto &item : v_result)
        std::cout << item << std::endl;
}

void unique()
{
    std::vector<Point> v_points = {{0, 0, 0},
                                   {0, 0, 0},
                                   {2, 2, 2},
                                   {2, 2, 2},
                                   {0, 0, 0}};

    auto last = std::unique(v_points.begin(), v_points.end());

    v_points.erase(last, v_points.end());

    for (auto &item : v_points)
        std::cout << item << std::endl;

}

void adjacent_difference()
{
    std::vector<int> numbers = {2, 3, 4, 10};

    std::adjacent_difference(numbers.begin(), numbers.end(), numbers.begin());

    for (auto &number : numbers)
        std::cout << number << std::endl;
}


void remove_copy_if()
{
    std::vector<Point> v_points = {{0, 0, 2},
                                   {1, 1, 2},
                                   {2, 2, 1},
                                   {3, 3, 0},
                                   {4, 4, 1}};

    auto f = [](const Point & p) -> bool
    {
        return (p.object_id == 2);
    };

    auto result_copy_if = std::remove_copy_if(v_points.begin(), v_points.end(), v_points.begin(), f);

    std::cout << *result_copy_if;
    std::cout << "===========" << std::endl;

    for (auto &item : v_points) {
        std::cout << item;
    }
}
template<class Iterator>
size_t count_permutations(Iterator p, Iterator q) {
    size_t counter = 0;
    std::vector<typename std::iterator_traits<Iterator>::value_type> a(p,q);
    auto first = a.begin();
    auto last = a.end();
    std::sort(first, last);
    do {
        if (std::adjacent_find(first, last) == last)
            counter++;
    } while (std::next_permutation(first, last));
    return counter;
}


void count_permutation()
{
    std::array<int, 3> a1 = {1,2,3};
    size_t c1 = count_permutations(a1.cbegin(), a1.cend()); // 6

    std::cout << c1 << std::endl;

    std::array<int, 5> a2 = {1,2,3,4, 4};
    size_t c2 = count_permutations(a2.cbegin(), a2.cend()); // 36
//    size_t c2 = std::distance(a2.begin(),std::adjacent_find(a2.begin(),a2.end()));

//    for (auto &item : a2) {
//        std::cout << item << " ";
//    }
//    std::cout << std::endl;
    std::cout << c2 << std::endl;

}

int main() {
//    shuffle();
//    replace_copy();
//    replace();
//    reverse();
//    rotate();
//    swap_ranges();
//    transform();
//    unique();
//    adjacent_difference();
//    remove_copy_if();
    count_permutation();

    return 0;
}
