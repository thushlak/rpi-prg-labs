.global _start

.section .text

_start:
    mov x1, #10
    mov x2, #5

    mul x0, x1, x2

    mov x8, #93
    svc #0