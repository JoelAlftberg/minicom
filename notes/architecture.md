# eeRTOS

Miniature RTOS written in C / AVR Assembly

Support for AVR-GCC toolchain

Cooperative scheduling

Tasks, Queues, Semaphores, Pipes

Timer1 as system clock

Support for UART debugging


## Log 2025-10-17
Started working on TCB structure and core RTOS components

implemented:
- init_tcb() - init static TCB array as a free list
- create_task() - allocates a TCB from the TCB free list and initializes it 
- task_tcb_t and task_status_t types


## Log 2025-10-19
Continued working on tcb and added the basics of the scheduler

- planned implementation of binary heap for task ready list
- scheduler() - added psuedo-code for the scheduler
- task_delete() - added way to delete tasks
- task_set_ready() - helper function to ready tasks and push them to ready list

## Log 2025-10-20
Worked on implementing binary heap as a priority queue for tasks

- heap_pop()
- heap_push()
- heap_swap()


