// htab_free.c
// Řešení IJC-DU2, příklad 2), 19. 4. 2022
// Autor: Matyáš Strelec, FIT
// Přeloženo: clang 13.1.6

#include <stdlib.h>
#include <stdio.h>

#include "htab.h"
#include "htab_priv.h"

// Free allocated memory for the table
void htab_free(htab_t * t)
{
    htab_clear(t);
    free(t);
}