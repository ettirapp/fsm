#include <stdio.h>
#define LIMIT 250

int initializeFsm(char input_file[], int fsm_states[], int fsm[50][26]) 
{
    FILE *infile;
    infile = fopen(input_file, "r");
    int i = 0;
    int state_num_in_array = 0;
    
    int cur_state;
    char input;
    int next_state;
    int row_num;
    int col_num;
    int success;
    
    if (infile != NULL) 
    {
        printf("processing FSM definition file %s\n", input_file);
        
        success = fscanf(infile, "%d:%c>%d", &cur_state, &input, &next_state);
        while (success != EOF && i < LIMIT)
        {
            i++; // throw error if gets too big
            
            if (success != 3) 
            {
                printf("Error: formatting error in input file!\n");
            }
            
            row_num = -1;
            for (int i = 0; i < state_num_in_array; i++) 
            {
                if (fsm_states[i] == cur_state)  // cur_state is the i'th row in the 2d array
                {
                    row_num = i;
                    break;
                }
            }
            if (row_num == -1) // not found
            { 
                fsm_states[state_num_in_array] = cur_state;
                row_num = state_num_in_array;
                state_num_in_array++;
            }
            
            col_num = input - 97;
            
            // should check if already there?
            fsm[row_num][col_num] = next_state;
            
            success = fscanf(infile, "%d:%c>%d", &cur_state, &input, &next_state);
        }
        printf("FSM has %d transitions\n", i);
        return state_num_in_array;
    }
    else {
        printf("Error: The FSM definition file could not be opened to read.\n");
    }
}
