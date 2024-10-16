cmake_minimum_required(VERSION 3.27)
project(BattleShip)

set(CMAKE_CXX_STANDARD 17)

add_executable(BattleShip main.cpp
        Ship.h
        Field.h
        Manager.h
        Segment.h
        Segment.cpp
        Ship.cpp
        Field.cpp
        Manager.cpp
        ShipManager.h
        ShipManager.cpp)
