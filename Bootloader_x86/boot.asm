;;boot.asm

;nasm directive - 32 bit
bits 32
section .text
    align 4
    dd 0x1BADB002            
    dd 0x00                  
    dd - (0x1BADB002 + 0x00)

global start
extern kmain	        ;kmain is defined in the c file

start:
  cli 			;block interrupts
  mov esp, stack_space	;set stack pointer
  call kmain
  hlt		 	;halt the CPU

section .bss
resb 8192		;8KB for stack
stack_space:
