#include "customstring.h"
#include <stdlib.h>
#include <stdio.h>

static custom_string *strings = NULL;
size_t MAXIMUM_STRINGS = SIZE_MAX / sizeof(custom_string);
size_t strings_count = 0;

custom_string createString(const custom_string string) {
    if(strings_count > MAXIMUM_STRINGS) {
        fprintf(stderr, "CustomStringError: Maximum Limit of strings have reached!!");
        return NULL;
    }

    custom_string buffer;
    size_t length = 0;
    size_t capacity = 0;

    while(string[length] != '\0' && string[length] != EOF) {
        if(length + 1 > capacity) {
            if(capacity < SIZE_MAX) {
                capacity++;
            } else {
                free(buffer);
                fprintf(stderr, "CustomStringError: Maximum length for a string have reached!!");
                return NULL;
            }

            custom_string temp = NULL;
            if(length == 0) {
                temp = (custom_string)malloc(capacity);
            } else {
                temp = (custom_string)realloc(buffer, capacity);
            }
            if(temp == NULL) {
                free(buffer);
                fprintf(stderr, "CustomStringError: Memory Allocation failed!!");
                return NULL;
            }
            buffer = temp;
        }

        buffer[length] = string[length];
        length++;
    }
    
    if(length == 0 && (string[length] == '\r' || string[length] == '\n' || string[length] == EOF)) {
        free(buffer);
        return NULL;
    }

    custom_string new_str = realloc(buffer, length + 1);
    if(new_str == NULL) {
        free(buffer);
        fprintf(stderr, "CustomStringError: Memory Allocation failed!!");
        return NULL;
    }
    new_str[length] = '\0';

    custom_string *new_strings = (custom_string*)realloc(strings, sizeof(custom_string) * (strings_count + 1));
    if(new_strings == NULL) {
        free(new_str);
        fprintf(stderr, "CustomStringError: Memory Allocation failed!!");
        return NULL;
    }
    strings = new_strings;
    strings[strings_count] = new_str;
    strings_count++;

    return new_str;
}

custom_string getString(const custom_string prompt) {
    if(strings_count > MAXIMUM_STRINGS) {
        fprintf(stderr, "CustomStringError: Maximum Limit of strings have reached!!");
        return NULL;
    }

    custom_string buffer;
    char ch;
    size_t length = 0;
    size_t capacity = 0;
    
    printf("%s", prompt);
    while((ch = getc(stdin)) != '\n' && ch != '\r' && ch != EOF) {
        if(length + 1 > capacity) {
            if(capacity < SIZE_MAX) {
                capacity++;
            } else {
                free(buffer);
                fprintf(stderr, "CustomStringError: Maximum length for a string have reached!!");
                return NULL;
            }

            custom_string temp = NULL;
            if(length == 0) {
                temp = (custom_string)malloc(capacity);
            } else {
                temp = (custom_string)realloc(buffer, capacity);
            }
            if(temp == NULL) {
                free(buffer);
                fprintf(stderr, "CustomStringError: Memory Allocation failed!!");
                return NULL;
            }
            buffer = temp;
        }

        buffer[length] = ch;
        length++;
    }

    if(length == 0 && (ch == '\r' || ch == '\n' || ch == EOF)) {
        free(buffer);
        return NULL;
    }

    custom_string new_str = realloc(buffer, length + 1);
    if(new_str == NULL) {
        free(buffer);
        fprintf(stderr, "CustomStringError: Memory Allocation failed!!");
        return NULL;
    }
    new_str[length] = '\0';

    custom_string *new_strings = (custom_string*)realloc(strings, sizeof(custom_string) * (strings_count + 1));
    if(new_strings == NULL) {
        free(new_str);
        fprintf(stderr, "CustomStringError: Memory Allocation failed!!");
        return NULL;
    }
    strings = new_strings;
    strings[strings_count] = new_str;
    strings_count++;

    return new_str;
}

size_t getLength(const custom_string string) {
    size_t counter = 0;

    for(int i = 0; string[i] != '\0'; i++) {
        counter++;
    }

    return counter;
}

void freeStrings() {
    for(size_t i = 0; i < strings_count; i++) {
        free(strings[i]);
        strings[i] = NULL;
    }
    free(strings);
    strings = NULL;
}