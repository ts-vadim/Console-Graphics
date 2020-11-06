#pragma once

#include <Windows.h>
#include <cstdio>
#include <stdarg.h>


class Graphics
{
public:
	const short& width = m_width;
	const short& height = m_height;

	static COORD GetConsoleSize();

	Graphics();
	Graphics(COORD size);
	~Graphics();

	void Clear(char c = ' ');
	void Draw();

	void Char(int x, int y, char c);
	void Rect(RECT area, char fill = '#', char stroke = '#');
	void Text(int x, int y, const char* format, ...);

	void Cursor(int x, int y);

private:
	HANDLE m_hconsole;
	short m_width = 0;
	short m_height = 0;
	char* m_screen = nullptr;
	CHAR_INFO* m_output_screen = nullptr;
	/*	Format text output	*/
	static const int max_text_length = 100;
	char m_text_buffer[max_text_length];

	bool onScreen(int x, int y);
};

