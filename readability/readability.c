#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Declaring functions prototypes
int count_letters(string);
int count_words(string);
int count_sentences(string);

int main(void)
{
    // Taking user input
    string text = get_string("Enter text here: \n");

    // Calculating letters
    int letters = count_letters(text);

    // Calculating words
    int words = count_words(text);

    // Calculating sentences
    int sentences = count_sentences(text);

    // Calculating grade reading index
    float averageWords = (100 / (float)words) * (float)letters;
    float averageSentence = (100 / (float)words) * (float)sentences;

    // Rounding off the results
    int readingIndex = round(0.0588 * averageWords - 0.296 * averageSentence - 15.8);

    // Displaying results
    if (readingIndex < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (readingIndex > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", readingIndex);
    }
}

// Function to count letters
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters += 1;
        }
    }

    return letters;
}

// Function to count words
int count_words(string text)
{
    int words = 0;

    for (int i = 0, length = strlen(text); i <= length; i++)
    {
        if (text[i] == ' ' || text[i] == '\0')
        {
            words += 1;
        }
    }

    return words;
}

// Function to count sentences
int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences += 1;
        }
    }

    return sentences;
}