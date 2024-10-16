#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Field.h"

class GameManager {
public:
    GameManager(int size);
    void startGame();
    void createEnemyField();
    void displayField() const;

private:
    GameField gameField;
};

#endif // GAMEMANAGER_H