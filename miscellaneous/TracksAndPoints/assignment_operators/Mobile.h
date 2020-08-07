//
// Created by ukio on 02.06.2020.
//

#ifndef ASSIGNMENT_OPERATORS_MOBILE_H
#define ASSIGNMENT_OPERATORS_MOBILE_H


#include <unordered_map>
#include <vector>
#include "Track.h"

typedef std::unordered_map<uint64_t, Track> UMapTracks_t;

class Mobile
{
public:
    Mobile()= default;
    ~Mobile() = default;

    enum TrackType{
        Radar, Full
    };

    UMapTracks_t radar_tracks;
    UMapTracks_t full_tracks;

    void processing(std::vector<Point> & data);
    void finalizeTrack(uint64_t track_id, Mobile::TrackType trackType);
    bool trackExist(uint64_t track_id, UMapTracks_t &container);

    void translateTrack(Point &point);

    void processNewTrack(Point &point);

    void finalizeTrack(uint64_t track_id);
};


#endif //ASSIGNMENT_OPERATORS_MOBILE_H
