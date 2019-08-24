#include <cstdio>
#include <iostream>
#include <iomanip>
#include <IL/il.h>
#include <IL/ilu.h>

#define ILUT_LIB

#ifdef ILUT_LIB
#include <IL/ilut.h>
#endif

#define HEX(x) std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(x)

int main(int argc, const char **argv) {
    // Названия всех основных функций начинаются с префикса il.




    // Желательно начать инициализацию с проверки номеров версий - дело в том,
    // что на другой машине уже могут стоять dll-ки от более старой версии
    // библиотеки и если при вызове приложения загрузятся именно они, то
    // программа вряд ли будет корректно работать. При запуске программы лучше
    // сразу же проверить соответствие версии библиотеки:

    std::cout << "ilGetInteger(IL_VERSION_NUM) < IL_VERSION" << std::endl;
    std::cout << ilGetInteger(IL_VERSION_NUM) << " < " << IL_VERSION << std::endl;
    std::cout << "IL_VERSION_NUM = " << ilGetInteger(IL_VERSION_NUM) << std::endl;
    std::cout << "IL_VERSION = " << IL_VERSION << std::endl;
    std::cout << std::endl;

    if (ilGetInteger(IL_VERSION_NUM) < IL_VERSION) {
        fprintf(stderr, "Incorrect devil.dll version\n");
        return EXIT_FAILURE;
    }

    std::cout << "iluGetInteger(ILU_VERSION_NUM) < ILU_VERSION" << std::endl;
    std::cout << iluGetInteger(ILU_VERSION_NUM) << " < " << ILU_VERSION << std::endl;
    std::cout << "ILU_VERSION_NUM = " << ilGetInteger(ILU_VERSION_NUM) << std::endl;
    std::cout << "ILU_VERSION = " << ILU_VERSION << std::endl;
    std::cout << std::endl;

    if (iluGetInteger(ILU_VERSION_NUM) < ILU_VERSION) {
        fprintf(stderr, "Incorrect ilu.dll version\n");
        return EXIT_FAILURE;
    }

#ifdef ILUT_LIB
    std::cout << "ilutGetInteger(ILUT_VERSION_NUM) < ILUT_VERSION" << std::endl;
    std::cout << ilutGetInteger(ILUT_VERSION_NUM) << " < " << ILUT_VERSION << std::endl;
    std::cout << "ILUT_VERSION_NUM = " << ILUT_VERSION_NUM << std::endl;
    std::cout << "ILUT_VERSION = " << ILUT_VERSION << std::endl;
    std::cout << std::endl;

    if (ilutGetInteger(ILUT_VERSION_NUM) < ILUT_VERSION) {
        fprintf(stderr, "Incorrect ilut.dll version\n");
        return EXIT_FAILURE;
    }
#endif



    // Перед тем как начать использовать функции библиотеки DevIL, ее необходимо
    // проинициализировать:
    ilInit();  // инициализация основной библиотеки.
    iluInit();  // инициализация библиотеки утилит.
#ifdef ILUT_LIB
    ilutInit();
#endif




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




    ILenum FileType = IL_BMP;
    const char *FileName = "rect.bmp";
    ILboolean result;

    // После того как изображение (его идентификатор) создано и выбрано текущим
    // его можно загрузить из файла при помощи одной из следующих команд:

    // Функция ilLoad отличается от функции ilLoadImage тем, что в ней явно
    // передается тип загружаемого файла (например IL_BMP, IL_TGA, IL_JPG):
    result = ilLoad(FileType, FileName);
    // В случае, когда тип заранее не известен, то можно в качестве типа
    // передать IL_TYPE_UNKNOWN и тогда данная функция ведет себя полностью
    // аналогично ilLoadImage, т.е. сперва пытается определить тип по расширению
    // файла, если это не получается - то по началу файла.

    // Функция ilLoadImage загружает текстуру из файла с заданным именем
    // (fileName) в текущее (bound) изображение и возвращает IL_TRUE при успехе
    // и IL_FALSE при ошибке:
    // result = ilLoadImage(FileName);

    // Функции ilLoadF и ilLoadL отличаются от ilLoadImage тем, что позволяют
    // загружать текстуру не из обычного файла, а, например, из архива, т.е.
    // вызывающая сторона сама обеспечивает доступ к данным:
    // result = ilLoadF(FileType, ILHANDLE file);
    // result = ilLoadL(FileType, ILvoid * data, ILuint size);

    // Типы файлов определены в виде макросов с помощью директивы #define в
    // заголовочном файле il\il.h, например, для загрузки файлов типа jpg нужно
    // указать FileType IL_JPG, для BMP — IL_BMP, для png — IL_PNG и т.д.




    // DevIL поддерживает стек ошибок, так что новые ошибки не затирают старые,
    // а просто добавляются в стек ошибок. Команда ilGetError снимает очередное
    // значение с вершины стека и возвращает его.

    // Код ошибки можно получить с помощью функции ilGetError(), строковое
    // представление ошибки позволяет получить функция iluErrorString():
    int err = ilGetError();

    // Для проверки, не возникла ли какая-либо ошибка служит функция ilGetError,
    // возвращающая код ошибки или IL_NO_ERROR, если все в порядке:
    if (err != IL_NO_ERROR) {
        std::cout << "Ошибка при загрузке!" << std::endl;
        // Для получения текстовой информации по коду ошибки можно
        // воспользоваться следующей функцией:
        const char *strError = iluErrorString(err);

        std::cout << strError << std::endl;
        exit(EXIT_FAILURE);
    }




    int width = ilGetInteger(IL_IMAGE_WIDTH);
    std::cout << "Ширина изображения: " << width << std::endl;

    int height = ilGetInteger(IL_IMAGE_HEIGHT);
    std::cout << "Высота изображения: " << height << std::endl;

    int bpp = ilGetInteger(IL_IMAGE_BYTES_PER_PIXEL);
    std::cout << "Число байт на пиксель: " << bpp << std::endl;

    // Для получения доступа к пиксельным данным изображения служит функция
    // ilGetData:
    unsigned char *data = ilGetData();
    std::cout << "Растровые данные: " << std::endl;
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width * bpp; ++col) {
            // printf("%X ", data[row * width + col]);
            std::cout << HEX(data[row * (width * bpp) + col]) << " ";
        }
        printf("\n");
    }




    // Если, при сохранении изображения в файл, DevIL обнаруживает, что файл с
    // таким именем уже существует, то сохранение заканчивается неудачей - по
    // умолчанию DevIL не перезаписывает файлы.
    // Для изменения этого поведения служит следующая команда:
    ilEnable(IL_FILE_OVERWRITE);

    ILenum type = IL_PNG;
    const char *fileName = "rect.png";

    // Сохранение выбранного изображения также осуществляется крайне просто, для
    // этого служат функции:
    result = ilSave(type, fileName);
    // result = ilSaveImage(fileName);




    // Для уничтожения изображений служит функция ilDeleteImages:
    ilDeleteImages(1, &id);

    return EXIT_SUCCESS;
}
