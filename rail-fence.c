#include <stdio.h>
#include <string.h>

void railFenceCipher(char *input, char *cipher, int rails) {
    int length = strlen(input);
    int cycle = 2 * (rails - 1);
    int cipherIndex = 0;

    for (int i = 0; i < rails; i++) {
        int step = cycle - 2 * i;
        for (int j = i; j < length; j += cycle) {
            cipher[cipherIndex++] = input[j];

            if (step > 0 && step < cycle && j + step < length)
                cipher[cipherIndex++] = input[j + step];
        }
    }

    cipher[cipherIndex] = '\0';
}

void displayRailFence(char *input, int rails) {
    int length = strlen(input);
    int cycle = 2 * (rails - 1);

    for (int i = 0; i < rails; i++) {
        int step = cycle - 2 * i;
        for (int j = i; j < length; j += cycle) {
            putchar(input[j]);

            if (step > 0 && step < cycle && j + step < length) {
                putchar(' ');
                putchar(input[j + step]);
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

void railFenceDecipher(char *cipher, char *decipher, int rails) {
    int length = strlen(cipher);
    int cycle = 2 * (rails - 1);
    int decipherIndex = 0;

    for (int i = 0; i < rails; i++) {
        int step = cycle - 2 * i;
        for (int j = i; j < length; j += cycle) {
            decipher[j] = cipher[decipherIndex++];

            if (step > 0 && step < cycle && j + step < length)
                decipher[j + step] = cipher[decipherIndex++];
        }
    }

    decipher[length] = '\0';
}

int main() {
    char input[100], cipher[100], decipher[100];
    int rails;

    printf("\nRAIL FENCE CIPHER");
    printf("\nEnter the input string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    printf("Enter the number of rails: ");
    scanf("%d", &rails);

    railFenceCipher(input, cipher, rails);
    printf("\nCipher text: %s", cipher);

    printf("\nRail Fence Pattern:\n");
    displayRailFence(input, rails);

    railFenceDecipher(cipher, decipher, rails);
    printf("\nDeciphered text: %s\n", decipher);

    return 0;
}
