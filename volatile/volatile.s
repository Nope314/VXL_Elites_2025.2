	.cpu arm7tdmi
	.arch armv4t
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 2
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"volatile.c"
	.text
	.align	2
	.global	test
	.syntax unified
	.arm
	.type	test, %function
test:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r2, .L9 
.L2:
	ldr	r3, [r2]
	cmp	r3, #0 
	beq	.L2
	ldr	r3, [r2]
	cmp	r3, #1
	ldreq	r3, [r2, #4] // Đọc giá trị của biến v
	addeq	r3, r3, #1
	streq	r3, [r2, #4]
	ldr	r3, [r2]
	cmp	r3, #1 // Kiểm tra nếu flag == 1
	ldreq	r3, [r2, #4]
	addeq	r3, r3, #1
	streq	r3, [r2, #4]
	ldr	r3, [r2, #8] // Đọc giá trị của biến n
	cmp	r3, #0 
	moveq	r3, #1 // Nếu n == 0, đặt n = 1 ->> sự khác biệt giữa volatile và non-volatile
	streq	r3, [r2, #8] // Lưu giá trị mới của n
	bx	lr
.L10:
	.align	2
.L9:
	.word	.LANCHOR0 // địa chỉ của biến flag
	.size	test, .-test
	.section	.text.startup,"ax",%progbits
	.align	2
	.global	main 
	.syntax unified
	.arm
	.type	main, %function
main:
	@ Function supports interworking.
	@ Volatile: function does not return.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, lr}
	bl	test
	mov	r2, #1
	ldr	r3, .L14
.L12:
	str	r2, [r3]
	b	.L12
.L15:
	.align	2
.L14:
	.word	.LANCHOR0
	.size	main, .-main
	.global	n
	.global	v
	.global	flag
	.bss
	.align	2
	.set	.LANCHOR0,. + 0
	.type	flag, %object
	.size	flag, 4
flag:
	.space	4
	.type	v, %object
	.size	v, 4
v:
	.space	4
	.type	n, %object
	.size	n, 4
n:
	.space	4
	.ident	"GCC: (GNU Tools for STM32 13.3.rel1.20250523-0900) 13.3.1 20240614"
