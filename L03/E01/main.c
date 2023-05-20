#include <stdio.h>
#include <ctype.h>

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"
#define MAX_LINE_LENGTH 25

int main() {
    FILE *input_file = fopen(INPUT_FILE, "r");
    FILE *output_file = fopen(OUTPUT_FILE, "w");
    char c, prev_c = '\0', prev2_c = '\0';
    int line_length = 0, original_line_length = 0;

    while ((c = fgetc(input_file)) != EOF) {
        if (isdigit(c)) {
            fputc('*', output_file);
        } else if (ispunct(c)) {
            fputc(c, output_file);
            if (!isspace(prev_c) && prev_c != '\n' && !ispunct(prev_c)) {
                fputc(' ', output_file);
            }
        } else if (isalpha(c)) {
            if (prev_c == '.' || prev_c == '!' || prev_c == '?') {
                if (islower(c)) {
                    c = toupper(c);
                }
            } else if (prev_c == '\n') {
                c = toupper(c);
            } else {
                c = tolower(c);
            }
            fputc(c, output_file);
        } else if (isspace(c)) {
            fputc(c, output_file);
        }
        original_line_length++;
        line_length++;
        if (c == '\n' || line_length == MAX_LINE_LENGTH) {
            if (prev2_c == '.' || prev2_c == '!' || prev2_c == '?') {
                if (islower(prev_c)) {
                    prev_c = toupper(prev_c);
                }
            }
            if (line_length < MAX_LINE_LENGTH) {
                for (int i = 0; i < MAX_LINE_LENGTH - line_length; i++) {
                    fputc(' ', output_file);
                }
            }
            fprintf(output_file, " | c:%d\n", original_line_length - 1);
            line_length = 0;
        }
        prev2_c = prev_c;
        prev_c = c;
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
