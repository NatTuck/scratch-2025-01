	.file	"hello.c"
	.intel_syntax noprefix
# GNU C17 (Ubuntu 13.3.0-6ubuntu2~24.04) version 13.3.0 (x86_64-linux-gnu)
#	compiled by GNU C version 13.3.0, GMP version 6.3.0, MPFR version 4.2.1, MPC version 1.3.1, isl version isl-0.26-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -masm=intel -mtune=generic -march=x86-64 -O0 -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection
	.text
	.section	.rodata
.LC0:
	.string	"Hello %s\n"
	.text
	.globl	hello
	.type	hello, @function
hello:
.LFB0:
	.cfi_startproc
	endbr64	
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
	sub	rsp, 16	#,
	mov	QWORD PTR -8[rbp], rdi	# name, name
# hello.c:5:     printf("Hello %s\n", name);
	mov	rax, QWORD PTR -8[rbp]	# tmp82, name
	mov	rsi, rax	#, tmp82
	lea	rax, .LC0[rip]	# tmp83,
	mov	rdi, rax	#, tmp83
	mov	eax, 0	#,
	call	printf@PLT	#
# hello.c:6: }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE0:
	.size	hello, .-hello
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64	
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
	sub	rsp, 16	#,
	mov	DWORD PTR -4[rbp], edi	# argc, argc
	mov	QWORD PTR -16[rbp], rsi	# argv, argv
# hello.c:10:     hello(argv[1]);
	mov	rax, QWORD PTR -16[rbp]	# tmp86, argv
	add	rax, 8	# _1,
# hello.c:10:     hello(argv[1]);
	mov	rax, QWORD PTR [rax]	# _2, *_1
	mov	rdi, rax	#, _2
	call	hello	#
# hello.c:11:     return 0;
	mov	eax, 0	# _6,
# hello.c:12: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
