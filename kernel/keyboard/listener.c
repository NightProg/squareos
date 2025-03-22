#include <keyboard/listener.h>
#include <keyboard/key.h>
#include <stdint.h>
#include <io/io.h>
#include <vga/vga.h>


void keyboard_isr() {
    vga_buffer_write(&global_vga_buffer, "Some THing happens");

    uint8_t scancode = inb(0x60);  // Lit le scancode du clavier

    if (scancode & 0x80) {
    } else {
        char key = keymap[scancode];  // Convertir le scancode en caractère
        if (key) {
            vga_buffer_putchar(&global_vga_buffer, key);
        }
    }
}