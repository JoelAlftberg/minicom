/*
 * task.c
 *
 * Created: 2025-10-17 20:49:12
 *  Author: joela
 */ 
#define MAX_TASKS 10

task_tcb_t tasks[MAX_TASKS];

task_tcb_t *free_task_head;

void init_tcb(){

	free_task_head = &tasks[0];

	for(uint8_t i = 0; i < (MAX_TASKS - 1); i++){
		tasks[i].next_free = &tasks[i + 1]; 
	}

	tasks[MAX_TASKS - 1].next_free = NULL;

}

task_tcb_t *create_task(uint8_t id, uint8_t priority, uint8_t *stack_base, uint8_t *stack_pointer){
	
	task_tcb_t *tcb = free_task_head;

	if(free_task_head != NULL){
		free_task_head = tcb->next_free;
		
	}
	else{
		return NULL;	
	}

	tcb->id = id;
	tcb->priority = priority;
	tcb->stack_base = stack_base;
	tcb->stack_pointer = stack_pointer;
	tcb->wake_tick = 0;
	tcb->status = READY;

	return tcb;

}
