//
// Created by ukio on 29.09.2020.
//

#include "Tracks.h"

std::ostream & operator<<(std::ostream & os, Point & point) {
    os << "x = " << point.x << ", y = " << point.y;
    return os;
}

std::ostream & operator<<(std::ostream & os, Rectangle & rect) {
    os << "x = " << rect.x << ", y = " << rect.y << ", width = " << rect.width << ", height = " << rect.height;
    return os;
}

std::ostream & operator<<(std::ostream & os, Instant::RadarTrack & track) {
    os << track.radar_number << "\n";
    for (auto &item : track.m_points) {
        os << item.radarPosition << ", speed is " << item.speed << "\n";
    }
    return os;
}

std::ostream & operator<<(std::ostream & os, Instant::PlateTrack & track) {
    for (auto &item : track.m_points) {
        os << item.carArea << "\n";
    }
    return os;
}