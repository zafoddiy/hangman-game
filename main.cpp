/**
 * File:        main.cpp
 * Author:      zafoddiy
 * Created:     26.11.2024
 * Last edit:   12.02.2026
 *
 * Description: Hangman game main source file. Reads user input
 * 				and compares against a chosen word from a text file. Error
 * 				handling to ensure the input is a singular character within
 * 				the alphabet.
 */

#include "wordConstruct.hpp"

/**
 * Function:       UserInsert
 *
 * Description:    Reads a line from user, converts to a character, and checks for errors.
 * 				   Checking if user input is one character, outside the alphabet and if
 * 				   the letter has already been guessed. Converts capital case to lower case.
 *
 * Parameters:     alphabet - string, holds all of the alphabet characters
 *
 * Return:         char, outputs the singular character from user, if correct.
 */
char UserInsert(std::string alphabet)
{
	std::string newUserInput;
	char convertedInput;
	std::string infoMessage = "Enter a single character!";
	do
	{
		std::cout << infoMessage << std::endl;
		std::cin >> newUserInput;
		convertedInput = (char)tolower(newUserInput.front());
		if (newUserInput.size() != 1)
		{
			infoMessage = "Enter a single character!";
		}
		else if ((convertedInput < 'a' || convertedInput > 'z'))
		{
			infoMessage = "Enter a character from a to z in the English alphabet!";
		}
		else if (alphabet.find(convertedInput) == std::string::npos)
		{
			infoMessage = "You've already entered that character!";
		}
	} while ((newUserInput.size() != 1) || (convertedInput < 'a' || convertedInput > 'z') || 
	(alphabet.find(convertedInput) == std::string::npos && (convertedInput >= 'a' && convertedInput <= 'z')));
	return convertedInput;
}

/**
 * Function:       Solving
 *
 * Description:    Game logic, checks if user input is correct for chosen word.
 *
 * Parameters:     alphabet - string, holds all of the alphabet characters
 * 				   initialWord - string, initial word chosen from the text file
 * 				   toSolve - 
 *
 * Return:         char, outputs the singular character from user, if correct.
 */
void Solving(std::string alphabet, std::string initialWord)
{
	std::cout << "Let's play hangman!" << std::endl;
	char userInput;
	std::string toSolve = initialWord;
	toSolve.replace(0, toSolve.size(), toSolve.size(), '_');
	int tries = 8;
	do
	{
		std::cout << toSolve << std::endl;
		std::cout << alphabet << std::endl;
		std::cout << "You have " << tries << " tries." << std::endl;
		if (initialWord.compare(toSolve) == 0)
		{
			break;
		}
		userInput = UserInsert(alphabet);
		if (initialWord.find(userInput) == std::string::npos)
		{
			std::cout << "Wrong!" << std::endl;
			std::size_t alphabetLoc = alphabet.find(userInput);
			alphabet[alphabetLoc] = ' ';
			tries--;
		}
		else
		{
			std::size_t alphabetLoc = alphabet.find_first_of(userInput);
			alphabet[alphabetLoc] = ' ';
			std::size_t inputLoc = initialWord.find(userInput);
			while (inputLoc != std::string::npos)
			{
				toSolve[inputLoc] = userInput;
				inputLoc = initialWord.find(userInput, inputLoc + 1);
			}
		}
	} while (tries > 0);
	if (tries == 0)
	{
		std::cout << "Failure. The word was " << initialWord << std::endl;
	}
	else
	{
		std::cout << initialWord << std::endl << "Well done!" << std::endl;
	}
}


int main(void)
{
	wordConstruct words;
	std::string answer = "y";
	do {
		std::string word = words.assignFromList();
		std::string alphabet = words.alphabet;
		Solving(alphabet, word);
		std::cout << "Play again? (y/n)" << std::endl;
		do {
			std::cin >> answer;
			if (answer[0] != 'y' && answer[0] != 'n')
			{
				std::cout << "Enter y or n!" << std::endl;
			}
		} while (answer[0] != 'y' && answer[0] != 'n');
	} while (answer[0] == 'y');
	return 0;
}