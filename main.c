#include <sys/mman.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "draw.h"
#include <stdlib.h>
#include <linux/input.h>
#include "touch.h"
#include "bmp.h"

/*--  文字:  原  --*/
/*--  微软雅黑26;  此字体下对应的点阵为：宽x高=24x31   --*/
unsigned char yuan[24 * 31 / 8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x3F,0xFF,0xFF,0x3F,0xFF,0xFF,0x3F,0xFF,0xFE,0x38,0x1E,0x00,0x39,0xFF,
0xFC,0x39,0xFF,0xFC,0x39,0xFF,0xFC,0x39,0xC0,0x1C,0x39,0xFF,0xFC,0x39,0xFF,0xFC,
0x39,0xC0,0x1C,0x39,0xC0,0x1C,0x39,0xFF,0xFC,0x39,0xFF,0xFC,0x39,0xC7,0x2C,0x38,
0xF7,0x70,0x79,0xE7,0x78,0x79,0xC7,0x3C,0x73,0xC7,0x1E,0xF7,0xEF,0x0F,0xEF,0x7F,
0x07,0xE6,0x7E,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};


int main() {
    // 初始化LCD
    int fd = init_lcd();

    lcd_clear(BLACK_COLOR);

    lcd_draw_word(100,100,24,31,yuan,RED_COLOR);

    close_lcd(fd);

    return EXIT_SUCCESS;
}
