// VIGENERE CIPHER

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encipherText();
void decipherText();

int main() {
  int choice;

  while (1) {
    printf("\n1. Encrypt Text");
    printf("\n2. Decrypt Text");
    printf("\n3. Exit");
    printf("\n\nEnter Your Choice : ");
    scanf("%d", &choice);

    if (choice == 3)
      break;
    else if (choice == 1)
      encipherText();
    else if (choice == 2)
      decipherText();
    else
      printf("Please Enter a Valid Option.");
  }

  return 0;
}

void encipherText() {
  char inputText[50], key[10];
  printf("\n\nEnter Plain Text: ");
  scanf("%s", inputText);
  printf("\nEnter Key Value: ");
  scanf("%s", key);
  printf("\nResult of Encrypted Text: ");

  for (int i = 0, j = 0; i < strlen(inputText); i++, j++) {
    if (j >= strlen(key)) {
      j = 0;
    }
    char encryptedChar = 65 + (((toupper(inputText[i]) - 65) + (toupper(key[j]) - 65)) % 26);
    printf("%c", encryptedChar);
  }
}

void decipherText() {
  char cipherText[50], key[10];
  printf("\n\nEnter Cipher Text: ");
  scanf("%s", cipherText);
  printf("\nEnter the Key Value: ");
  scanf("%s", key);
  printf("\nDeciphered Text: ");

  for (int i = 0, j = 0; i < strlen(cipherText); i++, j++) {
    if (j >= strlen(key)) {
      j = 0;
    }
    int value = (toupper(cipherText[i]) - 64) - (toupper(key[j]) - 64);
    if (value < 0) {
      value = value * -1;
    }
    char decipheredChar = 65 + (value % 26);
    printf("%c", decipheredChar);
  }
}
