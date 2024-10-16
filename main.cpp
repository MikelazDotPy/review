#include "Manager.h"
#include <iostream>


int main() {
    GameManager gameManager(10);
    gameManager.startGame();
    gameManager.displayField();
    gameManager.createEnemyField();
    return 0;
}


