
#include <iostream>
#include "SerialClass.h"

wchar_t *convertCharArrayToLPCWSTR(const char* charArray)
{
	wchar_t* wString = new wchar_t[20];
	MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 20);
	return wString;
}

void GetDesktopResolution(int& width, int& height)
{
	RECT desktop;
	// Get a handle to the desktop window
	const HWND hDesktop = GetDesktopWindow();
	// Get the size of screen to the variable desktop
	GetWindowRect(hDesktop, &desktop);
	// The top left corner will have coordinates (0,0)
	// and the bottom right corner will have coordinates
	// (horizontal, vertical)
	width = desktop.right;
	height = desktop.bottom;
}

struct hero
{
	int ls[2]; // left shift
	int e[2];
	int q[2];
	int rc[2]; // right-click
	//character() { ls[0] = ls[1] = e[0] = e[1] = q[0] = q[1] = rc[0] = rc[1] = 0; }
};

int main()
{
	Serial* SP = new Serial(convertCharArrayToLPCWSTR("COM5"));    // adjust as needed

	if (SP->IsConnected())
		printf("We're connected");

	char buff0[2] = {'0', '\0'};
	char buff1[2] = {'1', '\0'};

	hero ow_heros[23] = {
			{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } }, // genji
			{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } }, // mccree
			{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } }, // pharah
			{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } }, // reaper
			{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } }, // soldier76
			{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } }, // TODO faster modszer
			{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } },
			{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } },
			{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } },
			{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } },
			{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } },
			{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } },
			{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } },
			{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } },
			{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } },
			{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } },
			{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } },
			{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } },
			{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } },
			{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } },
			{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } },
			{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } },
			{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } }
	};
	
	int screen_w, screen_h;
	GetDesktopResolution(screen_w, screen_h);

	HDC screen = GetDC(NULL);
	
	int ls_pos[2] = {1505, 916}; // left-shift mercy skill

	while (SP->IsConnected())
	{
		COLORREF ls_color = GetPixel(screen, ls_pos[0], ls_pos[1]);
		int mean = ((unsigned int)GetBValue(ls_color) + GetRValue(ls_color) + GetGValue(ls_color)) / 3;
		if (mean > 220)
			SP->WriteData(buff1, 2);
		else
			SP->WriteData(buff0, 2);
		Sleep(10);
	}

	ReleaseDC(NULL, screen);

	return 0;
}