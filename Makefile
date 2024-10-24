OPT = -Wall

a05 : main.o Participants.o Escape.o Hero.o MoveBehaviour.o Ninja.o Snorc.o random.o 
	g++ $(OPT) -o a05 main.o Participants.o Escape.o Hero.o MoveBehaviour.o Ninja.o Snorc.o random.o

main.o: main.cc defs.h
	g++ $(OPT) -g -c main.cc 

Participants.o: Participants.cc Participants.h
	g++ $(OPT) -g -c Participants.cc

Escape.o : Escape.cc Escape.h List.h
	g++ $(OPT) -g -c Escape.cc

Hero.o : Hero.cc Hero.h
	g++ $(OPT) -g -c Hero.cc

MoveBehaviour.o : MoveBehaviour.cc MoveBehaviour.h
	g++ $(OPT) -g -c MoveBehaviour.cc

Ninja.o : Ninja.cc Ninja.h
	g++ $(OPT) -g -c Ninja.cc 

Snorc.o : Snorc.cc Snorc.h
	g++ $(OPT) -g -c Snorc.cc

random.o : random.cc
	g++ $(OPT) -c random.cc


clean:
	rm -f *.o a05
