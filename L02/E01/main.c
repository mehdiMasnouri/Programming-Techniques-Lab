#include <stdio.h>

int main() {

    int  num1 , num2 ,remainder;
    printf("ciao!\n");
    printf("enter first number : ");
    scanf(" %d",&num1);
    printf("\nenter the second number : ");
    scanf(" %d",&num2);



    if ( num2>num1){
        remainder=num1;
        num1 = num2;
        num2=remainder;

    }

    remainder=num1%num2;
    while (!(remainder==0))
    {

        num1= num2;
        num2=remainder;

        remainder=num1%num2;

    }

    printf("Result GCF = %d",num2);

    return 0;
}
