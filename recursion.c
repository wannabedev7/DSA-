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
        printf("%d",n);
        Recursion(n-1);
    }
}