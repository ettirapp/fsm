# FSM
Final project for Fall 2020 Computer Systems class

This project is a simulation of a deterministic finite state machine, written in C.  To compile this code, type `make` on the command line.  To run it, type `./fsm <fsm-definition-file-name> <fsm-input-file-name>`.  To run it with an interactive debugger, type `./fsm -d <fsm-definition-file-name> <fsm-input-file-name>`.  To use the debugger, type `n` to process the next input to the finite state machine and type `p` to print the current state of the machine.

Type `./run_tests.sh` to run the files in the `testing_files` folder. The first test is the example from the assignment description, the second uses a mixture of uppercase and lowercase inputs, the third has the states listed out of order in the FSM definition file, the fourth has transitions from a state to itself, and the fifth uses non-consecutive numbers as state names.