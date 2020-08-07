#include <iostream>
#include <vector>
#include "Track.h"
#include "Mobile.h"

void processFrame_1(Mobile & m)
{
    std::cout << __func__ <<std::endl;
    Point p1_2(0,0,1);  p1_2.type = Point::Type::Radar;
    std::vector<Point> frame_1 = {p1_2};
    m.processing(frame_1);
    frame_1.erase(frame_1.begin());
}


void processFrame_2(Mobile & m)
{
    std::cout << __func__ <<std::endl;
    Point p2_2(1,1,1);  p2_2.type = Point::Type::Radar;
    std::vector<Point> frame_2({p2_2});
    m.processing(frame_2);
    frame_2.erase(frame_2.begin());
}

void processFrame_3(Mobile & m)
{
    std::cout << __func__ <<std::endl;
    Point p3_2(2,2,1);  p3_2.type = Point::Type::Number;
    std::vector<Point> frame_3({p3_2});
    m.processing(frame_3);
    frame_3.erase(frame_3.begin());
}

int main() {
    std::cout << "START" << std::endl;

    auto module = Mobile();

    processFrame_1(module);
    processFrame_2(module);
    processFrame_3(module);

    module.finalizeTrack(1);

    std::cout << "END" << std::endl;
    return 0;
}
