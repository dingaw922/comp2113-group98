FLAGS = -pedantic-errors -std=c++11

user.o: user.cpp user.h
	g++ $(FLAGS) -c $<

debris.o: debris.cpp debris.h source.h
	g++ $(FLAGS) -c $<

rocket.o: rocket.cpp rocket.h debris.h
	g++ $(FLAGS) -c $<

map.o: map.cpp map.h rocket.h debris.h 
	g++ $(FLAGS) -c $<

input.o: input.cpp input.h
	g++ $(FLAGS) -c $<

game.o: game.cpp game.h map.h rocket.h input.h debris.h user.h
	g++ -$(FLAGS) -c $<

menu.o: menu.cpp menu.h user.h game.h debris.h
	g++ $(FlAGS) -c $<

fileinout.o: fileinout.cpp fileinout.h user.h
	g++ $(FLAGS) -c $<

main.o: main.cpp user.h menu.h debris.h fileinout.h
	g++ $(FLAGS) -c $<

main: main.o user.o menu.o debris.o game.o rocket.o map.o input.o fileinout.o source.h
	g++ $(FLAGS) -g $^ -o $@
