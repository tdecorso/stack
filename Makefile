all: test

test: test.c test.h stack.h
	gcc -g test.c -o test

clean:
	rm test
