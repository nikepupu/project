attackGenerator.out: attackGenerator.o
	g++ -ansi -Wall -g attackGenerator.cpp -o attackGenerator.o

attackGenerator.o: attackGenerator.cpp
	g++ -Wall -g -ansi -c attackGenerator.cpp

clean: 
	rm -f attackGenerator.out *.o
