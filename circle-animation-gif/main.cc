#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>

#include <IL/il.h>
#include <IL/ilu.h>
#include <IL/ilut.h>

#include "../third-party/gif.h"



struct PixelData {
    ILubyte r, g, b, a;
    PixelData(ILubyte r, ILubyte g, ILubyte b, ILubyte a) : r(r), g(g), b(b), a(a) {};
};
struct PixelData kWhitePx(255,255,255,0);
struct PixelData kRedPx(255,0,0,0);
struct PixelData kOrangePx(255,165,0,0);
struct PixelData kYellowPx(255,255,0,0);
struct PixelData kGreenPx(0,128,0,0);
struct PixelData kCyanPx(0,255,255,0);
struct PixelData kBluePx(0,0,255,0);
struct PixelData kVioletPx(238,130,238,0);
struct PixelData kBlackPx(0,0,0,0);
struct PixelData kColors[] = {
    kWhitePx, kRedPx, kOrangePx, kYellowPx, kGreenPx, kCyanPx, kBluePx, kVioletPx, kBlackPx
};




void ExitIfVersionIncompatible();
void Init();
ILuint CreateImage();
void ExitIfErrorOccured();
void PrintInfo();
ILboolean Save(char const *fileName, ILenum type = IL_PNG);
void DeleteImage(ILuint &id);
void PutPx(ILint XOff, ILint YOff, PixelData *pxData);
void Fill(struct PixelData const &pxData);




// --
void DrawFilledCircle(int x0, int y0, int radius)
{
    int x = radius;
    int y = 0;
    int xChange = 1 - (radius << 1);
    int yChange = 0;
    int radiusError = 0;

    while (x >= y)
    {
        for (int i = x0 - x; i <= x0 + x; i++)
        {
            PutPx(i, y0 + y, &kYellowPx);
            PutPx(i, y0 - y, &kYellowPx);
        }
        for (int i = x0 - y; i <= x0 + y; i++)
        {
            PutPx(i, y0 + x, &kYellowPx);
            PutPx(i, y0 - x, &kYellowPx);
        }

        y++;
        radiusError += yChange;
        yChange += 2;
        if (((radiusError << 1) + xChange) > 0)
        {
            x--;
            radiusError += xChange;
            xChange += 2;
        }
    }
}
// --

int main(int argc, const char **argv) {
    ExitIfVersionIncompatible();
    Init();
    ILuint id = CreateImage();


    ILuint Width = 500;
    ILuint Height = 100;
    ILuint Depth = 1;
    ILubyte Bpp = 4;  // bytes per pixel
    ILenum Format = IL_RGBA;
    ILenum Type = IL_UNSIGNED_BYTE;
    void *Data  =  nullptr;
    ILboolean result = ilTexImage(Width, Height, Depth, Bpp, Format, Type, Data);
    ExitIfErrorOccured();
    PrintInfo();

    auto fileName = "circle.gif";
	int delay = 1;
	GifWriter g;
	GifBegin(&g, fileName, Width, Height, delay);

    for (int x = 50; x < Width - 50; x += 10) {
        Fill(kBlackPx);
        DrawFilledCircle(x, 50, 26);
    	GifWriteFrame(&g, ilGetData(), Width, Height, delay);
    }

    GifEnd(&g);

    DeleteImage(id);
    return EXIT_SUCCESS;
}




// Названия всех основных функций начинаются с префикса il.




void ExitIfVersionIncompatible() {
    // Желательно начать инициализацию с проверки номеров версий - дело в том,
    // что на другой машине уже могут стоять dll-ки от более старой версии
    // библиотеки и если при вызове приложения загрузятся именно они, то
    // программа вряд ли будет корректно работать. При запуске программы лучше
    // сразу же проверить соответствие версии библиотеки:

    if (ilGetInteger(IL_VERSION_NUM) < IL_VERSION) {
        fprintf(stderr, "Incorrect devil.dll version\n");
        exit(EXIT_FAILURE);
    }

    if (iluGetInteger(ILU_VERSION_NUM) < ILU_VERSION) {
        fprintf(stderr, "Incorrect ilu.dll version\n");
        exit(EXIT_FAILURE);
    }

    if (ilutGetInteger(ILUT_VERSION_NUM) < ILUT_VERSION) {
        fprintf(stderr, "Incorrect ilut.dll version\n");
        exit(EXIT_FAILURE);
    }
}




void Init() {
    // Перед тем как начать использовать функции библиотеки DevIL, ее необходимо
    // проинициализировать:
    ilInit();  // инициализация основной библиотеки.
    iluInit();  // инициализация библиотеки утилит.
    ilutInit();
}




