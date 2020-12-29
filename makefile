fsm: fsm.c initialize_fsm.c process_inputs.c print_fsm.c calculate_next_state.c calculate_row.c calculate_column.c initialize_matrix.c
	gcc -g -o fsm fsm.c initialize_fsm.c process_inputs.c print_fsm.c calculate_row.c calculate_column.c calculate_next_state.c initialize_matrix.c
test: test.c calculate_next_state.c assert_equals.c calculate_column.c calculate_row.c initialize_fsm.c initialize_matrix.c
	gcc -g -o test test.c calculate_next_state.c assert_equals.c calculate_column.c calculate_row.c initialize_fsm.c initialize_matrix.c
all: fsm test
clear:
	rm fsm test
