#include <iostream>
#include <cassert>

typedef struct
{
  int *elems;
  int logicalLength;
  int allocatedLength;
} stack;

// a constructor function
void stackNew(stack *s)
{
  s->logicalLength = 0;
  s->allocatedLength = 4; // initial allocation
  s->elems = (int *)malloc(sizeof(int) * 4);

  // assert is a macro which takes a boolean value
  // it becomes a no op when conditon is true and terminates the program otherwise
  assert(s->elems != NULL);
}

// a destructor function
void stackDespose(stack *s)
{
  free(s->elems);
}

void stackPush(stack *s, int value)
{
  if (s->logicalLength == s->allocatedLength)
  {
    s->allocatedLength *= 2;
    s->elems = (int *)realloc(s->elems, s->allocatedLength * sizeof(int));

    assert(s->elems != NULL);
  }
  // append value to stack and increment logicalLength
  s->elems[s->logicalLength] = value;
  s->logicalLength++;
}

int stackpPop(stack *s)
{
  // isEmpty check
  assert(s->logicalLength > 0);

  s->logicalLength--;
  return s->elems[s->logicalLength];
}

// a destructor function
void stackDispose(stack *s);

void stackPush(stack *s, int value);
void stackPop(stack *s);