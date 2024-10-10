#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
	int i = 1;

	double x = 0;
	double y = 0;
	double circle = 0;
	double count = 0;

	srand((double)time(NULL));

	for (i; i <= 100; i++) {
		while (10000000 * i > count){

			x = (double)rand() / (double)RAND_MAX;
			y = (double)rand() / (double)RAND_MAX;

			if (sqrt((x * x) + (y * y)) <= 1) {
				circle++;
			}

			count++;

		}
		
		printf("%d %%진행..원주율 = %f\n", i, (circle / count) * 4.0);

	}

	
}