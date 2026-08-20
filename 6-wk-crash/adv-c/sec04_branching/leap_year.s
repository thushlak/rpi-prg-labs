	.arch armv8-a
	.file	"leap_year02.c"
	.text
	.section	.rodata
	.align	3
.LC0:
	.string	"Enter year: "
	.align	3
.LC1:
	.string	"%d"
	.align	3
.LC2:
	.string	"Year = %d"
	.align	3
.LC3:
	.string	" Yes, %d is a Leap Year\n"
	.align	3
.LC4:
	.string	"No, %d is not a Leap Year\n"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
.LFB0:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	adrp	x0, .LC0
	add	x0, x0, :lo12:.LC0
	bl	printf
	add	x0, sp, 28
	mov	x1, x0
	adrp	x0, .LC1
	add	x0, x0, :lo12:.LC1
	bl	__isoc99_scanf
	ldr	w0, [sp, 28]
	mov	w1, w0
	adrp	x0, .LC2
	add	x0, x0, :lo12:.LC2
	bl	printf
	ldr	w0, [sp, 28]
	and	w0, w0, 3
	cmp	w0, 0
	bne	.L2
	ldr	w0, [sp, 28]
	mov	w1, 100
	sdiv	w2, w0, w1
	mov	w1, 100
	mul	w1, w2, w1
	sub	w0, w0, w1
	cmp	w0, 0
	bne	.L3
.L2:
	ldr	w0, [sp, 28]
	mov	w1, 400
	sdiv	w2, w0, w1
	mov	w1, 400
	mul	w1, w2, w1
	sub	w0, w0, w1
	cmp	w0, 0
	bne	.L4
.L3:
	ldr	w0, [sp, 28]
	mov	w1, w0
	adrp	x0, .LC3
	add	x0, x0, :lo12:.LC3
	bl	printf
	b	.L5
.L4:
	ldr	w0, [sp, 28]
	mov	w1, w0
	adrp	x0, .LC4
	add	x0, x0, :lo12:.LC4
	bl	printf
.L5:
	mov	w0, 0
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Debian 14.2.0-19) 14.2.0"
	.section	.note.GNU-stack,"",@progbits
