#include <iostream>
#include <cassert>
#include <string>
#include "./stack.h"

// non standard function so implementing it manually
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

// custom free function to free strings (char **)
void stringFree(void *elem)
{
  free(*(char **)elem);
}

// driver function
int main()
{
  const char *friends[] = {"Al", "Bob", "Carl"};
  stack stringStack;

  // stack init
  // stackNewOld(&stringStack, sizeof(char *));
  stackNew(&stringStack, sizeof(char *), stringFree);

  // pushing elements to stack
  for (int i = 0; i < 3; i++)
  {
    char *copy = strdup((char *)friends[i]);
    stackPush(&stringStack, &copy);
  }

  // popping elements from stack
  char *name;
  for (int i = 0; i < 3; i++)
  {
    stackPop(&stringStack, &name);
    printf("%s\n", name);
    free(name);
  }

  // stack clear
  stackDispose(&stringStack);

  return 0;
}