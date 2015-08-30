#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_TYPES_H

#include "wcwidth_cygwin.h"
#include "charlist.h"
#define HALF_WIDTH_MAX 700
#define HALF_WIDTH 1
#define DOUBLE_WIDTH 2

#if defined(__WIN32__) || defined(__linux__)
extern int wcwidth(wchar_t c);
#endif

void print_face_detail(FT_Face face)
{
    printf("face -> num_glyphs\t%ld\n", face->num_glyphs);
    printf("face -> face_flags       0x%08X\n", face->face_flags);
    printf("face -> units_per_EM     %ld\n", face->units_per_EM);
    printf("face -> num_fixed_sizes  %ld\n", face->num_fixed_sizes);
    printf("face -> available_sizes  %ld\n", face->available_sizes);
}

int print_glyphinfo(FT_Face face, FT_ULong ul)
{
    FT_UInt glyph_index;
    FT_GlyphSlot slot = face->glyph;
    int error;

    glyph_index = FT_Get_Char_Index(face, ul);
    error = FT_Load_Glyph( face, /* handle to face object */
                           glyph_index, /* glyph index */
                           FT_LOAD_DEFAULT ); /* load flags, see below */
    if ( error )
    {
        printf("FT_Load_Glyph() failed: %d (0x%08X)\n", error, error);
        return -1;
    }

     error = FT_Render_Glyph( face->glyph, FT_RENDER_MODE_NORMAL );
     if ( error )
     {
         printf("FT_Render_Glyph() failed: %d (0x%08X)\n", error, error);
         return -1;
     }

     /* printf("advance x=%d y=%d\n", face->glyph->advance.x, face->glyph->advance.y); */
     if (face->glyph->advance.x <= HALF_WIDTH_MAX)
     {
         printf("freetype: %lc %d\n", ul, HALF_WIDTH);
         return HALF_WIDTH;
     }
     else
     {
         printf("freetype: %lc %d\n", ul, DOUBLE_WIDTH);
         return DOUBLE_WIDTH;
     }
}

int print_wcwidth_cygwin(wchar_t wc)
{
    int width = 0;
    width = wcwidth_cygwin(wc);
    printf("wcwidth_cygwin : %lc %d\n", wc, width);
    return width;
}

int print_wcwidth(wchar_t wc)
{
    int width = 0;
    width = wcwidth(wc);
    printf("wcwidth : %lc %d\n", wc, width);
    return width;
}

int main(int argc, char *argv[])
{
    FT_Library library; /* handle to library */
    FT_Face face; /* handle to face object */
    int error;
    wchar_t warg[1024];

    int width_wc_cygwin;
    int width_wc;
    int width_glyph;

    if (argc != 2)
    {
        printf("invalid arguments.\n");
        printf("Usage: ./commandline CHAR");
        return -1;
    }

    setlocale(LC_ALL, "");

    printf("char = %d, wchar_t = %d, wint_t = %d\n", sizeof(char), sizeof(wchar_t), sizeof(wint_t));
    printf("argv[1] = %s\n", argv[1]);

    mbstowcs(warg, argv[1], sizeof(warg));
    error = printf("warg[0] = %ls\n", warg);
    printf("wprintf return = %d\n", error);

    error = FT_Init_FreeType( &library );
    if ( error )
    {
        printf("FT_Init_FreeType() failed: error = %d (0x%08X)\n", error, error);
        return -1;
    }

    error = FT_New_Face( library,
                         "/usr/share/fonts/truetype/vlgothic/VL-Gothic-Regular.ttf",
                         0,
                         &face );

    /* print_face_detail(face); */
    if (error == FT_Err_Unknown_File_Format )
    {
        printf("FT_New_Face() failed: error = %d (0x%08X)\n", error, error);
        return -1;
    }
    else if ( error )
    {
        printf("FT_New_Face() failed: error = %d (0x%08X)\n", error, error);
        return -1;
    }

    error = FT_Set_Char_Size( face, 14 * 64, 0,
                              100, 0 );                /* set character size */

    if ( error )
    {
        printf("FT_Select_Size() failed: error = %d (0x%08X)\n", error, error);
        return -1;
    }

    width_wc_cygwin = print_wcwidth_cygwin(warg[0]);
    width_wc = print_wcwidth(warg[0]);
    width_glyph = print_glyphinfo(face, warg[0]);
    if (width_wc != width_glyph)
    {
        printf("*** %lc, width_wc_cygwin = %d, width_wc = %d, width_glyph = %d\n", warg[0],
               width_wc_cygwin, width_wc, width_glyph);
    }
    return 0;
}
