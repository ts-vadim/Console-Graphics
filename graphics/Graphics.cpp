#include "Graphics.h"

FrameBuffer Graphics::m_frame;
const unsigned short& Graphics::width = Graphics::m_frame.width;
const unsigned short& Graphics::height = Graphics::m_frame.height;

HANDLE Graphics::m_hconsole;
const int Graphics::m_max_text_length = 100;
char Graphics::m_text_buffer[Graphics::m_max_text_length];
bool Graphics::m_graphics_created = false;


void Graphics::Begin()
{
	m_graphics_created = true;
	m_hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD size = GetConsoleSize();
	m_frame.Create(size.X, size.Y);
	Clear({ ' ', ForeBlack });
}

void Graphics::End()
{
	Clear({ ' ', ForeBlack });
	Display();
	Cursor(0, 0);
	m_frame.Destroy();
	m_graphics_created = false;
}


COORD Graphics::GetConsoleSize()
{
	CONSOLE_SCREEN_BUFFER_INFO sbInfo;
	GetConsoleScreenBufferInfo(m_hconsole, &sbInfo);
	short w = sbInfo.srWindow.Right - sbInfo.srWindow.Left + 1;
	short h = sbInfo.srWindow.Bottom - sbInfo.srWindow.Top + 1;
	return { w, h };
}


void Graphics::Resize(COORD size)
{
	assert(m_graphics_created);
	m_frame.Create(size.X, size.Y);
	Clear({ ' ', ForeBlack });
}


void Graphics::Clear(CHAR_INFO c)
{
	assert(m_graphics_created);
	for (int i = 0; i < m_frame.width * m_frame.height; i++)
		m_frame.Set(i, c);
}


void Graphics::Display()
{
	assert(m_graphics_created);
	SMALL_RECT screen_write_area = { 0, 0, (SHORT)m_frame.width, (SHORT)m_frame.height };
	WriteConsoleOutputA(m_hconsole, m_frame.GetData(), { (SHORT)m_frame.width, (SHORT)m_frame.height }, { 0, 0 }, &screen_write_area);
}


void Graphics::ColorChar(int x, int y, WORD color, bool addColor)
{
	assert(m_graphics_created);
	if (addColor)
		m_frame.SetAttr(m_frame.Coord2Index(x, y), m_frame.Get(m_frame.Coord2Index(x, y)).Attributes | color);
	else
		m_frame.SetAttr(m_frame.Coord2Index(x, y), color);
}


void Graphics::Char(int x, int y, CHAR_INFO c)
{
	assert(m_graphics_created);
	m_frame.Set(m_frame.Coord2Index(x, y), c);
}


void Graphics::Rect(RECT area, CHAR_INFO fill, CHAR_INFO stroke)
{
	assert(m_graphics_created);
	for (int y = area.top; y < area.bottom; y++)
	{
		for (int x = area.left; x < area.right; x++)
		{
			CHAR_INFO c = fill;
			if (x == area.left || x == area.right - 1 || y == area.top || y == area.bottom - 1)
				c = stroke;
			m_frame.Set(m_frame.Coord2Index(x, y), c);
		}
	}
}


void Graphics::Text(int x, int y, WORD color, const char* format, ...)
{
	assert(m_graphics_created);
	va_list args;
	va_start(args, format);

	vsnprintf_s(m_text_buffer, m_max_text_length, format, args);

	CHAR_INFO chr;
	chr.Attributes = color;
	for (int i = 0; i < strlen(m_text_buffer); i++)
	{
		chr.Char.AsciiChar = m_text_buffer[i];
		m_frame.Set(m_frame.Coord2Index(x + i, y), chr);
	}
}


void Graphics::Text(int x, int y, WORD color, int max_length, const char* format, ...)
{
	assert(m_graphics_created);
	va_list args;
	va_start(args, format);

	vsnprintf_s(m_text_buffer, m_max_text_length, format, args);

	CHAR_INFO chr;
	chr.Attributes = color;
	for (int i = 0; i < strlen(m_text_buffer) && i < max_length; i++)
	{
		chr.Char.AsciiChar = m_text_buffer[i];
		m_frame.Set(m_frame.Coord2Index(x + i, y), chr);
	}
		
}


void Graphics::Frame(FrameBuffer& frame, int x, int y)
{
	assert(m_graphics_created);
	for (int py = 0; py < frame.height; py++)
		for (int px = 0; px < frame.width; px++)
			m_frame.Set(
				int(x + px + m_frame.width * (y + py)),
				frame.Get(px + py * frame.width)
			);
}


void Graphics::Cursor(int x, int y)
{
	assert(m_graphics_created);
	SetConsoleCursorPosition(m_hconsole, { (short)x, (short)y });
}


CHAR_INFO Graphics::GetChar(int x, int y)
{
	return m_frame.Get(m_frame.Coord2Index(x, y));
}
