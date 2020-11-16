# Graphics
Simple classes for drawing in console.

## Classes:
- [Graphics](https://github.com/ts-vadim/Console-Graphics/blob/main/Graphics.md)
<a href="https://github.com/ts-vadim/Console-Graphics/blob/main/Graphics.md" target="_blank">Graphics</a>
- [FrameBuffer](https://github.com/ts-vadim/Console-Graphics/blob/main/FrameBuffer.md)
- [Drawable](https://github.com/ts-vadim/Console-Graphics/blob/main/Drawable.md)

## Example:
```c++
Graphics graphics;
graphics.Clear();

graphics.Rect({ 0, 0, 10, 5 }, '.');
graphics.Text(0, 5, "It looks like %s game", "rogue");

graphics.Display();
graphics.Cursor(0, graphics.height - 4);
```
## Output:
<image width="600px" src="https://github.com/ts-vadim/Console-Graphics/blob/main/view.png">
