#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
printcomb(int m, int n, unsigned char *c, char *data[])
{
	int ri;
	char *item, *token, *saveptr;
	int i, r;
	r = n;
	for (i = n; i--;) {
		/* If entry contains more than one non-combinable items then recursively
		 * expand the data when printing.
		 *
		 * E.g. 1 2 "3 4" will become:
		 "    1 2 3
		 "    1 2 4
		 */
		if (strchr(data[c[i]-1], ' ')) {
			/* Here we duplicate the string because strtok_r manipulates the text content in-place. */
			item = strdup(data[c[i]-1]);
			token = strtok_r(item, " ", &saveptr);
			while (token != NULL) {
				char *d[m + 1];
				/* Generating a new data array */
				for (ri = n; ri--;) {
					d[c[ri]-1] = (ri == i ? token : data[c[ri]-1]);
				}
				printcomb(m, n, c, d);
				token = strtok_r(NULL, " ", &saveptr);
			}
			free(item);
			return;
		}
	}

	/* Print the generated combination */
	for (i = n; i--;) {
		printf("%s%c", data[c[i]-1], i ? ' ': '\n');
	}
}

void
comb(int r, int n, unsigned char *c, char *argv[])
{
	int i;
	for (i = 0; i < n; i++)
		c[i] = n - i;

	while (1) {
		printcomb(r, n, c, argv);

		i = 0;
		if (c[i]++ < r) continue;

		for (; c[i] >= r - i;) if (++i >= n) return;
		for (c[i]++; i; i--) c[i-1] = c[i] + 1;
	}
}

int
main(int argc, char *argv[])
{
	if (argc < 3) {
		fprintf(stderr, "Usage: %s <sample size> <value1> <value2> ... <valueN>\n", argv[0]);
		return 1;
	}

	int r = atoi(argv[1]);
	int n = argc - 2;

	if (n < r) {
		fprintf(stderr, "Not enough values; have %d needed at least %d\n", n, r);
		return 1;
	}

	argv+=2;

	unsigned char buf[n];
	comb(n, r, buf, argv);

	return 0;
}