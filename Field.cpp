#include "Field.h"
#include "Ship.h"
#include <iostream>


GameField::GameField(int n) : size(n), field(n, std::vector<ShipSegment*>(n, nullptr)) {
    if (n <= 0) {
        throw std::invalid_argument("Size must be greater than zero.");
    }
}

GameField::~GameField() {
    clearField();
}

GameField::GameField(const GameField& other) : size(other.size), field(other.size, std::vector<ShipSegment*>(other.size, nullptr)) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (other.field[i][j] != nullptr) {
                field[i][j] = new ShipSegment(*other.field[i][j]);
            }
        }
    }
}

GameField& GameField::operator=(const GameField& other) {
    if (this != &other) {
        clearField();

        size = other.size;
        field = std::vector<std::vector<ShipSegment*>>(size, std::vector<ShipSegment*>(size, nullptr));

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (other.field[i][j] != nullptr) {
                    field[i][j] = new ShipSegment(*other.field[i][j]);
                }
            }
        }
    }
    return *this;
}

GameField::GameField(GameField&& other) noexcept
        : size(other.size), field(std::move(other.field)) {
    other.size = 0;
}

GameField& GameField::operator=(GameField&& other) noexcept {
    if (this != &other) {
        clearField();

        size = other.size;
        field = std::move(other.field);

        other.size = 0;
    }
    return *this;
}

bool GameField::placeShip(int x, int y, int length, bool horizontal) {
    if (!canPlaceShip(x, y, length, horizontal)) return false;

    for (int i = 0; i < length; ++i) {
        if (horizontal) {
            field[x][y + i] = new ShipSegment();
        } else {
            field[x + i][y] = new ShipSegment();
        }
    }
    return true;
}

bool GameField::canPlaceShip(int x, int y, int length, bool horizontal) {
    for (int i = 0; i < length; ++i) {
        int newX = x + (horizontal ? 0 : i);
        int newY = y + (horizontal ? i : 0);

        if (newX < 0 || newX >= size || newY < 0 || newY >= size) {
            return false;
        }

        if (field[newX][newY] != nullptr) {
            return false;
        }

        if (!checkAdjacency(newX, newY)) {
            return false;
        }
    }

    return true;
}

bool GameField::checkAdjacency(int x, int y) {
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;

            int newX = x + dx;
            int newY = y + dy;

            if (newX >= 0 && newX < size && newY >= 0 && newY < size) {
                if (field[newX][newY] != nullptr) {
                    return false;
                }
            }
        }
    }
    return true;
}

void GameField::display() const {
    std::cout << "   a b c d e f g h i j" << std::endl;
    for (int i = 0; i < size; ++i) {
        if(i+1!=10){
            std::cout << (i + 1) << "  ";
        }
        else{
            std::cout << (i + 1) << " ";
        }

        for (const auto& cell : field[i]) {
            if (cell == nullptr) {
                std::cout << "* ";
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
}

void GameField::clearField() {
    for (auto& row : field) {
        for (auto& segment : row) {
            delete segment;
        }
    }
}
