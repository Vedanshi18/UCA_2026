#include <stdio.h>
#include <stdbool.h>
int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    int matrix[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int col0 = 1;
    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) 
        {
            col0 = 0;
        }
        // Excluding first column to avoid overwriting the first column's zeroes
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; // First cell of the row as 0
                matrix[0][j] = 0; // First cell of the column as 0
            }
        }
    }
    // Updating matrix excluding first row and column
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    // Updating first row based on matrix[0][0]
    if (matrix[0][0] == 0) {
        for (int j = 0; j < cols; j++) {
            matrix[0][j] = 0;
        }
    }
    // Updating the first column based on col0
    if (col0 == 0) {
        for (int i = 0; i < rows; i++) {
            matrix[i][0] = 0;
        }
    }
    // Printing the updated matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}