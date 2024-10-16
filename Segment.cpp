#include "Segment.h"

ShipSegment::ShipSegment() : state(SegmentState::Empty), damage(0) {}

void ShipSegment::applyDamage(int damage) {
    this->damage += damage;
    if (this->damage >= 1) {
        state = SegmentState::Damaged;
    }
}

ShipSegment::SegmentState ShipSegment::getState() const {
    return state;
}