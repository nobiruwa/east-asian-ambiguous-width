
CFLAGS=`freetype-config --cflags`
LIBS=`freetype-config --libs`
CC=gcc
MKDIR_P=mkdir -p
BIN_DIR=bin

.PHONY: dir

%.o:%.c
	$(CC) $(CFLAGS) $(LIBS) $< -c

all: $(BIN_DIR)/commandline $(BIN_DIR)/ambiguous_width_comparison

$(BIN_DIR)/commandline: commandline.o wcwidth_cygwin.o
	$(MKDIR_P) $(BIN_DIR)
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

$(BIN_DIR)/ambiguous_width_comparison: ambiguous_width_comparison.o wcwidth_cygwin.o
	$(MKDIR_P) $(BIN_DIR)
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

clean:
	rm -f *.o
	rm -rf bin
