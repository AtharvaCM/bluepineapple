// AtharvaCM

// A program to print all perfect numbers between 1 to n.

// Sample 1
// Input: 100
// Expected output:
// 6
// 28

// Algorithm:
// 1] Input n
// 2] loop till n from i=1
//     3] Call getSumOfFactors(i)
//     4] check if sum matches i
//          5] print i is perfect

// Mon, Jan 10 2022
// -----------------------------------------------------------------------

#include <stdio.h>

int getSumOfFactors(int num)
{
    // test case for i == 1
    if (num == 1)
        return 0;

    int sum = 0;

    // check for factors and add them
    for (int i = 1; i < (num / 2) + 1; i++)
        if ((num % i) == 0)
            sum += i;

    return sum;
}

int main()
{
    int n;

    // input n
    printf("\n[+] Enter n: ");
    scanf("%d", &n);

    // iterate n times
    for (int i = 1; i <= n; i++)
        // check if i == sum of its factors
        if (i == getSumOfFactors(i))
            // print i
            printf("\n[+] %d is a perfect number.", i);

    printf("\n");
}

/*

atharva-cm@ShadyXV:~/dev/bluepineapple-internship/Assignment_1$ ./a.out 

[+] Enter n: 100

[+] 6 is a perfect number.
[+] 28 is a perfect number.

*/