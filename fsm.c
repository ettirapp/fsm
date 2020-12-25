#include <stdio.h>
#include "initialize_fsm.h"
#include "process_fsm.h"

// TODO: Look for all errors. Break on error. Test code. Add to git.  Run on ada.

int main(int argc,char* argv[])
{
    int fsm_states[50];
    int fsm[50][26];
    
    int num_states = initializeFsm(argv[1], fsm_states, fsm);
    processFsm(argv[2], fsm_states, fsm);
}

