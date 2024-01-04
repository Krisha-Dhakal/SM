#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long midSquareRandom(unsigned long long seed, int digits, int iterations) {
    unsigned long long square, result;
    unsigned long long divisor = pow(10, digits / 2);
	int i;
    for (i = 0; i < iterations; i++) {
        square = seed * seed;
        result = (square / divisor) % (unsigned long long)pow(10, digits); // Extracting middle digits
        
        printf("Random Number %d: %llu\n", i + 1, result);
        
        seed = result; // Update seed for the next iteration
    }

    return result;
}

int main() {
    unsigned long long seed;
    int digits, iterations;
	// Get the number of digits for the random numbers
    printf("Enter the number of digits for the random numbers: ");
    scanf("%d", &digits);
    // Get seed value from the user
    printf("Enter the seed value: ");
    scanf("%llu", &seed);
    // Get the number of random numbers to generate
    printf("How many random numbers do you want to generate?: ");
    scanf("%d", &iterations);

    // Generate random numbers using mid-square method
    midSquareRandom(seed, digits, iterations);

    return 0;
}
