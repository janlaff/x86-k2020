#include <stdio.h>
#include <stdint.h>
#include <kernel/keyboard.h>

char getchar()
{
    uint8_t code = 0;
    uint8_t key = 0;
    while (1)
    {
        if (KB_readControllerStatus() & KYBRD_CTRL_STATS_MASK_OUT_BUF)
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