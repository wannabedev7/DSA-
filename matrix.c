#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row,col,i,j;
    printf("Enter the size of the matrix : ");
    scanf("%d %d",&row, &col);

    int matrix[row][col];

    if(row!=col)
    {
        printf("Non-Square matrix!!!!!!");
    }

    else 
    {
        printf("Enter the elements of array :\n ");
        for( i = 0 ; i<row ;i++)
       {
        for( j = 0 ; j<col;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
       }

       printf("The original matrix :\n");
        for( i = 0 ; i<row ;i++)
       {
        for( j = 0 ; j<col;j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
       }

       printf("Transpose matrix :\n");
       for( i = 0 ; i<row ;i++)
       {
        for( j = 0 ; j<col;j++)
        {
            matrix[j][i] = matrix[i][j];
        }
        
       }
       



       if(matrix[i][j]==matrix[j][i])
       {
        printf("Symmetric matrix.");
       }
       else
       {
        printf("Asymmetric matrix.");
       }

    }
    
}