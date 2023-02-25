/*
 * ksim/header/state.h
 * cs-240.wilder..........g++ -std=c++11..........jenna-luz pura
 * december 4, 2022.......pura0273@vandals.uidaho.edu
 *
 * header file for State_e enumeration.
 *
 * used in Dispatcher_t when initializing stateQueue[].
 * each enumeration corresponds to a state that a Process_t object can take on.
 */

#pragma once

enum State_e {
    NEW         = 0,
    READY       = 1,
    RUNNING     = 2,
    BLOCKED_0   = 3,
    BLOCKED_1   = 4,
    BLOCKED_2   = 5,
    BLOCKED_3   = 6,
    EXIT        = 7,
    STATES      = 8
};
