#ifndef USER_TERMINAL_H 
#define USER_TERMINAL_H

void UT_init();
void UT_handleUserInput(int key);
void UT_setInputString(const char *str);
void UT_appendInputChar(char c);
void UT_clearInputBuffer();
void UT_clearOutputBuffer();
void UT_updateTerminalBuffer();
void UT_removeInputCharacter();
void UT_applyInputString();

void UT_printLine(const char *str);

#endif