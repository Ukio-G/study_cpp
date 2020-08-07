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

#define OPERATOR_ASSIGMENT_DEBUG 1
#define CONSTRUCTORS_DEBUG 1

struct Track;

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
        std::cout << "Point has been destroyed "  << this  << std::endl;
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

#endif //CONCAT_TRACKS_TRACK_H
