#include <cstdio>
#include <iostream>
#include <iomanip>
#include <IL/il.h>
#include <IL/ilu.h>
#include <IL/ilut.h>

int main(int argc, const char **argv) {
    if (ilGetInteger(IL_VERSION_NUM) < IL_VERSION) {
        fprintf(stderr, "Incorrect devil.dll version\n");
        return EXIT_FAILURE;
    }

    if (iluGetInteger(ILU_VERSION_NUM) < ILU_VERSION) {
        fprintf(stderr, "Incorrect ilu.dll version\n");
        return EXIT_FAILURE;
    }

    if (ilutGetInteger(ILUT_VERSION_NUM) < ILUT_VERSION) {
        fprintf(stderr, "Incorrect ilut.dll version\n");
        return EXIT_FAILURE;
    }
    ilInit();  // инициализация основной библиотеки.
    iluInit();  // инициализация библиотеки утилит.
    ilutInit();

    ILuint id;
    ilGenImages(1, &id);
    ilBindImage(id);

    ILenum FileType = IL_PNG;
    const char *FileName = "YOUR_IMAGE_HERE.png";
    ILboolean result;

    result = ilLoad(FileType, FileName);
    int err = ilGetError();

    if (err != IL_NO_ERROR) {
        std::cout << "Ошибка при загрузке!" << std::endl;
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

    ilDeleteImages(1, &id);

    return EXIT_SUCCESS;
}
