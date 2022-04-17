// htab_lookup_add.c
// Řešení IJC-DU2, příklad 2), 19. 4. 2022
// Autor: Matyáš Strelec, FIT
// Přeloženo: clang 13.1.6

#include <stdio.h>
#include <stdlib.h>

#include "htab.h"
#include "htab_priv.h"

htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key)
{
    // Calculate the index in the table using hash function
    size_t index = htab_hash_function(key) % t->arr_size;
    htab_item_t *item_p = t->arr_ptr[index];

    // Attempt to lookup the key in the table
    while (item_p != NULL)
    {
        // Key is found, increment value and return pointer to the pair
        if (strcmp(item_p->pair.key, key) == 0)
        {
            return &item_p->pair;
        }
        
        // If not found, go to the next item
        item_p = item_p->next;
    }

    // Key was not found in the table, new item is added
    item_p = malloc(sizeof(htab_item_t));

    if (item_p == NULL)
    {
        fprintf(stderr, "Error allocating memory.\n");
        return NULL;
    }

    item_p->pair.key = key;
    item_p->next = t->arr_ptr[index];

    // Add the new item to the table
    t->arr_ptr[index] = item_p;
    t->size++;

    return &item_p->pair;
}