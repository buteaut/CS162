/*********************************************************************************
** Program name: Lab 3 (integerValidation Header File)
** Author: Thomas Buteau
** Date: 1-29-17
** Description: IntegerValidation header file for project1. Validates the input 
**				as an integer and returns true or false.
**
**				Originally written for Project 1 in CS162 on 1-21-17
*********************************************************************************/

#ifndef INTEGERVALIDATION_HPP
#define INTEGERVALIDATION_HPP

#include <string>


bool intVal(std::string input, int length);

bool intValPos(std::string input, int length);

bool intValPosRanged(std::string input, int length, int min, int max);

#endif