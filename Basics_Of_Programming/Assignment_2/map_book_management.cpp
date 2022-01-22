// Program that implements map for book management system.
// Tue, Jan 11 2022

#include <iostream>
#include <iterator>
#include <map>
#include <bits/stdc++.h> // unordered map

// map container
std::unordered_map<std::string, std::string> bookMap;

void display_menu()
{
    std::cout << "\n------------------------------------------------";
    std::cout << "\n[+] 1. Insert A Book\n[+] 2. Delete A Book\n[+] 3. Display Books\n[+] 4. Search By Name\n[+] 5. Exit\n";
    std::cout << "\n[+] Select an option: ";
}

void insertBook()
{
    std::string name;

    std::cout << "\n[+] Enter the book name to insert: ";
    std::cin >> name;

    // insert into the map
    bookMap.insert(std::pair<std::string, std::string>(name, name));
}

void deleteBook()
{
    std::string name;

    std::cout << "\n[+] Enter the book name to delete: ";
    std::cin >> name;

    // delete from the map with key
    bookMap.erase(name);
}

void displayMap()
{
    // iterator for the map
    std::unordered_map<std::string, std::string>::iterator itr;

    // print all elements of the map
    std::cout << "\n------------------------------------------------\n";
    std::cout << "\n[+] List of all the books: ";
    std::cout << "\n------------------------------------------------\n";

    for (itr = bookMap.begin(); itr != bookMap.end(); ++itr)
    {
        std::cout << '\t' << itr->second << '\n';
    }
    std::cout << std::endl;
}

void searchByName()
{
    std::string name;

    std::cout << "\n[+] Enter the book name to search: ";
    std::cin >> name;

    // find the element with given key
    // find() returns map.end() if the key is not present
    if (bookMap.find(name) != bookMap.end())
        std::cout << "[+] " + name + " Book is PRESENT in the map\n";
    else
        std::cout << "[+] " + name + " Book is NOT PRESENT in the map\n";
}

int main()
{
    int op;

    // menu
    do
    {
        display_menu();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            insertBook();
            break;

        case 2:
            deleteBook();
            break;

        case 3:
            displayMap();
            break;

        case 4:
            searchByName();
            break;

        case 5:
            exit(0);
            break;
        default:
            printf("\n[+] Invalid input!");
        }
    } while (1);

    return 0;
}