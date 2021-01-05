#pragma once

#include <Windows.h>
#include <cstdio>
#include <stdarg.h>
#include <assert.h>
#include "FrameBuffer.h"


class Graphics
{
public:
	enum Color
	{
		// brightness levels: intensity, RGB, RGB + intensity
		ForeBright = FOREGROUND_INTENSITY,
		ForeWhite = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
		ForeBlack = 0,
		ForeRed = FOREGROUND_RED,
		ForeGreen = FOREGROUND_GREEN,
		ForeBlue = FOREGROUND_BLUE,
		ForeCyan = FOREGROUND_BLUE | FOREGROUND_GREEN,
		ForeYellow = FOREGROUND_RED | FOREGROUND_GREEN,
		ForeMagenta = FOREGROUND_RED | FOREGROUND_BLUE,

		BackBright = BACKGROUND_INTENSITY,
		BackWhite = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
		BackBlack = 0,
		BackRed = BACKGROUND_RED,
		BackGreen = BACKGROUND_GREEN,
		BackBlue = BACKGROUND_BLUE,
		BackCyan = BACKGROUND_BLUE | BACKGROUND_GREEN,
		BackYellow = BACKGROUND_RED | BACKGROUND_GREEN,
		BackMagenta = BACKGROUND_RED | BACKGROUND_BLUE,

		Inverse = COMMON_LVB_REVERSE_VIDEO,
		// underscore, line above character, on the left side, on the right
		Underscore = COMMON_LVB_UNDERSCORE,
		UpperLine = COMMON_LVB_GRID_HORIZONTAL,
		LeftLine = COMMON_LVB_GRID_LVERTICAL,
		RightLine = COMMON_LVB_GRID_RVERTICAL
	};

public:
	static const unsigned short& width;
	static const unsigned short& height;

	static COORD GetConsoleSize();

	static void Begin();
	static void End();

	static void Resize(COORD size);

	static void Clear(CHAR_INFO c = { ' ', ForeBlack });
	static void Display();

	static void Char(int x, int y, CHAR_INFO c);
	static void Rect(RECT area, CHAR_INFO fill = { '#', ForeWhite }, CHAR_INFO stroke = { '#', ForeWhite });
	static void Text(int x, int y, WORD color, const char* format, ...);
	static void Text(int x, int y, WORD color, int max_length, const char* format, ...);
	static void Frame(FrameBuffer& frame, int x, int y);

	static void Cursor(int x, int y);

private:
	static bool m_graphics_created;
	static HANDLE m_hconsole;
	static FrameBuffer m_frame;
	/*	Format text output	*/
	static const int m_max_text_length;
	static char m_text_buffer[];
};

