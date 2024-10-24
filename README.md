# Simulation
Escape simulation from zombie
List of source :
README : Explaination for files
Makefile : To compile easy
defs.h : A kind of data collection
Escape.cc, Escape.h : Making Escape object with source file and header file
Hero.cc Hero.h : Making Hero obejct with source file and header file
main.cc : Making main 
List.cc List.h : Making List (template) object to collect Paritipants object with source file and header file
Participants.cc Paritipants.h : Making Participants object, which is parent class of Hero, Snorc objects and Ninja object with source file and header file
Ninja.cc Ninja.h : Making Ninja object, which is helping Hero(Timmy and Harold) out with source file and header file
Snor.cc Snor.h : Making Snor object to make Snor object, which is snow with source file and header file
MoveBehaviour.h MoveBeahviour.cc : Making MoveBehaviour object, in here, each behaviour defined and each participants follow it, and change when one of condition is satisfied.
random.cc : To make random int 

How to run ?
make -> ./a05

make : compile and make object files of each source & header file and make a04 file to exectue the source and header files
./a05 : execute command

How to clean ?
make clean : delete every obejct files. 
