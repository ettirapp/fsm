#include <stdio.h>
#include "calculate_row.h"
#include "calculate_column.h"

int calculateNextState(int cur_state, char input, int fsm_states[], int fsm[50][52])
{
  int row_num;
  int col_num;
  int next_state;
  
  // Calculate the row number of the current state.
  row_num = calculateRow(fsm_states, cur_state);
  
  // Calculate the column number of the current input.
  col_num = calculateColumn(input);

  // Catch errors
  if (row_num == -1 || col_num == -1)
    {
      return -1;
    }
  
  // Calculate the next state for the given current state and input.
  next_state = fsm[row_num][col_num];
  if (next_state == -1)
    {
      printf("Error: Transition is not defined for input %c with current state %d.\n", input, cur_state);
    }

  // Return -1 upon error, else return next_state.
  return next_state;
}
