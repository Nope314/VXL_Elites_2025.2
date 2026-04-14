	.cpu arm7tdmi
	.arch armv4t
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"switch_cases.c"
	.text
	.section	.rodata
	.align	2
.LC0:
	.ascii	"%d \012\000"
	.text
	.align	2
	.global	main
	.syntax unified
	.arm
	.type	main, %function
main:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #24
	mov	r3, #15
	str	r3, [fp, #-16]
	ldr	r3, [fp, #-16]
	cmp	r3, #5
	beq	.L2
	ldr	r3, [fp, #-16]
	cmp	r3, #15
	beq	.L3
	b	.L4
.L2:
	mov	r3, #1
	str	r3, [fp, #-8]
	b	.L4
.L3:
	mov	r3, #2
	str	r3, [fp, #-8]
	nop
.L4:
	ldr	r1, [fp, #-8]
	ldr	r0, .L14
	bl	printf
	mov	r3, #2
	str	r3, [fp, #-20]
	nop
	ldr	r1, [fp, #-20]
	ldr	r0, .L14
	bl	printf
	ldr	r3, [fp, #-16]
	cmp	r3, #10
	beq	.L5
	ldr	r3, [fp, #-16]
	cmp	r3, #15
	beq	.L6
	b	.L13
.L5:
	mov	r3, #1
	str	r3, [fp, #-12]
	b	.L8
.L6:
	mov	r3, #2
	str	r3, [fp, #-12]
	b	.L8
.L13:
	mov	r3, #3
	str	r3, [fp, #-12]
.L8:
	ldr	r1, [fp, #-12]
	ldr	r0, .L14
	bl	printf
	ldr	r3, [fp, #-16]
	cmp	r3, #15
	beq	.L9
	ldr	r3, [fp, #-16]
	cmp	r3, #30
	beq	.L10
	b	.L11
.L9:
	mov	r3, #1
	str	r3, [fp, #-24]
.L10:
	mov	r3, #2
	str	r3, [fp, #-24]
	nop
.L11:
	ldr	r1, [fp, #-12]
	ldr	r0, .L14
	bl	printf
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
.L15:
	.align	2
.L14:
	.word	.LC0
	.size	main, .-main
	.ident	"GCC: (GNU Arm Embedded Toolchain 10.3-2021.10) 10.3.1 20210824 (release)"
