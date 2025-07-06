#include <stdio.h>
#include <limits.h>

int main() {
    // Demonstrate positive value
    int signed_int = 200;
    unsigned int unsigned_int = 200;
    printf("Positive value:\n");
    printf("Signed int: %d, Unsigned int: %u\n", signed_int, unsigned_int);

    // Demonstrate negative value
    signed_int = -200;
    unsigned_int = -200; // This will wrap around
    printf("Negative value:\n");
    printf("Signed int: %d, Unsigned int: %u\n", signed_int, unsigned_int);

    // Demonstrate overflow
    signed_int = INT_MAX;
    unsigned_int = UINT_MAX;
    printf("At maximum limits:\n");
    printf("Signed int max: %d, Unsigned int max: %u\n", signed_int, unsigned_int);

    signed_int++;
    unsigned_int++;
    printf("After incrementing by 1:\n");
    printf("Signed int: %d (overflowed), Unsigned int: %u (wrapped around)\n\n", signed_int, unsigned_int);


    return 0;
}