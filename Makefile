target = binary
source = $(target).c

CC = clang
CFLAGS = -Wall -Wextra -Werror

$(target): $(source) Makefile
	$(CC) $(CFLAGS) -o $@ $<

test: $(target)
	./$<

clean:
	rm -fv a.out *.o

allclean: clean
	rm -fv $(target)

vi:
	vi $(source)

