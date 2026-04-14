
volatile.o:     file format elf32-littlearm
volatile.o
architecture: armv4t, flags 0x00000011:
HAS_RELOC, HAS_SYMS
start address 0x00000000
private flags = 0x5000000: [Version5 EABI]

Sections:
Idx Name          Size      VMA       LMA       File off  Algn
  0 .text         00000050  00000000  00000000  00000034  2**2
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, CODE
  1 .data         00000000  00000000  00000000  00000084  2**0
                  CONTENTS, ALLOC, LOAD, DATA
  2 .bss          0000000c  00000000  00000000  00000084  2**2
                  ALLOC
  3 .text.startup 0000001c  00000000  00000000  00000084  2**2
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, CODE
  4 .comment      00000044  00000000  00000000  000000a0  2**0
                  CONTENTS, READONLY
  5 .ARM.attributes 0000002a  00000000  00000000  000000e4  2**0
                  CONTENTS, READONLY
SYMBOL TABLE:
00000000 l    df *ABS*	00000000 volatile.c
00000000 l    d  .text	00000000 .text
00000000 l    d  .data	00000000 .data
00000000 l    d  .bss	00000000 .bss
00000000 l    d  .text.startup	00000000 .text.startup
00000000 l    d  .comment	00000000 .comment
00000000 l    d  .ARM.attributes	00000000 .ARM.attributes
00000000 g     F .text	00000050 test
00000000 g     F .text.startup	0000001c main
00000008 g     O .bss	00000004 n
00000004 g     O .bss	00000004 v
00000000 g     O .bss	00000004 flag



Disassembly of section .text:

00000000 <test>:
   0:	e59f2044 	ldr	r2, [pc, #68]	@ 4c <test+0x4c>
   4:	e5923000 	ldr	r3, [r2]
   8:	e3530000 	cmp	r3, #0
   c:	0afffffc 	beq	4 <test+0x4>
  10:	e5923000 	ldr	r3, [r2]
  14:	e3530001 	cmp	r3, #1
  18:	05923004 	ldreq	r3, [r2, #4]
  1c:	02833001 	addeq	r3, r3, #1
  20:	05823004 	streq	r3, [r2, #4]
  24:	e5923000 	ldr	r3, [r2]
  28:	e3530001 	cmp	r3, #1
  2c:	05923004 	ldreq	r3, [r2, #4]
  30:	02833001 	addeq	r3, r3, #1
  34:	05823004 	streq	r3, [r2, #4]
  38:	e5923008 	ldr	r3, [r2, #8]
  3c:	e3530000 	cmp	r3, #0
  40:	03a03001 	moveq	r3, #1
  44:	05823008 	streq	r3, [r2, #8]
  48:	e12fff1e 	bx	lr
			48: R_ARM_V4BX	*ABS*
  4c:	00000000 	andeq	r0, r0, r0
			4c: R_ARM_ABS32	.bss

Disassembly of section .text.startup:

00000000 <main>:
   0:	e92d4010 	push	{r4, lr}
   4:	ebfffffe 	bl	0 <main>
			4: R_ARM_CALL	test
   8:	e3a02001 	mov	r2, #1
   c:	e59f3004 	ldr	r3, [pc, #4]	@ 18 <main+0x18>
  10:	e5832000 	str	r2, [r3]
  14:	eafffffd 	b	10 <main+0x10>
  18:	00000000 	andeq	r0, r0, r0
			18: R_ARM_ABS32	.bss

Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	movtmi	r4, #14080	@ 0x3700
   4:	4728203a 			@ <UNDEFINED> instruction: 0x4728203a
   8:	5420554e 	strtpl	r5, [r0], #-1358	@ 0xfffffab2
   c:	736c6f6f 	cmnvc	ip, #444	@ 0x1bc
  10:	726f6620 	rsbvc	r6, pc, #32, 12	@ 0x2000000
  14:	4d545320 	ldclmi	3, cr5, [r4, #-128]	@ 0xffffff80
  18:	31203233 			@ <UNDEFINED> instruction: 0x31203233
  1c:	2e332e33 	mrccs	14, 1, r2, cr3, cr3, {1}
  20:	316c6572 	smccc	50770	@ 0xc652
  24:	3230322e 	eorscc	r3, r0, #-536870910	@ 0xe0000002
  28:	32353035 	eorscc	r3, r5, #53	@ 0x35
  2c:	39302d33 	ldmdbcc	r0!, {r0, r1, r4, r5, r8, sl, fp, sp}
  30:	20293030 	eorcs	r3, r9, r0, lsr r0
  34:	332e3331 			@ <UNDEFINED> instruction: 0x332e3331
  38:	3220312e 	eorcc	r3, r0, #-2147483637	@ 0x8000000b
  3c:	30343230 	eorscc	r3, r4, r0, lsr r2
  40:	00343136 	eorseq	r3, r4, r6, lsr r1

Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00002941 	andeq	r2, r0, r1, asr #18
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	0000001f 	andeq	r0, r0, pc, lsl r0
  10:	00543405 	subseq	r3, r4, r5, lsl #8
  14:	01080206 	tsteq	r8, r6, lsl #4
  18:	04120109 	ldreq	r0, [r2], #-265	@ 0xfffffef7
  1c:	01150114 	tsteq	r5, r4, lsl r1
  20:	01180317 	tsteq	r8, r7, lsl r3
  24:	011a0119 	tsteq	sl, r9, lsl r1
  28:	Address 0x28 is out of bounds.

