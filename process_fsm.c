#include <stdio.h>

void processFsm(char input_file[], int fsm_states[], int fsm[50][26])
{
    FILE *infile;
    infile = fopen(input_file, "r");
    char input;
    int step = 0;
    int cur_state = 0;
    int next_state;
    int row_num;
    int col_num;
    
    printf("processing FSM inputs file %s\n", input_file);
    
    while (fscanf(infile, "%c\n", &input) != EOF) // don't read more than a limit?
    {
        row_num = -1;
        for (int i = 0; i < 50; i++) 
        {
            if (fsm_states[i] == cur_state)
            {
                row_num = i;
                break;
            }
        }
        if (row_num == -1) 
        {
            printf("Error: current state does not exist in the FSM!\n");
        }
        col_num = input - 97;
        
        next_state = fsm[row_num][col_num];
        printf("at step %d, input %c transitions FSM from state %d to state %d\n", step, input, cur_state, next_state);
        
        cur_state = next_state;
        step++;
    }
    printf("after %d steps, state machine finished successfully at state %d\n", step, cur_state);
}
