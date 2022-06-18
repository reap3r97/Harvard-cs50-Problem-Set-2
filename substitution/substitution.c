#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Checking if command line argument is not equal to 2
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Getting the lenth of argv[1]
    int argv_length = strlen(argv[1]);

    // Making sure argv length is 26 characters
    if (argv_length != 26)
    {
        printf("Key must be up to 26\n");
        return 1;
    }

    // Iterating over argv_length to get its characters
    for (int i = 0; i < argv_length; i++)
    {
        // Checking if argv[1] is not alphabets
        if (!isalpha(argv[1][i]))
        {
            printf("All keys must be an alphabeth\n");
            return 1;
        }

        // Declaring another iteration on argv_length to check repeated alphabets
        for (int j = i + 1; j < argv_length; j++)
        {
            // Checking repeated alphabets in argv[1]
            if (argv[1][i] == argv[1][j])
            {
                printf("Key must not contain repeated alphabets");
                return 1;
            }
        }
    }

    // Getting user's input
    string plaintext = get_string("plaintext: ");

    // Printing ciphertext
    printf("ciphertext: ");

    // Getting length of user's input
    int plaintext_length = strlen(plaintext);

    // Iterating over the plaintext_Length
    for (int i = 0; i < plaintext_length; i++)
    {
        // Checking if plaintext character is uppercase
        if (isupper(plaintext[i]))
        {
            printf("%c", toupper(argv[1][plaintext[i] - 65]));
        }
        // Checking if plaintext character is lowercase
        else if (islower(plaintext[i]))
        {
            printf("%c", tolower(argv[1][plaintext[i] - 97]));
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}