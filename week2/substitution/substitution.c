#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc > 2 || argc == 1) {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int key_size = strlen(argv[1]);
    if (key_size != 26) {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // key is the difference between plain text and cipher text
    // cipher_char = plain_char + key[plain_char_index];
    int index;
    int key[26];
    bool is_present[26];
    for (int i = 0, j = strlen(argv[1]); i < j; ++i) {
        if (isupper(argv[1][i])) {
            index = argv[1][i]-'A';
            if (is_present[index]) {
                printf("Key must not be duplicated.\n");
                return 1;
            }
            is_present[index] = true;
            key[i] = index - i;
        } else if (islower(argv[1][i])) {
            index = argv[1][i]-'a';
            key[i] = index - i;
            if (is_present[index]) {
                printf("Key must not be duplicated.\n");
                return 1;
            }
            is_present[index] = true;
        } else {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    string plain_text = get_string("plaintext:  ");
    printf("ciphertext: ");

    int len_plain_text = strlen(plain_text);
    for (int i = 0; i < len_plain_text; ++i) {
        // type next_char as int for checking overflow
        int next_char;

        if (isupper(plain_text[i])) {
            printf("%c", plain_text[i] + key[plain_text[i]-'A']);
        } else if (islower(plain_text[i])) {
            printf("%c", plain_text[i] + key[plain_text[i]-'a']);
        } else printf("%c", plain_text[i]);
    }
    printf("\n");
}