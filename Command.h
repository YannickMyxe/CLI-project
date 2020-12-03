#pragma once
#include "includes.h"

// Do not use utils in here: utils imports this library

class Command
{
public:
	Command(std::string name)
		: name{ name }
	{
	}

	~Command()
	{
	}

	std::string getName()
	{
		return name;
	}

	virtual std::string execute()
	{
		return "Command execute of " + getName();
	}

	virtual std::string explenation()
	{
		return ("Prints out the explenation of a command");
	}

	virtual void print()
	{
		std::cout << toString() << std::endl;
	}

	virtual std::string toString()
	{
		return "command";
	}

private:
	std::string name;
};