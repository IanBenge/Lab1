SIZE = 50000
EXPECTED_CHECKSUM = 41667916675000

def main():
    # Initialize arrays
    A = [i for i in range(SIZE)]
    B = [SIZE - i for i in range(SIZE)]
    C = [0 for _ in range(SIZE)]

    # Precompute prefix sums of B
    prefix_sum = [0] * SIZE
    prefix_sum[0] = B[0]
    for i in range(1, SIZE):
        prefix_sum[i] = prefix_sum[i - 1] + B[i]

    # Compute C[i] using prefix sums
    for i in range(SIZE):
        C[i] = prefix_sum[A[i]]

    # Compute checksum
    checksum = sum(C)

    # Verify checksum
    if checksum == EXPECTED_CHECKSUM:
        print("Checksum =", checksum)
        return 0
    else:
        print("Error: checksum mismatch! Got", checksum, "expected", EXPECTED_CHECKSUM)
        return 1

if __name__ == "__main__":
    main()
