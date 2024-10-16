#include "Ship.h"
#include <stdexcept>

Ship::Ship(int length) : segments(length) {}

void Ship::damage(int segmentIndex) {
    if (segmentIndex < 0 || segmentIndex >= segments.size()) {
        throw std::out_of_range("Invalid segment index");
    }
    segments[segmentIndex].applyDamage(1);
}

bool Ship::isSunk() const {
    for (const auto& segment : segments) {
        if (segment.getState() != ShipSegment::SegmentState::Destroyed) {
            return false;
        }
    }
    return true;
}

int Ship::getLength() const {
    return segments.size();
}