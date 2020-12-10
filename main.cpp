#include "includes.h" // A library of the most used includes
#include "CommandList.h" // A library with all the commands
#include "Command.h" // The Command Library used for making commands
#include "CLI.h" // The CLI (Command line interface) library


int main()
{
    std::string username{ "Yannick" };
    CLI::CLI* cli{ new CLI::CLI{ username } };
    std::vector<CLI::procces*> processlist{};

    cli->printCommands();
    std::cout << "CLI initiated" << std::endl;

    // start Cli
    cli->start();
    // Running loop
    bool running{ true };
    while (running)
    {
        running = cli->run();
    }
    utils::printNewLine(); // print out a new line
    // Print out the history of all commands used
    cli->printHistory();
    // Closing program
    cli->end();

    File fl{ "fl.txt", "Output/" };

    if (fl.isWritable())
    {
        fl.write("The first line of the file is here.");
        fl.append("This is the second line of the file");
    }

    // signal a non problematic run of the program
    return 0;
}
