// htab_size.c
// Řešení IJC-DU2, příklad 2), 19. 4. 2022
// Autor: Matyáš Strelec, FIT
// Přeloženo: clang 13.1.6

#include "htab.h"
#include "htab_priv.h"

// Return number of elements in table
size_t htab_size(const htab_t * t)
{
    if (t == NULL)
        return 0;
    else
        return t->size;
}