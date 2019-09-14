#include <iostream>
#include <IL/il.h>
#include <IL/ilu.h>
#include <IL/ilut.h>

int main(int argc, const char * argv[]) {
    ilInit();
    iluInit();
    ilutInit();

    ILuint id;
    ilGenImages(1, &id);
    ilBindImage(id);

    ILenum FileType = IL_PNG;
    char const *FileName = "42454-globe-with-meridians-icon.png";
    ILboolean result = ilLoad(FileType, FileName);

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

    return 0;
}
