// io.c
// Řešení IJC-DU2, příklad 2), 19. 4. 2022
// Autor: Matyáš Strelec, FIT
// Přeloženo: clang 13.1.6

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#include "io.h"

// Read one word from file into given array, returns number of characters read, if word is longer than max, shorten it, expect file ending with \n
int read_word(char *s, int max, FILE *f)
{
    char word[max+1]; // Store word in this array
    memset(word, '\0', max+1); // Set string to \0
    int character;    // Currently read character
    int count = 0;    // Character count
    bool allRead = false;
    static bool errorPrinted;

    // Read a character
    character = fgetc(f);
    // Skip all whitespace characters
    while (isspace(character))
    {
        character = fgetc(f);
    }

    // Read word
    for (int i = 0; i < max; i++)
    {
        // End if end of word or file is reached
        if (isspace(character) || character == EOF)
        {
            word[count] = '\0';
            allRead = true;
            break;
        }
        else
        {
            word[count] = character;
            count++;
            character = fgetc(f);
        }
    }

    // If word is longer than max, shorten it
    if(!allRead)
    {
        word[max] = '\0';
        if(!errorPrinted)
        {
            fprintf(stderr, "Word too long. Continuing with words shortened to %d characters (excluding '\\0').\n", max);
            errorPrinted = true;
        }

        // Skip all remaining characters of the word
        do
        {
            character = fgetc(f);
        }
        while (!isspace(character));

    }

    // Copy the word to the destination array and return number of characters
    strcpy(s, word);

    if (character == EOF)
        return EOF;
    else
        return count;
}
