#include <interupt/isr.h>
#include <interupt/idt.h>
#include <keyboard/listener.h>
#include <io/io.h>

#include <vga/vga.h>

void isr_handler(uint32_t* stack_ptr) {

    uint32_t isr_num = stack_ptr[ISR_NUM_OFFSET];
    vga_buffer_putchar(&global_vga_buffer, isr_num + '0');

}

void isr0() {
    vga_buffer_write(&global_vga_buffer, "DIVIDE BY ZERO");
    while(1);
}

void isr1() {
    vga_buffer_write(&global_vga_buffer, "DEBUG");
    while(1);
}

void isr2() {
    vga_buffer_write(&global_vga_buffer, "NON MASKABLE INTERRUPT");
    while(1);
}

void isr3() {
    vga_buffer_write(&global_vga_buffer, "BREAKPOINT");
    while(1);
}

void isr4() {
    vga_buffer_write(&global_vga_buffer, "INTO DETECTED OVERFLOW");
    while(1);
}

void isr5() {
    vga_buffer_write(&global_vga_buffer, "OUT OF BOUNDS");
    while(1);
}

void isr6() {
    vga_buffer_write(&global_vga_buffer, "INVALID OPCODE");
    while(1);
}

void isr7() {
    vga_buffer_write(&global_vga_buffer, "NO COPROCESSOR");
    while(1);
}

void isr8() {
    vga_buffer_write(&global_vga_buffer, "DOUBLE FAULT");
    while(1);
}



void isr_install() {
    idt_set_gate(0, (uint32_t)isr0, 0x08, 0x8E);
    idt_set_gate(1, (uint32_t)isr1, 0x08, 0x8E);
    idt_set_gate(2, (uint32_t)isr2, 0x08, 0x8E);
    idt_set_gate(3, (uint32_t)isr3, 0x08, 0x8E);
    idt_set_gate(4, (uint32_t)isr4, 0x08, 0x8E);
    idt_set_gate(5, (uint32_t)isr5, 0x08, 0x8E);
    idt_set_gate(6, (uint32_t)isr6, 0x08, 0x8E);
    idt_set_gate(7, (uint32_t)isr7, 0x08, 0x8E);
    idt_set_gate(8, (uint32_t)isr8, 0x08, 0x8E);
    idt_set_gate(33, (uint32_t) keyboard_handler, 0x08, 0x8E);
}


void keyboard_handler() {
    vga_buffer_putchar(&global_vga_buffer, 'K');
    uint8_t scancode = inb(0x60);
    vga_buffer_putchar(&global_vga_buffer, '0' + (scancode & 0xF));
    outb(0x20, 0x20);
}
