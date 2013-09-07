
CFLAGS=`freetype-config --cflags`
LIBS=`freetype-config --libs`
CC=gcc

%.o:%.c
	$(CC) $(CFLAGS) $(LIBS) $< -c

all: commandline ambiguous_width_comparison

commandline: commandline.o wcwidth_cygwin.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

ambiguous_width_comparison: ambiguous_width_comparison.o wcwidth_cygwin.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

clean:
	rm *.o commandline ambiguous_width_comparison.c
