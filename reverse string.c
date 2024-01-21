#include <stdio.h>
#include<string.h>
char b[];
char revstr(char *a[],int n)
{
    if((a[n]) != '\0'){
        strcat(b,a[n]);
        return revstr(a,n+1);
    }
    else return b[0];
}
void main()
{
    char a[100];
    printf("enter a string");
    gets(a);
    puts(revstr(a,0));
}