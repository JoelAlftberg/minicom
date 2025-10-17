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


