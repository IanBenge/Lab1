SIZE = 50000  # Define the size of the arrays

# Initialize arrays A, B, and C with zeros
A = [0] * SIZE
B = [0] * SIZE 
C = [0] * SIZE

# Populate arrays A and B
for i in range(SIZE):
    A[i] = i                  # A contains increasing integers from 0 to SIZE-1
    B[i] = 50000 - i          # B contains decreasing integers from SIZE to 1
    C[i] = 0                  # C is initialized to all zeros

# Perform computation: 
for i in range(SIZE):
    for j in range(A[i] + 1): # Loop from 0 to A[i] (inclusive)
        C[i] += B[j]          # Add B[j] to C[i]

# Calculate checksum by summing all elements in C
checksum = sum(C)
print("Checksum:", checksum)

expected = 41667916675000     # Expected checksum value

# Verify result
if checksum != expected:
    print("ERROR: expected", expected)
else:
    print("Result is correct")