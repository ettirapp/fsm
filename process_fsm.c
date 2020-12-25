#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define LIMIT 250

/******************************************************************************

This function processes the FSM input file and outputs a description of the
simulation it is performing. The function processes at most 250 inputs.

*******************************************************************************/

void processFsm(char input_file[], int fsm_states[], int fsm[50][52], bool debugging)
{
  FILE *infile;
  char input;
  int num_inputs = 0;
  // initial state defaults to state 0
  int cur_state = 0;
  int next_state;
  int row_num;
  int col_num;
  char debugger_input;
  int scan_status = 0;
  
  // Open FSM inputs file for reading.
  infile = fopen(input_file, "r");
  
  if (infile != NULL) 
    {
      printf("processing FSM inputs file %s\n", input_file);
      
      scan_status = fscanf(infile, "%c\n", &input);
      
      // Process at most 250 inputs.
      while (scan_status != EOF && num_inputs < LIMIT)
	{
	  if (debugging)
	    {
	      printf("FSM debugger> ");
	      scanf(" %c", &debugger_input);
	    }
	  
	  if ((! debugging) || (debugger_input == 'n'))
	    {	      
	      // Calculate the row number of the current state.
	      row_num = -1;
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
		  break;
		}
	      
	      // Calculate the column number of the current input.
	      // EXTRA CREDIT: My code also works with uppercase inputs.
	      if (input >= 'a' && input <= 'z')
		{
		  col_num = input - 97;
		}
	      else if (input >= 'A' && input <= 'Z') 
		{
		  col_num = input - 65 + 26;
		}
	      else
		{
		  printf("Error: Invalid input! Inputs must be alphabetic characters.\n");
		  break;
		}
	      
	      // Calculate the next state for the given current state and input.
	      next_state = fsm[row_num][col_num];
	      printf("\tat step %d, input %c transitions FSM from state %d to state %d\n", num_inputs, input, cur_state, next_state);
	      
	      // Increment state and number of inputs.
	      cur_state = next_state;
	      num_inputs++;
	      scan_status = fscanf(infile, "%c\n", &input);
	    }
	  
	  else if (debugger_input == 'p')
	    {
	      printf("The FSM is currently in state %d\n", cur_state); 
	    }
	  
	  else
	    {
	      printf("Error: Invalid input to debugger! Type n to process the next FSM input or p to print the current state of the FSM.\n");
	    }
	}
      
      printf("after %d steps, state machine finished successfully at state %d\n", num_inputs, cur_state);
    }
  
  // If the FSM inputs file could not be opened to read, throw an error.
  else 
    {
      printf("Error: The FSM inputs file could not be opened to read.\n");
    }
}
