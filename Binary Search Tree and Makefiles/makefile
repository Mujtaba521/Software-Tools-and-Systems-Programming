main : main.o matrix.o bstree.o datatype.o
	cc -o mymatrix main.o matrix.o bstree.o datatype.o
main.o: main.c matrix.h bstree.h datatype.h
	cc -c main.c
matrix.o: matrix.c matrix.h bstree.o
	cc -c matrix.c

clean: 
	rm -f mymatrix *.o core
