/*
 * source/ksimProcessNode.cpp
 *
 * methods for processNode class.
 *
 */

    /*system-defined includes*/
#include <string>   //std::string
#include <iostream> //std::cout     std::endl

    /*user-defined includes*/
#include "../header/ksimTreeNode.h"
#include "../header/ksimProcess.h"

    /*method defines*/
//constructor
node::node(process *newProcess)
{
    processName = newProcess -> name;
    pcb = newProcess;
    leftChild = NULL;
    rightChild = NULL;
    leftLevels = 0;
    rightLevels = 0;
}

bool node::find(std::string processName)
{
        //check if this node's processName is equal to processName that wishes to be added
    if (this -> processName == processName) {
        return true;
    }

    bool existsLeft = false;
    bool existsRight = false;

    if (leftChild != NULL) {
        existsLeft = leftChild -> find(processName);
    }

    if (rightChild != NULL) {
        existsRight = rightChild -> find(processName);
    }

    return (existsLeft || existsRight);
}

//
int node::add(process *newProcess)
{
    bool lessThan = (newProcess -> name) < (this -> processName);

    if (lessThan == true) {
        if (leftChild == NULL) {
            leftChild = new node(newProcess);

            if (rightChild == NULL) {
                leftLevels++;
                return 1;
            }

            return 0;
        }

        leftLevels += leftChild -> add(newProcess);
        return leftLevels;
    }

    if (rightChild == NULL) {
        rightChild = new node(newProcess);

        if (leftChild == NULL) {
            rightLevels++;
            return 1;
        }

        return 0;
    }

    rightLevels += rightChild -> add(newProcess);
    return rightLevels;
}

void node::print()
{
    std::cout << "left levels: " << this -> leftLevels << std::endl;
    std::cout << "right levels: " << this -> rightLevels << std::endl;

    return;
}
