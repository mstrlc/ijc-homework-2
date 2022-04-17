// htab_priv.h
// Řešení IJC-DU2, příklad 1), 19. 4. 2022
// Autor: Matyáš Strelec, FIT
// Přeloženo: clang 13.1.6

#ifndef __HTAB_PRIV_H__
#define __HTAB_PRIV_H__

#include "htab.h"

typedef struct htab_item
{
    struct htab_pair pair;
    struct htab_item *next;
} htab_item_t;

struct htab
{
    size_t size;
    size_t arr_size;
    htab_item_t **arr_ptr;
};

#endif // __HTAB_PRIV_H__