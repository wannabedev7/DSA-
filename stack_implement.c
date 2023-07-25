#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define SIZE 6
struct stack
{
    int data[SIZE];
    int top;
};
void push(struct stack *sptr, int num);
void pop(struct stack *sptr);
void display(struct stack *sptr);
void peek(struct stack *sptr);
int main()

{
    FILE *fptr ;
    fptr = fopen("stack_file.txt","r");
    struct stack * sptr;
    struct stack s;
    sptr=&s;
    sptr->top=-1;
    int num,ch;
    while(1)
    {
        printf("Enter choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            fscanf(fptr, "%d", &num);
            fclose(fptr);
            push(sptr,num);
            break;
            case 2:pop(sptr);
            break;
            case 3:peek(sptr);
            printf("\n");
            break;
            case -1:exit(0);
            break;
            default:printf("Enter valid choice\n");
            break;
        }
    }
    return 0;
}
void push(struct stack *sptr, int num)
{
    if(sptr->top==SIZE-1)
    {
        printf("stack Overflow\n");
    }
    else
    {
        sptr->top++;
        sptr->data[sptr->top]=num;
    }
}
void pop(struct stack *sptr)
{
    int num;
    if(sptr->top==-1)
    {
        printf("stack underflow\n");
    }
    else
    {
        num=sptr->data[sptr->top];
        sptr->top--;
        printf("%d \n",num);
    }
    
}

void peek(struct stack *sptr)
{
    if(sptr->top==-1)
    {
        printf("Stack empty\n");
    }
    else
    {
        printf("%d",sptr->data[sptr->top]);
    }
}

