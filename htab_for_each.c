// htab_for_each.c
// Řešení IJC-DU2, příklad 2), 19. 4. 2022
// Autor: Matyáš Strelec, FIT
// Přeloženo: clang 13.1.6

#include "htab.h"
#include "htab_priv.h"

// Go through all elements in the table and call the function on each
void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data))
{
    // Go through all array elements in the table
    for (size_t i = 0; i<t->arr_size; i++)
    {
        // Go through all items in array element
        htab_item_t *item_p = t->arr_ptr[i];

        // Call a function on each pair and go to next
        while (item_p != NULL)
        {
            (*f)(&item_p->pair);
            item_p = item_p->next;
        }
    }
}