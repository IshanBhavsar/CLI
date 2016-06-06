
main.exe : main.o autocomplete.o
	gcc main.o autocomplete.o -o main.exe

main.o : main.cpp
	gcc -c main.cpp

autocomplete.o : autocomplete.c
	gcc -c autocomplete.c
	
terminal.o : terminal.c
	gcc -c terminal.c