// htab_init.c
// Řešení IJC-DU2, příklad 2), 19. 4. 2022
// Autor: Matyáš Strelec, FIT
// Přeloženo: clang 13.1.6

#include <stdio.h>
#include <stdlib.h>

#include "htab.h"
#include "htab_priv.h"

// Table constructor
htab_t *htab_init(size_t n)
{
    // Allocate memory for the table
    htab_t *table = malloc(sizeof(htab_t));
    if (table == NULL)
    {
        // Malloc error
        fprintf(stderr, "Error allocating memory.\n");
        return NULL;
    }

    // Initialize default values
    table->size = 0;
    table->arr_size = n;

    // Allocate memory for the array of items
    table->arr_ptr = malloc(n * sizeof(htab_item_t *));

    if (table->arr_ptr == NULL)
    {
        // Malloc error
        fprintf(stderr, "Error allocating memory.\n");
        free(table);
        return NULL;
    }

    // Initialize all items of array, NULL by default
    for (size_t i = 0; i < table->arr_size; i++)
    {
        table->arr_ptr[i] = NULL;
    }
    
    return table;
}
