#include <stdio.h>
#include <stdlib.h>

#define FILENAME "numbers.txt"

int main()
{
    FILE *fp;
    int x0, x1, x2, max, min, count;
    char op;

    if ((fp = fopen(FILENAME, "r")) == NULL)
    {
        printf("Error opening file %s\n", FILENAME);
        exit(1);
    }

    fscanf(fp, "%d", &x0);
    fscanf(fp, "%d", &x1);

    if (x0 > x1)
    {
        max = x0;
        min = x1;
        op = '-';
    }
    else
    {
        max = x1;
        min = x0;
        op = '+';
    }

    printf("%d %c %d\n", min, op, max);

    count = 0;
    while (fscanf(fp, "%d", &x2) != EOF)
    {
        if (x1 == 0 && op == '/') // Check for division by zero
        {
            printf("Discarding %d\n", x2);
            count++;
            continue;
        }

        int expected = 0;
        switch (op) // Determine expected value
        {
            case '+':
                expected = x0 + x1;
                break;
            case '-':
                expected = x0 - x1;
                break;
            case '*':
                expected = x0 * x1;
                break;
            case '/':
                expected = x0 / x1;
                break;
            default:
                break;
        }

        if (x2 != expected) // Check if value is valid
        {
            printf("Discarding %d\n", x2);
            count++;
            continue;
        }

        if (x2 > max) // Update max value
            max = x2;

        if (x2 < min) // Update min value
            min = x2;

        printf("%d %c %d\n", x1, op, x2);

        op = '+';
        if (x2 < x1)
            op = '-';
        else if (x2 > x1)
            op = '*';

        x0 = x1;
        x1 = x2;
    }

    printf("# of discarded values: %d\n", count);
    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);

    fclose(fp);

    return 0;
}
