// Program that checks if an array of chars is a palindrome or not
// Tue, Jan 11 2022

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Check if string is palindrome or not
bool isPalindrome(char *word)
{
    int len = strlen(word);

    for (int i = 0; i < len; i++)
        // check i with len - i
        if (word[i] != word[len - i - 1])
            return false;
    return true;
}

int main()
{
    // input the array
    char word[256];

    printf("\n[+] Enter a word: ");
    scanf("%s", word);

    if (isPalindrome(word))
        printf("\n[+] %s is a palindrome!\n", word);
    else
        printf("\n[+] %s is not a palindrome!\n", word);
}