/*
 * header/state.h
 *
 * header file for State_e enumeration.
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
