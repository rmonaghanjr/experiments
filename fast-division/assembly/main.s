	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 1
	.section	__TEXT,__literal16,16byte_literals
	.p2align	4                               ## -- Begin function main
LCPI0_0:
	.long	1127219200                      ## 0x43300000
	.long	1160773632                      ## 0x45300000
	.long	0                               ## 0x0
	.long	0                               ## 0x0
LCPI0_1:
	.quad	0x4330000000000000              ## double 4503599627370496
	.quad	0x4530000000000000              ## double 1.9342813113834067E+25
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3
LCPI0_2:
	.quad	0x412e848000000000              ## double 1.0E+6
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r12
	pushq	%rbx
	.cfi_offset %rbx, -48
	.cfi_offset %r12, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	callq	_clock
	movq	%rax, %r14
	leaq	L_.str(%rip), %r15
	movq	___stdoutp@GOTPCREL(%rip), %r12
	xorl	%ebx, %ebx
	.p2align	4, 0x90
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	%r15, %rdi
	movl	%ebx, %esi
	xorl	%eax, %eax
	callq	_printf
	movq	(%r12), %rdi
	callq	_fflush
	addl	$1, %ebx
	cmpl	$1000000, %ebx                  ## imm = 0xF4240
	jne	LBB0_1
## %bb.2:
	callq	_clock
	subq	%r14, %rax
	movq	%rax, %xmm1
	punpckldq	LCPI0_0(%rip), %xmm1    ## xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	LCPI0_1(%rip), %xmm1
	movapd	%xmm1, %xmm0
	unpckhpd	%xmm1, %xmm0                    ## xmm0 = xmm0[1],xmm1[1]
	addsd	%xmm1, %xmm0
	divsd	LCPI0_2(%rip), %xmm0
	leaq	L_.str.1(%rip), %rdi
	movb	$1, %al
	callq	_printf
	callq	_clock
	movq	%rax, %r14
	leaq	L_.str.2(%rip), %r15
	xorl	%ebx, %ebx
	.p2align	4, 0x90
LBB0_3:                                 ## =>This Inner Loop Header: Depth=1
	movq	%r15, %rdi
	movl	%ebx, %esi
	xorl	%eax, %eax
	callq	_printf
	movq	(%r12), %rdi
	callq	_fflush
	addl	$1, %ebx
	cmpl	$1000000, %ebx                  ## imm = 0xF4240
	jne	LBB0_3
## %bb.4:
	callq	_clock
	subq	%r14, %rax
	movq	%rax, %xmm1
	punpckldq	LCPI0_0(%rip), %xmm1    ## xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	LCPI0_1(%rip), %xmm1
	movapd	%xmm1, %xmm0
	unpckhpd	%xmm1, %xmm0                    ## xmm0 = xmm0[1],xmm1[1]
	addsd	%xmm1, %xmm0
	divsd	LCPI0_2(%rip), %xmm0
	leaq	L_.str.3(%rip), %rdi
	movb	$1, %al
	callq	_printf
	callq	_clock
	movq	%rax, %r14
	leaq	L_.str.4(%rip), %r15
	xorl	%ebx, %ebx
	.p2align	4, 0x90
LBB0_5:                                 ## =>This Inner Loop Header: Depth=1
	movq	%r15, %rdi
	movl	%ebx, %esi
	xorl	%eax, %eax
	callq	_printf
	movq	(%r12), %rdi
	callq	_fflush
	addl	$1, %ebx
	cmpl	$1000000, %ebx                  ## imm = 0xF4240
	jne	LBB0_5
## %bb.6:
	callq	_clock
	subq	%r14, %rax
	movq	%rax, %xmm1
	punpckldq	LCPI0_0(%rip), %xmm1    ## xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	LCPI0_1(%rip), %xmm1
	movapd	%xmm1, %xmm0
	unpckhpd	%xmm1, %xmm0                    ## xmm0 = xmm0[1],xmm1[1]
	addsd	%xmm1, %xmm0
	divsd	LCPI0_2(%rip), %xmm0
	leaq	L_.str.5(%rip), %rdi
	movb	$1, %al
	callq	_printf
	xorl	%eax, %eax
	popq	%rbx
	popq	%r12
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"\rsd: running test %d..."

L_.str.1:                               ## @.str.1
	.asciz	"\rstandard division: %f(s)\n"

L_.str.2:                               ## @.str.2
	.asciz	"\rfp: running test %d..."

L_.str.3:                               ## @.str.3
	.asciz	"\rfloating point mul: %f(s)\n"

L_.str.4:                               ## @.str.4
	.asciz	"\rfd: running test %d..."

L_.str.5:                               ## @.str.5
	.asciz	"\rfast division: %f(s)\n"

.subsections_via_symbols
