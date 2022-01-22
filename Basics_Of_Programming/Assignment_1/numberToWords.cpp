// AtharvaCM

// A program to convert number to words.

// Sample 1
// Input: 2763654
// Expected output:
// two MILLION seven HUNDRED sixty three THOUSAND six HUNDRED fifty four

// write a function convertToWords(numString) function which will take a number string of maxlen 3 as input
// and convert it to words and prepend to result string

// write a function convert(numString) which will take numString as argument and iterate over the string
// taking max 3 digits per iteration and convert them to words and then add proper suffix

// Mon, Jan 10 2022
// -----------------------------------------------------------------------

#include <iostream>
#include <string>

// string to store result
std::string RESULT;

// A function which converts max 3 digits to words
void convertToWords(std::string numString)
{
    const char *digits_1[20] = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine", "Ten",
                                " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen",
                                " Seventeen", " Eighteen", " Nineteen"};

    const char *digits_2[11] = {"",
                                " Ten",
                                " Twenty",
                                " Thirty",
                                " Fourty",
                                " Fifty",
                                " Sixty",
                                " Seventy",
                                " Eighty",
                                " Ninety",
                                " Hundred"};

    int len = numString.length();
    // convert string to int
    int numInt = std::stoi(numString);

    switch (len)
    {
    case 3:
        // if all digits are 0
        if (numString == "000")
            return;

        if ((numInt % 100) / 10 == 1)
            RESULT.insert(0, digits_1[numInt % 100]); // tens place
        else
        {
            RESULT.insert(0, digits_1[numInt % 10]);         // units place
            RESULT.insert(0, digits_2[(numInt % 100) / 10]); // tens place
        }
        if ((numInt / 100) != 0) // if hundreds place is not empty
            RESULT.insert(0, " HUNDRED");
        RESULT.insert(0, digits_1[numInt / 100]); // hundreds palce
        break;

    case 2:
        if ((numInt % 100) / 10 == 1)
            RESULT.insert(0, digits_1[numInt % 100]);
        else
        {
            RESULT.insert(0, digits_1[numInt % 10]);         // units place
            RESULT.insert(0, digits_2[(numInt % 100) / 10]); // tens place
        }
        break;

    case 1:
        if (numInt % 10 == 0)
            RESULT.insert(0, " Zero");
        else
            RESULT.insert(0, digits_1[numInt % 10]); // units place
        break;

    default:
        std::cout << "\n[+] Invalid length!" << std::endl;
        exit(1);
    }
    // std::cout << RESULT << std::endl;
}

// A function which takes a numString and converts it to words
void convert(std::string numString)
{
    const char *suffix[] = {"", " THOUSAND,", " MILLION,", " BILLION,", " TRILLION,", " QUADRILLION,", " QUINTRILLION,", " SEXTILLION,",
                            " SEPTILIION,", " OCTILLION,", " NONILLION,", " DECILLION,", " UNDECILLION", " DUODECILLION", " TREDECILLION",
                            " QUATTUORDECILLION", " QUINDECILLION", " SEXDECILLION", " SPETEN-DECILLION", " OCTODECILLION", " NOVEMDECILLION",
                            " VIGINTILLION"};

    int len = numString.length();
    std::string splitString;
    int i = 0;

    if (len % 3 == 0)
        i++;
    // loop over the string taking max 3 digits per iteration
    for (i; i <= (len / 3); i++)
    {
        // copy rightmost 3 digits into a string buffer
        // std::cout << "numstr = " << numString << std::endl;
        if (numString.length() > 3)
            splitString = numString.substr(numString.length() - 3);
        else
            splitString = numString;

        // std::cout << "split = " << splitString << std::endl;
        // add proper suffix
        if (splitString != "000")
        {
            if (len % 3 == 0)
                RESULT.insert(0, suffix[i - 1]);
            else
                RESULT.insert(0, suffix[i]);
        }

        // convert to words
        convertToWords(splitString);

        // truncate string
        if (numString.length() >= 3)
            numString.erase(numString.length() - 3);
    }
}

int main()
{
    std::string numString;
    // input the number
    std::cout << "\n[+] Enter the number to convert: ";
    std::cin >> numString;

    // convert the string
    convert(numString);

    // print the result
    std::cout << RESULT << std::endl;
}