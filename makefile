Project1.exe : test.o user.o hashTable.o
	g++ test.o -o Project1.exe user.cpp hashTable.cpp
	./Project1.exe

test.o : user.o hashTable.o
	g++ -Wall -c test.cpp user.cpp hashTable.cpp

clean :
	rm *.o
	rm *.exe
	rm rawdata.txt
	rm encrypteddata.txt;


testDriven.exe : testDriven.o user.o hashTable.o
	g++ testDriven.o -o testDriven.exe user.cpp hashTable.cpp
	./testDriven.exe

testDriven.o : user.o hashTable.o
	g++ -Wall -c testDriven.cpp user.cpp hashTable.cpp

user.o : user.cpp user.hpp

hashTable.o : hashTable.cpp hashTable.hpp