#pragma once
#include "includes.h"
#include "CommandList.h"
#include "History.h"

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
		{

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
		std::string runCommand(std::string input)
		{
			if (utils::compareBool(input, commands.echo.getName()))
			{
				history.push(commands.echo.getName());
				return commands.echo.execute(input);
			}
			else if (utils::compareBool(input, commands.hello.getName()))
			{
				history.push(commands.hello.getName());
				return commands.hello.execute();
			}
			else
			{
				history.push("no command found, input: [" + input + "]");
				return "No command found: [" + input + "];";
			}
		}

		// * Stops the Cli, prints out some information at the end
		void end()
		{
			// Closing program
			std::cout << std::endl;
			std::cout << "Closing CLI..." << std::endl;
		}

		// * Used in a loop, returns false if the exit statement is reached, else returns true
		bool run()
		{
			toConsole(inputLine);
			std::getline(std::cin, input);

			if (utils::compareBool(input, exit))
			{
				history.push(exit);
				return false;
			}
			else
			{
				output = runCommand(input);
				utils::print(outputLine, false);
				utils::print(output);

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