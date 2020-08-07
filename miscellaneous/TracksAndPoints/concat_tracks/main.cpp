#include <iostream>
#include <unordered_map>
#include "Track.h"


std::unordered_map<uint64_t, Track> track_source;
std::unordered_map<uint64_t, Track> track_destination;

int main() {

    Track source;
    Track destination;

    source.appendExistingPoint(Point(0,0));
    source.appendExistingPoint(Point(1,1));
    source.appendExistingPoint(Point(2,2));
    source.appendExistingPoint(Point(3,3));

    destination.appendExistingPoint(Point(4,4));
    destination.appendExistingPoint(Point(5,5));
    destination.appendExistingPoint(Point(6,6));
    destination.appendExistingPoint(Point(7,7));


    source.appendTrack(source, POINT_PUSH_BACK);

    std::cout << source;

    return 0;
}
