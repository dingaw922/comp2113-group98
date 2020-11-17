FLAGS = -pedantic-errors -std=c++11

menu.o: menu.cpp menu.h
	g++ $(FLAGS) -c $<

user.o: user.cpp user.h
	g++ $(FLAGS) -c $<

main.o: main.cpp menu.h user.h
	g++ -$(FLAGS) -c $<

main: main.o menu.o user.o
	g++ $(FLAGS) $^ -o $@
