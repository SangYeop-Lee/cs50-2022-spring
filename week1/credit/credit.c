#include <cs50.h>
#include <stdio.h>

int count_digits(long int card_number);
bool is_valid_card_number(long int card_number, int length);
bool is_visa(long int card_number, int length);
bool is_master(long int card_number, int length);
bool is_amex(long int card_number, int length);
long int power_of_ten(int n);

int main(void)
{
    long int card_number = get_long("Number: ");

    int length = count_digits(card_number);

    if (!is_valid_card_number(card_number, length)) {
        printf("INVALID\n");
        return 0;
    }

    if (is_visa(card_number, length)) {
        printf("VISA\n");
    } else if (is_master(card_number, length)) {
        printf("MASTERCARD\n");
    } else if (is_amex(card_number, length)) {
        printf("AMEX\n");
    } else {
        printf("INVALID\n");
    }
}

int count_digits(long int card_number) {
    int i = 0;
    while (card_number != 0) {
        ++i;
        card_number /= 10;
    }
    return i;
}

bool is_valid_card_number(long int card_number, int length) {
    int acc = 0;
    for (int i = 0; i < length; ++i) {
        int last_digit = card_number % 10;
        if (i % 2) {
            last_digit *= 2;
        }
        acc += last_digit % 10 + last_digit / 10;
        card_number /= 10;
    }
    return acc % 10 == 0;
}

// length: 13, 16
// start with 4
bool is_visa(long int card_number, int length) {
    if (!(length == 13 || length == 16)) {
        return false;
    }

    long int head_number = card_number / power_of_ten(length - 1);
    return head_number == 4;
}

// length: 16
// start with 51 52 53 54 55
bool is_master(long int card_number, int length) {
    if (!(length == 16)) {
        return false;
    }

    int head_number = card_number / power_of_ten(length - 2);
    return head_number <= 55 && head_number >= 51;
}

// length: 15
// start with 34, 37
bool is_amex(long int card_number, int length){
    if (!(length == 15)) {
        return false;
    }

    int head_number = card_number / power_of_ten(length - 2);
    return head_number == 34 || head_number == 37;
}

long int power_of_ten(int n) {
    long int ret = 1;
    for (int i = 0; i < n; ++ i) {
        ret *= 10;
    }
    return ret;
}