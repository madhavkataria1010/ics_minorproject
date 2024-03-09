# ICS Minor Project

---

# Eigenvalue Calculator

This program calculates the dominant eigenvalue of a square matrix using the power iteration method. It allows the user to either enter a matrix manually or generate a random matrix.

## How to Use

1. Clone the repository to your local machine.
2. Compile the program using a C compiler. For example, using GCC:

   ```bash
   gcc eigenvalue_calculator.c -o eigenvalue_calculator -lm
   ```

   Note: The `-lm` flag is used to link the math library.
   
3. Run the compiled program:

   ```bash
   ./eigenvalue_calculator
   ```

4. Choose one of the following options:

   - Enter matrix manually: Enter the number of rows and columns, followed by the elements of the matrix.
   - Generate random matrix: Enter the number of rows and columns for a randomly generated matrix.

5. The program will display the entered/generated matrix and calculate the dominant eigenvalue using the power iteration method.

## Requirements

- C compiler (e.g., GCC)
- Standard C libraries (stdio.h, stdlib.h, math.h, time.h)

## Example

```bash
Eigenvalue Calculator

1. Enter matrix manually
2. Generate random matrix
Enter your choice: 2
Enter the number of rows: 3
Enter the number of columns: 3

The matrix is:
0.621720 0.679952 0.985775
0.519720 0.151520 0.335464
0.819637 0.303816 0.505522

Dominant Eigenvalue: 1.709209
```

---
## Made by 
- Madhav Kataria 
- Roll no - B23CH1025 


