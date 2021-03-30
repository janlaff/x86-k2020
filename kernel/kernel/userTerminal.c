#include <kernel/userTerminal.h>
#include <kernel/terminal.h>
#include <string.h>

#define NUM_LINES TERMINAL_HEIGHT - 2

static int currentLineIndex;
static int currentInputCharCount;
static char outputBuffer[NUM_LINES][TERMINAL_WIDTH] = {0};
static char inputBuffer[TERMINAL_WIDTH] = {0};

static const char* TERMINAL_PREFIX = "x86-k2020:$ ";


void UT_init()
{
    terminal_init();

    currentLineIndex = 0;
    currentInputCharCount = 0;
    UT_clearInputBuffer();
    UT_clearOutputBuffer();
    UT_printLine("Welcome to x86-k2020 OS!\n");
    UT_printLine("Start by typing commands below.\n");
    UT_updateCursor();
}

void UT_handleUserInput(int key)
{
    switch (key)
    {
        case 0x0D:
            UT_applyInputString();
            break;
        case 0x08:
            UT_removeInputCharacter();
            break;
        default:
            UT_appendInputChar(key);
            break;
    }

    UT_updateCursor();
}

// user input field (editable by user - last line)
void UT_setInputString(const char* str)
{
    memcpy(inputBuffer, str, strlen(str));
    terminal_writestring(inputBuffer);
    UT_updateTerminalBuffer();
}

void UT_appendInputChar(char c)
{
    if (currentInputCharCount == TERMINAL_WIDTH)
    {
        UT_clearInputBuffer();
    }
    inputBuffer[currentInputCharCount++] = c;
    UT_updateTerminalBuffer();
}

void UT_clearInputBuffer()
{
    for (int i = 0; i < TERMINAL_WIDTH - 1; i++)
    {
        inputBuffer[i] = ' ';
    }
    currentInputCharCount = 0;
}

void UT_clearOutputBuffer()
{
    for (int i = 0; i < TERMINAL_WIDTH - 1; i++)
    {
        for (int x = 0; x < NUM_LINES; x++)
        {
            outputBuffer[x][i] = ' ';
        }
           
    }
}

void UT_updateTerminalBuffer()
{
    for (int i = 0; i < TERMINAL_HEIGHT - 2; i++) {
        terminal_row = i;
        terminal_column = 0;
        terminal_writestring(outputBuffer[i]);
    }

    terminal_row = TERMINAL_HEIGHT - 1;
    terminal_column = 0;
    terminal_writestring(TERMINAL_PREFIX);
    for (int i = 0; i < TERMINAL_WIDTH; i++)
    {
        terminal_putchar(inputBuffer[i]);
    }
}

void UT_removeInputCharacter()
{
    if (strlen(inputBuffer) >= TERMINAL_WIDTH)
        return;
    inputBuffer[--currentInputCharCount] = ' ';
    UT_updateTerminalBuffer();
}

void UT_applyInputString()
{
    UT_printLine(inputBuffer);
    UT_clearInputBuffer();
    UT_updateTerminalBuffer();
}

void UT_printLine(const char *str)
{
    if(currentLineIndex >= NUM_LINES - 1)
    {
        for (int i = 0; i < NUM_LINES - 1; i++)
        {
            memcpy(outputBuffer[i], outputBuffer[i + 1], TERMINAL_WIDTH);
        }
        memcpy(outputBuffer[NUM_LINES - 1], str, TERMINAL_WIDTH);
    } 
    else 
    {
        memcpy(outputBuffer[currentLineIndex++], str, TERMINAL_WIDTH);
    }
    UT_updateTerminalBuffer();
}

void UT_updateCursor() {
    terminal_move_cursor(strlen(TERMINAL_PREFIX) + currentInputCharCount, TERMINAL_HEIGHT - 1);
}