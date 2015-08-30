
CFLAGS=
LIBS=
CC=gcc
MKDIR_P=mkdir -p
BIN_DIR=bin

%.o:%.c
	$(CC) $(CFLAGS) $(LIBS) $< -c

all: display_wcwidth

display_wcwidth: display_wcwidth.o
	$(MKDIR_P) $(BIN_DIR)
	$(CC) $(CFLAGS) $(LIBS) -o $(BIN_DIR)/$@ $^

clean:
	rm -f *.o $(BIN_DIR)/display_wcwidth
