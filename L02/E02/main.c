#include <stdio.h>

int main() {
    printf("ciao!\n");

    int n , x0=0 , x1=1 ,x;

    printf("how many number? ");

    scanf(" %d",&n);

    if (n>=1 ){
        if (n>=3){
            printf("1--> %d\n",x0);
            printf("2--> %d\n",x1);

            for (int i = 1; i <n-1 ; ++i) {
                x= x0 + x1;
                printf("%d--> %d\n",i+2,x);
                x0=x1;
                x1=x;

            }


        } else{
            printf("1--> %d\n",x0);
            printf("2--> %d\n",x1);
        }


    } else
        printf("Wrong input!");




    return 0;
}
