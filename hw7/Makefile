CC = clang
CFLAGS = -Wall -Wextra -g

all: businessdb

businessdb: main.o hash_table.o customeer.o fileIO.o
	$(CC) $(CFLAGS) -o businessdb main.o hash_table.o customeer.o fileIO.o

main.o: main.c hash_table.h fileIO.h customer.h
	$(CC) $(CFLAGS) -c main.c

hash_table.o: hash_table.c hash_table.h customer.h
	$(CC) $(CFLAGS) -c hash_table.c

customer.o: customeer.c customer.h
	$(CC) $(CFLAGS) -c customeer.c

file_io.o: fileIO.c fileIO.h hash_table.h customer.h
	$(CC) $(CFLAGS) -c fileIO.c

clean:
	rm -f *.o businessdb
format:
	clang-format -i -style=file *.[ch]

test:	test.o hash_table.o customeer.o fileIO.o
	$(CC) $(CFLAGS) -o test test.o hash_table.o customeer.o fileIO.o
