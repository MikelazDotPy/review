#include "Manager.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>

GameManager::GameManager(int size) : gameField(size) {}

void GameManager::startGame() {
    try {
        int x, y, length;
        int count_quantity = 1;
        int count_single_deck = 0;
        int count_double_deck = 0;
        int count_three_deck = 0;
        int count_four_deck = 0;
        bool direction;

        while (count_quantity != 11) {
            std::cout << "Введите координаты и направление для размещения корабля " << count_quantity << " (x y length direction): ";
            std::cin >> x >> y >> length >> direction;

            if (x >= 1 && x <= 10 && y >= 1 && y <= 10) {
                if (length == 1 && count_single_deck != 4) {

                    if (!gameField.placeShip(y - 1, x - 1, length, direction)) {
                        std::cout << "Вы ввели координаты,которые противоречат правилам игры. "
                                     "Напоминание: между соседними кораблями должно быть одна клетка со всех сторон" << std::endl;
                    } else {
                        count_single_deck++;
                        count_quantity++;
                    }
                } else if (length == 2 && count_double_deck != 3) {

                    if (!gameField.placeShip(y - 1, x - 1, length, direction)) {
                        std::cout << "Вы ввели координаты,которые противоречат правилам игры. "
                                     "Напоминание: между соседними кораблями должно быть одна клетка со всех сторон" << std::endl;
                    } else {
                        count_double_deck++;
                        count_quantity++;
                    }
                } else if (length == 3 && count_three_deck != 2) {

                    if (!gameField.placeShip(y - 1, x - 1, length, direction)) {
                        std::cout << "Вы ввели координаты,которые противоречат правилам игры. "
                                     "Напоминание: между соседними кораблями должно быть одна клетка со всех сторон" << std::endl;
                    } else {
                        count_three_deck++;
                        count_quantity++;
                    }
                } else if (length == 4 && count_four_deck != 1) {

                    if (!gameField.placeShip(y - 1, x - 1, length, direction)) {
                        std::cout << "Вы ввели координаты,которые противоречат правилам игры. "
                                     "Напоминание: между соседними кораблями должно быть одна клетка со всех сторон" << std::endl;
                    } else {
                        count_four_deck++;
                        count_quantity++;
                    }
                } else {
                    std::cout << "Вы превысили количество кораблей одного типа" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            } else {
                std::cout << "Вы вышли за пределы поля" << std::endl;
            }
        }

    } catch (const std::exception& e) {
        std::cout << "Ошибка размещения корабля" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        startGame();
    }
}

void GameManager::createEnemyField() {
    GameField enemyField(10);
    srand(time(0));
    std::vector<int> shipLengths = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
    for (int length : shipLengths) {
        int x, y;
        bool direction;
        do {
            x = rand() % 10;
            y = rand() % 10;
            direction = rand() % 2 == 0;
        } while (!enemyField.canPlaceShip(x, y, length, direction));
        enemyField.placeShip(x, y, length, direction);
    }

    std::cout << "Enemy Field:" << std::endl;
    enemyField.display();
}

void GameManager::displayField() const {
    gameField.display();
}