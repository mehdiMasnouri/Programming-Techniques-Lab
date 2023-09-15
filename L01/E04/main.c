#include <stdio.h>

#define PI 3.14

int main() {
    int shape,lenType,length;

    printf("Enter your input :");
    scanf("%c%c%d",&shape,&lenType,&length);

    switch (shape) {
        case 'S':
            if (lenType=='S' ||lenType=='D' )
                if(lenType=='S')
                    printf("The area of the square with side %d is %.2f",length,(float )length*length);
                else
                    printf("The area of the square with diagonal %d is %.2f",length,((float )length)*(length)/2);

            else
                printf("\nError Wrong input");

            break;
        case 'C':

            switch (lenType) {
                case 'R':
                    printf("The area of the circle with radius %d is %.2f",length,(float )length*length*PI);
                    break;
                case 'D':
                    printf("The area of the circle with diagonal %d is %.2f",length,(float )length*(length/4)*PI);
                    break;
                default:
                    printf("\nError Wrong input");

            }
            break;


        default:
            printf("\nError Wrong input");

    }

    return 0;
}
