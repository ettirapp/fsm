#include <stdio.h>
#include <string.h>
#include "initialize_fsm.h"
#include "process_fsm.h"
#include "process_fsm_with_debugger.h"

int main(int argc, char* argv[])
{  
  int fsm_states[50];
  int fsm[50][52];
  
  // Initialize fsm matrix to -1's so we will be able to see if an element
  // has been set yet.
  for (int i = 0; i < 50; i++)
    {
      for (int j = 0; j < 52; j++)
	{
          fsm[i][j] = -1;
	}
    }
  
  if (strcmp(argv[1], "-d") == 0)
    {
      if (argc != 4)
	{
	  printf("Error: Incorrect number of command line arguments!");
	}
      
      // Read fsm definition file, fill fsm matrix.
      int num_states = initializeFsm(argv[2], fsm_states, fsm);

      // Read input file, process transitions with debugger.
      processFsmWithDebugger(argv[3], fsm_states, fsm);
    }
  
  else
    {
      if (argc != 3)
	{
	  printf("Error: Incorrect number of command line arguments!");
	}
      
      // Read fsm definition file, fill fsm matrix.
      int num_states = initializeFsm(argv[1], fsm_states, fsm);
      
      // Read input file, process transitions.
      processFsm(argv[2], fsm_states, fsm);
    }
}
