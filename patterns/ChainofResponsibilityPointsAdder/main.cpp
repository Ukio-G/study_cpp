#include <iostream>
#include <vector>
#include "Tracks.h"
#include "AddPointHandler.h"


class BaseLinker {
public:
    BaseLinker() = default;
    virtual bool isLinkable(Instant::iTrack & first_track, Instant::iTrack & second_track) = 0;
    virtual ~BaseLinker() = default;
};

class RadarTrackerLinker : public BaseLinker {
public:
    RadarTrackerLinker() = default;
    ~RadarTrackerLinker() override {
    }
    bool isLinkable(Instant::iTrack & radar_track, Instant::iTrack & tracker_track){
        Instant::RadarTrack & radarTrack = (Instant::RadarTrack &)(radar_track);
        Instant::PlateTrack & trackerTrack = (Instant::PlateTrack &)(tracker_track);
        return true;
    }
};

int main() {
    Instant::RadarTrack radarTrack;
    radarTrack.radar_number = "123456789";

    radarTrack.m_points = std::vector<Instant::RadarPoint> {
            Instant::RadarPoint({1,1},2.0),
            Instant::RadarPoint({2,2},2.0),
            Instant::RadarPoint({3,1},2.1),
            Instant::RadarPoint({4,2},2.2),
            Instant::RadarPoint({5,2},2.2)
    };

    Instant::PlateTrack trackerTrack;
    BaseLinker * linker = new RadarTrackerLinker();
    linker->isLinkable( radarTrack, trackerTrack);

    BaseConsistencyHandler radarTrackChecker;
    radarTrackChecker.appendNewHandler(new CoordinateDirectionHandler);
    radarTrackChecker.appendNewHandler(new SpeedDeviationHandler);

    radarTrackChecker.check(&radarTrack, new Instant::RadarPoint({7, 7}, 5));

//    std::cout << (int)radarTrackChecker.check(&radarTrack, new Instant::RadarPoint({6, 6}, 2.63)) << std::endl;
//    std::cout << (int)radarTrackChecker.check(&radarTrack, new Instant::RadarPoint({7, 7}, 5)) << std::endl;

    delete radarTrackChecker.next_handler->next_handler;
    delete radarTrackChecker.next_handler;
    return 0;
}
