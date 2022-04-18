// htab_clear.c
// Řešení IJC-DU2, příklad 2), 19. 4. 2022
// Autor: Matyáš Strelec, FIT
// Přeloženo: clang 13.1.6

#include <stdlib.h>

#include "htab.h"
#include "htab_priv.h"

// Clear all elements in the table, table remains empty after the call
void htab_clear(htab_t * t)
{
    // Go through all array elements in the table
    for (size_t i = 0; i < t->arr_size; i++)
    {
        // Go through all items in array element
        while (t->arr_ptr != NULL)
        {
            // Store current item pointer so it is possible to free and go to the next one after
            htab_item_t *temp_p = *t->arr_ptr;
            
            // Free the memory allocated for the item
            free(t->arr_ptr);

            // Set pointer to next item
            t->arr_ptr[i] = temp_p->next;
        }
    }

    // Set size to 0
    t->arr_size = 0;
    t->size = 0;
}
