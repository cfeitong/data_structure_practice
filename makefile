CC = clang
FLAG = -Wall -g

test: bin/list.test bin/darray.test bin/stack.test bin/queue.test bin/deque.test bin/string.test
	cd bin &&\
	./list.test &&\
	./darray.test &&\
	./stack.test &&\
	./queue.test &&\
	./deque.test &&\
	./string.test

bin/string.o: string.c string.h
	$(CC) $(FLAG) -c string.c -o bin/string.o

bin/string.test: bin/string.o bin/list.o test/test_string.c test/test_string.h
	$(CC) $(FLAG) -c test/test_string.c -o bin/test_string.o
	$(CC) bin/string.o bin/list.o bin/test_string.o -o bin/string.test

bin/deque.o: deque.c deque.h
	$(CC) $(FLAG) -c deque.c -o bin/deque.o

bin/deque.test: bin/deque.o bin/list.o test/test_deque.c test/test_deque.h
	$(CC) $(FLAG) -c test/test_deque.c -o bin/test_deque.o
	$(CC) bin/deque.o bin/list.o bin/test_deque.o -o bin/deque.test

bin/queue.o: queue.c queue.h
	$(CC) $(FLAG) -c queue.c -o bin/queue.o

bin/queue.test: bin/queue.o bin/list.o test/test_queue.c test/test_queue.h
	$(CC) $(FLAG) -c test/test_queue.c -o bin/test_queue.o
	$(CC) bin/queue.o bin/list.o bin/test_queue.o -o bin/queue.test

bin/stack.o: stack.c stack.h
	$(CC) $(FLAG) -c stack.c -o bin/stack.o

bin/stack.test: bin/stack.o bin/list.o test/test_stack.c test/test_stack.h
	$(CC) $(FLAG) -c test/test_stack.c -o bin/test_stack.o
	$(CC) bin/stack.o bin/list.o bin/test_stack.o -o bin/stack.test

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
