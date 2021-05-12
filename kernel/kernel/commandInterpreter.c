#include <string.h>
#include <stdio.h>

#include <kernel/commandInterpreter.h>
#include <kernel/userTerminal.h>

enum CommandType CI_getCommand(const char *command)
{
    if (!strlcmp(command, "help", 4))
    {
        return C_HELP;
    }
    else if (!strlcmp(command, "shutdown", 8))
    {
        return C_SHUTDOWN;
    }
    else if (!strlcmp(command, "clear", 5))
    {
        return C_CLEAR;
    }

    printf("Error: unrecognized command: %s\n", command);
    return C_UNKNOWN;
}

void CI_executeCommand(enum CommandType command)
{
    switch (command) {
    case C_HELP:
        printf("**************************************\n");
        printf("**********Kernel Help Page************\n");
        printf("**************************************\n\n");
        printf("Available commands: \n");
        printf("help: Shows help page\n");
        printf("clear: Cleans the terminal display buffer\n");
        printf("shutdown: Shuts down the kernel\n");
        break;
    case C_SHUTDOWN:

        break;
    case C_CLEAR:
        UT_clearTerminal();
        break;
    }

}
