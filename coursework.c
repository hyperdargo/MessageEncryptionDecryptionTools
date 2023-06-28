#include <stdio.h>
#include <ctype.h>

void encrypt(char *plaintext, int shift) {
    int i = 0;
    while (plaintext[i] != '\0') {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                plaintext[i] = (((plaintext[i] - 'A') + shift) % 26) + 'A';
            } else {
                plaintext[i] = (((plaintext[i] - 'a') + shift) % 26) + 'a';
            }
        }
        i++;
    }
}

void decrypt(char *ciphertext, int shift) {
    int i = 0;
    while (ciphertext[i] != '\0') {
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i])) {
                ciphertext[i] = (((ciphertext[i] - 'A') - shift + 26) % 26) + 'A';
            } else {
                ciphertext[i] = (((ciphertext[i] - 'a') - shift + 26) % 26) + 'a';
            }
        }
        i++;
    }
}

void welcome() {
    printf("Welcome to Message encryption and decryption\n");
    printf("This program can encrypt and decrypt messages\n");
}

int enter_message() {
    int msg;
    printf("Write 1 to encrypt, 2 to decrypt, and 3 to quit the program: ");
    scanf("%d", &msg);
    return msg;
}

int main() {
    welcome();

    while (1) {
        int choice = enter_message();

        if (choice == 1) {
            char plaintext[100];
            int shift;

            printf("Enter a string to encrypt: ");
            scanf(" %[^\n]s", plaintext);

            printf("Enter the shift value: ");
            scanf("%d", &shift);

            encrypt(plaintext, shift);
            printf("Encrypted message: %s\n", plaintext);
        } else if (choice == 2) {
            char ciphertext[100];
            int shift;

            printf("Enter a string to decrypt: ");
            scanf(" %[^\n]s", ciphertext);

            printf("Enter the shift value: ");
            scanf("%d", &shift);

            decrypt(ciphertext, shift);
            printf("Decrypted message: %s\n", ciphertext);
        } else if (choice == 3) {
            printf("Quitting the program\n");
            break;
        } else {
            printf("Invalid choice. Please enter either 1, 2, or 3.\n");
        }

        // Clear the input buffer
        while (getchar() != '\n');
    }

    return 0;
}
