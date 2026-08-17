.global _start

.section .text

_start:
    mov x1, #20
    mov x2, #10

    add x3, x1, x2
    sub x0, x3, #5

    mov x8, #93
    svc #0