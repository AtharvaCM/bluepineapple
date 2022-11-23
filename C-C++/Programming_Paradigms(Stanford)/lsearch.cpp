// demo generic function for linear search

#include <iostream>
#include <cstring>

// helper function to compare two integers
// returns 0 if equal, negative and positive for 1 > 2 and 1 < 2 respectively
int intCmp(void *elem1, void *elem2)
{
  int *ip1 = (int *)elem1;
  int *ip2 = (int *)elem2;

  return *ip1 - *ip2;
}

// helper function to compare two char *
int strCmp(void *vp1, void *vp2)
{
  char *s1 = *(char **)vp1;
  char *s2 = *(char **)vp2;

  return strcmp(s1, s2);
}

// integer linear search
int int_lsearch(int key, int array[], int size)
{
  for (int i = 0; i < size; i++)
  {
    if (array[i] == key)
    {
      return i;
    }
  }

  return -1;
}

// generic function for linear search
// need size of the elements, a comparison function
// base -- base of the array
// n -- size of the array
void *lsearch_suboptimal(void *key, void *base, int n, int elemSize)
{
  for (int i = 0; i < n; i++)
  {
    void *elemAddress = (unsigned long *)base + i * elemSize;

    // won't work very well for char * and structs which have pointers inside
    if (memcmp(key, elemAddress, elemSize) == 0)
    {
      return elemAddress;
    }
  }

  return NULL;
}

// cmpfn is a function pointer
void *lsearch(void *key, void *base, int n, int elemSize, int (*cmpfn)(void *, void *))
{
  for (int i = 0; i < n; i++)
  {
    void *elemAddress = (char *)base + i * elemSize;

    if (cmpfn(key, elemAddress) == 0)
    {
      return elemAddress;
    }
  }

  return NULL;
}

// driver fuction
int main()
{
  int array[] = {4, 2, 3, 7, 11, 6};
  int size = 6;
  // key should be stored in a variable so we can pass the address
  int number = 7;

  // int *found = (int *)lsearch(&number, array, 6, sizeof(int), intCmp);

  char *notes[] = {(char *)"Ab",
                   (char *)"F#",
                   (char *)"B",
                   (char *)"Gb",
                   (char *)"D"};
  char *favoriteNote = (char *)"D";
  char **found = (char **)lsearch(&favoriteNote, notes, 5, sizeof(char *), strCmp);

  if (found == NULL)
  {
    std::cout << "ERROR: Could not find favorite note" << std::endl;
  }
  else
  {
    std::cout << "Found favorite note: " << **found << std::endl;
  }

  return 0;
}