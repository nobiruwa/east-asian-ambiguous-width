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

int glyphinfo(FT_Face face, FT_ULong ul)
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

     if (face->glyph->advance.x <= HALF_WIDTH_MAX)
     {
         return HALF_WIDTH;
     }
     else
     {
         return DOUBLE_WIDTH;
     }
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

    int i,j,k, char_num;

    if (argc != 2)
    {
        printf("Usage: ./ambiguous_width_comparison FONT_PATH\n");
        printf("Example: ./ambiguous_width_comparison \"/usr/share/fonts/truetype/vlgothic/VL-Gothic-Regular.ttf\"\n");
        return -1;
    }
    setlocale(LC_ALL, "");

    error = FT_Init_FreeType( &library );
    if ( error )
    {
        printf("FT_Init_FreeType() failed: error = %d (0x%08X)\n", error, error);
        return -1;
    }

    error = FT_New_Face( library,
                         //"/usr/share/fonts/truetype/vlgothic/VL-Gothic-Regular.ttf",
                         argv[1],
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

    char_num = sizeof(charlist) / sizeof(charlist[0]);
    printf("char_num = %d\n", char_num);

    for(i = 0; i < char_num; i++)
    {
        width_wc_cygwin = wcwidth_cygwin(charlist[i][0]);
        width_wc = wcwidth(charlist[i][0]);
        width_glyph = glyphinfo(face, charlist[i][0]);
        if (width_wc_cygwin < 0 || width_glyph < 0)
        {
            printf("Failed: width_wc_cygwin = %d, width_wc = %d, width_glyph = %d, emacs_width = %d (0x%08X = %lc)\n", 
                   width_wc_cygwin, width_wc, width_glyph, 
                   charlist[i][1], charlist[i][0], charlist[i][0]);
            break;
        }
        if (width_wc_cygwin != width_glyph)
        {
            printf("*** width_wc_cygwin = %d, width_wc = %d, width_glyph = %d emacs_width = %d (0x%08X = %lc)\n", 
                   width_wc_cygwin, width_wc, width_glyph,
                   charlist[i][1], charlist[i][0], charlist[i][0]);
        }
    }
    return 0;
}
