/*
 * OperatorConsole.h
 *
 *  Created on: Nov 4, 2024
 *     
 */

#ifndef OPERATORCONSOLE_H_
#define OPERATORCONSOLE_H_

#include <vector>
#include <iostream>
#include <string>
#include <sstream>

class OperatorConsole {
public:
	OperatorConsole();
	virtual ~OperatorConsole();
	std::vector<int> operatorCommand();
};

#endif /* OPERATORCONSOLE_H_ */
