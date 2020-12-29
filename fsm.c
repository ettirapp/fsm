#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "initialize_fsm.h"
#include "process_inputs.h"

int main(int argc, char* argv[])
{  
  // Max 50 states and 52 unique inputs in the FSM
  int fsm_states[50];
  int fsm[50][52];
  int num_states;
  int num_transitions;
  
  // Running the FSM with the interactive debugger
  if (strcmp(argv[1], "-d") == 0)
    {
      if (argc != 4)
	{
	  printf("Error: Incorrect number of command line arguments!\n");
	}
      
      // Read fsm definition file, fill fsm matrix.
      initializeFsm(argv[2],  &num_states, &num_transitions, fsm_states, fsm);

      // Read input file, process transitions with debugger.
      processInputs(argv[3], num_states, num_transitions, fsm_states, fsm, true);
    }
  
  // Running the FSM without the interactive debugger
  else
    {
      if (argc != 3)
	{
	  printf("Error: Incorrect number of command line arguments!\n");
	}
      
      // Read fsm definition file, fill fsm matrix.
      initializeFsm(argv[1], &num_states, &num_transitions, fsm_states, fsm);
      
      // Read input file, process transitions.
      processInputs(argv[2], num_states, num_transitions, fsm_states, fsm, false);
    }
}
