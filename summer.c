#include<stdio.h>
int summing(int x)
{
    if(x>0) return(x+ summing(x-1));
    else return 0;
}
void main()
{
    int a;
    printf("enter the number upto which you need to add");
    scanf("%d", &a);
    printf(" the sum is %d", summing(a));
}