#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_PATH_LENGTH     128
#define MAX_LINE_DATA_LENGTH     128

char log_string[]   = "log";
char start_note[]   = "/*";
char end_note[]     = "*/";

int main(int argc, char *argv[])
{
    unsigned char block_note_flag = 0;
    char *line_data = (char *)malloc(sizeof(char) * MAX_LINE_DATA_LENGTH);
    memset(line_data, 0, MAX_LINE_DATA_LENGTH);

    char *pfile_path = (char *)malloc(sizeof(char) * MAX_PATH_LENGTH);
    memset(pfile_path, 0, MAX_PATH_LENGTH);

    if (argc == 1) {
        strncpy(pfile_path, "test.txt", MAX_PATH_LENGTH - 1);
    } 
    else {
        strncpy(pfile_path, argv[1], MAX_PATH_LENGTH - 1);
    }

    FILE *fp = fopen(pfile_path, "r");
    if (fp == NULL) {
        printf("error when open file\n");
        free(pfile_path);
        free(line_data);
        return -1;
    }

    while (fgets(line_data, MAX_LINE_DATA_LENGTH, fp) != NULL) {
        if (block_note_flag == 1) {
            if (strstr(line_data, end_note)) {
                block_note_flag = 0;
            }
            continue;
        }
        else {
            if (strstr(line_data, start_note)) {
                block_note_flag = 1;
                continue;
            }
            else if (strstr(line_data, log_string)) {
                continue;
            }
            printf("%s", line_data);
        }
    }

    free(pfile_path);
    free(line_data);
    return 0;
}