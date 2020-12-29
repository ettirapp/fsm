#include <stdio.h>

void assertEquals(int a, int b)
{
  if (a == b)
    {
      printf("Test passed!\n");
    }
  else
    {
      printf("Test FAILED.\n");
    }
}
