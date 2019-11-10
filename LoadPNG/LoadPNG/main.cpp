#include <cstdio>
#include <iostream>
#include <iomanip>
#include <IL/il.h>
#include <IL/ilu.h>
#include <IL/ilut.h>
#include <unistd.h>

int main(int argc, const char **argv) {
    usleep(1000000);  // will sleep for 9 s

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
    ilInit();
    iluInit();
    ilutInit();

    ILuint id;
    ilGenImages(1, &id);
    ilBindImage(id);

    ILenum FileType = IL_PNG;
    const char *FileName = "PATH_TO_IMAGE.png";

    ILboolean result;

    result = ilLoad(FileType, FileName);
    int err = ilGetError();

    if (err != IL_NO_ERROR) {
        std::cout << "Ошибка при загрузке!" << std::endl;
        const char *strError = iluErrorString(err);
        std::cout << strError << std::endl;
        exit(EXIT_FAILURE);
    }

    //
    if (ilGetInteger(IL_IMAGE_FORMAT) != IL_RGBA || ilGetInteger(IL_IMAGE_TYPE) != IL_UNSIGNED_BYTE) {
        ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
    }

    switch (ilTypeFromExt(FileName)) {
        case IL_TGA:
            break;
        default:
            iluFlipImage();
            break;
    }
    //

    int width = ilGetInteger(IL_IMAGE_WIDTH);
    std::cout << "Ширина изображения: " << width << std::endl;

    int height = ilGetInteger(IL_IMAGE_HEIGHT);
    std::cout << "Высота изображения: " << height << std::endl;

    int bpp = ilGetInteger(IL_IMAGE_BYTES_PER_PIXEL);
    std::cout << "Число байт на пиксель: " << bpp << std::endl;

    int depth = ilGetInteger(IL_IMAGE_DEPTH);
    std::cout << "Depth: " << depth << std::endl;

    int Bpc = ilGetInteger(IL_IMAGE_BPC);
    std::cout << "Bpc: " << Bpc << std::endl;

    int sizeOfData = ilGetInteger(IL_IMAGE_SIZE_OF_DATA);
    std::cout << "Size Of Data: " << sizeOfData << std::endl;


    usleep(1000000);  // will sleep for 9 s

    ilDeleteImages(1, &id);

    usleep(1000000);  // will sleep for 9 s
    return EXIT_SUCCESS;
}
