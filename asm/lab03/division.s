.global _start

.section .text

_start:
    mov x1, #100
    mov x2, #4

    udiv x0, x1, x2

    mov x8, #93
    svc #0