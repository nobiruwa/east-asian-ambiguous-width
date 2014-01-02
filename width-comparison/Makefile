
CFLAGS=
LIBS=
CC=gcc

%.o:%.c
	$(CC) $(CFLAGS) $(LIBS) $< -c

all: display_wcwidth

display_wcwidth: display_wcwidth.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

clean:
	rm *.o display_wcwidth
