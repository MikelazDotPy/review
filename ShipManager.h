#ifndef SHIPMANAGER_H
#define SHIPMANAGER_H

#include <vector>
#include "Ship.h"

class ShipManager {
public:
    ShipManager(int count, const std::vector<int>& sizes);
    ~ShipManager();

private:
    std::vector<Ship*> ships;
};

#endif // SHIPMANAGER_H