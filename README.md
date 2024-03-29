Библиотека OpenIL также известная как DevIL (второе название дали из-за вопросов торговой марки) свободно распространяемая.

Для загрузки jpg многие используют библиотеку Intel Jpeg Liblary или jpeglib, для загрузки формата png используют libpng и т.д. В противоположность этому библиотека OpenIL (DevIl) универсальна, она объединяет в себе загрузку всех перечисленных форматов.

При этом сама библиотека организована по образу и подобию OpenGL (так что первоначальное название OpenIL отнюдь не случайно) - она представляет из себя набор функций и констант, разбитых на три модуля - IL, ILU и ILUT.

- Собственно за чтение и запись текстур отвечает именно библиотека IL,
- библиотека ILU предоставляет ряд возможностей по обработке изображений,
- а библиотека ILUT служит для упрощения работы с IL для сторонних библиотек (таких как OpenGL).

Примеры:

- [Простой пример загруки PNG-изображения](simple-load)
- [Загрузка PNG-файла в CMake-проекте с build type = Release](examples-devil/cmake-release)
- [Загрузка PNG-файла в Xcode-проекте](LoadPNG)
- [Установка цветных пикселей](draw-colors)
- [Рисование круга](draw-circle)
- [Анимация круга](circle-animation-gif)

