#ifndef CUSTOM_STRING_H
#define CUSTOM_STRING_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef char* string;

string get_string(const string prompt, const unsigned int size, string location);
int length_string(const string text);
bool isvowel(char character);
bool isconsonant(char character);
void capitalize(const string text);
void convert_to_upper(const string text);
void convert_to_lower(const string text);
void swapcase(const string text);

#endif // !DEBUG
