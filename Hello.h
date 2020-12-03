#pragma once
#include "includes.h"
#include "Command.h"

class Hello : public Command
{
public:
	Hello()
		: name{ "hello" }
		, Command( "hello" )
	{
	}

	~Hello()
	{

	}

	Errorcode execute()
	{
		utils::print( "Hello there! How are you doing today?" );
		return Errorcode::none;
	}

	std::string explenation()
	{
		return ("[hello]: Prints out a nice hello.");
	}

	void print()
	{
		utils::print(toString());
	}

	std::string toString()
	{
		return name;
	}


private:
	std::string name;
};

