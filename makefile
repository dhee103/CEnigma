CC = g++
CFLAGS = -std=c++11 -O -Wall -Werror -Wextra -Wunused-function -pedantic -g
OBJS = Main.o Rotor.o Plugboard.o Reflector.o Component.o

.PHONY: clean

enigma: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^

test: enigma
	./tests.py

clean:
	rm -rf enigma *.o
