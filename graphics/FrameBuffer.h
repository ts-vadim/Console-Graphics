#pragma once



class FrameBuffer
{
public:
	char* buffer = nullptr;
	unsigned short width = 0;
	unsigned short height = 0;

	FrameBuffer()
	{
	}
	FrameBuffer(unsigned short w, unsigned short h)
	{
		Create(w, h);
	}
	~FrameBuffer()
	{
		delete[] buffer;
	}

	void Create(unsigned short w, unsigned short h)
	{
		delete[] buffer;
		buffer = new char[w * h];
		for (int i = 0; i < w * h; i++)
			buffer[i] = ' ';
		width = w;
		height = h;
	}

	bool onFrame(int x, int y)
	{
		return x >= 0 && x < width && y >= 0 && y < height;
	}
};
