#include <stdio.h>
#include <ctype.h>
const int MAX=50;
int encoding(FILE *fin, FILE *fout);
int decoding(FILE *fin, FILE *fout);
int decode(FILE *fin, FILE *fout);
int main() {
    FILE *fin , *fout;
    char choice,fileName[MAX+1] ;
    int result;

    printf("Ciao\n");
    printf("Enter \'D\' for decoding or \'E\' for encoding : ");
    scanf(" %c",&choice);



    switch (toupper(choice)){


        case 'E':
            //printf("Enter source file name : ");
            // scanf("%s",&fileName);
            fin= fopen("..\\plain.txt","r");
            if ( fin == NULL){
                printf("Error in opening the \'%s\'",fileName);
                return 1;
            }
            // printf("Enter destination file name : ");
            // scanf(" %s",&fileName);
            fout= fopen("..\\encoded.txt","w");
            if ( fout == NULL){
                printf("Error in opening the \'%s\'",fileName);
                return 1;
            }
            result= encoding(fin,fout);
            puts("encoding...");
            break;
        case 'D':
            //printf("Enter source file name : ");
            // scanf("%s",&fileName);
            fin= fopen("..\\encoded.txt","r");
            if ( fin == NULL){
                printf("Error in opening the \'%s\'",fileName);
                return 1;
            }
            // printf("Enter destination file name : ");
            // scanf(" %s",&fileName);
            fout= fopen("..\\decodec.txt","w");
            if ( fout == NULL){
                printf("Error in opening the \'%s\'",fileName);
                return 1;
            }
            puts("decoding...");
                 result= decode(fin,fout);
            break;
        default:
            printf("Wrong input!");
            return 1;


    }
    fclose(fin);
    fclose(fout);
    printf("Operation done!");
    printf("%d",result);
    return 0;
}



int encoding(FILE *fin, FILE *fout) {
    char ch , ch_prec;
    int num,flag,ch_coded;
    int counter = 0 , num_char=0;

    ch_prec = '\n';
    while ( !feof(fin)){
        ch = fgetc(fin);
        flag=0;
        if ( !feof(fin)){
            if (isdigit(ch)){
                num = (int)(ch) + counter;
                counter++;
                while (num > 9){
                    num = num-10;
                }
                fputc(num, fout);
                num_char++;
                ch_prec = ch;
            }
            else if (isalpha(ch)) {
                if (isalpha(ch_prec)){
                    if (islower(ch_prec)){
                        ch_coded = ch + ch_prec-'a';
                    }
                    else{
                        ch_coded = ch + ch_prec-'A';
                    }
                    if (islower(ch) && ch_coded>122){
                        flag=1;
                    }
                    else if (isupper(ch) && ch_coded>90){
                        flag=1;
                    }
                    if (flag){
                        ch_coded = ch_coded-26;
                    }
                    fprintf(fout,"%c",ch_coded);
                    num_char++;
                    // maybe my mistake was here
                    ch_prec = ch_coded;



                }// preced is not alphabet
                else{
                    fputc(ch, fout);
                    num_char++;
                    ch_prec = ch;

                }

            }// not number not alphabet
            else{
                fputc(ch, fout);
                num_char++;
                ch_prec = ch;

            }

        }
    }// end of while
    return num_char;
}


/*
int encoding(FILE *fin, FILE *fout) {
    char ch, ch_prec;
    int num, flag, ch_cod;
    int counter = 0, num_car = 0;

    ch_prec = '\n';

    while (!feof(fin)) {
        ch = fgetc(fin);
        flag = 0;
        if (!feof(fin)) {
            if (isdigit(ch)) {
                num = (int) (ch) + counter;
                counter++;
                while (num > 9) {
                    num = num - 10;
                }
                fputc(num, fout);
                num_car++;
                ch_prec = ch;
            } else if (isalpha(ch)) {
                if (isalpha(ch_prec)) {
                    if (islower(ch_prec)) {
                        ch_cod = ch + ch_prec - 'a';
                    } else {
                        ch_cod = ch + ch_prec - 'A';
                    }
                    if (islower(ch) && ch_cod > 122) {
                        flag = 1;
                    } else if (isupper(ch) && ch_cod > 90) {
                        flag = 1;
                    }
                    if (flag) {
                        ch_cod = ch_cod - 26;
                    }
                    fprintf(fout, "%c", ch_cod);
                    num_car++;
                    ch_prec = ch_cod;
                } else {
                    fputc(ch, fout);
                    num_car++;
                    ch_prec = ch;
                }
            } else {
                fputc(ch, fout);
                num_car++;
                ch_prec = ch;
            }
        }
    }
    return num_car;
}


*/


int decode(FILE *fin, FILE *fout){
    char preceding_Char , current_Char;
    int number,flag,char_coded;
    int total_ch=0 , counter=0;

        preceding_Char='\n';
        while ( ! feof(fin)){
            current_Char= fgetc(fin);

            flag=0;
            if ( !feof(fin)){
                if ( isdigit(current_Char)){
                    number = (int) (current_Char) - counter;
                    counter++;
                    while ( number < 0){
                        number=number+10;
                    }
                    fputc(number,fout);
                    total_ch++;
                    preceding_Char=current_Char;
                    }
                    else if (isalpha(current_Char)){
                        if (isalpha(preceding_Char)){
                            if (islower(preceding_Char)){
                                char_coded = current_Char - preceding_Char + 'a';
                            }
                            else{
                                char_coded = current_Char - preceding_Char + 'A';
                            }
                            if (islower(current_Char) && char_coded < 97)
                            {
                                flag=1;
                            }
                            else if (isupper(current_Char) && char_coded >65){
                                flag=1;
                            }
                            if (flag){
                                char_coded=char_coded+26;
                            }
                            fprintf(fout,"%c",char_coded);
                            total_ch++;
                            preceding_Char= current_Char;

                        }
                        else{
                            fputc(current_Char,fout);
                            total_ch++;
                            preceding_Char= current_Char;
                        }

                    } else{
                    fputc(current_Char,fout);
                    total_ch++;
                    preceding_Char= current_Char;

                }
                }

        }

    return total_ch;


}
/*

int decode(FILE *fin, FILE *fout){
    char ch, ch_prec;
    int num, flag, ch_cod;
    int counter=0, num_car=0;

    ch_prec = '\n';

    while(!feof(fin)){
        ch = fgetc(fin);
        flag = 0;
        if (!feof(fin)){
            if(isdigit(ch)){
                num = (int)(ch) - counter;
                counter++;
                while(num < 0){
                    num = num + 10;
                }
                fputc(num, fout);
                num_car++;
                ch_prec = ch;
            }
            else if(isalpha(ch)) {
                if(isalpha(ch_prec)) {
                    if(islower(ch_prec)){
                        ch_cod = ch - ch_prec + 'a';
                    }
                    else {
                        ch_cod = ch - ch_prec + 'A';
                    }
                    if (islower(ch) && ch_cod < 97){
                        flag = 1;
                    }
                    else if (isupper(ch) && ch_cod > 65){
                        flag = 1;
                    }
                    if(flag){
                        ch_cod = ch_cod + 26;
                    }
                    fprintf(fout,"%c", ch_cod);
                    num_car++;
                    ch_prec = ch;
                }
                else {
                    fputc(ch, fout);
                    num_car++;
                    ch_prec = ch;
                }
            }
            else {
                fputc(ch, fout);
                num_car++;
                ch_prec = ch;
            }
        }
    }
    return num_car;
}*/
