#pragma once

#include <assert.h>


class FrameBuffer
{
public:
	unsigned short const& width = m_width;
	unsigned short const& height = m_height;

	FrameBuffer()
	{
	}
	FrameBuffer(unsigned short w, unsigned short h)
	{
		Create(w, h);
	}
	~FrameBuffer()
	{
		Destroy();
	}

	void Create(unsigned short w, unsigned short h)
	{
		Destroy();
		m_buffer = new CHAR_INFO[w * h];
		for (int i = 0; i < w * h; i++)
		{
			m_buffer[i].Char.AsciiChar = ' ';
			m_buffer[i].Attributes = FOREGROUND_INTENSITY;
		}
			
		m_width = w;
		m_height = h;
	}

	void Destroy()
	{
		delete[] m_buffer;
		m_buffer = nullptr;
		m_width = 0;
		m_height = 0;
	}

	void SetAttr(unsigned short i, WORD attr)
	{
		assert(m_buffer);
		if (i < m_width * m_height)
			m_buffer[i].Attributes = attr;
	}

	void Set(unsigned short i, CHAR_INFO c, bool addColor = false)
	{
		assert(m_buffer);
		if (i < m_width * m_height)
		{
			if (addColor)
				c.Attributes |= m_buffer[i].Attributes;
			m_buffer[i] = c;
		}
	}

	void Set(unsigned short i, char c)
	{
		assert(m_buffer);
		if (i < m_width * m_height)
			m_buffer[i].Char.AsciiChar = c;
	}

	CHAR_INFO Get(unsigned short i)
	{
		assert(m_buffer);
		if (i < m_width * m_height)
			return m_buffer[i];
		return { '\0', 0 };
	}

	const CHAR_INFO* GetData()
	{
		return m_buffer;
	}

	bool OnFrame(int x, int y)
	{
		return x >= 0 && x < m_width&& y >= 0 && y < m_height;
	}

	int Coord2Index(int x, int y)
	{
		if (OnFrame(x, y))
			return m_width * y + x;
		return -1;
	}

private:
	unsigned short m_width = 0;
	unsigned short m_height = 0;
	CHAR_INFO* m_buffer = nullptr;
};
