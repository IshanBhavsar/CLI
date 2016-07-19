main.exe : main.o autocomplete.o terminal.o helper.o
	g++ main.o terminal.o autocomplete.o helper.o -o Terminal.exe

autocomplete.o : autocomplete.cpp
	g++ -c autocomplete.cpp
terminal.o : terminal.cpp
	g++ -c terminal.cpp
helper.o : helper.cpp
	g++ -c helper.cpp	
main.o : main.cpp
	g++ -c main.cpp
