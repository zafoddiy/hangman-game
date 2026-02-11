/**
 * File:        wordConstruct.cpp
 * Author:      zafoddiy
 * Created:     11.02.2026
 * Last edit:   12.02.2026
 *
 * Description: wordConstruct class contructor and method definitions.
 */

#include "wordConstruct.hpp"
#include <random>

wordConstruct::wordConstruct()
{
    alphabet = "abcdefghijklmnopqrstuvwxyz";
    filePath = "words.txt";
}

/**
 * Method:         assignFromList
 *
 * Description:    Assigns a word at a randomly given line in the words text file.
 *
 * Parameters:     None
 *
 * Return:         string, outputs a word from word list file.
 */
std::string wordConstruct::assignFromList()
{
    std::string chosenWord;

    int randomWordRow = generateRandomRow();
    wordList.open(filePath);
    if (wordList.fail())
    {
        std::cout << "Failed to open word list file." << std::endl;
        exit(1);
    }
    for (int i = 1; i < randomWordRow; i++)
    {
        std::getline(wordList, chosenWord);
    }
    wordList.close();
    return chosenWord;
}

/**
 * Method:         generateRandomRow
 *
 * Description:    Assigns a random number between 1 and the number of rows in word list file.
 *
 * Parameters:     None
 *
 * Return:         int, number assigned from random generator
 */
int wordConstruct::generateRandomRow()
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> dist(1, findRowAmount());
    int randomNum = dist(generator);
    return randomNum;
}

/**
 * Method:         findRowAmount
 *
 * Description:    Finds the number of words in the word list file.
 *
 * Parameters:     None
 *
 * Return:         int, number of lines in word list file.
 */
int wordConstruct::findRowAmount()
{
    int numberOfLines = 0;
    std::string line;
    wordList.open(filePath);
    if (wordList.fail())
    {
        std::cout << "Failed to open word list file." << std::endl;
        exit(1);
    }
    while (std::getline(wordList, line))
    {
        numberOfLines++;
    }
    wordList.close();
    return numberOfLines;
}