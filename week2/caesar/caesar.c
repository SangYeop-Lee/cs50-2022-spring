#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc > 2 || argc == 1) {
        printf("Usage: ./casear key\n");
        return 1;
    }
    for (int i = 0, j = strlen(argv[1]); i < j; ++i) {
        if (!isdigit(argv[1][i])) {
            printf("Usage: ./casear key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]) % 26;

    string plain_text = get_string("plaintext:  ");
    printf("ciphertext: ");

    int len_plain_text = strlen(plain_text);
    for (int i = 0; i < len_plain_text; ++i) {
        // type next_char as int for checking overflow
        int next_char = plain_text[i] + key;
        if (isupper(plain_text[i])) printf("%c", next_char > 'Z' ? next_char-26 : next_char);
        else if (islower(plain_text[i])) printf("%c", next_char > 'z' ? next_char-26 : next_char);
        else printf("%c", plain_text[i]);
    }
    printf("\n");
}