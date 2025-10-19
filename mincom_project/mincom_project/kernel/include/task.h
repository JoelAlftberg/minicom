/*
 * task.h
 *
 * Created: 2025-10-17 20:50:31
 *  Author: Joel Alftberg
 */ 
#ifndef TASK_H_
#define TASK_H_

#define MAX_TASKS 10

task_tcb_t tasks[MAX_TASKS];

task_tcb_t *free_task_head;

typedef void (*task_function_t)(void);

typedef enum {
	READY,
	RUNNING,
	SLEEPING,
	BLOCKED,
	FREE
} task_status_t;

typedef struct {
	uint8_t id;
	uint8_t priority;
	task_function_t function;
	uint8_t *stack_base;
	uint8_t *stack_pointer;
	uint8_t *next_free;
	uint32_t wake_tick;
	task_status_t status;
	
} task_tcb_t;

#endif /* TASK_H_ */