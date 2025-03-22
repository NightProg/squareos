#ifndef KERNEL_IDT_ISR
#define KERNEL_IDT_ISR

#define ISR_NUM_OFFSET 2
#define ISR_ERR_CODE_OFFSET 7

#include <libc/register.h>



void isr_handler(uint32_t* stack_ptr);

void isr0();
void isr1();
void isr2();
void isr3();
void isr4();
void isr5();
void isr6();
void isr7();
void isr8();
void keyboard_handler();




void isr_install();

#endif