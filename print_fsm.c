#include <stdio.h>

void printFsm(int num_states, int fsm_states[], int fsm[50][52])
{
  int state_name;
  char input;
  int transition = 0;
  
  for (int row = 0; row < num_states; row++)
    {
      state_name = fsm_states[row];
      for (int col = 0; col < 52; col++)
	{
	  if (fsm[row][col] != -1)
	    {
	      if (col >= 0 && col <= 25)
		{
		  input = (char) col + 97;
		}
	      else
		{
		  input = (char) col + 39;
		}
	      printf("transition %d: state %d with input %c goes to state %d\n", transition, state_name, input, fsm[row][col]);
	      transition++;
	    }
	}
    }
}
