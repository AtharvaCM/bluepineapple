/*
The ticket booking system of Cinemax theater has to be implemented using C++ program. There are 10 rows
and 7 seats in each row. Doubly circular linked list has to be maintained to keep track of free seats at
rows. Assume some random booking to start with. Use array to store pointers (Head pointer) to each row.
On demand -
a) The list of available seats is to be displayed
b) The seats are to be booked
c) The booking can be cancelled
*/

#include <iostream>
#include "lib/doubly_circular_ll.h"

int main()
{
  DoublyCircularLLNode *header = NULL;

  init(&header);
  append(header, 1);
  append(header, 3);
  append(header, 4);
  append(header, 6);
  append(header, 8);
  append(header, 11);
  append(header, 12);
  append(header, 14);

  displayList(header);
  displayListReverse(header);

  // std::cout << "[+] header->data " << header->next->data << std::endl;
  // if (header->next->next == header)
  // {
  //   std::cout << "[+] header->next " << header->next << std::endl;
  // }

  return 0;
}