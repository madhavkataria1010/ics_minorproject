#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multifit.h>

#define MAX_ROWS 1000
#define MAX_COLS 100

int read_csv(const char *filename, gsl_matrix *data) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file\n");
        return 0;
    }

    int rows = 0, cols = 0;
    char line[MAX_COLS * 10]; // Assuming a maximum line length

    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        int col = 0;
        while (token != NULL) {
            gsl_matrix_set(data, rows, col, atof(token));
            token = strtok(NULL, ",");
            col++;
        }
        if (cols == 0) cols = col;
        rows++;
    }

    fclose(file);
    return rows;
}

double sigmoid(double x, double a, double b) {
    return 1.0 / (1.0 + exp(-(a * x + b)));
}

void plot_graph(gsl_vector *coefficients, gsl_matrix *data) {
    for (int i = 0; i < data->size1; i++) {
        double x = gsl_matrix_get(data, i, 0);
        double y = gsl_matrix_get(data, i, 1);
        printf("%lf %lf\n", x, y);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    gsl_matrix *data = gsl_matrix_alloc(MAX_ROWS, MAX_COLS);
    int rows = read_csv(argv[1], data);

    if (rows == 0) {
        printf("No data found in file\n");
        gsl_matrix_free(data);
        return 1;
    }

    gsl_vector *coefficients = gsl_vector_alloc(2);
    gsl_matrix *covariance = gsl_matrix_alloc(2, 2);
    double chisq;

    gsl_vector *x = gsl_vector_alloc(rows);
    gsl_vector *y = gsl_vector_alloc(rows);

    for (int i = 0; i < rows; i++) {
        gsl_vector_set(x, i, gsl_matrix_get(data, i, 0));
        gsl_vector_set(y, i, gsl_matrix_get(data, i, 1));
    }

    gsl_multifit_linear_workspace *work = gsl_multifit_linear_alloc(rows, 2);
    gsl_multifit_linear(x, y, coefficients, covariance, &chisq, work);
    gsl_multifit_linear_free(work);

    printf("# x y\n");
    plot_graph(coefficients, data);

    gsl_matrix_free(data);
    gsl_vector_free(coefficients);
    gsl_matrix_free(covariance);
    gsl_vector_free(x);
    gsl_vector_free(y);

    return 0;
}

