attackGenerator.out:
	g++ -Wall -g -ansi attackGenerator.cpp -o attackGenerator.out

clean: 
	rm -f attackGenerator.out *.o
