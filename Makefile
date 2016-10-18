try: mymath.o try.o
	cc *.o -o try
math.o: mymath.c mymath.h
	cc -c mymath.c -Wall
test.o: test.c mymath.h
	cc -c test.c -Wall
