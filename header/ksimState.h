/*
 * header/ksimState.h
 *
 * header file for enum STATE.
 *
 */

    /*macros*/
#pragma once

    /*global variables*/
enum STATE_E {
    NEW         = 0,
    READY       = 1,
    RUNNING     = 2,
    BLOCKED_0   = 3,
    BLOCKED_1   = 4,
    BLOCKED_2   = 5,
    BLOCKED_3   = 6,
    EXIT        = 7,
    STATES      = 8,    //total number of process states
};
