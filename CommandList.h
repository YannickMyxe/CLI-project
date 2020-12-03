#pragma once
/// A library containing all commands
///
///

#include "Echo.h" // The echo command library
#include "Hello.h"

class Commandlist
{
public:
	Commandlist()
	{

	}
	~Commandlist()
	{

	}

	Echo echo{};
	Hello hello{};

private:

};