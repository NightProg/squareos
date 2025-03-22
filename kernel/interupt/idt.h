#ifndef KERNEL_IDT_IDT
#define KERNEL_IDT_IDT
#define IDT_ENTRIES 256

#include <stdint.h>

struct idt_entry {
    uint16_t base_low;  // Bits 0-15 de l'adresse du handler
    uint16_t sel;       // Segment du code (0x08 en général pour le kernel)
    uint8_t  always0;   // Toujours 0
    uint8_t  flags;     // Type et privilèges
    uint16_t base_high; // Bits 16-31 de l'adresse du handler
} __attribute__((packed));


static struct idt_entry idt[IDT_ENTRIES];

struct idt_ptr {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

extern struct idt_ptr idtp;


void idt_set_gate(int num, uint32_t base, uint16_t sel, uint8_t flags);
void idt_install();

extern void idt_load();



#endif

