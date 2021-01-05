# *class* Graphics
Simple class for drawing in console.

## Usage:
```c++
Graphics::Begin();
Graphics::Clear();

Graphics::Rect({ 1, 1, 28, 11 }, { ' ', 0 }, { '#', Graphics::ForeWhite | Graphics::ForeBright });
Graphics::Text(2, 2, Graphics::ForeWhite | Graphics::Underscore, "Some text with %s", "underscore");

WORD framed =
	Graphics::UpperLine |
	Graphics::Underscore |
	Graphics::LeftLine |
	Graphics::RightLine;

Graphics::Text(2, 4, Graphics::ForeWhite | framed, "Some framed text");

Graphics::Char(4, 6, { '%', Graphics::ForeCyan });
Graphics::Char(5, 6, { 'I', Graphics::ForeCyan | Graphics::Inverse });

Graphics::Display();
Graphics::Cursor(0, Graphics::height - 4);
```
## Output:
<image width="600px" src="https://github.com/ts-vadim/Console-Graphics/blob/main/view.png">

## TODO:
- [x] Добавить цвета
- [ ] Упростить работу с массивами символов
- [ ] Добавить отрисовку линий
- [x] Сделать класс статичным
- [ ] Дать возможность читать символы с экрана