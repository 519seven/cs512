all: pa-6.bin

imp: pa-6-imp.bin

pa-6.bin: main.o
	g++ -o pa-6.bin main.o

#main.o: main.cpp unorderedLinkedList.h linkedList.h
#	g++ -Wall -c -g main.cpp

main.o: main.cpp queueADT.h queueAsArray.h
	g++ -Wall -c -g main.cpp

<<<<<<< HEAD
pa-6-imp.bin: main.o unorderedLinkedListImp.o
	g++ -o pa-6.bin main.o

unorderedLinkedListImp.o: unorderedLinkedListImp.cpp linkedList.h unorderedLinkedList.h
	g++ -Wall -c -g unorderedLinkedListImp.cpp
=======
pa-6-imp.bin: main.o queueAsArrayImp.o
	g++ -o pa-6-imp.bin main.o queueAsArrayImp.o

queueAsArrayImp.o: queueAsArrayImp.cpp queueAsArray.h queueADT.h
	g++ -Wall -c -g queueAsArrayImp.cpp
>>>>>>> 504b159055789d13bc97b66c061f63fc43f8ca26

clean:
	rm *.bin *.o ._*