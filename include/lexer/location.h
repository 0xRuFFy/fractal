#ifndef LOCATION_H_
#define LOCATION_H_

#include "defines.h"

typedef struct {
    const char* file_path;
    usize line;
    usize column;
} Location;

/**
 * @brief Print a location to the console.
 *
 * @param location The location to print.
 */
void print_location(Location location);

#endif //LOCATION_H_
