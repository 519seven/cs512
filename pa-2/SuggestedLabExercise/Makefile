all: main.bin

main.bin: testComplexNumber.o
	g++ -o main.bin testComplexNumber.o

testComplexNumber.o: testComplexNumber.cpp complexType.h complexTypeImp.cpp
	g++ -Wall -c -g testComplexNumber.cpp complexTypeImp.cpp

clean:
	rm *.bin *.o ._*

