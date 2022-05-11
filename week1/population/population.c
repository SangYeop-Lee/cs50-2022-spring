#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int population, end;
    do {
        population = get_int("Start size: ");
    } while (population < 9);

    do {
        end = get_int("End size: ");
    } while (end <= population);

    int year = 0;
    while (population < end) {
        int delta = population / 3;
        delta -= population / 4;
        population += delta;
        ++year;
    }
    printf("Year: %d\n", year);
}
