#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
// calculate 0.0588 * L - 0.296 * S - 15.8 for given string where
// L : avg # of letters per 100 words (100.0 * letters / words)
// S : avg # of sentences per 100 words (100.0 * sentences / words)

// specifications:
//  letters: [a-zA-Z]
//  words: ' 'count + 1 (no multiple spaces between words.)
//  sentence: '.'count + '?'count + '!'count

    string s = get_string("Text: ");

    // variable as double to calculate L, S
    double letters = 0;
    double words = 1;
    double sentences = 0;

    for (int i = 0, j = strlen(s); i < j; ++i) {
        if (isalpha(s[i])) letters = letters + 1;
        else if (s[i] == ' ') words = words + 1;
        else if (s[i] == '!' || s[i] == '?' || s[i] == '.') sentences = sentences + 1;
    }

    // check results
    // printf("letters: %f\nwords: %f\nsentences: %f\n", letters, words, sentences);

    double L = 100.0 * letters / words;
    double S = 100.0 * sentences / words;
    int index = (int) round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1) {
        printf("Before Grade 1\n");
        return 0;
    }
    for (int i = 1; i < 16; ++ i) {
        if (index == i) {
            printf("Grade %i\n", i);
            return 0;
        }
    }
    printf("Grade 16+\n");
}