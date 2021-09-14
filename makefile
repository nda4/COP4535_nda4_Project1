

Project1.exe : test.o
	g++ test.o -o Project1.exe

test.o :
	g++ -Wall -c test.cpp



run :
	./Project1.exe

clean :
	rm *.o
	rm *.exe



testDriven.exe : testDriven.o user.o hashTable.o
	g++ testDriven.o -o testDriven.exe user.cpp hashTable.cpp
	./testDriven.exe

testDriven.o : user.o hashTable.o
	g++ -Wall -c testDriven.cpp user.cpp hashTable.cpp

user.o : user.cpp user.hpp

hashTable.o : hashTable.cpp hashTable.hpp