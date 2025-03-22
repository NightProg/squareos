[bits 32]

section .data
gdt_start:
    dq 0x0000000000000000   ; NULL descriptor
    dq 0x00CF9A000000FFFF   ; Code segment (0x08)
    dq 0x00CF92000000FFFF   ; Data segment (0x10)
    

gdt_descriptor:
    dw gdt_end - gdt_start - 1  ; Taille de la GDT - 1
    dd gdt_start                ; Adresse de la GDT
gdt_end:

section .text
global load_gdt
load_gdt:
    lgdt [gdt_descriptor]  ; Charge la GDT

    mov ax, 0x10   ; Charge le segment de données (0x10)
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    jmp 0x08:flush_cs  ; Change le segment de code via un far jump
flush_cs:
    ret
