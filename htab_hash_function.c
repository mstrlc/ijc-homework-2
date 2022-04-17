// htab_hash_function.c
// Řešení IJC-DU2, příklad 2), 19. 4. 2022
// Autor: Matyáš Strelec, FIT
// Přeloženo: clang 13.1.6

#include <stdint.h>

#include "htab.h"
#include "htab_priv.h"

// SDBM hash function from http://www.cse.yorku.ca/~oz/hash.html
// Return hash value for given string
size_t htab_hash_function(htab_key_t str)
{
    uint32_t h = 0;     // musí mít 32 bitů
    const unsigned char *p;
    
    for(p = (const unsigned char *) str; *p != '\0'; p++)
    {
        h = 65599 * h + *p;
    }
       
    return h;
}