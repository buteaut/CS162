/*********************************************************************************
** Program name: Data Validation Utilities (integerValidation Header File)
** Author: Thomas Buteau
** Date: 2-12-17
** Description: dataValidation header file. Series of functions to handle data 
**				validation which either return true/false or the desired data.
**
**				Originally written for Project 1 in CS162 on 1-21-17
*********************************************************************************/

#ifndef DATAVALIDATION_HPP
#define DATAVALIDATION_HPP

#include <string>
#include <math.h>
#include <iostream>

bool intVal(std::string input, int length);

int valInt(int length); 

bool intValPos(std::string input, int length);

int valIntPos(int length); 

bool intValPos(std::string input, int length, int min, int max);

int valIntPos(int length, int min, int max); 

bool doubleVal(std::string input, int length);

double valDouble(int length);

bool doubleValPos(std::string input, int length);

double valDoublePos(int length);

bool doubleValPos(std::string input, int length, double min, double max);

double valDoublePos(int length, double min, double max);

#endif
