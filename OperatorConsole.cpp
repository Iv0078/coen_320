/*
 * OperatorConsole.cpp
 *
 *  Created on: Nov 4, 2024
 *     
 */

#include "OperatorConsole.h"

std::vector<std::string> split_sentence(std::string& sen) {
	std::stringstream ss(sen);
	std::string word;
	std::vector<std::string> words;
	while (ss >> word) {
		words.push_back(word);
	}
	return words;
}




OperatorConsole::OperatorConsole() {
	// TODO Auto-generated constructor stub

}

OperatorConsole::~OperatorConsole() {
	// TODO Auto-generated destructor stub
}

std::vector<int> OperatorConsole::operatorCommand()
{
	std::cout << "\nEnter command you would like to execute: " << std::endl;
	std::string user_input;
	getline(std::cin, user_input);
	std::vector<std::string> words= split_sentence(user_input);
	std::vector<int> command{};
	if (words.at(0) == "print") {
		if (words.at(1) == "all") {
			command.push_back(0);

		}
		else {
			command.push_back(1);
			command.push_back(std::stoi(words.at(1)));
		}

	}
	else if (words.at(0) == "change") {
		command.push_back(2);
		for (int i{ 1 }; i < words.size(); i++) {
			command.push_back(std::stoi(words.at(i)));
		}
	}
	else {
		std::cout << "ERROR 404 NOT FOUND! INCORRECT COMMAND GIVEN" << std::endl;
	}


	if (command.size() == 0) {
		command.push_back(-1);
	}
	return command;
}

