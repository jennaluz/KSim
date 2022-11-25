/*
 * header/ksimTreeNode.h
 *
 * header file for ksimTreeNode.cpp.
 *
 */

    /*macros*/
#pragma once

    /*system-defined includes*/
#include <string>   //std::string

    /*user-defined includes*/
#include "ksimProcess.h"

    /*struct define*/
struct node {
        //data members
    std::string processName;
    process *pcb;
    node *leftChild;
    node *rightChild;
    int leftLevels;
    int rightLevels;
        //constructor
    node (process *newProcess);
        //destructor

        //methods
    bool find(std::string processName);
    int add(process *newProcess);
    void print();
};
