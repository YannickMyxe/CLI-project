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

	Errorcode execute(std::vector<std::string> commands, bool purePrint = false)
	{
		std::string output{};
		if (!purePrint)
		{
			output.append("Echo: ");
		}

		if (commands.size() < 2)
			commands.push_back("");

		for (int index{1}; index < commands.size(); ++index)
		{
			output.append(commands[index]);
		}
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

