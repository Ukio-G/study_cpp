//
// Created by ukio on 30.05.2020.
//

#ifndef CONCAT_TRACKS_TRACK_H
#define CONCAT_TRACKS_TRACK_H
#include <unordered_map>
#include <iostream>
#include <deque>

#define POINT_PUSH_BACK 1
#define POINT_PUSH_FRONT 0

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
    void appendExistingPoint(Point & point, bool push_at = POINT_PUSH_BACK)
    {
        point.parent = this;
        (push_at == POINT_PUSH_BACK) ? points.push_back(point) : points.push_front(point);
    }

    void appendExistingPoint(Point && point, bool push_at = POINT_PUSH_BACK)
    {
        point.parent = this;
        (push_at == POINT_PUSH_BACK) ? points.push_back(point) : points.push_front(point);
    }

    void copyExistingPoint(Point point)
    {
        point.parent = this;
        this->points.push_back(point);
    }

    void appendTrack(Track & other, bool push_at)
    {
        auto & o_points = other.points;
        if(push_at == POINT_PUSH_BACK)
            for(auto & point : o_points)
                appendExistingPoint(point, push_at);
        if(push_at == POINT_PUSH_FRONT)
            for(auto r_it = o_points.rbegin(); r_it != o_points.rend(); r_it++)
                appendExistingPoint(*r_it, push_at);
    }
};

std::ostream & operator <<( std::ostream &os, const Point &point );
std::ostream & operator <<( std::ostream &os, const Track &track );

#endif //CONCAT_TRACKS_TRACK_H
