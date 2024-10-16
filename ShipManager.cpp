#include "ShipManager.h"

ShipManager::ShipManager(int count, const std::vector<int>& sizes)
        : ships(count)
{
    for (int i = 0; i < count; ++i) {
        ships[i] = new Ship(sizes[i]);
    }
}

ShipManager::~ShipManager() {
    for(auto ship : ships){
        delete ship;
    }
}