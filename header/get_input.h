/*
 * ksim/header/get_input.h
 * cs-240.wilder..........g++ -std=c++11..........jenna-luz pura
 * december 4, 2022.......pura0273@vandals.uidaho.edu
 *
 * header file for get_input() function in ../source/get_input.cpp.
 *
 * prints the user prompt, reads in user commands, and stores it in buffer.
 */

#pragma once

#include <string>   //std::string

void get_input(int ticks, std::string &buffer);
