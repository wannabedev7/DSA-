#include <stdio.h>

void Recursion(int n);

int main()
{
    int n;
    printf("Enter the value of n :");
    scanf("%d",&n);
    Recursion(n);
}

void Recursion(int n)
{
    if(n>0)
    {
        for(int i=0;i<n;i++)
        {
             printf("%d",n);
        }
        printf("\n");
         Recursion(n-1);
    }
}