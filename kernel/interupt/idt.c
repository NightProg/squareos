#include "idt.h"
#include <libc/mem.h>
#include <vga/vga.h>


struct idt_ptr idtp;

void idt_set_gate(int num, uint32_t base, uint16_t sel, uint8_t flags) {
    idt[num].base_low  = (base & 0xFFFF);
    idt[num].sel       = sel;
    idt[num].always0   = 0;
    idt[num].flags     = flags;
    idt[num].base_high = (base >> 16) & 0xFFFF;
}

void idt_install() {
    idtp.limit = (sizeof(struct idt_entry) * IDT_ENTRIES) - 1;
    idtp.base  = (uint32_t)&idt;
    memset(&idt, 0, sizeof(struct idt_entry) * IDT_ENTRIES);
    asm volatile("lidt %0" :: "m" (idtp));
}
