#ifndef SHIP_H
#define SHIP_H

#include <vector>
#include "Segment.h"

class Ship {
public:
    Ship(int length);
    void damage(int segmentIndex);
    bool isSunk() const;
    int getLength() const;

private:
    std::vector<ShipSegment> segments;
};

#endif // SHIP_H