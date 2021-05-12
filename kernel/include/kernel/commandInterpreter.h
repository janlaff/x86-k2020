#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

enum CommandType
{
    C_SHUTDOWN,
    C_CLEAR,
    C_HELP,
    C_UNKNOWN
};

enum CommandType CI_getCommand(const char* command);
void CI_executeCommand(enum CommandType command);


#endif