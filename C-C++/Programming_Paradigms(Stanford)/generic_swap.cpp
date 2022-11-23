// demo function for generic swap implementation

#include <iostream>
#include <stdlib.h>
#include <string.h>

// non standard C function
char *strdup(const char *s)
{
  size_t slen = strlen(s);
  char *result = (char *)malloc(slen + 1);
  if (result == NULL)
  {
    return NULL;
  }

  memcpy(result, s, slen + 1);
  return result;
}

//  takes 2 generic pointers and a size parameter and swaps the bit pattern
void swap(void *vp1, void *vp2, int size)
{
  char *buffer = (char *)malloc(sizeof(size));
  memcpy(buffer, vp1, size);
  memcpy(vp1, vp2, size);
  memcpy(vp2, buffer, size);
}

// driver
int main()
{
  int i = 44;
  int j = 22;
  short s = 5;
  short k = 7;
  char *man = strdup("Fred");
  char *woman = strdup("Wilma");

  // int and short swap
  // swap(&i, &s, sizeof(s));

  // int and int swap
  // swap(&i, &j, sizeof(i));

  // short and short swap
  // swap(&s, &k, sizeof(s));

  // char * and char * swap
  // swap(&man, &woman, sizeof(char *));

  // evalutating the pointers in the call
  // swap(man, woman, sizeof(int));

  // char * and &char
  swap(man, &woman, sizeof(int));

  // std::cout << "size of char * : " << sizeof(char *) << std::endl;
  // std::cout << "size of int : " << sizeof(int) << std::endl;
  // std::cout << "size of short : " << sizeof(short) << std::endl;

  std::cout << "char &man : " << &man << std::endl;
  std::cout << "char **man : " << *man << std::endl;
  std::cout << "char *man : " << man << std::endl;
  std::cout << "unsigned long : " << sizeof(unsigned long) << std::endl;

  std::cout << man << " " << woman << std::endl;

  return 0;
}