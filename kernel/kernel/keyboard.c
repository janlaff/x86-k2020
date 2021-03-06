#include <kernel/keyboard.h>

void KB_waitWrite()
{
    // the input buffer bit in the status must be zero in order to send commands to the controller
    int timeout = 10000;
    while (1)
    {
        if (timeout-- < 0 || (KB_readControllerStatus() & KB_CONTROLLER_STATUS_INPUT_REGISTER_MASK) == 0)
            break;
    }
}

void KB_waitRead()
{
    // the output buffer bit in the status must be set in order read data
    int timeout = 10000;
    while (1)
    {
        if (timeout-- < 0 || (KB_readControllerStatus() & KB_CONTROLLER_STATUS_OUTPUT_REGISTER_MASK) == 1)
            break;
    }
}

// ref: https://www.avrfreaks.net/sites/default/files/PS2%20Keyboard.pdf
int KB_initialize()
{
    int result = 1;
    // we dont need the mouse
    KB_sendControllerCommandByte(KB_CONTROLLER_CMD_MOUSE_DISABLE);
    KB_waitWrite();

    // flush the output buffer
    KB_readEncoderBuffer();

    // perform controller self test
    KB_sendControllerCommandByte(KB_CONTROLLER_CMD_SELF_TEST);
    KB_waitRead();
    int response = KB_readEncoderBuffer();
    result &= response == 0x55; // self test successful
  
    // perform interface self test
    KB_sendControllerCommandByte(KB_CONTROLLER_CMD_INTERFACE_TEST);
    KB_waitRead();
    response = KB_readEncoderBuffer();
    result &= response == 0; // self test successful

    return result;
}

uint8_t KB_readControllerStatus()
{
    // read the keyboard controller status register
    return inb(KB_CONTROLLER_STATUS_REGISTER);
}

void KB_sendControllerCommandByte(uint8_t cmd)
{
    // the controller input reister has to be empty
    while (1)
        if ((KB_readControllerStatus() & KB_CONTROLLER_STATUS_INPUT_REGISTER_MASK) == 0)
            break;
    // send the command to the keyboard controller
    outb(KB_CONTROLLER_COMMAND_REGISTER, cmd);
}

uint8_t KB_readEncoderBuffer()
{
    return inb(KB_ENCODER_INPUT_REGISTER);
}

void KB_writeEncoderCommandByte(uint8_t cmd)
{
    // the controller input register has to be empty
    while (1)
    if ((KB_readControllerStatus() & KB_CONTROLLER_STATUS_INPUT_REGISTER_MASK) == 0)
        break;
    // send the command byte to the encoder
    outb(KB_ENCODER_COMMAND_REGISTER, cmd);
}