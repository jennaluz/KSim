/*
 * source/ksimTree.cpp
 *
 * methods for tree class.
 *
 */

    /*user-defined includes*/
#include "../header/ksimTree.h"
#include "../header/ksimProcess.h"

    /*method defines*/
//constructor
tree::tree()
{
    root = NULL;
}

bool tree::find(std::string processName)
{
    if (root == NULL) {
        return false;
    }

    return root -> find(processName);
}

//
void tree::add(process *newProcess)
{
    if (root == NULL) {
        root = new node(newProcess);
        return;
    }

    root -> add(newProcess);
}

void tree::print()
{
    root -> print();
    return;
}
