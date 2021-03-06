#include "kernel.h"
#include "kernel/keyboard.h"

uint8_t KB_readControllerStatus()
{
    return inb(KYBRD_CTRL_STATS_REG);
}

void KB_sendControllerCommandByte(uint8_t cmd)
{
    // the controller input buffer has to be empty
    while (1)
        if ((KB_readControllerStatus() & KYBRD_CTRL_STATS_MASK_IN_BUF) == 0)
            break;
    outb(KYBRD_CTRL_CMD_REG, cmd);
}

uint8_t KB_readEncoderBuffer()
{
    return inb(KYBRD_ENC_INPUT_BUF);
}

void KB_writeEncoderCommandByte(uint8_t cmd)
{
    // the controller input buffer has to be empty
    while (1)
        if ((KB_readControllerStatus() & KYBRD_CTRL_STATS_MASK_IN_BUF) == 0)
            break;
    // send the command byte to the encoder
    outb(KYBRD_ENC_CMD_REG, cmd);
}