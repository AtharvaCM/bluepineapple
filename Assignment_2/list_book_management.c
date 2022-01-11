// Program that implements linked list for book management system.
// Tue, Jan 11 2022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node *head = NULL;

struct node
{
    int id;
    char *name;
    struct node *next;
};

struct node *getnode(int id, char *name)
{
    // allocate memory and initialize the node
    struct node *temp = NULL;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->id = id;
    // allocate mem for temp->name
    temp->name = malloc(strlen(name) + 1);
    strcpy(temp->name, name);
    temp->next = NULL;

    // return the address of the node
    return temp;
}

// init the header node
void init()
{
    // id in the header node will represent the ccount of nodes
    head = getnode(0, "");
}

void freenode(struct node *p)
{
    // free memory
    free(p);
}

void append(int id, char *name)
{
    struct node *temp = head->next;

    // if list is empty
    if (temp == NULL)
        head->next = getnode(id, name);
    else
    {
        // traverse to the end
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = getnode(id, name);
    }

    // increment the header count
    head->id++;
}

void insert(int pos, int id, char *name)
{
    // if the list is empty just use append()
    if (head->id == 0 && pos == 1)
    {
        append(id, name);
        return;
    }

    // declare temp pointers
    struct node *p = (struct node *)head;
    struct node *q = p->next;
    struct node *temp = NULL;

    // check position
    if (pos > head->id || pos <= 0)
    {
        printf("\n[+] Invalid position passed to Insert function!");
        return;
    }

    // traverse to the required pos
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    // insert node
    temp = getnode(id, name);
    temp->next = q;
    p->next = temp;

    head->id++;
}

void delete_by_name(char *name)
{
    struct node *p = (struct node *)head;
    struct node *q = p->next;
    struct node *temp = NULL;
    int name_not_found = 1;

    if (temp->next == NULL)
    {
        printf("\b[+] The list is empty!");
        return;
    }

    // traverse to the required pos
    while (p->next != NULL)
    {
        if (name_not_found = strcmp(p->next->name, name) == 0)
            break;
        p = p->next;
        q = q->next;
    }
    if (name_not_found != 0)
    {
        printf("\n[+] Book does not exist!");
        return;
    }

    // rearrange the list
    temp = q;
    p->next = q->next;

    // free the memory
    freenode(temp);

    // decrement the header count
    head->id--;
}

void search_by_name(char *name)
{
    struct node *temp = (struct node *)head;
    int name_not_found = 1;

    if (temp->next == NULL)
    {
        printf("\b[+] The list is empty!");
        return;
    }

    // traverse the list
    while (temp->next != NULL)
    {
        // break when the name matches
        if (name_not_found = strcmp(temp->next->name, name) == 0)
            break;
        temp = temp->next;
    }
    if (name_not_found < 0 || name_not_found > 0)
        printf("\n[+] Book Does Not Exist!");
    else
        printf("\n[+] Book With '%s' Exists!", name);
}

void display_list()
{
    struct node *temp = head->next;

    // if list is empty
    if (temp == NULL)
    {
        printf("\n[+] The list is empty");
        return;
    }

    printf("\n------------------------------------------------\n");
    while (temp != NULL)
    {
        printf("%d-%s|", temp->id, temp->name);
        temp = temp->next;
    }
    printf("\n------------------------------------------------\n");
}

void display_menu()
{
    printf("\n------------------------------------------------");
    printf("\n[+] 1. Append\n[+] 2. Insert A Book\n[+] 3. Delete A Book By Name\n[+] 4. Display Books\n[+] 5. Search By Name\n[+] 6. Exit\n");
    printf("\n[+] Select an option: ");
}

int main()
{
    int op, pos, id;
    char name[100] = {'\0'};

    // init the header node
    init();

    // menu
    do
    {
        display_menu();

        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\n[+] Enter the book name: ");
            scanf("%d", &id);
            printf("\n[+] Enter the book name: ");
            scanf("%s", name);
            append(id, name);
            break;

        case 2:
            printf("\n[+] Enter the book name: ");
            scanf("%d", &id);
            printf("\n[+] Enter the book name: ");
            scanf("%s", name);
            printf("\n[+] Enter the position to insert: ");
            scanf("%d", &pos);
            insert(pos, id, name);
            break;

        case 3:
            printf("\n[+] Enter a bookname to delete: ");
            scanf("%s", name);
            delete_by_name(name);
            break;

        case 4:
            display_list();
            break;

        case 5:
            printf("\n[+] Enter a bookname to search: ");
            // scanf("%s", value);
            fgets(name, 100, stdin);
            search_by_name(name);
            break;

        case 6:
            exit(0);
            break;
        default:
            printf("\n[+] Invalid input!");
        }
    } while (1);
}