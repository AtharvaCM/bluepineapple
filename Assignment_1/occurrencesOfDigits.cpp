// AtharvaCM

// Program to find total occurennces of each digit (0-9) using funtion.
// number can be 10 digits or so

// Sample 1
// Input: 9168066559
// Expected output:
// 0 = 1
// 1 = 1
// 2 = 0
// 3 = 0
// 4 = 0
// 5 = 2
// 6 = 3
// 7 = 0
// 8 = 1
// 9 = 2

// Algorithm:
// 1] Input number
// 2] init array of digits to 0
// 3] loop the number
//      4] get the char of number
//      5] calculate the index using ASCII values (char - '0')...0 is 49 in ASCII
//      6] increment the digits array for that index
// 7] print the digits array

// Mon, Jan 10 2022
// -----------------------------------------------------------------------

#include <iostream>

void getOccurrences(std::string number, int digits[])
{
    // iterate over the number
    for (int i = 0; i < number.length(); i++)
    {
        char digit = number[i];
        int index = digit - '0'; // '0' will be equivalent to int(49)
        // increment the counter for that respective digit
        digits[index]++;
    }
}

int main()
{
    // storing number as string
    std::string number;
    std::cout << "\n[+] Enter a number: ";
    std::cin >> number;

    // init array of digits to store the count of each digit (0 - 9)
    int digits[10] = {0};

    getOccurrences(number, digits);

    // print the occurrences
    for (int i = 0; i < 10; i++)
        printf("\n[+] The digit %d occurred %d times", i, digits[i]);

    std::cout << "\n";
}

/*

atharva-cm@ShadyXV:~/dev/bluepineapple-internship/Assignment_1$ ./a.out 

[+] Enter a number: 9168066559

[+] The digit 0 occurred 1 times
[+] The digit 1 occurred 1 times
[+] The digit 2 occurred 0 times
[+] The digit 3 occurred 0 times
[+] The digit 4 occurred 0 times
[+] The digit 5 occurred 2 times
[+] The digit 6 occurred 3 times
[+] The digit 7 occurred 0 times
[+] The digit 8 occurred 1 times
[+] The digit 9 occurred 2 times

*/