#include <stdio.h>

#define MAX_SIZE 100

int Symmetric_matrix(int matrix[MAX_SIZE][MAX_SIZE], int row, int col) {
    int i, j;
    
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0; 
            }
        }
    }
    
    return 1; 
}

int Asymmetric_matrix(int matrix[MAX_SIZE][MAX_SIZE], int row,int col) {
    int i, j;
    
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (matrix[i][j] == matrix[j][i]) {
                return 0 ;
            }
        }
    }
    
    return 1; 
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int row,col, i, j;
    
    printf("Enter the size of the matrix: ");
    scanf("%d %d", &row, &col);
    
   

    if(row!=col)
    {
        printf("Not a sqaure matrix!!!!!!!");
    }
    else
    {
         printf("Enter the elements of the matrix:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < row; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    if (Symmetric_matrix(matrix,row,col)) {
        printf("The matrix is symmetric.\n");
    } else if (Asymmetric_matrix(matrix, row,col)) {
        printf("The matrix is asymmetric.\n");
    } else {
        printf("The matrix is neither symmetric nor asymmetric.\n");
    }
    }
    return 0;
}
