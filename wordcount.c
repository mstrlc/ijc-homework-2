// wordcount.c
// Řešení IJC-DU2, příklad 2), 19. 4. 2022
// Autor: Matyáš Strelec, FIT
// Přeloženo: clang 13.1.6

#include <stdio.h>
#include <ctype.h>

#include "io.h"
#include "htab.h"

#define MAX_WORD_LEN 127 // Maximum length of a word is 127 characters + \0

// Print output as specified in the assignment
void print_count(htab_pair_t *data)
{
    printf("%s\t%d\n", data->key, data->value);
}

// Count how many times words are used in given file
int main()
{
    // Create new hashtable
    htab_t *table = htab_init(7919); // Prime number is used to minimze collisions

    char string[MAX_WORD_LEN+1];   // String to store word, +1 for \0

    // Read words from file
    while(read_word(string, MAX_WORD_LEN, stdin) != EOF)
    {
        // Look the word in the able, also increase the value == number of occurences
        htab_lookup_add(table, string)->value++;
    }

    // Print output
    htab_for_each(table, print_count);
}
