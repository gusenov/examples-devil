#ifndef UTILSDEVIL_HPP
#define UTILSDEVIL_HPP


#include <cstring>
#include <IL/il.h>

class UtilsDevIL {
public:
    static ILenum GetFormatByExtension(const char *ext) {
        //!< JPEG - .jpg, .jpe and .jpeg extensions
        if (!strcasecmp(ext, ".jpg")) {
            return IL_JPG;

        //!< Microsoft Windows Bitmap - .bmp extension
        } else if (!strcasecmp(ext, ".bmp")) {
            return IL_BMP;

        //!< Dr. Halo - .cut extension
        } else if (!strcasecmp(ext, ".cut")) {
            return IL_CUT;

        //!< Microsoft Windows Icons and Cursors - .ico and .cur extensions
        } else if (!strcasecmp(ext, ".ico") || !strcasecmp(ext, ".cur")) {
            return IL_ICO;

        //!< JPEG - .jpg, .jpe and .jpeg extensions
        } else if (!strcasecmp(ext, ".jpg") || !strcasecmp(ext, ".jpe") || !strcasecmp(ext, ".jpeg")) {
            return IL_JPG;

        //!< Amiga IFF (FORM ILBM) - .iff, .ilbm, .lbm extensions
        } else if (!strcasecmp(ext, ".iff") || !strcasecmp(ext, ".ilbm") || !strcasecmp(ext, ".lbm")) {
            return IL_ILBM;

        //!< Kodak PhotoCD - .pcd extension
        } else if (!strcasecmp(ext, ".pcd")) {
            return IL_PCD;

        //!< ZSoft PCX - .pcx extension
        } else if (!strcasecmp(ext, ".pcx")) {
            return IL_PCX;

        //!< PIC - .pic extension
        } else if (!strcasecmp(ext, ".pic")) {
            return IL_PIC;

        //!< Portable Network Graphics - .png extension
        } else if (!strcasecmp(ext, ".png")) {
            return IL_PNG;

        //!< Portable Any Map - .pbm, .pgm, .ppm and .pnm extensions
        } else if (!strcasecmp(ext, ".pbm") || !strcasecmp(ext, ".pgm") || !strcasecmp(ext, ".ppm") || !strcasecmp(ext, ".pnm")) {
            return IL_PNM;

        //!< Silicon Graphics - .sgi, .bw, .rgb and .rgba extensions
        } else if (!strcasecmp(ext, ".sgi") || !strcasecmp(ext, ".bw") || !strcasecmp(ext, ".rgb") || !strcasecmp(ext, ".rgba")) {
            return IL_SGI;

        //!< TrueVision Targa File - .tga, .vda, .icb and .vst extensions
        } else if (!strcasecmp(ext, ".tga") || !strcasecmp(ext, ".vda") || !strcasecmp(ext, ".icb") || !strcasecmp(ext, ".vst")) {
            return IL_TGA;

        //!< Tagged Image File Format - .tif and .tiff extensions
        } else if (!strcasecmp(ext, ".tif") || !strcasecmp(ext, ".tiff")) {
            return IL_TIF;

        //!< C-Style Header - .h extension
        } else if (!strcasecmp(ext, ".h")) {
            return IL_CHEAD;

        //!< Half-Life Model Texture - .mdl extension
        } else if (!strcasecmp(ext, ".mdl")) {
            return IL_MDL;

        //!< Quake 2 Texture - .wal extension
        } else if (!strcasecmp(ext, ".wal")) {
            return IL_WAL;

        //!< Homeworld Texture - .lif extension
        } else if (!strcasecmp(ext, ".lif")) {
            return IL_LIF;

        //!< Multiple-image Network Graphics - .mng extension
        } else if (!strcasecmp(ext, ".mng")) {
            return IL_MNG;

        //!< Graphics Interchange Format - .gif extension
        } else if (!strcasecmp(ext, ".gif")) {
            return IL_GIF;

        //!< DirectDraw Surface - .dds extension
        } else if (!strcasecmp(ext, ".dds")) {
            return IL_DDS;

        //!< ZSoft Multi-PCX - .dcx extension
        } else if (!strcasecmp(ext, ".dcx")) {
            return IL_DCX;

        //!< Adobe PhotoShop - .psd extension
        } else if (!strcasecmp(ext, ".psd")) {
            return IL_PSD;

        //!< PaintShop Pro - .psp extension
        } else if (!strcasecmp(ext, ".psp")) {
            return IL_PSP;

        //!< PIX - .pix extension
        } else if (!strcasecmp(ext, ".pix")) {
            return IL_PIX;

        //!< Pixar - .pxr extension
        } else if (!strcasecmp(ext, ".pxr")) {
            return IL_PXR;

        //!< X Pixel Map - .xpm extension
        } else if (!strcasecmp(ext, ".xpm")) {
            return IL_XPM;

        //!< Radiance High Dynamic Range - .hdr extension
        } else if (!strcasecmp(ext, ".hdr")) {
            return IL_HDR;

        //!< Macintosh Icon - .icns extension
        } else if (!strcasecmp(ext, ".icn")) {
            return IL_ICNS;

        //!< Jpeg 2000 - .jp2 extension
        } else if (!strcasecmp(ext, ".jp2")) {
            return IL_JP2;

        //!< OpenEXR - .exr extension
        } else if (!strcasecmp(ext, ".exr")) {
            return IL_EXR;

        //!< Microsoft HD Photo - .wdp and .hdp extension
        } else if (!strcasecmp(ext, ".wdp") || !strcasecmp(ext, ".hdp")) {
            return IL_WDP;

        //!< Valve Texture Format - .vtf extension
        } else if (!strcasecmp(ext, ".vtf")) {
            return IL_VTF;

        //!< Wireless Bitmap - .wbmp extension
        } else if (!strcasecmp(ext, ".wbm")) {
            return IL_WBMP;

        //!< Sun Raster - .sun, .ras, .rs, .im1, .im8, .im24 and .im32 extensions
        } else if (!strcasecmp(ext, ".sun") || !strcasecmp(ext, ".ras") || !strcasecmp(ext, ".rs") || !strcasecmp(ext, ".im1") || !strcasecmp(ext, ".im8") || !strcasecmp(ext, ".im24") || !strcasecmp(ext, ".im32")) {
            return IL_SUN;

        //!< Interchange File Format - .iff extension
        } else if (!strcasecmp(ext, ".iff")) {
            return IL_IFF;

        //!< Gamecube Texture - .tpl extension
        } else if (!strcasecmp(ext, ".tpl")) {
            return IL_TPL;

        //!< Flexible Image Transport System - .fit and .fits extensions
        } else if (!strcasecmp(ext, ".fit") || !strcasecmp(ext, ".fits")) {
            return IL_FITS;

        //!< Digital Imaging and Communications in Medicine (DICOM) - .dcm and .dicom extensions
        } else if (!strcasecmp(ext, ".dcm") || !strcasecmp(ext, ".dicom")) {
            return IL_DICOM;

        //!< Call of Duty Infinity Ward Image - .iwi extension
        } else if (!strcasecmp(ext, ".iwi")) {
            return IL_IWI;

        //!< Blizzard Texture Format - .blp extension
        } else if (!strcasecmp(ext, ".blp")) {
            return IL_BLP;

        //!< Heavy Metal: FAKK2 Texture - .ftx extension
        } else if (!strcasecmp(ext, ".ftx")) {
            return IL_FTX;

        //!< Homeworld 2 - Relic Texture - .rot extension
        } else if (!strcasecmp(ext, ".rot")) {
            return IL_ROT;

        //!< Medieval II: Total War Texture - .texture extension
        } else if (!strcasecmp(ext, ".tex")) {
            return IL_TEXTURE;

        //!< Digital Picture Exchange - .dpx extension
        } else if (!strcasecmp(ext, ".dpx")) {
            return IL_DPX;

        //!< Unreal (and Unreal Tournament) Texture - .utx extension
        } else if (!strcasecmp(ext, ".utx")) {
            return IL_UTX;

        //!< MPEG-1 Audio Layer 3 - .mp3 extension
        } else if (!strcasecmp(ext, ".mp3")) {
            return IL_MP3;

        //!< Khronos Texture - .ktx extension
        } else if (!strcasecmp(ext, ".ktx")) {
            return IL_KTX;

        /*
        //!< DooM walls - no specific extension
        } else if (!strcasecmp(ext, ".")) {
            return IL_DOOM;

        //!< DooM flats - no specific extension
        } else if (!strcasecmp(ext, ".")) {
            return IL_DOOM_FLAT;

        //!< Raw Image Data - any extension
        } else if (!strcasecmp(ext, ".")) {
            return IL_RAW;

        //!< PaintShop Pro Palette
        } else if (!strcasecmp(ext, ".")) {
            return IL_JASC_PAL;
        */

        } else {
            return IL_TYPE_UNKNOWN;
        }
    }
};


#endif  // UTILSDEVIL_HPP
