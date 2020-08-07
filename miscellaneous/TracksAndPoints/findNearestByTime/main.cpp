#include <iostream>
#include "Track.h"


int main() {
    Track track;

    Point p1(0,0,0);            // t = 3
    Point p2(1,0,0);            // t = 7
    Point p3(2,0,0);            // t = 10
    Point p4(3,0,0);            // t = 13
    Point p5(4,0,0);            // t = 16

    track.appendExistingPoint(p1);
    track.appendExistingPoint(p2);
    track.appendExistingPoint(p3);
    track.appendExistingPoint(p4);
    track.appendExistingPoint(p5);

    IS_Track is_track;
    is_track.track = &track;

    IS_Point is_p1 = {-1, 0, 0, 1, &is_track};
    IS_Point is_p2 = {-1, 0, 1, 2, &is_track};
    IS_Point is_p3 = {-1, 0,2, 3, &is_track};
    IS_Point is_p4 = {0, 0,3, 4, &is_track};
    IS_Point is_p5 = {-1, 0,4, 5, &is_track};
    IS_Point is_p6 = {-1, 0,5, 6, &is_track};
    IS_Point is_p7 = {-1, 0,6, 7, &is_track};
    IS_Point is_p8 = {1, 0,7, 8, &is_track};
    IS_Point is_p9 = {-1, 0,8, 9, &is_track};
    IS_Point is_p10 = {-1, 0,9, 10, &is_track};
    IS_Point is_p11 = {2, 0,10, 11, &is_track};
    IS_Point is_p12 = {-1, 0,11, 12, &is_track};
    IS_Point is_p13 = {-1, 0,12, 13, &is_track};
    IS_Point is_p14 = {3, 0,13, 14, &is_track};
    IS_Point is_p15 = {4, 0,16, 15, &is_track};

    is_track.appendISPoint(is_p1);
    is_track.appendISPoint(is_p2);
    is_track.appendISPoint(is_p3);
    is_track.appendISPoint(is_p4);
    is_track.appendISPoint(is_p5);
    is_track.appendISPoint(is_p6);
    is_track.appendISPoint(is_p7);
    is_track.appendISPoint(is_p8);
    is_track.appendISPoint(is_p9);
    is_track.appendISPoint(is_p10);
    is_track.appendISPoint(is_p11);
    is_track.appendISPoint(is_p12);
    is_track.appendISPoint(is_p13);
    is_track.appendISPoint(is_p14);
    is_track.appendISPoint(is_p15);


    Point & p = getNextNearestPoint(is_p1);
    std::cout << p.x << " " << p.y << " " << p.object_id << std::endl;

    Point & p_p = getPrevNearestPoint(is_p1);
    std::cout << p_p.x << " " << p_p.y << " " << p_p.object_id << std::endl;

    IS_Point & prev_point = is_p1.prev();
    std::cout << prev_point.timestamp << std::endl;

    IS_Point & next_point = is_p12.next();
    std::cout << next_point.timestamp << std::endl;

    return 0;
}
