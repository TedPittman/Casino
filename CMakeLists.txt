cmake_minimum_required(VERSION 3.30)
project(CasinoM2OEP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CasinoOEP
        Casino.cpp
        Casino.h
        Blackjack.cpp
        Slotmachine.cpp
        Card.h
        Roulette.cpp
        Roulette.h)

add_executable(TestingCasino
        testing.cpp
        Casino.cpp
        Casino.h
        Blackjack.cpp
        Slotmachine.cpp
        Card.h
        Roulette.cpp
        Roulette.h)