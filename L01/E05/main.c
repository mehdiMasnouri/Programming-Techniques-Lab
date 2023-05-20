#include <stdio.h>

int main() {


    printf("(+, -, *, /)\n");
    printf("Enter one of above  operators : ");
    char operator;
    operator = getchar();
    printf("Enter two operands: ");
    float op1, op2, result;
    scanf("%f %f", &op1, &op2);

    switch(operator) {
        case '+':
            result = op1 + op2;
            printf("%c %.2f", operator, result);
            break;
        case '-':
            result = op1 - op2;
            printf("%c %.2f", operator, result);
            break;
        case '*':
            result = op1 * op2;
            printf("%c %.2f", operator,result);
            break;
        case '/':
            if(op2 == 0){
                printf("Division by zero is not allowed!");
            }
            else{

                result = op1 / op2;
                printf("%c %.2f", operator,result);
            }
            break;

        default:
            printf("Oops.wrong input!");
    }

    return 0;
}
