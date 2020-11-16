# *class* Graphics
Simple class for drawing in console.

## Variables:
- *const short&* width
- *const short&* height

## Static Methods:
- *COORD* **GetConsoleSize**()

## Methods:
- **Display**()
- **Clear**(char c = ' ')
- **Draw**(Drawable& drawable)
- **Frame**(FrameBuffer& frame, int x, int y)
- **Char**(int x, int y, char c)
- **Rect**(RECT area, char fill = '#', char stroke = '#')
- **Text**(int x, int y, const char* format, ...)
- **Text**(int x, int y, int max_length, const char* format, ...)
- **Cursor**(int x, int y)

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
