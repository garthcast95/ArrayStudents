all: main

main: main.o Date.o Address.o Student.o
		g++ main.o Date.o Address.o Student.o -o main

main.o: main.cpp
		g++ -c main.cpp

Date.o: Date.cpp
		g++ -c Date.cpp
		
Address.o: Address.cpp
		g++ -c Address.cpp
		
Student.o: Student.cpp
		g++ -c Student.cpp
		
clean:
	rm -f *o main

