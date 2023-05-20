#include <stdio.h>

int main() {

    FILE *inputFile, *outputFile;
   inputFile = fopen("Input_file.txt", "r" );
    outputFile = fopen ("output_file.txt", "w" );


    char operator;
    float op1;
    float op2;
    float result;

    while(fscanf(inputFile, " %c %f %f", &operator, &op1, &op2) != EOF) {
        switch(operator) {
            case '+':
                result = op1 + op2;
                fprintf(outputFile, "+ %.2f\n", result);
                break;
            case '-':
                result = op1 - op2;
                fprintf(outputFile, "- %.2f\n", result);
                break;
            case '*':
                result = op1 * op2;
                fprintf(outputFile, "* %.2f\n", result);
                break;
            case '/':
                if(op2 == 0){
                    fprintf(outputFile, "/ Error: Division by zero!\n");
                }
                else{
                    result = op1 / op2;
                    fprintf(outputFile, "/ %.2f\n", result);
                }
                break;
            default:
                fprintf(outputFile, "Error: Invalid operator!\n");
        }
    }

    fclose(inputFile);
    fclose(outputFile);




    return 0;
}
