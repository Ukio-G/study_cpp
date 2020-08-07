//
// Created by ukio on 30.05.2020.
//

#include <algorithm>
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
    if(DESTRUCTOR_DEBUG) std::cout << "Track with address " << this << " and id = " << id << " has been destroyed" << std::endl;
}

Track::Track() {
    if(CONSTRUCTORS_DEBUG) std::cout << "Track with address " << this << " has been created" << std::endl;
}

void IS_Track::appendISPoint(IS_Point & is_point)
{
    is_point.is_point_id = is_points.size();
    is_points.push_back(is_point);
    if(is_point.point_id != -1 && is_point.timestamp!= 0)
        timeToTrackpoint[is_point.timestamp] = is_point.point_id;
}

Point & getNextNearestPoint (IS_Point & point){
    auto & track = point.parent;
    auto timestamp = point.timestamp;
    auto it = track->timeToTrackpoint.find(timestamp);
    if (it != track->timeToTrackpoint.end())
        return track->track->points[it->second];

    uint64_t previousTimestamp = track->timeToTrackpoint.begin()->first;
    if (point.timestamp < previousTimestamp)
        return track->track->points.front();

    for (auto &item : track->timeToTrackpoint) {
        if (previousTimestamp <= timestamp && timestamp <= item.first)
            return track->track->points[item.second];
        previousTimestamp = item.first;
    }
    return track->track->points[(--track->timeToTrackpoint.end())->second];
}


Point & getPrevNearestPoint (IS_Point & point){
    auto & track = point.parent;
    auto timestamp = point.timestamp;
    auto it = track->timeToTrackpoint.find(timestamp);
    if (it != track->timeToTrackpoint.end())
        return track->track->points[it->second];

    uint64_t previousTimestamp = track->timeToTrackpoint.begin()->first;
    if (point.timestamp < previousTimestamp)
        return track->track->points[track->timeToTrackpoint.begin()->second];

    for (auto &item : track->timeToTrackpoint) {
        if (previousTimestamp <= timestamp && timestamp <= item.first)
            return track->track->points[item.second-1];
        previousTimestamp = item.first;
    }
    return track->track->points[(--track->timeToTrackpoint.end())->second];
}

IS_Point & IS_Point::next() {
    if (this->is_point_id >= parent->is_points.size() - 1)
        return parent->is_points.back();
    return parent->is_points[this->is_point_id+1];
}

IS_Point & IS_Point::prev() {
    if (this->is_point_id <= 0)
        return parent->is_points.front();
    return parent->is_points[this->is_point_id-1];
}


