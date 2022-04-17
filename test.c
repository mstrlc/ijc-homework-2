#include <stdio.h>
#include <stdlib.h>

#include "htab.h"
#include "htab_priv.h"

int main()
{
    htab_t *table = htab_init(7);

    printf("table size: %zu\n", table->size);
    printf("hash \"brambora\": %zu\n", htab_hash_function("brambora")%table->arr_size);
    printf("hash \"autobus\": %zu\n", htab_hash_function("autobus")%table->arr_size);
    printf("hash \"kurecirizek\": %zu\n", htab_hash_function("kurecirizek")%table->arr_size);

    printf("\n");

    htab_lookup_add(table, "brambora");
    htab_lookup_add(table, "autobus");
    htab_lookup_add(table, "kurecirizek");
    htab_lookup_add(table, "chlebasmaslem");
    htab_lookup_add(table, "smazenysyr");
    htab_lookup_add(table, "pivecko");
    htab_lookup_add(table, "bramborovysalat");
    htab_lookup_add(table, "omeletasesunkou");

    printf("\"brambora\" value: %s\n", htab_find(table, "brambora")->key);
    printf("\"autobus\" value: %s\n", htab_find(table, "autobus")->key);
    printf("\"kurecirizek\" value: %s\n", htab_find(table, "kurecirizek")->key);

    printf("\n");

    printf("htab_size: %zu\n", htab_size(table)); 
    printf("htab_bucket_count: %zu\n", htab_bucket_count(table));

    printf("\n");

    printf("htab_find brambora: %s\n", htab_find(table, "brambora")->key);
    printf("htab_find autobus: %s\n", htab_find(table, "autobus")->key);
    printf("htab_find kurecirizek: %s\n", htab_find(table, "kurecirizek")->key);
    printf("htab_find chlebasmaslem: %s\n", htab_find(table, "chlebasmaslem")->key);
    printf("htab_find smazenysyr: %s\n", htab_find(table, "smazenysyr")->key);
    printf("htab_find neexistujici: %s\n", htab_find(table, "neexistujici"));
}
