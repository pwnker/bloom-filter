
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	size_t *ap;
} PT;

int main()
{
	size_t myt[5] = {1,2,3,4,5};

	PT pt = {0};
	pt.ap = myt;

	pt.ap[0] = 0;

	printf("%zu", *(pt.ap+0));

	return 0;
}

