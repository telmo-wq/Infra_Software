tensor: main.o biblioteca.o
	gcc main.o biblioteca.o -o tensor -lm

main.o: main.c
	gcc -c main.c

biblioteca.o: biblioteca.c biblioteca.h
	gcc -c biblioteca.c

clean: 
	rm *.o tensor