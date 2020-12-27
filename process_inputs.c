#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "print_fsm.h"
#include "calculate_next_state.h"
#define LIMIT 250

/******************************************************************************

This function processes the FSM input file and outputs a description of the
simulation it is performing. The function processes at most 250 inputs.

*******************************************************************************/

void processInputs(char input_file[], int num_states, int num_transitions, int fsm_states[], int fsm[50][52], bool debugging)
{
  FILE *infile;
  char input;
  int num_inputs = 0;
  int cur_state = 0;	// initial state defaults to state 0
  int next_state;
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
	  
	  // Process the next input to the FSM.
	  if ((! debugging) || (debugger_input == 'n'))
	    {
	      // Calculate and print the next state of the FSM
	      next_state = calculateNextState(cur_state, input, fsm_states, fsm);
	      // If calculating next state returned an error, break.
	      if (next_state == -1)
		{
		  break;
		}
	      
	      printf("\tat step %d, input %c transitions FSM from state %d to state %d\n", num_inputs, input, cur_state, next_state);
	      
	      // Increment state and number of inputs.
	      cur_state = next_state;
	      num_inputs++;
	      scan_status = fscanf(infile, "%c\n", &input);
	    }
	  
	  // Print the current state of the FSM.
	  else if (debugger_input == 'p')
	    {
	      printf("The FSM is currently in state %d\n", cur_state);
	      printFsm(num_states, num_transitions, fsm_states, fsm);
	    }
	  
	  // Throw error for invalid input to debugger.
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
