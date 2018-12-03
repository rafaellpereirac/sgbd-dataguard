all: dataguard

dataguard: main.o funcoes.o
	gcc -o dataguard main.o funcoes.o

main.o: main.c funcoes.h
	gcc -o main.o main.c -c -W

funcoes.o: funcoes.c funcoes.h
	gcc -o funcoes.o funcoes.c -c -W