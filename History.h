#pragma once
#include "includes.h"
#include "Command.h"

class History
{
public:
	History()
		: historyList{}
	{

	}

	~History()
	{
		delete[] &historyList;
	}

	void undo()
	{
		historyList.pop_back();
	}

	void push(std::string command)
	{
		historyList.push_back(command);
	}

	std::vector<std::string> getList()
	{
		return historyList;
	}

	void clear()
	{
		for (unsigned int index{ 0 }; index < historyList.size(); ++index)
		{
			undo();
		}
	}


private:
	std::vector<std::string> historyList;

};
