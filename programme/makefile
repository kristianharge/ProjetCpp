CC=g++
CFLAGS=-Wall -std=c++11 -g
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
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
	@rm -rf *.o $(EXEC)

mrproper: clean
	@rm -rf $(EXEC)