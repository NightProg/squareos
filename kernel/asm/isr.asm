; global isr0
; extern isr_handler
; ; isr0:
; ;     cli                  ; Désactiver les interruptions
; ;     push 0               ; Ajouter un faux code d'erreur
; ;     push 0               ; Ajouter le numéro d'interruption
; ;     jmp isr_common_stub  ; Appel du handler général

; global isr1
; isr1:
;     cli
;     push 0
;     push 1
;     jmp isr_common_stub


; global isr2
; isr2:
;     cli
;     push 0
;     push 2
;     jmp isr_common_stub

; global isr3
; isr3:
;     cli
;     push 0
;     push 3
;     jmp isr_common_stub

; global isr4
; isr4:
;     cli
;     push 0
;     push 4
;     jmp isr_common_stub

; global isr5
; isr5:
;     cli
;     push 0
;     push 5
;     jmp isr_common_stub

; global isr6
; isr6:
;     cli
;     push 0
;     push 6
;     jmp isr_common_stub

; global isr7
; isr7:
;     cli
;     push 0
;     push 7
;     jmp isr_common_stub



    
; isr_common_stub:
;     pusha                ; Sauvegarde tous les registres
;     mov ax, ds
;     mov dx, 0x10         ; Kernel Data Segment
;     mov ds, dx
;     mov es, dx
;     mov fs, dx
;     mov gs, dx

;     mov eax, esp         ; Charger ESP dans EAX (adresse de la pile)
;     push eax             ; Passer ESP en argument à isr_handler
;     call isr_handler     ; Appel de la fonction C

;     add esp, 4           ; Nettoyer la pile après l'appel
;     ; popa                 ; Restaurer les registres
;     add esp, 8           ; Retirer code d'erreur + numéro ISR de la pile
;     sti                  ; Réactiver les interruptions
;     iret
