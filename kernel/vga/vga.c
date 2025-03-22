#include <vga/vga.h>
#include <libc/string.h>

static inline uint8_t vga_entry_color(vga_color fg, vga_color bg) 
{
	return fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color) 
{
	return (uint16_t) uc | (uint16_t) color << 8;
}

vga_buffer vga_buffer_init() {
    vga_buffer buffer;
    return buffer;
}

void vga_buffer_putchar(vga_buffer *buffer, char c) {
    const uint32_t index = buffer->row * VGA_WIDTH + buffer->col;
    if (buffer->col == VGA_WIDTH) {
        buffer->col = 0;
        buffer->row += 1;
    }
    vga_buffer_ptr[index] = vga_entry(c, vga_entry_color(VGA_COLOR_DARK_GREY, VGA_COLOR_BLACK));
    buffer->col += 1;
}


void vga_buffer_write(vga_buffer *buffer, const char* string) {
    for (int i = 0; i < strlen(string); i++) {
        vga_buffer_putchar(buffer, string[i]);
    }
}

void init_global_vga_buffer() {
    global_vga_buffer = vga_buffer_init();
}
