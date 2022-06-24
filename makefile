all: main

main:
	gcc -o main source/*.c -lm

clean: all
	rm -f main
	rm -f entrada/*.*
	rm -f saida/*.*