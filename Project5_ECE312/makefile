UTPodDriver: UTPodDriver.o UTPod.o Song.o
	g++ -o UTPodDriver UTPodDriver.o UTPod.o Song.o

UTPodDriver.o: UTPodDriver.cpp UTPod.h Song.h
	g++ -c UTPodDriver.cpp -o UTPodDriver.o

UTPod.o: UTPod.cpp UTPod.h Song.h
	g++ -std=c++11 -c UTPod.cpp -o UTPod.o

Song.o: Song.cpp Song.h
	g++ -c Song.cpp -o Song.o

clean:
	rm -f *.o UTPodDriver
