#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4096

int main(int argc, char *argv[])
{
    char * filename;
    int width_wc;
    int i;
    int char_value;
    FILE *fp;
    char readline[MAX] = {'\0'};
    char * find;

    if (argc != 2)
    {
        printf("Usage: ./ambiguous_width_comparison FONT_PATH\n");
        printf("Example: ./ambiguous_width_comparison \"filename\"\n");
        exit(-1);
    }
    filename = argv[1];
    setlocale(LC_ALL, "");

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Failed to open %s\n", filename);
        exit(-1);
    }

    while (fgets(readline, MAX, fp) != NULL) {
        // 改行を削除する
        if ((find = strchr(readline, '\n')) != NULL) {
            *find = '\0';
        }
        char_value = (int)strtol(readline, NULL, 16);
        //printf("%s %ld\n", readline, ul);
        width_wc = wcwidth((wchar_t)char_value);
        printf("%s %d\n", readline, width_wc);
    }
    fclose(fp);
    return 0;
}
