#include "Graphics.h"


Graphics::Graphics()
{
	m_hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD size = GetConsoleSize();
	m_width = size.X;
	m_height = size.Y;
	m_screen = new char[m_width * m_height];
	m_output_screen = new CHAR_INFO[m_width * m_height];
	Clear();
}

Graphics::Graphics(COORD size)
{
	m_hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	m_width = size.X;
	m_height = size.Y;
	m_screen = new char[m_width * m_height];
	m_output_screen = new CHAR_INFO[m_width * m_height];
	Clear();
}

Graphics::~Graphics()
{
	delete[] m_screen;
}

COORD Graphics::GetConsoleSize()
{
	CONSOLE_SCREEN_BUFFER_INFO sbInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &sbInfo);
	short width = sbInfo.srWindow.Right - sbInfo.srWindow.Left + 1;
	short height = sbInfo.srWindow.Bottom - sbInfo.srWindow.Top + 1;
	return { width, height };
}


void Graphics::Clear(char c)
{
	for (int i = 0; i < m_width * m_height; i++)
	{
		m_screen[i] = c;
		m_output_screen[i].Attributes = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
		m_output_screen[i].Char.AsciiChar = m_screen[i];
	}
}

void Graphics::Draw()
{
	for (int i = 0; i < m_width * m_height; i++)
		m_output_screen[i].Char.AsciiChar = m_screen[i];
	SMALL_RECT screen_write_area = { 0, 0, m_width, m_height };
	WriteConsoleOutputA(m_hconsole, m_output_screen, { m_width, m_height }, { 0, 0 }, &screen_write_area);
}

void Graphics::Char(int x, int y, char c)
{
	if (!onScreen(x, y))
		return;
	m_screen[x + m_width * y] = c;
}

void Graphics::Rect(RECT area, char fill, char stroke)
{
	for (int y = area.top; y < area.bottom; y++)
	{
		for (int x = area.left; x < area.right; x++)
		{
			if (!onScreen(x, y))
				continue;
			char c = fill;
			if (x == area.left || x == area.right - 1 || y == area.top || y == area.bottom - 1)
				c = stroke;
			m_screen[x + m_width * y] = c;
		}
	}
}

void Graphics::Text(int x, int y, const char* format, ...)
{
	va_list args;
	va_start(args, format);

	vsnprintf_s(m_text_buffer, max_text_length, format, args);

	for (int i = 0; i < strlen(m_text_buffer); i++)
	{
		if (onScreen(x + i, y))
			m_screen[x + i + m_width * y] = m_text_buffer[i];
	}
}

bool Graphics::onScreen(int x, int y)
{
	return x >= 0 && x < m_width && y >= 0 && y < m_height;
}

void Graphics::Cursor(int x, int y)
{
	SetConsoleCursorPosition(m_hconsole, { (short)x, (short)y });
}