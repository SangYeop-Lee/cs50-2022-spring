#include <cs50.h>
#include <stdio.h>

void print_char_n_times (char c, int iter);

int main(void)
{
    int i;
    do {
        i = get_int("Height: ");
    } while (!(i > 0 && i < 9));

    for (int j=0; j<i; ++j) {
        print_char_n_times(' ', i - j - 1);
        print_char_n_times('#', j + 1);
        print_char_n_times(' ', 2);
        print_char_n_times('#', j + 1);
        printf("\n");
    }
}

void print_char_n_times (char c, int iter) {
    for (int i = 0; i < iter; ++i) {
        printf("%c", c);
    }
}