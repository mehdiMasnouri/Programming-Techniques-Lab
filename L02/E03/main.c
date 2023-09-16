#include <stdio.h>


int compressing(FILE *fin, FILE *fout);
int decompressing(FILE *fin, FILE *fout);
int main() {
    int result=1;
    char inputFile []= "..\\source.txt";
    char choice;
    FILE *input , *output;


    printf("ciao!\n");
    printf("1 - compressing\n");
    printf("2 - decompressing\n");
    printf("enter the number corresponds to operation : ");
    scanf(" %c",&choice);

    switch (choice) {

        case '1':
            input= fopen(inputFile,"r");
            if (input== NULL){
                printf("Error in opening input file!");
                return 1;
            }
            result=compressing(input,output);
            break;
        case '2':
            input= fopen("..\\compressing.txt","r");
            if (input== NULL){
                printf("Error in opening input file!");
                return 1;
            }
            result=decompressing(input,output);
            break;
        default:
            printf("Wrong input!");
            break;


    }

    fclose(input);
    printf("Done.\n");
    printf("-->%d char",result);


    return 0;
}



int compressing(FILE *fin, FILE *fout){
    fout = fopen("..\\compressing.txt","w");
    char ch1, ch2;
    int repeat=0, totalChar=0 ,i=0;


    ch1 = fgetc(fin);
    while (!feof(fin)) {
        ch2 = fgetc(fin);
        if (ch2==ch1 && repeat < 9){
            repeat++;
        }
        else {
            if (repeat >= 2){
                fprintf(fout,"%c$%d", ch1, repeat);
                totalChar+=3;
                repeat=0;
            }
            else{
                for(i=0;i<repeat+1;i++){
                    fputc(ch1, fout);
                    totalChar++;
                }
                repeat = 0;
            }
        }
        ch1=ch2;
    }
    return totalChar;
}


int decompressing(FILE *fin, FILE *fout){
    fout = fopen("..\\decompressing.txt","w");

    char ch1,ch2;
    int totalChar=0 , repeat=0 ,i;

    ch1= fgetc(fin);
    while ( !feof(fin)){
        ch2= fgetc(fin);
        if (ch2=='$'){
            repeat = fgetc(fin) - '0';
            for (i=0;i<=repeat;++i){
                fputc(ch1,fout);
                ++totalChar;
            }
            ch1= fgetc(fin);

        } else{
            fputc(ch1,fout);
            totalChar++;
            ch1=ch2;
        }


    }
    fclose(fout);
    return totalChar;
}
