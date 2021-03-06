#include <stdio.h>
#include <stdint.h>
#include <kernel/keyboard.h>

int getchar()
{
    uint8_t code = 0;
    uint8_t key = 0;
    while (1)
    {
        if (KB_readControllerStatus() & KB_CONTROLLER_STATUS_INPUT_REGISTER_MASK > 0)
        {
            code = KB_readEncoderBuffer();
            if (code <= 0x58)
            {
                key = _kkybrd_scancode_std[code];
                break;
            }
        }
    }
    return key;
}