/*
 * task.h
 *
 * Created: 2025-10-17 20:50:31
 *  Author: joela
 */ 


#ifndef TASK_H_
#define TASK_H_

typedef enum {
	READY,
	WAITING,
	BLOCKED
} task_status_t;

typedef struct {
	uint8_t id;
	uint8_t priority;
	uint8_t *stack_base;
	uint8_t *stack_pointer;
	uint8_t *next_free;
	uint32_t wake_tick;
	task_status_t status;
	
} task_tcb_t;

#endif /* TASK_H_ */