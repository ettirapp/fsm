#include <stdio.h>

// Helper function to calculate the row number of the current state.
int calculateRow(int fsm_states[], int cur_state)
{
  int row_num = -1;
  for (int i = 0; i < 50; i++) 
    {
      if (fsm_states[i] == cur_state)
	{
	  row_num = i;
	  break;
	}
    }
  
  // If the current state does not exist, throw an error.
  if (row_num == -1) 
    {
      if (cur_state == 0)
	{
	  printf("Error: FSM must contain a state 0!");
	}
      else 
	{
	  printf("Error: State %d does not exist in the FSM!\n", cur_state);
	}
      return -1;
    }
}
