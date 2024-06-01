#include "custom_string.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

string get_string(const string prompt, const unsigned int size, string location) {
  /* Description: Saves a string to a pointer with a null terminator, given its size
   * Parameters: const char* prompt - Displays the given prompt
   *             const int size - Size of your string
   *                            - "size" must be greater than 0
   *             string location - The pointer you want the text to save
   * Return type: "void" */
  if (size == 0) {
    return NULL;
  }

  if (location != NULL) {
    free(location);
  }

  string str = (string)malloc(size + 1 * sizeof(char));
  if (str == NULL) {
    return NULL;
  }

  int i = 0;
  char ch;
  printf("%s", prompt);
  while((ch = getchar()) != '\n' && ch != EOF && i < size) {
    str[i++] = ch;
  }

  str[i] = '\0';

  return str;
}

int length_string(const string text) {
  /* Description: Returns the length of the string
   * Parameters: const string text - The string you want to get its length
   * Return type: "int" */
  if (text == NULL) {
    return 0;
  }

  int counter = 0;
  int i = 0;
  while(text[i] != '\0') {
    if (text[i++] != '\0') {
      counter++;
    }
  }

  return counter;
}

bool isvowel(char character) {
  /* Description: Checks if the given character is vowel
   * Parameters: char character - The character you want to check
   * Return type: "bool" */
  char c = (char)tolower(character);
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
    return true;
  }
  return false;
}


bool isconsonant(char character) {
  /* Description: Checks if the given character is consonant
   * Parameters: char character - The character you want to check
   * Return type: "bool" */
  char c = (char)tolower(character);
  if (c != 'a' || c != 'e' || c != 'i' || c != 'o' || c != 'u') {
    return true;
  }
  return false;
}

void capitalize(const string text) {
  /* Description: Capitalizes the first character of a string
   * Parameters: const string text - The string you want to capitalize
   * Return type: "void" */
  if (text[0] >= 97 && text[0] <= 122) {
    text[0] -= 32;
  }
}

void convert_to_upper(const string text) {
  /* Description: Converts every letter on a string to uppercase
   * Parameters: const string text - The string you want to convert
   * Return type: "void" */
  int i = 0;
  while(text[i] != '\0') { 
    if (text[i] >= 97 && text[i] <= 122) {
      text[i] -= 32;
    }
    i++;
  }
}

void convert_to_lower(const string text) {
  /* Description: Converts every letter on a string to lowercase
   * Parameters: const string text - The string you want to convert
   * Return type: "void" */
  int i = 0;
  while(text[i] != '\0') { 
    if (text[i] >= 65 && text[i] <= 90) {
      text[i] += 32;
    }
    i++;
  }
}

void swapcase(const string text) {
  /* Description: Swaps the casing of every letter on a string
   * Parameters: const string text - The string you want to convert
   * Return type: "void" */
  int i = 0;
  while(text[i] != '\0') { 
    if (text[i] >= 65 && text[i] <= 90) {
      text[i] += 32;
    } else if (text[i] >= 97 && text[i] <= 122) {
      text[i] -= 32;
    }
    i++;
  }
}
