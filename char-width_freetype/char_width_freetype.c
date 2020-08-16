#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <ft2build.h>
#include <wchar.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H
#include FT_TYPES_H

#define PROJECT_NAME "char-width_freetype"
#define HALF_WIDTH_MAX 700
#define HALF_WIDTH 1
#define DOUBLE_WIDTH 2

FT_Pos print_glyphinfo(FT_Face face, FT_ULong ul)
{
    FT_UInt glyph_index;
    /* FT_GlyphSlot slot = face->glyph; */
    int error;

    glyph_index = FT_Get_Char_Index(face, ul);
    error = FT_Load_Glyph( face, /* handle to face object */
                           glyph_index, /* glyph index */
                           FT_LOAD_NO_BITMAP ); /* load flags, see below */
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

     /* printf("advance x=%lu y=%lu\n", face->glyph->advance.x, face->glyph->advance.y); */
     /* printf("glyph.metrics x=%lu y=%lu\n", face->glyph->metrics.width, face->glyph->metrics.height); */
     /* printf("metrics x=%d y=%d\n", face->size->metrics.x_ppem, face->size->metrics.y_ppem); */

     FT_Glyph glyph;
     FT_BBox bbox;
     FT_Get_Glyph(face->glyph, &glyph);
     FT_Glyph_Get_CBox(glyph, FT_LOAD_NO_SCALE, &bbox);
     /* printf("glyph width=%ld height=%ld\n", bbox.xMax - bbox.xMin, bbox.yMax - bbox.yMin); */
     FT_Pos width;
     width = bbox.xMax - bbox.xMin;
     /* printf("width = %lu\n", width); */

     return width;

     /* if (face->glyph->advance.x <= HALF_WIDTH_MAX) */
     /* { */
     /*   /\* printf("freetype: %c %lu %u %d\n", (unsigned char)ul, ul, glyph_index, HALF_WIDTH); *\/ */
     /*   return HALF_WIDTH; */
     /* } */
     /* else */
     /* { */
     /*   /\* printf("freetype: %c %lu %u %d\n", (unsigned char)ul, ul, glyph_index, DOUBLE_WIDTH); *\/ */
     /*   return DOUBLE_WIDTH; */
     /* } */
}

int main(int argc, char **argv) {
    FT_Library library; /* handle to library */
    FT_Face face; /* handle to face object */
    int error;
    unsigned long i;
    wchar_t warg[1024];
    char filename[1024];
    int width; /*  1 or 2 */
    FT_Pos width_glyph;

    if (argc != 3)
    {
        printf("invalid arguments.\n");
        printf("Usage: ./char_width_freetype CHAR FONT_PATH");
        return -1;
    }

    setlocale(LC_ALL, "");


    mbstowcs(warg, argv[1], sizeof(warg));
    printf("text = %ls\n", warg);
    /* error = printf("warg[0] = %ls\n", warg); */

    printf("font path: %s\n", argv[2]);
    strncpy(filename, argv[2], strlen(argv[2]));

    /*  */
    error = FT_Init_FreeType( &library );
    if ( error )
    {
        printf("FT_Init_FreeType() failed: error = %d (0x%08X)\n", error, error);
        return -1;
    }

    error = FT_New_Face( library,
                         /* "/usr/share/fonts/truetype/vlgothic/VL-Gothic-Regular.ttf", */
                         /* "/usr/share/fonts/opentype/noto/NotoSansCJK-Regular.ttc", */
                         filename,
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

    for (i = 0; i < wcslen(warg); ++i) {
      width_glyph = print_glyphinfo(face, warg[i]);
      if (width_glyph <= HALF_WIDTH_MAX) {
        width = HALF_WIDTH;
      } else {
        width = DOUBLE_WIDTH;
      }
      printf("width_glyph = %lc %lu (%d)\n", (unsigned int)warg[i], width_glyph, width);
    }

    return 0;
}
