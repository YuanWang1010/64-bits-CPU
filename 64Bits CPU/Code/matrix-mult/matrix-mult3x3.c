#include <stdio.h>

unsigned long matrix1[3][3] = {
    {1, 0, 0},
    {0, 2, 1},
    {0, 1, 0}
};

unsigned long matrix2[3][3] = {
    {0, 1, 0},
    {2, 1, 1},
    {0, 0, 1}
};

unsigned long multiply(unsigned long num1, unsigned long num2) {
    unsigned long result = 0;

    for (int i = 0; i < num1; ++i)
        result += num2;
    return result;
}

void matrix_multiply(unsigned long matrix1[3][3], unsigned long matrix2[3][3], unsigned long result[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[i][j] = 0;
            for (int x = 0; x < 3; ++x)
                result[i][j] += multiply(matrix1[i][x], matrix2[x][j]);
        }
    }
}

int main() {
    unsigned long result[3][3];
    matrix_multiply(matrix1, matrix2, result);
    
    printf("Matrix in decimal: \n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%ld ", result[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatrix in hex: \n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%lx ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
