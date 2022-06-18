#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int cipher(int, string);

int main(int argc, string argv[])
{
    // Checking if there is only 1 arguments and it is a number
    if (argc == 2 && isdigit(*argv[1]))
    {
        // Convert into integar
        int key = atoi(argv[1]);

        // Getting text
        string plainText = get_string("Enter text: ");

        // Printing out the cipher
        printf("Ciphertext: ");
        cipher(key, plainText);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

int cipher(int key, string plainText)
{
    // Iterate through plain text letter by letter
    for (int i = 0, length = strlen(plainText); i < length; i++)
    {
        // Checking if it is lowercase
        if (plainText[i] >= 'a' && plainText[i] <= 'z')
        {
            // Print out lowercase with key
            printf("%c", (((plainText[i] - 'a') + key) % 26) + 'a');
        }
        // Checking if it is between uppercase
        else if (plainText[i] >= 'A' && plainText[i] <= 'Z')
        {
            // Printing out uppercase with key
            printf("%c", (((plainText[i] - 'A') + key) % 26) + 'A');
        }
        else
        {
            printf("%c", plainText[i]);
        }
    }
    printf("\n");

    return 0;
}