# Graphics
Simple classes for drawing in console.

## Example:
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
