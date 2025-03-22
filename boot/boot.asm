; Définition des constantes pour l'en-tête Multiboot
%define ALIGN    (1 << 0)  ; Alignement des modules sur des frontières de pages
%define MEMINFO  (1 << 1)  ; Fournir la carte mémoire
%define FLAGS    (ALIGN | MEMINFO)  ; Champ "flag" du Multiboot
%define MAGIC    0x1BADB002  ; Nombre magique pour identifier l'en-tête
%define CHECKSUM -(MAGIC + FLAGS)  ; Vérification pour valider l'en-tête



; Déclaration de l'en-tête Multiboot
section .multiboot
align 4
dd MAGIC
dd FLAGS
dd CHECKSUM

; Définition de la pile
section .bss
align 16
stack_bottom:
    resb 16384  ; Allouer 16 Ko pour la pile
stack_top:

; Code du kernel
section .text

extern kernel_main
global _start
_start:
    ; Initialisation de la pile
    mov esp, stack_top

    ; Appel de la fonction principale du kernel
    call kernel_main

    ; Boucle infinie pour stopper le CPU
    cli
.halt:
    hlt
    jmp .halt
