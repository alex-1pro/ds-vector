lib: vector.c
	gcc -c  vector.c
	ar cr dslib.a vector.o

clear: 
	-rm *.o *.a
