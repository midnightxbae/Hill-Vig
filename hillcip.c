// HILL CIPHER

#include <stdio.h>
#include <string.h>

int main() {
  // Define the Hill Cipher matrices
  int keyMatrix[3][3] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}};
  int inverseKeyMatrix[3][3] = {{8, 5, 10}, {21, 8, 21}, {21, 12, 8}};

  int i, j, sum;
  int encryptedText[3], decryptedText[3];
  char plaintext[20];

  printf("Enter plain text: ");
  scanf("%s", plaintext);

  // Convert the plaintext to numbers
  for (i = 0; i < strlen(plaintext); i++) {
    encryptedText[i] = plaintext[i] - 'A';
  }

  // Encryption
  printf("\nEncrypted Cipher Text: ");
  for (i = 0; i < 3; i++) {
    sum = 0;
    for (j = 0; j < 3; j++) {
      sum += keyMatrix[i][j] * encryptedText[j];
    }
    decryptedText[i] = sum % 26;
    printf("%c", decryptedText[i] + 'A');
  }

  // Decryption
  printf("\nDecrypted Cipher Text: ");
  for (i = 0; i < 3; i++) {
    sum = 0;
    for (j = 0; j < 3; j++) {
      sum += inverseKeyMatrix[i][j] * decryptedText[j];
    }
    encryptedText[i] = sum % 26;
    printf("%c", encryptedText[i] + 'A');
  }

  printf("\n");

  return 0;
}
