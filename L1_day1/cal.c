#include<stdio.h>
int main()
{
    float op1,op2;
    char ope;
    float result;
    scanf("%f",&op1);
    scanf("%c",&ope);
    scanf("%f",&op2);
    switch(ope)
    {
        case '+':
             result=op1+op2;
             break;
        case '-':
             result=op1-op2;
             break;
        case '*':
             result = op1*op2;
             break;
        case '/':
            if(op2!=0)
            result=op1/op2;
            else
            printf("zero division error");
        default :
            printf("Invalid opation");
    }
    printf("%.2f",result);
}

