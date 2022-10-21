; how to compile
; nasm -f elf64 test.asm

;how to linker
; ld --dynamic-linker /lib64/ld-linux-x86-64.so.2 -o test /usr/lib/x86_64-linux-gnu/crtn.o test.o -lc

global _start
extern printf 
extern exit
section .data

message:
    db "%ld x %ld = %ld",10,00 ; \x0a\x00 
    i: dq 2 ; long int i = 2
    j: dq 1 ; long int j = 1
    max : dq 9 ; long int max = 9

end:
    db 'good bye',10,00 

section .text

_start:
        push rbp
        mov rbp, rsp
        sub rsp, 0x20
        jmp _init
        jle _row_comp

_init:
        xor rax,rax
        xor rcx,rcx
        xor rdx,rdx
        xor rdi,rdi
        xor rsi,rsi
        mov rcx, 0x2 ; i value 

_row_comp:
        cmp rcx,[max]
        jle _column_set
        jmp _end

_column_set:
        mov rdi, [j] ; y
        jmp _column_comp

_column_comp:
        cmp rdi,[max]
        jle _calc
        pop rcx
        mov rcx, r9
        add rcx, 0x1
        jmp _row_comp

_calc:
        mov r8, rdi ; backup (j value)
        mov r11,r8 ; backup (j value) twice backup
        push r11 ; backup j value
        push r11 ; backup twice 
        mov r14,rcx ; backup (i value)
        mov r9, rcx ; backup (i value) twice backup 
        push r9 ; i value 
        mov rax, rcx
        imul rax, rdi  ; result = x*y , rax == result
        mov rdi, message 
        mov rsi, r9 
        mov rdx, r8
        mov rcx, rax
        xor eax, eax
        call printf
        pop r9 ; recover i value 
        mov rcx, r9
        pop rdi ; recover j value
        pop rax
        add rdi,0x1
        jmp _column_comp        
        ; 64bit is rdi -> rsi -> rdx -> rcx -> r8 -> r9 
_end:
    xor rax, rax
    mov rdi, rax
    call exit
    pop rbp
    ret
