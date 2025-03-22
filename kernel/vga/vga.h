#ifndef KERNEL_VGA
#define KERNEL_VGA 

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#include <stdint.h>


#define VGA_ADDRESS_BUFFER 0xB8000


typedef enum {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
} vga_color;

static inline uint8_t vga_entry_color(vga_color fg, vga_color bg);
static inline uint16_t vga_entry(unsigned char uc, uint8_t color);

static uint16_t* vga_buffer_ptr = (uint16_t*) VGA_ADDRESS_BUFFER;

typedef struct {
	int row;
	int col;
} vga_buffer;

vga_buffer vga_buffer_init();
void vga_buffer_write(vga_buffer *buffer, const char* string);
void vga_buffer_putchar(vga_buffer *buffer, char c);
void init_global_vga_buffer();

static vga_buffer global_vga_buffer;

#endif