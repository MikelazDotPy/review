#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <vector>
#include "Segment.h"

class GameField {
public:
    GameField(int n);
    ~GameField();

    GameField(const GameField& other);
    GameField& operator=(const GameField& other);

    GameField(GameField&& other) noexcept;
    GameField& operator=(GameField&& other) noexcept;

    bool placeShip(int x, int y, int length, bool horizontal);
    bool canPlaceShip(int x, int y, int length, bool horizontal);

    void display() const;

private:
    int size;
    std::vector<std::vector<ShipSegment*>> field;

    bool checkAdjacency(int x, int y);
    void clearField();
};

#endif // GAMEFIELD_H