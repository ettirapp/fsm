#include <stdio.h>

// Calculate the column number corresponding to an FSM input.
// EXTRA CREDIT: My code also works with uppercase inputs.
int calculateColumn(int input)
{
  int col_num;

  // Lowercase input
  if (input >= 'a' && input <= 'z')
    {
      col_num = input - 97;
    }

  // Uppercase input
  else if (input >= 'A' && input <= 'Z') 
    {
      col_num = input - 65 + 26;
    }

  // Error
  else
    {
      printf("Error: Invalid input! Inputs must be alphabetic characters.\n");
      col_num = -1;
    }
  
  return col_num;
}
