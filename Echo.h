#pragma once
#include "includes.h"

#include "Command.h"

class Echo: public Command
{
public:
	Echo() 
		: name{"echo"}
		, Command("echo")
	{
	}

	~Echo()
	{

	}

	Errorcode execute(std::string text, bool purePrint = false)
	{
		std::string output{};
		if (!purePrint)
		{
			output.append("Echo: ");
		}
		output.append(text);
		utils::print(output);
		return Errorcode::none;
	}

	std::string explenation()
	{
		return ("[" + toString() + "]: Prints out the given arguement, use true to remove the echo in front");
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

