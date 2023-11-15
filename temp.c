#include <stdio.h>
#define ROWS 4
#define COLS 3
double get_row_avg(int m[ROWS][COLS], int r);
double get_total_avg(int m[ROWS][COLS]);
int main()
{
    double sum = 0;
    double total = 0;
    int m[ROWS][COLS] = {
        {10, 20, 30},
        {10, 20, 30},
        {10, 20, 30},
        {10, 20, 30}};
    sum = get_row_avg(m, 2);
    printf("Row 2 average: %2.2lf\n", sum);
    total = get_total_avg(m);
    printf("Total average: %2.2lf\n", total);
}
double
get_row_avg(int m[ROWS][COLS], int r)
{
    double sum = 0.0;
    int *p = &m[0][r];
    for (int i = 0; i < ROWS; i++)
    {
        sum += *p;
        p += COLS;
    }
    return sum / ROWS;
}
double
get_total_avg(int m[ROWS][COLS])
{
    double sum = 0.0;
    int *p = &m[0][0];
    for (int i = 0; i < ROWS * COLS; i++)
    {
        sum += *p;
        p++;
    }
    return sum / (ROWS * COLS);
}