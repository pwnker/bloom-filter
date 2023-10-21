
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN(xs) sizeof((xs))/sizeof((xs)[0])

#define h1(x, m) x%m		// first  hash function
#define h2(x, m) (2*x+3)%m	// second hash function

/**
 * Adds a value to the bloom filter
 */
void bf_add(size_t *filter, size_t m, size_t v)
{
	size_t p1 = h1(v, m);
	size_t p2 = h2(v, m);
	
	filter[p1] = 1;
	filter[p2] = 1;
}

/**
 * Resets all values of the bloom filter to false (0)
 */
void bf_clear(size_t *filter, size_t fl)
{
	for (size_t i = 0; i < fl; ++i) {
		filter[i] = 0;
	}
}

/**
 * Prints the bloom filter
 */
void bf_print(size_t *filter, size_t fl)
{
	printf("[ ");
	for (size_t i = 0; i < fl; ++i) {
		printf("%zu ", filter[i]);
	}
	printf("]\n");
}

int main()
{
	size_t m = 5;
	size_t filter[m];

	bf_add(filter, 5, 15);
	bf_print(filter, ARRAY_LEN(filter));
	bf_clear(filter, ARRAY_LEN(filter));
	bf_print(filter, ARRAY_LEN(filter));

	return 0;
}

