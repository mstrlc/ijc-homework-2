# Makefile 
# Řešení IJC-DU2, 19. 4. 2022
# Autor: Matyáš Strelec, FIT

CC = gcc
CFLAGS = -std=c11 -pedantic -Wall -Wextra

.PHONY: all clean zip

all: tail wordcount wordcount-dynamic wordcount-dynamic-mac libhtab.a libhtab.so libhtab.dylib test

# Task 1
tail: tail.o
	$(CC) $(CFLAGS) -o $@ $<

tail.o: tail.c
	$(CC) $(CFLAGS) -c $<

# Task 2
wordcount: wordcount.o io.o libhtab.a
	$(CC) $(CFLAGS) $^ -o $@

wordcount-dynamic: wordcount.o io.o libhtab.so
	$(CC) $(CFLAGS) $^ -o $@

wordcount-dynamic-mac: wordcount.o io.o libhtab.dylib
	$(CC) $(CFLAGS) $^ -o $@

test: test.o libhtab.so
	$(CC) $(CFLAGS) $^ -o $@

# Libraries
# Static -- .a for both macOS and Linux
libhtab.a: htab_bucket_count.o htab_clear.o htab_erase.o htab_find.o htab_for_each.o htab_free.o htab_hash_function.o htab_init.o htab_lookup_add.o htab_resize.o htab_size.o
	ar rcs libhtab.a $^

# Dynamic -- .dylib for macOS, .so for Linux
libhtab.dylib: htab_bucket_count.o htab_clear.o htab_erase.o htab_find.o htab_for_each.o htab_free.o htab_hash_function.o htab_init.o htab_lookup_add.o htab_resize.o htab_size.o
	$(CC) $(CFLAGS) -fPIC -shared $^ -o $@

libhtab.so: htab_bucket_count.o htab_clear.o htab_erase.o htab_find.o htab_for_each.o htab_free.o htab_hash_function.o htab_init.o htab_lookup_add.o htab_resize.o htab_size.o
	$(CC) $(CFLAGS) -fPIC -shared $^ -o $@

%.o: %.c htab.h htab_priv.h
	$(CC) $(CFLAGS) -fPIC -c $<

clean:
	rm *.o *.a *.so *.dylib tail wordcount- wordcount wordcount-dynamic wordcount-dynamic-mac *.zip

zip:
	zip xstrel03.zip *.h *.c *.cc Makefile