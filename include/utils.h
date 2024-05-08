#ifndef UTIL_H_
#define UTIL_H_

#include "defines.h"

/**
 * @brief Reads the contents of a file into a string.
 * 
 * The string is allocated on the heap and must be freed by the caller.
 * If the file does not exist or cannot be read,
 * NULL is returned and an error message is printed to stderr.
 * 
 * @param file_path The path to the file to read.
 * 
 * @return The contents of the file as a string.
 */
String *read_file(const char *file_path);

#endif  // UTIL_H_