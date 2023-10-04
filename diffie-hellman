#include <stdio.h>

long long int customPower(int base, int exponent, int modulo) {
    long long int result = 1;
    long long int term = base % modulo;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * term) % modulo;
        }
        term = (term * term) % modulo;
        exponent /= 2;
    }

    return result;
}

long long int calculateSharedKey(int generator, int privateExponent, int modulus) {
    return customPower(generator, privateExponent, modulus);
}

int main() {
    int modulus, generator, person1Exponent, person2Exponent;

    printf("Enter the modulus (n) and generator (g): ");
    scanf("%d %d", &modulus, &generator);

    printf("Enter the first person's private exponent (x): ");
    scanf("%d", &person1Exponent);

    printf("Enter the second person's private exponent (y): ");
    scanf("%d", &person2Exponent);

    long long int sharedKey1 = calculateSharedKey(generator, person1Exponent, modulus);
    long long int sharedKey2 = calculateSharedKey(generator, person2Exponent, modulus);

    printf("First person's shared key: %lld\n", sharedKey1);
    printf("Second person's shared key: %lld\n", sharedKey2);

    return 0;
}
