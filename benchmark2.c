#include <stdio.h>
#include <stdlib.h>

#define SIZE 50000
#define EXPECTED_CHECKSUM 41667916675000LL

int main() {
    static long long A[SIZE];
    static long long B[SIZE];
    static long long C[SIZE];
    long long checksum = 0;

    // Initialize arrays
    for (int i = 0; i < SIZE; i++) {
        A[i] = i;
        B[i] = SIZE - i;
        C[i] = 0;
    }

    // Perform computation
    for (int i = 0; i < SIZE; i++) {
        long long sum = 0;
        for (int j = 0; j <= A[i]; j++) {
            sum += B[j];
        }
        C[i] = sum;
    }

    // Compute checksum
    for (int i = 0; i < SIZE; i++) {
        checksum += C[i];
    }

    // Verify checksum
    if (checksum == EXPECTED_CHECKSUM) {
        printf("Checksum = %lld\n", checksum);
        return 0;
    } else {
        fprintf(stderr, "Error: checksum mismatch! Got %lld, expected %lld\n", checksum, EXPECTED_CHECKSUM);
        return 1;
    }
}