all: main

main:
	gcc -o main source/*.c -lm

clean:
	rm main