#include "includes.h" // A library of the most used includes
#include "CommandList.h" // A library with all the commands
#include "Command.h" // The Command Library used for making commands
#include "CLI.h" // The CLI (Command line interface) library

int main()
{
    std::string username{ "Yannick" };
    CLI::CLI* cli{ new CLI::CLI{ username } };
    std::vector<CLI::procces*> processlist{};

    std::vector<Command*> Commands{};
    Commands.push_back(&cli->commands.echo);
    Commands.push_back(&cli->commands.hello);

    utils::print("List of all commands: ");
    utils::printList(Commands);
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

    // signal a non problematic run of the program
    return 0;
}
