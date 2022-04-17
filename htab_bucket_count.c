// htab_bucket_count.c
// Řešení IJC-DU2, příklad 2), 19. 4. 2022
// Autor: Matyáš Strelec, FIT
// Přeloženo: clang 13.1.6

#include "htab.h"
#include "htab_priv.h"

// Return number of items of array
size_t htab_bucket_count(const htab_t * t)
{
    if (t == NULL)
        return 0;
    else
        return t->arr_size;
}