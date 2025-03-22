#include <vga/vga.h>
#include <interupt/idt.h>
#include <interupt/isr.h>
#include <interupt/gdt.h>
#include <io/io.h>


void kernel_main() {



    init_global_vga_buffer();
    load_gdt();

    idt_install();
    isr_install();
    outb(0x21, inb(0x21) & ~0x02);
    outb(0x60, 'a');
    asm volatile ("int $0x21");

    while(1) {
        asm volatile ("hlt");

    }

    return;
}