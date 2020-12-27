#include <stdio.h>

/******************************************************************************

This function reads the FSM definition file and fills the fsm matrix.
Rows in the fsm matrix correspond to states, columns correspond to inputs.
fsm[row_for_current_state][column_for_current_input] = next_state.
State names are mapped to row numbers in the fsm_states array.
Row numbers are mapped to the characters a-z then A-Z in that order.
On encountering an error, the code stops processing the input file and prints
the number of transitions that were processed before reaching the error.

*******************************************************************************/

void initializeFsm(char input_file[], int* num_states, int* num_transitions, int fsm_states[], int fsm[50][52]) 
{
  FILE *infile;
  int scan_status;
  int transitions = 0;
  int fsm_states_index = 0;
  int cur_state;
  char input;
  int next_state;
  int row_num;
  int col_num;
  
  // Open FSM definition file for reading.
  infile = fopen(input_file, "r");
  
  if (infile != NULL) 
    {
      printf("processing FSM definition file %s\n", input_file);
      
      scan_status = fscanf(infile, "%d:%c>%d", &cur_state, &input, &next_state);
      
      // Scan until the end of the file
      while (scan_status != EOF)
        {
	  // If the input format is not current_state:input>next_state,
	  // throw an error.
	  if (scan_status != 3)
            {
	      printf("Error: formatting error in input file!\n");
	      break;
            }
	  
	  // Find the row number in the fsm matrix corresponding to the
	  // current state. fsm_states has a reverse lookup scheme: if
	  // fsm_states[i] = j, then state name j corresponds to the i'th
	  // row of the fsm matrix.
	  row_num = -1;
	  
	  // First check if we've already seen this state name.
	  for (int i = 0; i < fsm_states_index; i++) 
            {
	      if (fsm_states[i] == cur_state)
                {
		  row_num = i;
		  break;
                }
            }
	  
	  // If we haven't seen this state yet, create a row number for it.
	  if (row_num == -1)
            {
	      if (fsm_states_index < 50)
		{
		  fsm_states[fsm_states_index] = cur_state;
		  row_num = fsm_states_index;
		  fsm_states_index++;
		}
	      else
		{
		  printf("Error: Too many states in the FSM!\n");
		}
            }
	  
	  // Now that we have the current state's column number, calculate the
	  // row number corresponding to the input. Rows 0-25 correspond to
	  // characters a-z, 26-51 correspond to characters A-Z.
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
	  
	  // If the next state for this current state and input has not been
	  // recorded yet, add it to the matrix.
	  if (fsm[row_num][col_num] == -1)
            {
	      fsm[row_num][col_num] = next_state;
            }
	  // If we have already recorded a next state for this current state
	  // and input, and that next state is different from the one we have 
	  // here (i.e. the fsm is non-deterministic), throw an error.
	  else if (fsm[row_num][col_num] != next_state)
            {
	      printf("Error: The FSM described by this definition file is non-deterministic!\n");
	      break;
            }
	  
	  // Increment number of transitions processed, scan the next line.
	  transitions++;
	  scan_status = fscanf(infile, "%d:%c>%d", &cur_state, &input, &next_state);
        }
      
      // Print number of transitions processed (either the number of lines in
      // the definition file, or the number of lines read before encountering 
      // an error.)
      printf("FSM has %d transitions\n", transitions);
      
      // Return the number of states and transitions in this FSM.
      *num_states = fsm_states_index;
      *num_transitions = transitions;
    }
  
  // If the FSM definition file could not be opened to read, return an error.
  else 
    {
      printf("Error: The FSM definition file could not be opened to read.\n");
    }
}
