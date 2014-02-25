#ifndef DATA_SCREEN_H
#define DATA_SCREEN_H

#include "Types.h"

// TODO scanline?
#define ScreenPixel(x,y) ((ScreenColor*)Data_Screen.drawBuffer)[(y) * Data_Screen.width + (x)]

extern struct Data_Screen {
	int width;
	int height;
	struct {
		int x, y;
	} offset640x480;
	int format; // 555, 565, ...
	void *drawBuffer; //[800*600];
	int scanlineBytes;
} Data_Screen;

#endif