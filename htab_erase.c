// htab_erase.c
// Řešení IJC-DU2, příklad 2), 19. 4. 2022
// Autor: Matyáš Strelec, FIT
// Přeloženo: clang 13.1.6

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "htab.h"
#include "htab_priv.h"

// Erase the given key from the table, return true if successful, false otherwise
bool htab_erase(htab_t * t, htab_key_t key)
{
    // ! TODO
    // ! Když průměrná délka seznamů klesne pod vámi
    // ! definovaný limit AVG_LEN_MIN provede operaci
    // ! htab_resize na poloviční velikost.

    // Calculate the index in the table using hash function
    size_t index = htab_hash_function(key) % t->arr_size;
    htab_item_t *item_p = t->arr_ptr[index];

    // Attempt to lookup the key in the table
    while (item_p != NULL)
    {
        // Key is found, remove the item from the table
        if (strcmp(item_p->pair.key, key) == 0)
        {
            // Remove the item from the table
            t->arr_ptr[index] = item_p->next;

            // Free the item from memory
            free((char *)item_p->pair.key);
            free(item_p);

            // Decrease the number of items in the table
            t->size--;

            return true;
        }
        
        // If not found, go to the next item
        item_p = item_p->next;
    }

    // Key was not found in the table
    return false;
}
