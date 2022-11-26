/*
 * header/get_input.h
 *
 * header file for get_input() function in source/get_input.cpp.
 * prints the user prompt, reads in user commands, and stores it in buffer.
 */

#pragma once

#include <string>   //std::string

void get_input(int ticks, std::string &buffer);
