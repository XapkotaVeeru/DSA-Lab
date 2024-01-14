#include<stdio.h>
int sum = 0, rem;
int reverse(int x){
    if(x == 0) {
        return sum;
    }
    else {
        rem = x%10;
        sum = sum*10 + rem;
        return reverse(x/10);
    }
}
void main()
{
    int a;
    printf("gib a number whose reverse you wanna know");
    scanf("%d",&a);
    printf("the reverse of %d is " , a);
    if(a%10 == 0) printf("0");
    printf("%d", reverse(a));
}
