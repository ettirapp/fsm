fsm: fsm.c process_fsm.c initialize_fsm.c
	gcc -g -o fsm fsm.c process_fsm.c initialize_fsm.c
	./fsm fsm_definition input_file 
