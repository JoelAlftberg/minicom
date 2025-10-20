/*
 * scheduler.c
 *
 * Created: 2025-10-19 18:09:52
 *  Author: Joel Alftberg
 */ 
#include "include/task.h"
#include "include/scheduler.h"

task_tcb_t *heap[MAX_TASKS];
uint8_t pq_size = 0;
task_tcb_t *current_task = NULL;

void scheduler(void){

	// Get next ready task with highest prio
	task_tcb_t *next_task = heap_pop();
	
    current_task = next_task;
	// Set task status to running and execute task
	current_task->status = RUNNING;
	current_task->function();
	
	// If task returns without blocking or becoming ready, make it ready
	if (current_task->status == RUNNING) {
		task_set_ready(&current_task);
	}
	
}

void heap_push(task_tcb_t *task){
    
    heap[pq_size] = task;
    uint8_t index = pq_size;
    pq_size++;
    
    // (bubble up)
    // compare upwards in the heap
    // only compare while we are not the largest node in the heap
    while (index > 0){
         uint8_t parent_index = (index - 1) / 2;
         if(heap[parent_index]->priority >= heap[index]->priority){
            break;
         }
         heap_swap(parent_index, index);
         index = parent_index;
    }
}

task_tcb_t *heap_pop(void){

    if (pq_size == 0){
        return NULL;
    }
       
    // get top member of heap
    task_tcb_t *root = heap[0];
    
    pq_size--;
    
    // take heap_size index (bottom level leaf) and move to root
    heap[0] = heap[pq_size];
    uint8_t index = 0;
    
    // (bubble down)
    while(1){
        
        uint8_t left_index = (index * 2) + 1;
        uint8_t right_index = (index * 2) + 2;
        uint8_t highest_priority = index;
        
        if (left_index < pq_size && heap[index]->priority < heap[left_index] ->priority){
            highest_priority = left_index;
        }        
        if (right_index < pq_size && heap[index]->priority < heap[right_index]->priority){
            highest_priority = right_index;
        }
        
        // if index is the highest prio stop swapping
        if (highest_priority == index){
            break;
        }
        
        // Swap places with the node that was largest
        heap_swap(highest_priority, index);
        index = highest_priority;
        
    }
    
    return root;
}

static void heap_swap(uint8_t i, uint8_t j){
    
}

void task_set_ready(task_tcb_t *task){
	
	if (task->status != READY) {
		task->status == READY;
		heap_push(task);
	}
	
}


