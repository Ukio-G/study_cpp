//
// Created by ukio on 02.06.2020.
//

#include "Mobile.h"

void Mobile::processing(std::vector<Point> & data) {
    std::cout << __func__ <<std::endl;
    for (auto &item : data) {
        auto id = item.object_id;
        bool translate = (item.type == Point::Type::Number && trackExist(id, radar_tracks));
        bool createNewTrack = !translate && !(trackExist(id, radar_tracks) || trackExist(id, full_tracks));
        auto & container = (item.type == Point::Type::Number) ? full_tracks : radar_tracks;

        if(translate) {
            translateTrack(item);
        }
        else if (createNewTrack){
            processNewTrack(item);
        } else {
            if (trackExist(id, container))
                container[id].appendExistingPoint(item);
        }
    }
}

void Mobile::translateTrack(Point& point)
{
    std::cout << __func__ <<std::endl;
    auto id = point.object_id;
    full_tracks.insert({id, Track(radar_tracks.at(id))});
    full_tracks[id].appendExistingPoint(point);
    radar_tracks.erase(id);
}

void Mobile::processNewTrack(Point &point) {
    std::cout << __func__ <<std::endl;
    auto trackType = (point.type == Point::Type::Number) ? Mobile::TrackType::Full : Mobile::TrackType::Radar;
    auto & container = (trackType == Mobile::TrackType::Full) ? full_tracks : radar_tracks;
    auto new_id = point.object_id;
    std::pair<int, Track> new_track(new_id, Track());
    container.insert(new_track);
    container[new_id].appendExistingPoint(point);
    container[new_id].id = new_id;
}

void Mobile::finalizeTrack(uint64_t track_id) {
    std::cout << __func__ <<std::endl;
    auto & container = (trackExist(track_id, full_tracks)) ? full_tracks : radar_tracks;
    container.erase(track_id);
}

bool Mobile::trackExist(uint64_t track_id, UMapTracks_t & container){
    return container.find(track_id) != container.end();
}