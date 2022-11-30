// -*- lsst-c++ -*-
/**
 * Header file for Doubly Linked List
 */

#include <iostream>

struct DoublyCircularLLNode
{
  struct DoublyCircularLLNode *prev;
  int data;
  struct DoublyCircularLLNode *next;
};

/**
 * Allocate a LL node and return it's address
 *
 * @param data Data to store in the node.
 *
 * @return Address of the allocated node.
 */
struct DoublyCircularLLNode *getNode(int data)
{
  struct DoublyCircularLLNode *temp = (struct DoublyCircularLLNode *)malloc(sizeof(struct DoublyCircularLLNode));

  temp->data = data;
  temp->prev = NULL;
  temp->next = NULL;

  return temp;
}

/**
 * Init the LL, return the address of hedaer node
 *
 * @param header A pointer to the header node.
 */
void init(struct DoublyCircularLLNode **header)
{
  struct DoublyCircularLLNode *temp = (struct DoublyCircularLLNode *)malloc(sizeof(struct DoublyCircularLLNode));

  temp->data = 0;
  temp->prev = temp;
  temp->next = temp;

  *header = temp;
}

/**
 * Append a node at the end of the list
 *
 * @param head Header node to which the node is to be appended.
 * @param data Data that needs to be stored in the node.
 */
void append(struct DoublyCircularLLNode *head, int data)
{
  struct DoublyCircularLLNode *temp = head;
  struct DoublyCircularLLNode *p = NULL;

  // if list epmty
  if (temp->next == head)
  {
    temp->next = getNode(data);
    p = temp->next;
    p->prev = temp;
    p->next = head;
    head->prev = p;

    return;
  }

  // traverse to the end of the list
  while (temp->next != head)
  {
    temp = temp->next;
  }

  temp->next = getNode(data);
  p = temp->next;
  p->prev = temp;
  p->next = head;
  head->prev = p;
}

/**
 * Insert node at given position
 *
 * @param head Header node to which the node is to be appended.
 * @param pos Position to insert node.
 * @param data Data that needs to be stored in the node.
 */
void insert(struct DoublyCircularLLNode *head, int pos, int data)
{
  // check if pos is valid
}

/**
 * Print the linked list
 *
 * @param head Header node to which the node is to be appended.
 */
void displayList(struct DoublyCircularLLNode *head)
{
  struct DoublyCircularLLNode *temp = head;

  // if list is empty
  if (temp->next == head)
  {
    std::cout << "[+] The list is empty" << std::endl;

    return;
  }

  std::cout << "---------------------------------------------------" << std::endl;
  while (temp->next != head)
  {
    temp = temp->next;
    std::cout << temp->data << " | ";
  }
  std::cout << std::endl;
  std::cout << "---------------------------------------------------" << std::endl;
}

/**
 * Print the linked list reversed
 *
 * @param head Header node to which the node is to be appended.
 */
void displayListReverse(struct DoublyCircularLLNode *head)
{
  struct DoublyCircularLLNode *temp = head;

  // if list is empty
  if (temp->prev == head)
  {
    std::cout << "[+] The list is empty" << std::endl;

    return;
  }

  std::cout << "---------------------------------------------------" << std::endl;
  while (temp->prev != head)
  {
    temp = temp->prev;
    std::cout << temp->data << " | ";
  }
  std::cout << std::endl;
  std::cout << "---------------------------------------------------" << std::endl;
}