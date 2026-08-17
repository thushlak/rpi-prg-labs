.global _start

.section .text

_start:
    mov x1, #5

    lsl x0, x1, #1

    mov x8, #93
    svc #0