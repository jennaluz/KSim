#
# ksim/Makefile
# cs-240.wilder..........g++ -std=c++11..........jenna-luz pura
# december 4, 2022.......pura0273@vandals.uidaho.edu
# ----------
# compiles all source files into object files.
# compiles all object files into one executable.
# ----------
#  to compile:
#		make
#
#  to run:
#  		make run
#
#  to clean:
#  		make clean
#

CC = g++
CFLAGS = -std=c++11 -Wall

HDRS := $(wildcard header/*.h)
SRCS := $(wildcard source/*.cpp)
OBJS := $(patsubst source/%.cpp, object/%.o, $(SRCS))
BIN = binary/ksim

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

object/%.o: source/%.cpp $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

run:
	./binary/ksim

clean:
	rm $(OBJS) $(BIN)
