// Program to create a map of all the unique words from a file and print their frequency.
// Tue, Jan 11 2022

#include <iostream>
#include <iterator>
#include <map>
#include <bits/stdc++.h>

// empty map container
std::unordered_map<std::string, int> frequencyMap;

void readWordsToMap()
{
    // input words from file
    std::fstream file;
    std::string filename, word;

    filename = "input.txt";

    // open file
    file.open(filename.c_str());

    // extracting words from file
    while (file >> word)
    {
        // check if the word is present in the map
        // if not then add the word in map
        if (frequencyMap.count(word) == 0)
        {
            // insert word with freq 1
            frequencyMap.insert(std::pair<std::string, int>(word, 1));
        }
        else
        {
            // increment the freq counter
            frequencyMap[word]++;
        }
    }
}

void printMap()
{
    // iterator for the map
    std::unordered_map<std::string, int>::iterator itr;

    std::cout << "\n";
    for (itr = frequencyMap.begin(); itr != frequencyMap.end(); ++itr)
    {
        std::cout << itr->first << "\t" << itr->second << std::endl;
    }
    std::cout << "\n";
}

void printWordFreq(std::string word)
{
    // check if the word is present in the map
    if (frequencyMap.count(word) == 0)
        std::cout << "\n[+] The word '" + word + "' is not present.\n";
    else
    {
        std::cout << "[+] The word '" + word + "' occurred ";
        std::cout << frequencyMap[word];
        std::cout << " times\n";
    }
}

int main()
{
    std::string word;

    readWordsToMap();

    // printMap();

    // input a word from user
    std::cout << "\n[+] Enter a word to check its frequency: ";
    std::cin >> word;

    printWordFreq(word);

    return 0;
}