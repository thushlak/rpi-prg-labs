.global _start

.section .data

numbers:
    .quad 10
    .quad 20
    .quad 30
    .quad 40

.section .text

_start:
    ldr x1, =numbers

    mov x2, #2

    ldr x0, [x1, x2, lsl #3]

    mov x8, #93
    svc #0