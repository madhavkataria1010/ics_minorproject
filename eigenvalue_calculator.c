#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 10

void get_matrix_dimensions(int *rows, int *cols) {
    printf("Enter the number of rows: ");
    scanf("%d", rows);
    printf("Enter the number of columns: ");
    scanf("%d", cols);
}

void get_matrix_elements(double matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element at [%d][%d]: ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void generate_random_matrix(double matrix[][MAX_SIZE], int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (double)rand() / RAND_MAX; 
        }
    }
}

void print_matrix(double matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

double power_iteration(double matrix[][MAX_SIZE], int rows, int cols) {
    double eigenvector[MAX_SIZE];
    double eigenvalue = 0.0;
    int iterations = 0;

    for (int i = 0; i < rows; i++) {
        eigenvector[i] = (double)rand() / RAND_MAX;
    }

    while (iterations < 100) { 
        double new_eigenvector[MAX_SIZE];

        for (int i = 0; i < rows; i++) {
            new_eigenvector[i] = 0.0;
            for (int j = 0; j < cols; j++) {
                new_eigenvector[i] += matrix[i][j] * eigenvector[j];
            }
        }

        double norm = 0.0;
        for (int i = 0; i < rows; i++) {
            norm += new_eigenvector[i] * new_eigenvector[i];
        }
        norm = sqrt(norm);
        for (int i = 0; i < rows; i++) {
            new_eigenvector[i] /= norm;
        }

        for (int i = 0; i < rows; i++) {
            eigenvector[i] = new_eigenvector[i];
        }
        eigenvalue = 0.0;
        for (int i = 0; i < rows; i++) {
            eigenvalue += matrix[i][i] * eigenvector[i] * eigenvector[i];
        }

        iterations++;
    }

    return eigenvalue;
}

int main() {
    int rows, cols;
    double matrix[MAX_SIZE][MAX_SIZE];

    printf("Eigenvalue Calculator\n");

    int choice;
    printf("1. Enter matrix manually\n");
    printf("2. Generate random matrix\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        get_matrix_dimensions(&rows, &cols);
        get_matrix_elements(matrix, rows, cols);
    } else if (choice == 2) {
        printf("Enter the number of rows: ");
        scanf("%d", &rows);
        printf("Enter the number of columns: ");
        scanf("%d", &cols);
        generate_random_matrix(matrix, rows, cols);
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    printf("\nThe matrix is:\n");
    print_matrix(matrix, rows, cols);

    double eigenvalue = power_iteration(matrix, rows, cols);
    printf("\nDominant Eigenvalue: %lf\n", eigenvalue);

    return 0;
}
