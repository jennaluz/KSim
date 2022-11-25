/*
 * header/ksimTree.h
 *
 * header file for ksimTree.cpp.
 *
 */

    /*macros*/
#pragma once

    /*system-defined includes*/
#include <string>

    /*user-defined includes*/
#include "ksimTreeNode.h"
#include "ksimProcess.h"

    /*class define*/
struct tree {
    node *root;
        //constructor
    tree();
        //methods
    bool find(std::string processName);
    void add(process *newProcess);
    void print();
};
