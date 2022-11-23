#include <iostream>
#include <cassert>

typedef struct
{
  void *elems;
  int elemSize;
  int logicalLength;
  int allocatedLength;
  void (*freeFn)(void *);
} stack;

// helper function
// static in this context means that this function should be used in this file only
// this is something called as internal linkage
static void stackGrow(stack *s)
{
  s->allocatedLength *= 2;
  s->elems = realloc(s->elems, s->allocatedLength * s->elemSize);
}

void stackNewOld(stack *s, int elemSize)
{
  assert(s->elemSize > 0);
  s->elemSize = elemSize;
  s->logicalLength = 0;
  s->allocatedLength = 4;
  s->elems = (void *)malloc(4 * elemSize);
  assert(s->elems != NULL);
}

void stackNew(stack *s, int elemSize, void (*freeFn)(void *))
{
  assert(s->elemSize > 0);
}

void stackDisposeOld(stack *s)
{
  free(s->elems);
}

void stackDispose(stack *s)
{
  // if a free function is provided, free remaining elements from stack
  if (s->freeFn != NULL)
  {
    // execute free function for every remaining element in stack
    for (int i = 0; i < s->logicalLength; i++)
    {
      s->freeFn((char *)s->elems + i * s->elemSize);
    }
  }

  free(s->elems);
}

void stackPush(stack *s, void *elemAddress)
{
  if (s->logicalLength == s->allocatedLength)
  {
    stackGrow(s);
  }

  // target address = base address + no of items in stack * elemSize
  void *target = (char *)s->elems + s->logicalLength * s->elemSize;
  memcpy(target, elemAddress, s->elemSize);
  s->logicalLength++;
}

// copying the popped element into elemAddress
void stackPop(stack *s, void *elemAddress)
{
  void *source = (char *)s->elems + (s->logicalLength - 1) * s->elemSize;

  memcpy(elemAddress, source, s->elemSize);
  s->logicalLength--;
}