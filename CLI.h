#pragma once
#include "includes.h"
#include "CommandList.h"
#include "History.h"

#include <algorithm>
#include <cctype>
#include <sstream>


namespace CLI
{
	class procces; // Forward declaration

	class CLI
	{
	public:
		CLI(std::string user)
			: user{ user }
			, preline{ "" }
			, postline{ "" }
			, inputLine{ user + " >> " }
			, outputLine{ "Console >> " }
			, exit{ "exit" }
			, history{}
			, commands{}
			, listOfCommands{}
		{
			listOfCommands.push_back(&commands.echo);
			listOfCommands.push_back(&commands.hello);

		}
		~CLI()
		{
			delete[] & history;
			delete[] & processes;
		}
  
		// * Starts the Cli, prints important information
		void start()
		{
			utils::print("To exit CLI enter: [" + exit + "]");
		}

		// * Try to run the given imput, returns a string depending on the command that was found
		Errorcode runCommand(std::vector<std::string> CommandList)
		{
			if (utils::compareBool(CommandList[0], commands.echo.getName()))
			{
				history.push(commands.echo.getName());
				return commands.echo.execute(CommandList);
			}
			else if (utils::compareBool(CommandList[0], commands.hello.getName()))
			{
				history.push(commands.hello.getName());
				return commands.hello.execute();
			}
			else if (utils::compareBool(CommandList[0], "error"))
			{
				history.push("error");
				return Errorcode::error;
			}
			else
			{
				std::string notFound{ "no command found, input: [" + CommandList[0] + "]" };
				history.push(notFound);
				utils::print(notFound);
				return Errorcode::none;
			}
		}

		// * Stops the Cli, prints out some information at the end
		void end()
		{
			// Closing program
			std::cout << std::endl;
			std::cout << "Closing CLI..." << std::endl;
		}

		std::vector<std::string> getCommandsList(std::string input)
		{
			// Puts the input line into lowercase
			std::transform(input.begin(), input.end(), input.begin(),
				[](unsigned char c) { return std::tolower(c); });

			std::stringstream stringStream(input);
			std::string segment;
			std::vector<std::string> list;
			char delimiter{' '};

			while (std::getline(stringStream, segment, delimiter))
			{
				list.push_back(segment);
			}

			// utils::printList(list);

			return list;
		}

		// * Used in a loop, returns false if the exit statement is reached, else returns true
		bool run()
		{
			toConsole(inputLine);
			std::getline(std::cin, input);

			std::vector<std::string> list{getCommandsList(input)};

			if (list.size() != 0) // check if there is any input else return true
			{
				if (utils::compareBool(list[0], exit))
				{
					history.push(exit);
					return false;
				}
				else
				{
					Errorcode err = runCommand(list);
					if (err != Errorcode::none)
					{
						utils::printError("Error while running code");
					}
					return true;
				}
			}
			else
			{
				return true;
			}
		}

		// * Start a new process
		std::string startProcess()
		{

		}

		// * Print out the history of the commands used
		void printHistory()
		{
			utils::print("Printing history: ");
			utils::printList(history.getList());
		}

		Commandlist commands; // A list of all commands
		std::vector<Command*> listOfCommands{};

		void printCommands()
		{
			utils::print("List of all commands: ");
			utils::printList(listOfCommands);
		}

	private:
		std::string user; // used for the name of the user
		std::string preline; // used to put something before every line
		std::string postline; // used to put something after every line

		std::string inputLine;  // used to show text for input
		std::string outputLine; // used to show text for output
		std::string input{};  // the input string
		std::string output{}; // the output string

		std::string exit; // Change this to change how you exit the Cli

		std::vector<procces*> processes{}; // A list of all processes

		History history; // The history of the commands

		// * Puts something on the console with the pre- & post-line
		void toConsole(std::string text, bool newline = false)
		{
			std::cout << preline << text << postline;
			if (newline)
			{
				std::cout << std::endl;
			}
		}

	};

	class procces
	{
	public:
		procces(std::string name)
			: name{ name }
		{

		}

		~procces()
		{

		}

		// * Return it's name
		std::string getName()
		{
			return name;
		}

		// * Execute this process
		std::string execute()
		{
			return getName();
		}

	private:
		std::string name{};
	};

}