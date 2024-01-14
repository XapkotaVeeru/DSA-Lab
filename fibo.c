#include <stdio.h>
int fibo(int x)
{
    if(x==1) return 0;
    else if(x==2) return 1;
    else return ( fibo(x-2) + fibo(x-1));

}
void main()
{
    int a;
    printf("enter the no of terms in the series");
    scanf("%d", &a);
    for(int i=1; i<=a; i++)
    {
        printf("%d \t", fibo(i));
    }
}