CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: one_test two_test three_test four_test

one_test: one.o one_test.o
	$(CC) one.o one_test.o -o one_test

one.o: one.c midterm.h
	$(CC) $(CFLAGS) -c one.c

one_test.o: one_test.c midterm.h
	$(CC) $(CFLAGS) -c one_test.c

two_test: two.o two_test.o
	$(CC) two.o two_test.o -o two_test -lm

two.o: two.c midterm.h
	$(CC) $(CFLAGS) -c two.c

two_test.o: two_test.c midterm.h
	$(CC) $(CFLAGS) -c two_test.c

three_test: three.o three_test.o
	$(CC) three.o three_test.o -o three_test

three.o: three.c midterm.h
	$(CC) $(CFLAGS) -c three.c

three_test.o: three_test.c midterm.h
	$(CC) $(CFLAGS) -c three_test.c

four_test: four.o four_test.o
	$(CC) four.o four_test.o -o four_test

four.o: four.c midterm.h
	$(CC) $(CFLAGS) -c four.c

four_test.o: four_test.c midterm.h
	$(CC) $(CFLAGS) -c four_test.c

clean:
	rm -f one_test two_test three_test four_test *.o

format:
	clang-format -i -style=file *.[ch]
