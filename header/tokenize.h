/*
 * header/tokenize.h
 *
 * header file for tokenize() function in source/tokenize.h.
 * parses buffer and store tokenized arguments into bufferArgv vector.
 */

#pragma once

#include <string>   //std::string
#include <vector>   //std::vector

void tokenize(std::string buffer, std::vector<std::string> &bufferArgv, int &bufferArgc);
