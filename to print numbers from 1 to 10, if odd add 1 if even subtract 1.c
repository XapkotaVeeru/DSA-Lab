#include<stdio.h>
void printer(int a)
{
    if(a==1) printf("2\t");
    else{
        printer(a-1);
        if(a%2==0) printf("%d\t",a-1);
        else printf("%d\t",a+1);
    }
}
void main()
{
    printer(10);
}