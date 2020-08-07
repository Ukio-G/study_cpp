
#include <unordered_map>
#include <iostream>
#include <cmath>

struct iPoint {
public:
    int x;
    int y;

    bool operator==(const iPoint & other) const {
        return (other.x == x && other.y == y);
    }

    bool operator!=(const iPoint & other) const {
        return (other.x != x || other.y != y);
    }

    bool operator<(const iPoint & other) const {
        int distance_this = distance({0,0});
        int distance_other = other.distance({0,0});
        return distance_this < distance_other;
    }

    int distance(const iPoint & other) const {
        int xx = (other.x - x) * (other.x - x);
        int yy = (other.y - y) * (other.y - y);
        int result = (int)std::sqrt(xx + yy);
        return  (result >= 0) ? result : -result;
    }

    iPoint operator+(const iPoint & other) const {
        return {x + other.x, y+other.y};
    }

    iPoint operator-(const iPoint & other) const {
        return {x - other.x, y-other.y};
    }
};

namespace std {
    template <> struct hash<iPoint>
    {
        size_t operator()(const iPoint & point) const
        {
            return hash<int>()(point.x) | hash<int>()(point.y);
        }
    };
}



int main(int argc, char const *argv[])
{
	std::unordered_map<iPoint, int> map;

	map[{0,0}] = 100;
	map[{0,1}] = 1000;
	map[{1,1}] = 2000;
	map[{1,100}] = 3000;
	map[{1356,786}] = 3685450;


	std::cout << (bool)(map.find({1356,786}) == map.end()) << std::endl;
	std::cout << (bool)(map.find({0,0}) == map.end()) << std::endl;
	std::cout << (bool)(map.find({0,1}) == map.end()) << std::endl;
	std::cout << (bool)(map.find({1,1}) == map.end()) << std::endl;
	std::cout << (bool)(map.find({1,100}) == map.end()) << std::endl;
	std::cout << (bool)(map.find({144,1}) == map.end()) << std::endl;

	return 0;
}
