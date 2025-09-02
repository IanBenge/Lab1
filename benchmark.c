#include <stdio.h>
#include <stdlib.h>
#define SIZE 50000

int main() {
    //allocate memory for three arrays of size SIZE
    int A[SIZE], B[SIZE], C[SIZE];

    //initialize arrays A, B, and C with some values
    for (int i = 0; i < SIZE; i++) {
        A[i] = i;
        B[i] = 50000 - i;
        C[i] = 0;
    }
    //compute C[i] as the sum of A[0] to A[i]
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j <= A[i]; j++) {
            C[i] += B[j];
        }
    }
    //compute a checksum to verify correctness
    long long checksum = 0;
    for (int i = 0; i < SIZE; i++) {
        checksum += C[i];
    }

    //print the first 10 elements of array C to verify correctness
    for (int i = 0; i < 10; i++) {
        printf("C[%d] = %d\n", i, C[i]);
    }

    const long long expected_checksum = 41667916675000LL;
    printf("Computed checksum: %lld\n", checksum);

    if (checksum != expected_checksum) {
        printf("ERROR: Checksum does not match expected value!\n");
        return 1; // Non-zero exit for error
    }

    return 0;
}