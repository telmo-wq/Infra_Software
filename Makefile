tensor: main.o
	gcc main.o -o tensor -lm

main.o: main.c
	gcc -c main.c

run: tensor
	./tensor

clean:
	rm -f * .o tensor