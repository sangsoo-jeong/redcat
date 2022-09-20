CC  = gcc
CFLAGS =-I.
DEPS = essential.h menu.h findfirst.h spec.h

# test
# gcc -c findfirst.c main.c spec.c && gcc -o main main.o findfirst.o spec.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

execute: main.o menu.o findfirst.o spec.o
	$(CC) -o main main.o menu.o findfirst.o spec.o