CFLAGS = -Wall -Wextra -Werror

rock: rock.c parser_for_circle.c errors.c
	$(CC) $(CFLAGS) -o $@ $^
