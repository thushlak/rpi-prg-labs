.global _start

.section .data

numbers:
    .quad 10
    .quad 20
    .quad 30
    .quad 50

.section .text

_start:
    ldr x1, =numbers

    ldr x0, [x1, #24]

    mov x8, #93
    svc #0