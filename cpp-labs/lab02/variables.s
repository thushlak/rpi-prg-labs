	.arch armv8-a
	.file	"variables.cpp"
	.text
	.section	.text._ZStorSt13_Ios_FmtflagsS_,"axG",@progbits,_ZStorSt13_Ios_FmtflagsS_,comdat
	.align	2
	.weak	_ZStorSt13_Ios_FmtflagsS_
	.type	_ZStorSt13_Ios_FmtflagsS_, %function
_ZStorSt13_Ios_FmtflagsS_:
.LFB1596:
	.cfi_startproc
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	w0, [sp, 12]
	str	w1, [sp, 8]
	ldr	w1, [sp, 12]
	ldr	w0, [sp, 8]
	orr	w0, w1, w0
	add	sp, sp, 16
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE1596:
	.size	_ZStorSt13_Ios_FmtflagsS_, .-_ZStorSt13_Ios_FmtflagsS_
	.section	.text._ZStoRRSt13_Ios_FmtflagsS_,"axG",@progbits,_ZStoRRSt13_Ios_FmtflagsS_,comdat
	.align	2
	.weak	_ZStoRRSt13_Ios_FmtflagsS_
	.type	_ZStoRRSt13_Ios_FmtflagsS_, %function
_ZStoRRSt13_Ios_FmtflagsS_:
.LFB1599:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	x0, [sp, 24]
	str	w1, [sp, 20]
	ldr	x0, [sp, 24]
	ldr	w0, [x0]
	ldr	w1, [sp, 20]
	bl	_ZStorSt13_Ios_FmtflagsS_
	mov	w1, w0
	ldr	x0, [sp, 24]
	str	w1, [x0]
	ldr	x0, [sp, 24]
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE1599:
	.size	_ZStoRRSt13_Ios_FmtflagsS_, .-_ZStoRRSt13_Ios_FmtflagsS_
	.section	.text._ZNSt8ios_base4setfESt13_Ios_Fmtflags,"axG",@progbits,_ZNSt8ios_base4setfESt13_Ios_Fmtflags,comdat
	.align	2
	.weak	_ZNSt8ios_base4setfESt13_Ios_Fmtflags
	.type	_ZNSt8ios_base4setfESt13_Ios_Fmtflags, %function
_ZNSt8ios_base4setfESt13_Ios_Fmtflags:
.LFB1628:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	mov	x29, sp
	str	x0, [sp, 24]
	str	w1, [sp, 20]
	ldr	x0, [sp, 24]
	ldr	w0, [x0, 24]
	str	w0, [sp, 44]
	ldr	x0, [sp, 24]
	add	x0, x0, 24
	ldr	w1, [sp, 20]
	bl	_ZStoRRSt13_Ios_FmtflagsS_
	ldr	w0, [sp, 44]
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE1628:
	.size	_ZNSt8ios_base4setfESt13_Ios_Fmtflags, .-_ZNSt8ios_base4setfESt13_Ios_Fmtflags
	.section	.text._ZSt9boolalphaRSt8ios_base,"axG",@progbits,_ZSt9boolalphaRSt8ios_base,comdat
	.align	2
	.weak	_ZSt9boolalphaRSt8ios_base
	.type	_ZSt9boolalphaRSt8ios_base, %function
_ZSt9boolalphaRSt8ios_base:
.LFB1639:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	x0, [sp, 24]
	mov	w1, 1
	ldr	x0, [sp, 24]
	bl	_ZNSt8ios_base4setfESt13_Ios_Fmtflags
	ldr	x0, [sp, 24]
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE1639:
	.size	_ZSt9boolalphaRSt8ios_base, .-_ZSt9boolalphaRSt8ios_base
#APP
	.globl _ZSt21ios_base_library_initv
	.section	.rodata
	.align	3
.LC0:
	.string	"Enter device name: "
	.align	3
.LC1:
	.string	"What is the temperatue?"
	.align	3
.LC2:
	.string	"Measure and enter  voltage"
	.align	3
.LC3:
	.string	"Enter the status:"
	.align	3
.LC4:
	.string	"Driver Status: enter 1 if loaded: enter 0 if not:"
	.align	3
.LC5:
	.string	"\n--- Device Report ---\n"
	.align	3
.LC6:
	.string	"Device:"
	.align	3
.LC7:
	.string	"Temperature: "
	.align	3
.LC8:
	.string	" C\n"
	.align	3
.LC9:
	.string	"Voltage: "
	.align	3
.LC10:
	.string	" V\n"
	.align	3
.LC11:
	.string	"Status: "
	.align	3
.LC12:
	.string	"Driver loaded: "
#NO_APP
	.text
	.align	2
	.global	main
	.type	main, %function
main:
.LFB2009:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA2009
	stp	x29, x30, [sp, -96]!
	.cfi_def_cfa_offset 96
	.cfi_offset 29, -96
	.cfi_offset 30, -88
	mov	x29, sp
	str	x19, [sp, 16]
	.cfi_offset 19, -80
	add	x0, sp, 64
	bl	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, :got:_ZSt4cout;ldr	x0, [x0, :got_lo12:_ZSt4cout]
