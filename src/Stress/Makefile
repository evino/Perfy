CC      := clang
CFLAGS  := -O3 -march=native -Wall -Wextra -funroll-loops
LDFLAGS := -pthread

SRC     := main.c int_stress.c list.c
OBJ     := $(SRC:.c=.o)
BIN     := stress

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN) $(LDFLAGS)

%.o: %.c intrate.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BIN)

.PHONY: all clean
