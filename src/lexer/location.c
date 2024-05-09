#include <stdio.h>

#include "lexer/location.h"

void print_location(Location location) {
    printf("<%40s> - (%7lu:%4lu)\n", location.file_path, location.line, location.column);
}
