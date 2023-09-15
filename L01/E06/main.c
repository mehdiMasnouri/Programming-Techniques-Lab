#include <stdio.h>

int main () {

    float firstNumber,secondNumber;
    char operation;
    FILE *fpin, *fout;

    fpin= fopen("../input.txt","r");
    if ( fpin == NULL)
    {
        puts("Error opening input file.\n");
        return 1;
    }

    fout= fopen("../output.txt","w");
    if (fout== NULL){
        puts("Error opening output file.\n");
        return 1;
    }


    do {
        int itemsRead = fscanf(fpin," %c %f %f",&operation,&firstNumber,&secondNumber);
        if ( itemsRead==3){
            switch (operation) {
                case '+':
                    fprintf(fout,"%c %.2f\n",operation,(firstNumber+secondNumber));
                    break;
                case '-':
                    fprintf(fout,"%c %.2f\n",operation,(firstNumber - secondNumber));
                    break;
                case '*':
                    fprintf(fout,"%c %.2f\n",operation,(firstNumber * secondNumber));
                    break;
                case '/':
                    if ( secondNumber==0){
                        printf("divide by zero");
                        return 1;
                    }
                    fprintf(fout,"%c %.2f\n",operation,(firstNumber / secondNumber));
                    break;
                default:
                    puts("Error occurred !\n");
                    fclose(fpin);
                    fclose(fout);
                    return 1;


            }


        } else if (itemsRead == EOF) {
            puts("programme reached at the end of the file.\n");

        } else
        {
            puts("Error occurred!");
            fclose(fpin);
            fclose(fout);
            return 1;
        }

    } while ( !feof(fpin));
    fclose(fpin);
    fclose(fout);
    puts("The programme successfully finished.");





    return 0;
}