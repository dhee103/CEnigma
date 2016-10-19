CC = g++
CFLAGS = -std=c++11 -O -Wall -Werror -Wextra -Wformat -Wunused-function -pedantic -g
OBJS = Main.o Rotor.o Plugboard.o Reflector.o Component.o

.PHONY: clean

enigma: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

Main.o: Main.cpp
	$(CC) $(CFLAGS) -c $^

Rotor.o: Rotor.cpp Rotor.hpp
	$(CC) $(CFLAGS) -c $^

Plugboard.o: Plugboard.cpp Plugboard.hpp
	$(CC) $(CFLAGS) -c $^

Reflector.o: Reflector.cpp Reflector.hpp
	$(CC) $(CFLAGS) -c $^

Component.o: Component.cpp Component.hpp
	$(CC) $(CFLAGS) -c $^

clean:
	rm -rf enigma *.o
