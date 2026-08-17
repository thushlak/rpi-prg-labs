.global _start

.section .text

_start:
    mov x1, #12
    mov x2, #10

    and x0, x1, x2

    mov x8, #93
    svc #0