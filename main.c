
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN(xs) sizeof((xs))/sizeof((xs)[0])

#define h1(x, m) x%m		// first  hash function
#define h2(x, m) (2*x+3)%m	// second hash function

typedef struct {
	size_t m;
	int *filter;
} BloomFilter;

void bf_init(BloomFilter *bf, size_t m)
{
	(*bf).m = m;
	int tmp[m];
	(*bf).filter = tmp;
	for (size_t i = 0; i < m; ++i) {
		*((*bf).filter + i) = 0;
	}
}

/**
 * Adds a value to the bloom filter
 */
void bf_add(BloomFilter bf, size_t v)
{
	size_t p1 = h1(v, bf.m);
	size_t p2 = h2(v, bf.m);
	
	bf.filter[p1] = 1;
	bf.filter[p2] = 1;
}

/**
 * Resets all values of the bloom filter to false (0)
 */
void bf_clear(BloomFilter bf)
{
	for (size_t i = 0; i < bf.m; ++i) {
		bf.filter[i] = 0;
	}
}

void bf_print(BloomFilter bf)
{
	for (size_t i = 0; i < bf.m; ++i) {
		printf("%d ", bf.filter[i]);
	}
	printf("\n");
	printf("------------\n");
}

int bf_contains(BloomFilter bf, size_t v)
{
	size_t p1 = h1(v, bf.m);
	size_t p2 = h2(v, bf.m);

    return bf.filter[p1] == 1 && bf.filter[p2] == 1;
}

int main()
{
	BloomFilter bf = {0};
	
	bf_init(&bf, 5);

	printf("------------\n");
	bf_print(bf);

	bf_add(bf, 2);
	bf_add(bf, 15);

	bf_print(bf);

	printf("Contains %d: %b\n", 15, bf_contains(bf, 15));
	printf("Contains %d: %b\n", 14, bf_contains(bf, 14));

    return 0;
}
