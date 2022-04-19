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
    // Go through all array elements in the table
    for (size_t i = 0; i<t->arr_size; i++)
    {
        htab_item_t *item_p = t->arr_ptr[i];

        // Go through all items in array element
        while (item_p != NULL)
        {
            // Store current item pointer so it is possible to free and go to the next one after
            htab_item_t *tmp = item_p;

            // Free the memory allocated for the item
            free((char *)item_p->pair.key);
            free(item_p);

            // Set pointer to next item
            item_p = tmp->next;
        }
    }
    
    // Set size of the table to 0
    t->arr_size = 0;
    t->size = 0;
    
    // Free the memory allocated for the array
    free(t->arr_ptr);
}
