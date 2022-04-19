// htab_resize.c
// Řešení IJC-DU2, příklad 2), 19. 4. 2022
// Autor: Matyáš Strelec, FIT
// Přeloženo: clang 13.1.6

#include <stdio.h>
#include <stdlib.h>

#include "htab.h"
#include "htab_priv.h"

// Change size of table without changing its content
void htab_resize(htab_t *t, size_t newn)
{
    // Create variables to store elements of table while it is resized
    char *tableKeys[t->size];
    long tableValues[t->size];
    long tableIndex = 0;
    
    // Go through all items and store them in temporary variables
    for (size_t i = 0; i<t->arr_size; i++)
    {
        htab_item_t *item_p = t->arr_ptr[i];

        while (item_p != NULL)
        {
            tableKeys[tableIndex] = malloc(sizeof(char) * (strlen(item_p->pair.key) + 1));
            strcpy(tableKeys[tableIndex], item_p->pair.key);
            tableValues[tableIndex] = item_p->pair.value;
            tableIndex++;
            item_p = item_p->next;
        }
    }

    // Free table so it can reinitialized with new size
    htab_free(t);
    t = htab_init(newn);

    // Go through all items and insert them into resized table
    for (long i = 0; i < tableIndex; i++)
    {
        htab_lookup_add(t, tableKeys[i]);
        htab_find(t, tableKeys[i])->value = tableValues[i];
        free(tableKeys[i]);
    }
}
