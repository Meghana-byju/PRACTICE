struct Trauma {
    char keyword[8];  // "specter" + '\0'
    char message[512];
};
struct Trauma arthurTrauma = {
    "specter",
    "I confess. After graduating from university, I was blinded by the arrogance of starting a startup and recklessly blocked my friends' paths. I painfully learned that when I am the only one convinced by my idea, it leads to disastrous results. The past Arthur was a ghost of dogmatism and stubbornness."
};
#include <stdio.h>
#include <string.h>

void to_binary_reverse(const char *keyword, char binary[7][9]) {
    for (int i = 6; i >= 0; --i) {
        unsigned char c = keyword[i];
        for (int j = 7; j >= 0; --j) {
            binary[6 - i][7 - j] = (c & (1 << j)) ? '1' : '0';
        }
        binary[6 - i][8] = '\0';
    }
}

int isRightChar(char binary[7][9], char user_chars[8]) {
    for (int i = 0; i < 7; ++i) {
        char ch = 0;
        for (int j = 0; j < 8; ++j) {
            ch <<= 1;
            if (binary[i][j] == '1') ch |= 1;
        }
        if (user_chars[i] != ch) return 0;
    }
    return 1;
}

int isEasterEgg(const char *input) {
    return strcmp(input, "specter") == 0;
}

void find_easter_egg() {
    printf("<<Arthur's Easter Egg>>\n");

    char binary[7][9];
    to_binary_reverse("specter", binary);

    printf("Binary values (reversed order of keyword):\n");
    for (int i = 0; i < 7; ++i) {
        printf("%s\n", binary[i]);
    }

    char user_chars[8];
    int correct = 0;
    while (!correct) {
        printf("Enter the 7 characters (no spaces): ");
        scanf("%7s", user_chars);
        if (isRightChar(binary, user_chars)) {
            correct = 1;
        } else {
            printf("Incorrect characters. Try again.\n");
        }
    }

    char final_word[8];
    printf("Combine the characters into the keyword: ");
    scanf("%7s", final_word);

    if (isEasterEgg(final_word)) {
        printf("##Easter Egg Discovered!$$\n");
        printf("%s\n", arthurTrauma.message);
    } else {
        printf("Incorrect keyword. Returning to menu...\n");
    }
}
char input[20];
printf("Enter your name: ");
scanf("%19s", input);
if (strcmp(input, "Arthur") == 0) {
    find_easter_egg();
}
#include <stdlib.h>
#include <time.h>

void shuffle_and_convert(const char *keyword) {
    char temp[8];
    strcpy(temp, keyword);

    // Shuffle
    srand((unsigned) time(NULL));
    for (int i = 6; i > 0; --i) {
        int j = rand() % (i + 1);
        char t = temp[i];
        temp[i] = temp[j];
        temp[j] = t;
    }

    printf("Shuffled Keyword: %s\n", temp);

    // Binary
    char binary[7][9];
    for (int i = 0; i < 7; ++i) {
        unsigned char c = temp[i];
        for (int j = 7; j >= 0; --j) {
            binary[i][7 - j] = (c & (1 << j)) ? '1' : '0';
        }
        binary[i][8] = '\0';
    }

    // Reverse and rearrange
    printf("Rearranged Binary:\n");
    for (int i = 1; i < 7; i += 2) printf("%s\n", binary[i]);
    for (int i = 0; i < 7; i += 2) printf("%s\n", binary[i]);
}
