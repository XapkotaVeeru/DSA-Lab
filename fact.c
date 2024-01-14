#include<stdio.h>
int fact(int x)
{
    if(x>0) return x*fact(x-1);
    else return 1;
}
void main()
{
    int a;
    printf("enter a number");
    scanf("%d", &a);
    printf("factorial is %d", fact(a));
}