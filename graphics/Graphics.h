#pragma once

#include <Windows.h>
#include <cstdio>
#include <stdarg.h>
#include "FrameBuffer.h"

class Graphics;

#include "Drawable.h"



class Graphics
{
public:
	const unsigned short& width = m_frame.width;
	const unsigned short& height = m_frame.height;

	static COORD GetConsoleSize();

	Graphics();
	Graphics(COORD size);
	~Graphics();

	void Resize(COORD size);
	void SetRenderTarget(FrameBuffer* frame);
	void ReleaseRenderTarget();

	void Clear(char c = ' ');
	void Display();

	void Char(int x, int y, char c);
	void Rect(RECT area, char fill = '#', char stroke = '#');
	void Text(int x, int y, const char* format, ...);
	void Text(int x, int y, int max_length, const char* format, ...);
	void Frame(FrameBuffer& frame, int x, int y);
	void Draw(Drawable& frame);

	void Cursor(int x, int y);

private:
	HANDLE m_hconsole;
	FrameBuffer m_frame;
	FrameBuffer* m_rendertarget = &m_frame;
	CHAR_INFO* m_output_screen = nullptr;
	/*	Format text output	*/
	static const int max_text_length = 100;
	char m_text_buffer[max_text_length];
};

