#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "initialize_fsm.h"
#include "calculate_next_state.h"
#include "assert_equals.h"

int main(void)
{  
  int fsm_states[50];
  int fsm[50][52];
  int num_states;
  int num_transitions;
  
  for (int i = 0; i < 50; i++)
    {
      for (int j = 0; j < 52; j++)
	{
          fsm[i][j] = -1;
	}
    }
  
  initializeFsm("testing_files/test.fsm", &num_states, &num_transitions, fsm_states, fsm);

  // Some tests
  assertEquals(17, calculateNextState(3, 'r', fsm_states, fsm));
  // Transition from state to self
  assertEquals(3, calculateNextState(3, 'a', fsm_states, fsm));
  // Transition with uppercase input
  assertEquals(5, calculateNextState(3, 'Q', fsm_states, fsm));
  // Lots more tests
  assertEquals(444, calculateNextState(0, 'r', fsm_states, fsm));
  assertEquals(17, calculateNextState(5, 'Z', fsm_states, fsm));
  assertEquals(5, calculateNextState(17, 'Z', fsm_states, fsm));

  // Test for errors - these will print errors
  // Input does not exist in FSM
  assertEquals(-1, calculateNextState(5, 'P', fsm_states, fsm));
  // State does not exist in FSM
  assertEquals(-1, calculateNextState(14, 'a', fsm_states, fsm));
  // Invalid input
  assertEquals(-1, calculateNextState(444, '&', fsm_states, fsm));
}
