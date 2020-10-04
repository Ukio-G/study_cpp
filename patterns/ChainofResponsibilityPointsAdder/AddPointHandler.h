//
// Created by ukio on 29.09.2020.
//

#ifndef CHAINOFRESPONSIBILITYPOINTSADDER_ADDPOINTHANDLER_H
#define CHAINOFRESPONSIBILITYPOINTSADDER_ADDPOINTHANDLER_H

#include <cmath>
#include "Tracks.h"

class BaseConsistencyHandler {
public:
    BaseConsistencyHandler * next_handler = nullptr;
    void appendNewHandler(BaseConsistencyHandler * new_handler){
        BaseConsistencyHandler * last_handler = this;
        while (last_handler->next_handler != nullptr)
            last_handler = last_handler->next_handler;
        last_handler->next_handler = new_handler;
    }

    virtual bool check(Instant::iTrack *track, Instant::BasePoint *point) {
        std::cout << "BaseConsistencyHandler \n";
        BaseConsistencyHandler * current_handler = next_handler;
        while (current_handler != nullptr) {
            if (!current_handler->check(track, point))
                return false;
            current_handler = current_handler->next_handler;
        }
        return true;
    }
    virtual ~BaseConsistencyHandler() = default;
};

class MovementDirectionHandler : public BaseConsistencyHandler {
    bool check(Instant::iTrack *track, Instant::BasePoint *point) override {
        Instant::PlateTrack * trackerTrack = (Instant::PlateTrack *)track;
        Instant::PlatePoint * trackerPoint = (Instant::PlatePoint *)point;
        return (trackerTrack->m_points.back().movementDirection == trackerPoint->movementDirection);
    }
    ~MovementDirectionHandler() override = default;
};

class CoordinateDirectionHandler : public BaseConsistencyHandler {
    bool check(Instant::iTrack *track, Instant::BasePoint *point) override {
        std::cout << "CoordinateDirectionHandler \n";
        Instant::RadarTrack * radarTrack = (Instant::RadarTrack*)track;
        Instant::RadarPoint * radarPoint = (Instant::RadarPoint*)point;
        int previous_x = radarTrack->m_points.back().radarPosition.x;
        int delta_x =  previous_x - radarPoint->radarPosition.x;
        return (std::signbit(-delta_x) == std::signbit(radarPoint->speed));
    }
    ~CoordinateDirectionHandler() override = default;
};

class SpeedDeviationHandler : public BaseConsistencyHandler {
    bool check(Instant::iTrack *track, Instant::BasePoint *point) override {
        std::cout << "SpeedDeviationHandler \n";
        Instant::RadarTrack * radarTrack = (Instant::RadarTrack*)track;
        Instant::RadarPoint * radarPoint = (Instant::RadarPoint*)point;
        float previous_speed = radarTrack->m_points.back().speed;
        bool sameSPeedDirection = std::signbit(previous_speed) == std::signbit(radarPoint->speed);
        bool acceptableSpeed = previous_speed * 0.8 <= radarPoint->speed && previous_speed * 1.2 >= radarPoint->speed;
        return (sameSPeedDirection && acceptableSpeed);
    }
    ~SpeedDeviationHandler() override = default;
};

#endif //CHAINOFRESPONSIBILITYPOINTSADDER_ADDPOINTHANDLER_H
