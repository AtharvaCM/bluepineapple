// AtharvaCM

// Write a program to count the number of digits in a given number.

// Sample 1
// Input: 62537
// Expected output: 5

// Sample 2
// Input: 62537554
// Expected output: 8

// Algorithm:
// 1] Input a number
// 2] Check if number > 0
//     3] Divide the number by 10 and increment counter
//     4] goto [2]
// 5] Print counter

// Mon, Jan 10 2022
// -----------------------------------------------------------------------

#include <stdio.h>

int main()
{
    int num, temp;
    int counter = 0;

    // input the number from user
    printf("\n[+] Enter a number: ");
    scanf("%d", &num);

    temp = num;

    while (temp > 0)
    {
        counter++;
        temp /= 10;
    }

    printf("\n[+] There are %d digits in %d\n", counter, num);
}

/*

atharva-cm@ShadyXV:~/dev/bluepineapple-internship/Assignment_1$ ./a.out 

[+] Enter a number: 62537

[+] There are 5 digits in 62537

*/