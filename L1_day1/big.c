#include<stdio.h>
int big(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}

int main()
{
    int a,b,c;
    scanf("%d %d",&a,&b);
    c=big(a,b);
    printf("Biggest number is %d",c);
    return 0;
}
