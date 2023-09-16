#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int compressing(FILE *fin, FILE *fout);
int decompressing(FILE *fin, FILE *fout);

int main()
{
    int choice;
    FILE *fin, *fout;
    char source[100], dest[100];

    printf("Enter the source filename: ");
    scanf("%s", source);

    fin = fopen(source, "r");
    if (fin == NULL) {
        printf("Error opening source file!\n");
        return 0;
    }

    printf("Enter the destination filename: ");
    scanf("%s", dest);

    fout = fopen(dest, "w");
    if (fout == NULL) {
        printf("Error opening destination file!\n");
        fclose(fin);
        return 0;
    }

    printf("Enter 1 to compress, 2 to decompress: ");
    scanf("%d", &choice);

    if (choice == 1) {
        if (!compressing(fin, fout)) {
            printf("Error compressing file!\n");
        }
    } else if (choice == 2) {
        if (!decompressing(fin, fout)) {
            printf("Error decompressing file!\n");
        }
    } else {
        printf("Invalid choice!\n");
    }

    fclose(fin);
    fclose(fout);
    return 0;
}

int compressing(FILE *fin, FILE *fout)
{
    int c, count;
    char last;

    count = 0;
    last = '\0';

    while ((c = fgetc(fin)) != EOF) {
        if (isalpha(c)) {
            if (c == last) {
                count++;
            } else {
                if (count >= 2) {
                    if (count > 9) {
                        while (count > 9) {
                            fputc(last, fout);
                            fprintf(fout, "$9");
                            count -= 9;
                        }
                    }
                    fputc(last, fout);
                    fprintf(fout, "$%d", count);
                    count = 0;
                }
                last = c;
            }
        } else {
            if (count >= 2) {
                if (count > 9) {
                    while (count > 9) {
                        fputc(last, fout);
                        fprintf(fout, "$9");
                        count -= 9;
                    }
                }
                fputc(last, fout);
                fprintf(fout, "$%d", count);
                count = 0;
            }
            last = '\0';
            fputc(c, fout);
        }
    }

    if (count >= 2) {
        if (count > 9) {
            while (count > 9) {
                fputc(last, fout);
                fprintf(fout, "$9");
                count -= 9;
            }
        }
        fputc(last, fout);
        fprintf(fout, "$%d", count);
    } else if (last != '\0') {
        fputc(last, fout);
    }

    return ftell(fout);
}

int decompressing(FILE *fin, FILE *fout) {
    char c;
    int count = 0;
    while ((c = fgetc(fin)) != EOF) {
        if (c == '$') {
            // read the number of repetitions
            int num_repetitions = 0;
            while ((c = fgetc(fin)) != EOF && isdigit(c)) {
                num_repetitions = num_repetitions * 10 + (c - '0');
            }
            // read the repeated character
            if (c == EOF) {
                return 0;
            }
            char repeated_char = c;
            // write the repeated character to the output file
            for (int i = 0; i < num_repetitions; i++) {
                fputc(repeated_char, fout);
                count++;
            }
        } else {
            fputc(c, fout);
            count++;
        }
    }
    return count;
}