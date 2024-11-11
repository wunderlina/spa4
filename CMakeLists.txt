cmake_minimum_required(VERSION 3.29)
project(temp)

set(CMAKE_CXX_STANDARD 20)

add_executable(temp main.cpp
        Game.cpp
        Game.h
        Room.h
        Room.cpp
        Player.cpp
        Player.cpp
        BlasterRoom.cpp
        AmbushRoom.h
        LakeRoom.h
        LightsaberRoom.h
        WampaRoom.h
        AmbushRoom.cpp
        WampaRoom.cpp
        LightsaberRoom.cpp
        LakeRoom.cpp
        TauntaunRoom.cpp
        DefaultRoom.cpp)
