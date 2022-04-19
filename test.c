#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "htab.h"
#include "htab_priv.h"
#include "io.h"

void print_count(htab_pair_t *data)
{
    printf("%s\t%d\n", data->key, data->value);
}

void print_keys(htab_pair_t *data)
{
    printf("%s ", data->key);
}

int main()
{
    htab_t *first = htab_init(5);

    htab_lookup_add(first, "key1");
    htab_lookup_add(first, "key2");
    htab_lookup_add(first, "key3");
    htab_lookup_add(first, "key4");
    htab_lookup_add(first, "key5");
    htab_lookup_add(first, "key6");
    htab_lookup_add(first, "key7");
    htab_lookup_add(first, "key8");
    htab_lookup_add(first, "key9");
    htab_lookup_add(first, "key10");

    printf("lookup: %s\n", htab_lookup_add(first, "key1")->key);

    printf("table of size %zu created, printing all items:\n", first->arr_size);
    htab_for_each(first, print_keys);
    printf("\n");
    htab_resize(first, 100);
    printf("resized\n");
    printf("table resize, new size %zu, printing all items:\n", first->arr_size);
    htab_for_each(first, print_keys);
    htab_erase(first, "key1");
    htab_erase(first, "key2");
    htab_erase(first, "key3");
    htab_erase(first, "key4");
    htab_erase(first, "key5");
    htab_erase(first, "key6");
    htab_erase(first, "key7");
    htab_erase(first, "key8");

    printf("trying to free\n");
    htab_free(first);
    printf("free complete\n");
    printf("end\n");
}
