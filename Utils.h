#pragma once
#include "includes.h"
#include "Command.h"
#include <fstream>

namespace utils
{
	// Prints out a new line on the console
	void printNewLine()
	{
		std::cout << std::endl;
	}

	// Output something to the console, standard with newline, set newLine to false to not have a newline
	void print(std::string text, bool newLine = true)
	{
		std::cout << text;
		if (newLine)
		{
			printNewLine();
		}
	}

	// Compare 2 strings, return true if both are equall, else returns false
	bool compareBool(std::string first, std::string second)
	{
		if (first.compare(second) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// Prints an item of a list at the index
	void printItem(std::vector<Command*> list, int index)
	{
		print(list[index]->toString());
	}

	// Returns the string of an item at a given index
	std::string returnItemString(const std::vector<Command*>* list, int index)
	{
		return (list->at(index)->toString());
	}

	// Returns a pointer of an item given a list and its index
	Command* returnItemPointer(const std::vector<Command*>* list, int index)
	{
		return (list->at(index));
	}

	// returns a string of a specified index of a list
	std::string returnItemString(const std::vector<std::string> list, int index)
	{
		return (list.at(index));
	}

	// prints out a given Command pointer list
	void printList(std::vector<Command*> list)
	{
		for (unsigned int index{ 0 }; index < list.size(); ++index)
		{
			std::string line{};
			std::string strIndex{ std::to_string(index) };
			line += "[";
			line += strIndex;
			line += "] : ";
			line += returnItemString(&list, index);
			print(line);
		}
	}

	// prints out a given string list
	void printList(std::vector<std::string> list)
	{
		for (unsigned int index{ 0 }; index < list.size(); ++index)
		{
			std::string line{};
			std::string strIndex{ std::to_string(index) };
			line += "[";
			line += strIndex;
			line += "] : ";
			line += returnItemString(list, index);
			print(line);
		}
	}

	// Print out an error
	void printError(std::string text)
	{
		print("ERROR: ", false);
		print(text);
	}

	// Write specified text to a file
	void writeToFile(std::string filename, std::string text, bool newline = true)
	{
		std::ofstream myfile{};
		utils::print("Writing to file: " + filename + ": " + text);
		myfile.open(filename);
		myfile << text;
		if (newline) myfile << "\n";
		myfile.close();
	}

	// Print the content of a file
	void printFile(std::string filename)
	{
		std::string line;
		std::ifstream myfile(filename);
		if (myfile.is_open())
		{
			print("Opening file with filename: " + filename);
			while (getline(myfile, line))
			{
				print("\t" + line);
			}
			myfile.close();
			print("End of file");
		}
		else
		{
			print("Unable to open file with name: " + filename);
		}
	}

	// Add text to a specified file
	void appendToFile(std::string filename, std::string text)
	{
		std::fstream myfile{ filename, std::ios::app };
		std::string line{};
		utils::print("Appending to file: " + filename + ": " + text);

		myfile << text;
		myfile.close();
	}

	// Give a vector of strings with the content of a given filename
	std::vector<std::string> readFile(std::string filename)
	{
		std::fstream myfile{filename};
		std::string line{};
		std::vector<std::string> fileContent{};

		if (myfile.is_open())
		{
			while (std::getline(myfile, line))
			{
				fileContent.push_back(line);
			}
		}
		myfile.close();
		return fileContent;
	}

}