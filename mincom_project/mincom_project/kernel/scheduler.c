/*
 * scheduler.c
 *
 * Created: 2025-10-19 18:09:52
 *  Author: Joel Alftberg
 */ 
#include "include/task.h"

void scheduler(void){


	
	// Get next ready task with highest prio
	task_tcb_t *next_task = heap_pop();
	
	// Set task status to running and execute task
	next_task->status = RUNNING;
	next_task->function();
	
	// If task returns without blocking or becoming ready, make it ready
	if (next_task->status == RUNNING) {
		task_set_ready(&next_task)
	}
	
}

void task_set_ready(task_tcb_t *task){
	
	if (task->status != READY) {
		task->status == READY;
		heap_push(task);
	}
	
}


