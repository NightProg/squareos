#ifndef KERNEL_LIBC_REGISTER
#define KERNEL_LIBC_REGISTER

#include <stdint.h>

typedef struct registers_32
{
    uint32_t ds;                             // Data segment selector
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax; // Pushed by pusha.
    uint32_t int_no, err_code;               // Interrupt number and error code (if applicable)
    uint32_t eip, cs, eflags, useresp, ss;   // Pushed by the processor automatically.
} registers_32_t;

typedef struct registers_64
{
    uint64_t ds;                             // Data segment selector
    uint64_t rdi, rsi, rbp, rsp, rbx, rdx, rcx, rax; // Pushed by pusha.
    uint64_t int_no, err_code;               // Interrupt number and error code (if applicable)
    uint64_t rip, cs, rflags, useresp, ss;   // Pushed by the processor automatically.
} registers_64_t;


typedef struct registers_16 {
    uint16_t gs, fs, es, ds;                  // Data segment selector
    uint16_t di, si, bp, sp, bx, dx, cx, ax;  // Pushed by pusha.
    uint16_t int_no, err_code;                // Interrupt number and error code (if applicable)
    uint16_t ip, cs, flags;                   // Pushed by the processor automatically.
} registers_16_t;

#endif