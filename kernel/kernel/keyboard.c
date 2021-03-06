#include "kernel.h"
#include "kernel/keyboard.h"

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