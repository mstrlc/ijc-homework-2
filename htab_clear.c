// htab_clear.c
// Řešení IJC-DU2, příklad 2), 19. 4. 2022
// Autor: Matyáš Strelec, FIT
// Přeloženo: clang 13.1.6

#include <stdlib.h>
#include <stdio.h>

#include "htab.h"
#include "htab_priv.h"

// Clear all elements in the table, table remains empty after the call
void htab_clear(htab_t * t)
{
    for (size_t i = 0; i<t->arr_size; i++)
    {
        htab_item_t *item_p = t->arr_ptr[i];

        while (item_p != NULL)
        {
            htab_item_t *tmp = item_p;

            free((char *)item_p->pair.key);
            free(item_p);

            item_p = tmp->next;
        }
    }
    
    t->arr_size = 0;
    t->size = 0;
    
    free(t->arr_ptr);
}
