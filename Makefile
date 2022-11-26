# /home/pura0273/homework/04/Makefile
# cs-240.wilder..........gcc..........jenna-luz pura
# december 4, 2022.......pura0273@vandals.uidaho.edu
# ----------
#  description
# ----------
#  to compile:
#
#  to clean:

CC = g++
CFLAGS = -std=c++11 -Wall

HDRS := $(wildcard header/*.h)
SRCS := $(wildcard source/*.cpp)
OBJS := $(patsubst source/%.cpp, object/%.o, $(SRCS))
BIN = binary/ksim

all: $(BIN)
	./$(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

object/%.o: source/%.cpp $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJS) $(BIN)