ILuint CreateImage() {
    // Работа с изображениями в DevIL'е очень напоминает работу с различными
    // объектами (текстурами, вершинными массивами, шейдерами и т.п.) в OpenGL.

    // Каждое изображение идентифицируется беззнаковым целым числом
    // (типа ILuint), называемым его именем:
    ILuint id;

    // Для работы с изображением необходимо сначала создать изображение,
    // запросив для него идентификатор при помощи функции ilGenImages:
    ilGenImages(1, &id);
    // Как и в аналогичных функциях OpenGL, первый параметр (n) задает сколько
    // идентификаторов (изображений) нужно создать, а второй (ids) - куда их
    // поместить.

    // После получения идентификатора изображения его можно сделать текущим при
    // помощи команды ilBindImage:
    ilBindImage(id);

    return id;
}




void ExitIfErrorOccured() {
    // DevIL поддерживает стек ошибок, так что новые ошибки не затирают старые,
    // а просто добавляются в стек ошибок. Команда ilGetError снимает очередное
    // значение с вершины стека и возвращает его.

    // Код ошибки можно получить с помощью функции ilGetError(), строковое
    // представление ошибки позволяет получить функция iluErrorString():
    int err = ilGetError();

    // Для проверки, не возникла ли какая-либо ошибка служит функция ilGetError,
    // возвращающая код ошибки или IL_NO_ERROR, если все в порядке:
    if (err != IL_NO_ERROR) {
        std::cout << "Ошибка!" << std::endl;
        // Для получения текстовой информации по коду ошибки можно
        // воспользоваться следующей функцией:
        const char *strError = iluErrorString(err);

        std::cout << strError << std::endl;
        exit(EXIT_FAILURE);
    }
}




void PrintInfo() {
    int width = ilGetInteger(IL_IMAGE_WIDTH);
    std::cout << "Ширина изображения: " << width << std::endl;

    int height = ilGetInteger(IL_IMAGE_HEIGHT);
    std::cout << "Высота изображения: " << height << std::endl;

    int bpp = ilGetInteger(IL_IMAGE_BYTES_PER_PIXEL);
    std::cout << "Число байт на пиксель: " << bpp << std::endl;
}




ILboolean Save(char const *fileName, ILenum type) {
    // Если, при сохранении изображения в файл, DevIL обнаруживает, что файл с
    // таким именем уже существует, то сохранение заканчивается неудачей - по
    // умолчанию DevIL не перезаписывает файлы.
    // Для изменения этого поведения служит следующая команда:
    ilEnable(IL_FILE_OVERWRITE);

    // Сохранение выбранного изображения также осуществляется крайне просто, для
    // этого служат функции:
    ILboolean result = ilSave(type, fileName);

    return result;
}




void DeleteImage(ILuint &id) {
    // Для уничтожения изображений служит функция ilDeleteImages:
    ilDeleteImages(1, &id);
}




void PutPx(ILint col, ILint row, PixelData *pxData) {
    ilSetPixels(
        col,               // XOff:   Specifies where to place the block of image data in the x direction.
        row,               // YOff:   Specifies where to place the block of image data in the y direction.
        0,                 // ZOff:   Specifies where to place the block of image data in the z direction. This will be 0 in most cases, unless you are using image volumes.
        1,                 // Width:  The width of the data block in Data.
        1,                 // Height: The height of the data block in Data
        1,                 // Depth:  The depth of the data block in Data. This will be 1, unless you are using image volumes.
        IL_RGBA,            // Format: The format of the data block in Data. Acceptable formats are IL_RGB, IL_RGBA, IL_BGR, IL_BGRA and IL_LUMINANCE.
        IL_UNSIGNED_BYTE,  // Type:   The type of the data block in Data. For acceptable types, refer to the documentation on ilTexImage. For most purposes, IL_UNSIGNED_BYTE is always acceptable here
        pxData             // Data:   A pointer to the actual data block. If this is NULL, DevIL will set an error of IL_INVALID_PARAM and return IL_FALSE (please refer to the section on error handling in DevIL).
    );
}




void Fill(struct PixelData const &pxData) {
    int width = ilGetInteger(IL_IMAGE_WIDTH);
    int height = ilGetInteger(IL_IMAGE_HEIGHT);
    int bpp = ilGetInteger(IL_IMAGE_BYTES_PER_PIXEL);

    ILubyte *data = ilGetData();
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width * bpp; col += bpp) {
            int q = row * (width * bpp) + col;
            data[q] = pxData.r;
            data[q+1] = pxData.g;
            data[q+2] = pxData.b;
            data[q+3] = pxData.a;
        }
    }
}
