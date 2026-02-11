// wordconstruct.hpp: 
#ifndef WORDCONSTRUCT_H
#define WORDCONSTRUCT_H

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cstddef>


class wordConstruct {
public:
	wordConstruct();
	std::string alphabet;
	std::string assignFromList();

private:
	std::ifstream wordList;
	std::string filePath;
	int generateRandomRow();
	int findRowAmount();
};

char UserInsert(std::string);
std::string InputErrorAlphabet();
std::string InputErrorExisting(std::string);
void Solving(std::string, std::string);

#endif
