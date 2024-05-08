#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

String* read_file(const char* file_path) {
    FILE* file;
    fopen_s(&file, file_path, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file: %s\n", file_path);
        return NULL;
    }

    String* string = malloc(sizeof(String));

    fseek(file, 0, SEEK_END);
    const usize file_size = ftell(file);
    rewind(file);

    char* buffer = malloc((file_size + 1) * sizeof(char));
    const usize read = fread(buffer, sizeof(char), file_size, file);
    if (read != file_size) {
        fprintf(stderr, "Could not read file: %s\n", file_path);
        return NULL;
    }
    buffer[file_size] = '\0';

    string->start = buffer;
    string->length = file_size;

    fclose(file);

    return string;
}