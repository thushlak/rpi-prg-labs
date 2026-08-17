.global _start

.section .data

number:
    .quad 75

.section .text

_start:
    ldr x1, =number
    ldr x0, [x1]

    mov x8, #93
    svc #0
