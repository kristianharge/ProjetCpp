CC=g++
CFLAGS=-Wall -g -std=c++11
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
EXEC=projet
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)

all: $(EXEC)

projet: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

main.o: *.hh

%.o: %.cc
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)