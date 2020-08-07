//
// Created by ukio on 16.05.2020.
//

#ifndef SOCKET_BASIC_TRACKER_H
#define SOCKET_BASIC_TRACKER_H


#include <cstdint>
#include <deque>
#include <algorithm>

struct Point;
struct Additional;

struct Track
{
    uint64_t id;
    std::deque<Point> points;

    void appendNewPoint(int x, int y, Additional additional);
};


struct Additional
{
    int dx;
    int dy;
};

struct Point
{
    Additional additional_data;
    int x;
    int y;
    uint64_t id;
    Track * parent;
    Point * next();
    Point * prev();
};

Point * Point::next()
{
    auto& container = parent->points;
    auto result = std::find_if(container.begin(), container.end() - 1, [this](Point& n) {
        return this == &n;
    });
    return (result == container.end() - 1 ) ? this : &(*(result + 1));
}

Point * Point::prev()
{
    auto& container = parent->points;
    auto result = std::find_if(container.rbegin(), container.rend() - 1, [this](Point& n) {
        return this == &n;
    });
    return (result == container.rend() - 1 ) ? this :  &(*(result + 1));
}

void Track::appendNewPoint(int x, int y, Additional additional)
{
    Point point = {additional, x, y, this->points.size(), this};
    this->points.push_back(point);
}


#endif //SOCKET_BASIC_TRACKER_H
