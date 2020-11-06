# Graphics
Simple class for console drawing.

## Static Methods:
- *COORD* **GetConsoleSize**()

## Methods:
- *void* **Clear**(char c = ' ')
- *void* **Draw**()
- *void* **Char**(int x, int y, char c)
- *void* **Rect**(RECT area, char fill = '#', char stroke = '#')
- *void* **Text**(int x, int y, const char* format, ...)
- *void* **Cursor**(int x, int y)

## Usage:
```c++
Graphics graphics;
graphics.Clear();

graphics.Rect({ 0, 0, 10, 5 }, '.');
graphics.Text(0, 5, "It looks like %s game", "rogue");

graphics.Draw();
graphics.Cursor(0, graphics.height - 4);
```
## Output:
<image width="600px" src="https://github.com/ts-vadim/Console-Graphics/blob/main/view.png">
