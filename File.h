#pragma once
#include "includes.h"

class File
{
public:
	File(std::string filename, std::string storageLocation, bool readonly = false)
		: filename{ filename }
		, storageLocation{ storageLocation }
		, readonly{ readonly }
		, fileLocation { storageLocation + filename}
		, fileBackup{ read() }
	{
	}

	~File()
	{

	}

	// Checks if you can write to the file
	bool isWritable()
	{
		return !readonly;
	}

	// Write some text to a file, clears the whole file
	void write(std::string text)
	{
		if(isWritable())
			utils::writeToFile(fileLocation, text);
	}

	// Write a list of strings to a file
	void write(std::vector<std::string> stringList)
	{
		for (unsigned int index{}; index < stringList.size(); ++index)
		{
			write(stringList[index]);
		}
	}

	// Append a string to a file
	void append(std::string text)
	{
		if(isWritable())
			utils::appendToFile(fileLocation, text);
	}

	// Append a list of strings to a file
	void append(std::vector<std::string> stringList)
	{
		for (unsigned int index{}; index < stringList.size(); ++index)
		{
			append(stringList[index]);
		}
	}

	// Give a list of the read file
	std::vector<std::string> read()
	{
		return utils::readFile(fileLocation);
	}

	// Return the file to its original text when the constructor was called
	void revertToOrigin()
	{
		write(fileBackup);
	}

	// Print out the whole document
	void print()
	{
		utils::printList(read());
	}

	// Print out a specified index of a file
	void print(unsigned int index)
	{
		std::vector<std::string> fileContent{read()};
		if (fileContent.size() > index)
			utils::print(read().at(index));
		else
			utils::print("Index out of bounds");
	}

	// Same as the print function with a index
	void printItem(unsigned int index)
	{
		print(index);
	}

	// Print a file from a starting index to a end index
	void print(unsigned int start, unsigned int end)
	{
		std::vector<std::string> fileContent{ read() };
		if (start < end)
			if (fileContent.size() > end)
				for (unsigned int index{ start }; index < end; ++index)
					utils::print(fileContent[index]);
			else
				utils::print("End index out of bounds.");
		else
			utils::print("Start index must be smaller than the End index.");
	}

	// Return a list of the file
	std::vector<std::string> getList()
	{
		return read();
	}

private:
	std::string filename;
	std::string storageLocation;
	bool readonly;
	std::string fileLocation;
	std::vector<std::string> fileBackup; // Used for backups
};