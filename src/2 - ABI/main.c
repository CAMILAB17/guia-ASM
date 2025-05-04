#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#include "../test-utils.h"
#include "ABI.h"

int main() {
	/* Acá pueden realizar sus propias pruebas */
	assert(alternate_sum_4_using_c(8, 2, 5, 1) == 10);

	assert(alternate_sum_4_using_c_alternative(8, 2, 5, 1) == 10);

	assert(alternate_sum_8(8,5,7,2,5,2,5,1) == 15);
	assert(alternate_sum_8(1,1,1,1,1,1,1,1) == 0);

	uint32_t res;
	product_2_f(&res, 1, 20);
	assert(res == 20);

	double* resD = malloc(sizeof(uint32_t*));
	product_9_f(resD, 1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,1,1,1);
	assert(*resD == 128);
	free(resD);
	return 0;
}
