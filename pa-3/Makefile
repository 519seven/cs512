all: pa-3.bin

pa-3.bin: main.o newClockImp.o
	g++ -o pa-3.bin main.o newClockImp.cpp

main.o: main.cpp
	g++ -Wall -c -g main.cpp

newClockImp.o: newClockImp.cpp newClock.h
	g++ -Wall -c -g newClockImp.cpp newClock.h

clean:
	rm *.bin *.o ._* *.gch
