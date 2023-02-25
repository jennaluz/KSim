/*
 * /home/pura0273/homework/04/header/tokenize.h
 * cs-240.wilder..........g++ -std=c++11..........jenna-luz pura
 * december 4, 2022.......pura0273@vandals.uidaho.edu
 *
 * header file for tokenize() function in ../source/tokenize.h.
 *
 * parses buffer and store tokenized arguments into bufferArgv vector.
 */

#pragma once

#include <string>   //std::string
#include <vector>   //std::vector

void tokenize(std::string buffer, std::vector<std::string> &bufferArgv, int &bufferArgc);
