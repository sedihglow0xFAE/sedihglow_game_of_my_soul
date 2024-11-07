/*
 * file: main.c
 * This is to demonstrate how a email can plae a string in the starting
 * location of the message, after saying hi.
 */

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define GT_NO_ARGS	 1
#define PROG_NAME_INDEX  1
#define NAME_INPUT_INDEX 2
#define NUM_NAME_LENGTHS 1
#define NAME_MAX	 748 /* longest name in the world with '\0' */

int main(int argc, char **argv)
{
	char *name = NULL;
	size_t *name_len;

	/* we only need one size_t for the len */
	name_len = calloc(size_t, NUM_NAME_LENGTHS);
	if (!name_len) {
		perror(errno);
		exit(EXIT_FAILURE);
	}

	if (argc > GT_NO_ARGS) {
		name_len = strnlen(argv[NAME_INPUT_INDEX]);
		name = calloc(char, *name_len);
		if (!name) {
			/* forget the arg for perror but errno prolly */
			perror(errno);
			exit(EXIT_FAILURE);
		}

		/*
		 * must chance if name_len has more lengths,
		 * name_len[i], same for above calloc()
		 */
		strncpy(name, argv[NAME_INPUT_INDEX], *name_len);
	}

	/* quick way for a most basic example */
	printf("Correct result: "
	       "Hi %s\n,", argv[NAME_INPUT_INDEX]);

	/*
	 * proper way for a less quick example probably with not enough
	 * error checking.
	 */
	printf("Hi %s\n", *name);

	free(name_len);
	free(name);

	exit(EXIT_SUCCESS);
}
