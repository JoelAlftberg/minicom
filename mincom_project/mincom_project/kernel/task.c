/*
 * task.c
 *
 * Created: 2025-10-17 20:49:12
 *  Author: joela
 */

void init_tcb(){

	free_task_head = &tasks[0];

	for(uint8_t i = 0; i < (MAX_TASKS - 1); i++){
		tasks[i].next_free = &tasks[i + 1]; 
	}

	tasks[MAX_TASKS - 1].next_free = NULL;

	return;
}

task_tcb_t *task_create(uint8_t id, uint8_t priority, uint8_t *stack_base, uint8_t *stack_pointer){
	
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


void task_delete(uint8_t task_id){
	
	for(uint8_t i = 0; i < MAX_TASKS; i++){
		
		if(tasks[i].id == task_id){	
			tasks[i].id = 0;
			tasks[i].priority = 0;
			tasks[i].stack_pointer = NULL;
			tasks[i].wake_tick = 0;
			tasks[i].status = FREE;
			
			tasks[i].next_free = free_task_head;
			free_task_head = &tasks[i];
		}
		
	}
	
	return;
}