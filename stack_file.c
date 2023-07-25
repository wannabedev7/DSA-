#include <stdio.h>
#define MAX_SIZE 100 

int main()
{
    FILE *fp;
    int value ;
    int stack[MAX_SIZE];
    int top ;
    
    // File Opening
    fp = fopen("val.txt", "r");
    if(fp == NULL)
    {
        printf("Error opening the file.\n");
        return 1 ;/* Fetch the value from file and 
   store it on stack */

    //printf("Enter the value: \n");
    fscanf(fp, "%d", &value);

// close the file
    fclose(fp);

// Pushing the value to the stack 
    if(top == MAX_SIZE - 1)
    {
        printf("Stack Overflow.\n");
        return 1;
    }
  
    stack[++top] = value ; 

    printf("The value stored on the stack is %d \n",stack[top]);

    return 0 ;
    }
}