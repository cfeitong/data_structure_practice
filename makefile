CC = clang
FLAG = -Wall -g

test: bin/list.test bin/darray.test

bin/list.o: list.c list.h
	$(CC) $(FLAG) -c list.c -o bin/list.o

bin/list.test: bin/list.o test/test_list.c test/test_list.h
	$(CC) $(FLAG) -c test/test_list.c -o bin/test_list.o
	$(CC) bin/list.o bin/test_list.o -o bin/list.test

bin/darray.o: darray.c darray.h
	$(CC) $(FLAG) -c darray.c -o bin/darray.o

bin/darray.test: bin/darray.o test/test_darray.c test/test_darray.h
	$(CC) $(FLAG) -c test/test_darray.c -o bin/test_darray.o
	$(CC) bin/darray.o bin/test_darray.o -o bin/darray.test
