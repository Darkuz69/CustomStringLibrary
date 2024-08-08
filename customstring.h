#ifndef CUSTOMSTRING_H
#define CUSTOMSTRING_H

#include <stdlib.h>

typedef char* custom_string;

custom_string getString(const custom_string prompt);
custom_string createString(const custom_string string);
size_t getLength(const custom_string string);
void freeStrings();

#endif //CUSTOMSTRING_H
