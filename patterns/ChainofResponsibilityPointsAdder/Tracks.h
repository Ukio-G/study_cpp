//
// Created by ukio on 29.09.2020.
//

#ifndef CHAINOFRESPONSIBILITYPOINTSADDER_TRACKS_H
#define CHAINOFRESPONSIBILITYPOINTSADDER_TRACKS_H

#include <string>
#include <vector>
#include <iostream>
#include "Basics.h"

namespace Instant {
    class iTrack {
    public:
        virtual ~iTrack() = default;
    };

    class iPoint {
    public:
        virtual ~iPoint() = default;
    };

    struct BasePoint : public iPoint {
    public:
        ~BasePoint() override = default;
    };

    class RadarPoint : public BasePoint {
    public:
        RadarPoint(Point point) : radarPosition(point) { }
        RadarPoint(Point point, float speed) : radarPosition(point), speed(speed) { }

        Point radarPosition;
        float speed;
    };

    class PlatePoint : public BasePoint {
    public:
        PlatePoint(Rectangle carArea) : carArea(carArea) { }
        PlatePoint(Rectangle carArea, MovementDirection movementDirection) : carArea(carArea), movementDirection(movementDirection) { }

        Rectangle carArea;
        MovementDirection movementDirection;
    };

    template<class T>
    class BaseTrack : public iTrack{
    public:
        std::vector<T> m_points;
    };

    class RadarTrack : public BaseTrack<RadarPoint> {
    public:
        std::string radar_number;
        bool radar_method(int i) {
            std::cout << i << "\n";
            return true;
        }
    };

    class PlateTrack : public BaseTrack<PlatePoint> {
    public:
        std::string tracker_method(std::string str) {
            std::cout << str << "\n";
            return "str";
        }
    };
}

std::ostream & operator<<(std::ostream & os, Point & point);
std::ostream & operator<<(std::ostream & os, Rectangle & rect);
std::ostream & operator<<(std::ostream & os, Instant::RadarTrack & track);


#endif //CHAINOFRESPONSIBILITYPOINTSADDER_TRACKS_H
