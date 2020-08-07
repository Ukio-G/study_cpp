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
