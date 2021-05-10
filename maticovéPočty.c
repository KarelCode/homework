#include <stdio.h>

#define ERROR 100

int matrixDimensions(int *row, int *col);
int readMatrix(int row, int col, int matrix[row][col]);
void printMatrix(int row, int col, int matrix[row][col]);
char readOperator();

int main() {
    int ret = 0;
    int row1, col1, row2, col2, row3, col3 = 1;
    
    int a = matrixDimensions(&row1, &col1);
    if (a != 2) {
        ret = ERROR;
    }

    int matrix1[row1][col1];

    if (ret == 0) {
        int b = readMatrix(row1, col1, matrix1);
        if (b != 0) {
            ret = ERROR;
        }
    }

    char op = readOperator();
    if (op != '+' && op != '-' && op != '*') {
        ret = ERROR;
    }

    int c = matrixDimensions(&row2, &col2);
    if (c != 2) {
        ret = ERROR;
    }

    if (op == '+' || op == '-') {
        if (row1 != row2 || col1 != col2) {
            ret = ERROR;
        } else {
            row3 = row1;
            col3 = col1;
        }
    }
    if (op == '*') {
        if (row2 != col1) {
            ret = ERROR;
        } else {
            row3 = row1;
            col3 = col2;
        }
    }

    int matrix2[row2][col2];

    if (ret == 0) {
        int d = readMatrix(row2, col2, matrix2);
        if (d != 0) {
            ret = ERROR;
        }
    }

    if (op == '+' && ret == 0) {
        int matrix3[row3][col3];
        for (int r = 0; r < row1; ++r) {
            for (int c = 0; c < col1; ++c) {
                matrix3[r][c] = matrix1[r][c] + matrix2[r][c];
            }
        }
        printf("%d %d\n", row3, col3);
        printMatrix(row3, col3, matrix3);
    }
    if (op == '-' && ret == 0) {
        int matrix3[row3][col3];
        for (int r = 0; r < row1; ++r) {
            for (int c = 0; c < col1; ++c) {
                matrix3[r][c] = matrix1[r][c] - matrix2[r][c];
            }
        }
        printf("%d %d\n", row3, col3);
        printMatrix(row3, col3, matrix3);
    }
    if (op == '*' && ret == 0) {
        int matrix3[row3][col3];
        int tmp;
        int currentRow = 0;
        int currentCol = 0;

        for (int i = 0; i < (row3 * col3); ++i) {
            tmp = 0;
            for (int c = 0; c < col1; ++c) {
                tmp += matrix1[currentRow][c] * matrix2[c][currentCol];
            }
            matrix3[currentRow][currentCol] = tmp;
            if (currentCol < (col2 - 1)) {
                ++currentCol;
            } else {
                ++currentRow;
                currentCol = 0;
            }
        }
        printf("%d %d\n", row3, col3);
        printMatrix(row3, col3, matrix3);
    }


    if (ret != 0) {
        fprintf(stderr, "Error: Chybny vstup!\n");
    }

    return ret;
}

int matrixDimensions(int *row, int *col) {
    int ret = scanf("%d %d", row, col);
    return ret;
}

int readMatrix(int row, int col, int matrix[row][col]) {
    int ret = 0;
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            int a = scanf("%d", &(matrix[r][c]));
            if (a != 1) {
                ret = 1;
            }
        }
    }
    return ret;
}

void printMatrix(int row, int col, int matrix[row][col]) {
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            printf("%d", matrix[r][c]);
            if ((c + 1) < col) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

char readOperator() {
    char c;
    while ((c = getchar()) == '\n');
    getchar();
    return c;
}
