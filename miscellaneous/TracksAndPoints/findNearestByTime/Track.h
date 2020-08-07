//
// Created by ukio on 30.05.2020.
//

#ifndef CONCAT_TRACKS_TRACK_H
#define CONCAT_TRACKS_TRACK_H
#include <unordered_map>
#include <iostream>
#include <deque>
#include <map>

#define POINT_PUSH_BACK 1
#define POINT_PUSH_FRONT 0

#define OPERATOR_ASSIGMENT_DEBUG 0
#define CONSTRUCTORS_DEBUG 0
#define DESTRUCTOR_DEBUG 0

struct Track;
struct IS_Track;

struct IS_Point
{
    int point_id = -1;
    int is_point_id = -1;
    uint64_t timestamp = 0;
    int data;
    IS_Track * parent = nullptr;

    IS_Point &prev();

    IS_Point &next();
};

struct IS_Track
{
    std::deque<IS_Point> is_points;
    std::map<uint64_t, int> timeToTrackpoint;
    Track * track;
    void appendISPoint(IS_Point &);
};

struct Point
{
    int x = 0;
    int y = 0;
    int object_id = 0;
    enum Type
    {
        Radar, Number, Undefined
    };
    Type type = Undefined;
    Track * parent = nullptr;
    Point(int x, int y, int object_id) : x(x), y(y), object_id(object_id) {
        if(CONSTRUCTORS_DEBUG) std::cout << "Point has been created with args "<< x << " " << y << " " << this << std::endl;
    }
    Point(){
        if(CONSTRUCTORS_DEBUG) std::cout << "Point has been created without args "  << this  << std::endl;
    }

    Point(const Point & p) : x(p.x), y(p.y), parent(p.parent), type(p.type), object_id(p.object_id){
        if(CONSTRUCTORS_DEBUG) std::cout << "Point copy constructor "  << this << std::endl;
    }

    Point& operator=(const Point & p);

    ~Point(){
        if (DESTRUCTOR_DEBUG) std::cout << "Point has been destroyed "  << this  << std::endl;
    }
};

struct Track
{
    uint64_t id;
    std::deque<Point> points;

    void appendExistingPoint(Point & point, bool push_at = POINT_PUSH_BACK);
    void appendExistingPoint(Point && point, bool push_at = POINT_PUSH_BACK);
    void copyExistingPoint(Point point);
    void appendTrack(Track & other, bool push_at);
    Track(const Track & other);
    Track();
    ~Track();
    void updateParent();
};

std::ostream & operator <<( std::ostream &os, const Point &point );
std::ostream & operator <<( std::ostream &os, const Track &track );

Point & getNextNearestPoint (IS_Point & point);
Point & getPrevNearestPoint (IS_Point & point);

#endif //CONCAT_TRACKS_TRACK_H
