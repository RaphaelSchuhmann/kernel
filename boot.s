.code32

.section .multiboot
.align 4
.long 0x1BADB002
.long 0x00000003
.long -(0x1BADB002 + 0x00000003)

.section .text
.global _start
_start:
    mov $0x900000, %esp
    call kmain

    mov $0x00, %al
    outb %al, $0xf4

.hang:
  cli
  hlt
  jmp .
