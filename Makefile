A3: A3.o
	g++ A3.o libGenerate.a -o KAP

A3.o: A3.cpp A3.h collect.h
	g++ -c A3.cpp
clea:
	rm*.o
