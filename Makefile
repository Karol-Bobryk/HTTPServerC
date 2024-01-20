compile:
	gcc *.c -o ./bin/main -lm; valgrind ./bin/main --track-origins=yes 
