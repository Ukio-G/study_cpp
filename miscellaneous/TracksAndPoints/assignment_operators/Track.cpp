//
// Created by ukio on 30.05.2020.
//

#include "Track.h"


std::ostream & operator <<( std::ostream &os, const Point &point )
{
    os << "x:" << point.x << " y:" << point.y << std::endl;
    return os;
}


std::ostream & operator <<( std::ostream &os, const Track &track )
{
    for (const auto &point : track.points)
        os << point;
    return os;
}

void Track::appendTrack(Track &other, bool push_at) {
    auto & o_points = other.points;
    if(push_at == POINT_PUSH_BACK)
        for(auto & point : o_points)
            appendExistingPoint(point, push_at);
    if(push_at == POINT_PUSH_FRONT)
        for(auto r_it = o_points.rbegin(); r_it != o_points.rend(); r_it++)
            appendExistingPoint(*r_it, push_at);
}

void Track::copyExistingPoint(Point point) {
    point.parent = this;
    this->points.push_back(point);
}

void Track::appendExistingPoint(Point &&point, bool push_at) {
    point.parent = this;
    (push_at == POINT_PUSH_BACK) ? points.push_back(point) : points.push_front(point);
}

void Track::appendExistingPoint(Point &point, bool push_at) {
    point.parent = this;
    (push_at == POINT_PUSH_BACK) ? points.push_back(point) : points.push_front(point);
}

Track::Track(const Track & other) : id(other.id), points(other.points)
{
    if(CONSTRUCTORS_DEBUG) std::cout << "Track with address " << this << " has been created from other "<< &other << std::endl;
    updateParent();
}

Point &Point::operator=(const Point &p) {
    if (OPERATOR_ASSIGMENT_DEBUG) std::cout << "Point operator= called" << std::endl;
    if (&p == this) return *this;
    *this = Point(p);
    return *this;
}

void Track::updateParent()
{
    for (auto &item : points)
        item.parent = this;
}

Track::~Track() {
    std::cout << "Track with address " << this << " and id = " << id << " has been destroyed" << std::endl;
}

Track::Track() {
    if(CONSTRUCTORS_DEBUG) std::cout << "Track with address " << this << " has been created" << std::endl;
}
