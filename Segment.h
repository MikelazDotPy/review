//
// Created by Софья Титкова on 08.10.2024.
//

#ifndef SHIPSEGMENT_H
#define SHIPSEGMENT_H

class Ship;

class ShipSegment {
public:
    enum class SegmentState {
        Empty,
        Whole,
        Damaged,
        Destroyed
    };

    ShipSegment();
    void applyDamage(int damage);
    SegmentState getState() const;
    void setShip(Ship* ship);

private:
    SegmentState state;
    int damage;
};

#endif // SHIPSEGMENT_H
