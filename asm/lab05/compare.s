.global _start

.section .text

_start:
    mov x1, #20
    mov x2, #10

    cmp x1, x2
    bgt greater

    mov x0, #1
    b exit

greater:
    mov x0, #0

exit:
    mov x8, #93
    svc #0