#include <stdio.h>
#include "initialize_fsm.h"
#include "process_fsm.h"

int main(int argc,char* argv[])
{
  if (argc != 3)
    {
      printf("Error: Incorrect number of command line arguments!");
    }
  
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
  
  // Read fsm definition file, fill fsm matrix.
  int num_states = initializeFsm(argv[1], fsm_states, fsm);

  // Read input file, process transitions.
  processFsm(argv[2], fsm_states, fsm);
}
