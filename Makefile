project: mymath.o mathtest.o
	cc *.o -o project -lm
mymath.o: mymath.c mymath.h
	cc -c mymath.c 
mathtest.o: mathtest.c mymath.h mymath.o
	cc -c mathtest.c 