.LEHB0:
	bl	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	add	x0, sp, 64
	mov	x1, x0
	adrp	x0, :got:_ZSt3cin;ldr	x0, [x0, :got_lo12:_ZSt3cin]
	bl	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
	adrp	x0, .LC1
	add	x1, x0, :lo12:.LC1
	adrp	x0, :got:_ZSt4cout;ldr	x0, [x0, :got_lo12:_ZSt4cout]
	bl	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	add	x0, sp, 60
	mov	x1, x0
	adrp	x0, :got:_ZSt3cin;ldr	x0, [x0, :got_lo12:_ZSt3cin]
	bl	_ZNSirsERi
	adrp	x0, .LC2
	add	x1, x0, :lo12:.LC2
	adrp	x0, :got:_ZSt4cout;ldr	x0, [x0, :got_lo12:_ZSt4cout]
	bl	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	add	x0, sp, 48
	mov	x1, x0
	adrp	x0, :got:_ZSt3cin;ldr	x0, [x0, :got_lo12:_ZSt3cin]
	bl	_ZNSirsERd
	adrp	x0, .LC3
	add	x1, x0, :lo12:.LC3
	adrp	x0, :got:_ZSt4cout;ldr	x0, [x0, :got_lo12:_ZSt4cout]
	bl	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	add	x0, sp, 47
	mov	x1, x0
	adrp	x0, :got:_ZSt3cin;ldr	x0, [x0, :got_lo12:_ZSt3cin]
	bl	_ZStrsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_RS3_
	adrp	x0, .LC4
	add	x1, x0, :lo12:.LC4
	adrp	x0, :got:_ZSt4cout;ldr	x0, [x0, :got_lo12:_ZSt4cout]
	bl	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	add	x0, sp, 46
	mov	x1, x0
	adrp	x0, :got:_ZSt3cin;ldr	x0, [x0, :got_lo12:_ZSt3cin]
	bl	_ZNSirsERb
	adrp	x0, .LC5
	add	x1, x0, :lo12:.LC5
	adrp	x0, :got:_ZSt4cout;ldr	x0, [x0, :got_lo12:_ZSt4cout]
	bl	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	adrp	x0, .LC6
	add	x1, x0, :lo12:.LC6
	adrp	x0, :got:_ZSt4cout;ldr	x0, [x0, :got_lo12:_ZSt4cout]
	bl	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	x2, x0
	add	x0, sp, 64
	mov	x1, x0
	mov	x0, x2
	bl	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE
	mov	w1, 10
	bl	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	adrp	x0, .LC7
	add	x1, x0, :lo12:.LC7
	adrp	x0, :got:_ZSt4cout;ldr	x0, [x0, :got_lo12:_ZSt4cout]
	bl	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	x2, x0
	ldr	w0, [sp, 60]
	mov	w1, w0
	mov	x0, x2
	bl	_ZNSolsEi
	mov	x2, x0
	adrp	x0, .LC8
	add	x1, x0, :lo12:.LC8
	mov	x0, x2
	bl	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	adrp	x0, .LC9
	add	x1, x0, :lo12:.LC9
	adrp	x0, :got:_ZSt4cout;ldr	x0, [x0, :got_lo12:_ZSt4cout]
	bl	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	ldr	d31, [sp, 48]
	fmov	d0, d31
	bl	_ZNSolsEd
	mov	x2, x0
	adrp	x0, .LC10
	add	x1, x0, :lo12:.LC10
	mov	x0, x2
	bl	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	adrp	x0, .LC11
	add	x1, x0, :lo12:.LC11
	adrp	x0, :got:_ZSt4cout;ldr	x0, [x0, :got_lo12:_ZSt4cout]
	bl	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	ldrb	w1, [sp, 47]
	bl	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	mov	w1, 10
	bl	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	adrp	x0, _ZSt9boolalphaRSt8ios_base
	add	x1, x0, :lo12:_ZSt9boolalphaRSt8ios_base
	adrp	x0, :got:_ZSt4cout;ldr	x0, [x0, :got_lo12:_ZSt4cout]
	bl	_ZNSolsEPFRSt8ios_baseS0_E
	adrp	x0, .LC12
	add	x1, x0, :lo12:.LC12
	adrp	x0, :got:_ZSt4cout;ldr	x0, [x0, :got_lo12:_ZSt4cout]
	bl	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	ldrb	w1, [sp, 46]
	bl	_ZNSolsEb
	mov	w1, 10
	bl	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
.LEHE0:
	mov	w19, 0
	add	x0, sp, 64
	bl	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	mov	w0, w19
	b	.L13
.L12:
	mov	x19, x0
	add	x0, sp, 64
	bl	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	mov	x0, x19
.LEHB1:
	bl	_Unwind_Resume
.LEHE1:
.L13:
	ldr	x19, [sp, 16]
	ldp	x29, x30, [sp], 96
	.cfi_restore 30
	.cfi_restore 29
	.cfi_restore 19
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE2009:
	.section	.gcc_except_table,"a",@progbits
.LLSDA2009:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE2009-.LLSDACSB2009
.LLSDACSB2009:
	.uleb128 .LEHB0-.LFB2009
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L12-.LFB2009
	.uleb128 0
	.uleb128 .LEHB1-.LFB2009
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE2009:
	.text
	.size	main, .-main
	.section	.rodata
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE, %object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE:
	.byte	1
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedImEE, %object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedImEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedImEE:
	.byte	1
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE, %object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE:
	.byte	1
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align	3
	.type	DW.ref.__gxx_personality_v0, %object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.xword	__gxx_personality_v0
	.global	__gxx_personality_v0
	.ident	"GCC: (Debian 14.2.0-19) 14.2.0"
	.section	.note.GNU-stack,"",@progbits
