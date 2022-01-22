// Program which suggests word w.r.t to given input.
// Tue, Jan 21 2022

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <fstream>
#include <chrono> // calculate time
using namespace std::chrono;

#define ALPHABET_SIZE 26

bool WORD_FOUND = false;

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

// Returns new trie node
struct TrieNode *getNode(void)
{
    struct TrieNode *temp = new TrieNode;
    if (temp == NULL)
    {
        std::cout << "\n[+] Cannot allocate memory...!";
        exit(0);
    }

    temp->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        temp->children[i] = NULL;

    return temp;
}

// insert a word in the trie
void insert(struct TrieNode *root, std::string key)
{
    // std::cout << "\t inserting";
    struct TrieNode *crawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        // if link does not exist to that letter create it
        if (!crawl->children[index])
            crawl->children[index] = getNode();
        crawl = crawl->children[index];
    }
    // mark the last node as leaf
    crawl->isEndOfWord = true;
}

// returns true if the key is present in the trie else false
bool search(struct TrieNode *root, std::string key)
{
    struct TrieNode *crawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        // if no link is present word is not in the trie
        if (!crawl->children[index])
            return false;

        crawl = crawl->children[index];
    }

    return crawl->isEndOfWord;
}

// display all the words in the trie
void display(struct TrieNode *root, std::string str, int level)
{
    // if node is a leaf node then display the word
    if (root->isEndOfWord)
        std::cout << "-" << str << std::endl;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        // if NON NULL child is found add parent key to str and call the display
        // function recursively for child node
        if (root->children[i])
        {
            str.at(level) = i + 'a';
            display(root->children[i], str, level + 1);
        }
    }
}

// searches the trie recursively for pattern and displays the words that match
void search_words(struct TrieNode *root, std::string pattern, std::string word, int level)
{
    // std::cout << "@" << std::endl;
    if (pattern.empty())
    {
        if (root->isEndOfWord)
        {
            WORD_FOUND = true;
            std::cout << word << std::endl;
        }

        return;
    }

    // if - is there traverse every node to check next pattern
    if (pattern[0] == '-')
    {
        std::string new_pattern = pattern.substr(1);
        level += 1;

        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            // if a child exists
            if (root->children[i])
            {
                word.at(level - 1) = i + 'a';
                search_words(root->children[i], new_pattern, word, level);
            }
        }

        return;
    }

    int index = pattern[0] - 'a';
    // if there is link available
    if (root->children[index])
    {
        word.at(level) = index + 'a';
        search_words(root->children[index], pattern.substr(1), word, level + 1);
    }
}

// driver code
int main()
{
    std::string temp;
    std::string word = "                                                 ";
    std::string pattern;
    int level = 0;

    struct TrieNode *root = getNode();

    std::ifstream file("alpha_dict.txt");
    if (file)
    {
        for (int i = 0; i < 370100; i++)
        {
            file >> temp;
            insert(root, temp);
        }
    }
    else
    {
        std::cerr << "[+] Could not open file!" << std::endl;
        exit(0);
    }
    file.close();
    std::cout << "[+] Loaded dictionary" << std::endl;

    // display(root, str, level);

    // search(root, "the") ? std::cout << "Yes\n" : std::cout << "No\n";

    std::cout << "\n[+] Enter the pattern to search, type '-' for unknown chars (ex: -a-): ";
    std::cin >> pattern;

    // Get starting timepoint
    auto start = high_resolution_clock::now();

    search_words(root, pattern, word, level);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    std::cout << "Time taken by function: "
              << duration.count() << " microseconds" << std::endl;

    if (!WORD_FOUND)
        std::cout << "\n[+] No words found!" << std::endl;
}