CC= gcc
FLAGS= -Wall -g

.PHONY: all clean

all : txtfind isort

rebuild: clean all

clean:
	rm  txtfind isort

isort:
	$(CC) $(FLAGS) -o isort isort.c

txtfind:
	$(CC) $(FLAGS) -o txtfind txtfind.c