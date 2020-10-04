//
// Created by ukio on 29.09.2020.
//

#ifndef CHAINOFRESPONSIBILITYPOINTSADDER_BASICS_H
#define CHAINOFRESPONSIBILITYPOINTSADDER_BASICS_H

enum MovementDirection {Forward, Backward, Undefined};

struct Point {
public:
    int x;
    int y;
};

struct Rectangle : Point{
public:
    int width;
    int height;
};

#endif //CHAINOFRESPONSIBILITYPOINTSADDER_BASICS_H
