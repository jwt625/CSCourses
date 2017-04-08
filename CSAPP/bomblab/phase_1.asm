Dump of assembler code for function phase_1:
   0x0000000000400f2d <+0>:	sub    $0x8,%rsp
   0x0000000000400f31 <+4>:	mov    $0x4026d0,%esi
   0x0000000000400f36 <+9>:	callq  0x40143e <strings_not_equal>
   0x0000000000400f3b <+14>:	test   %eax,%eax
   0x0000000000400f3d <+16>:	je     0x400f44 <phase_1+23>
   0x0000000000400f3f <+18>:	callq  0x401712 <explode_bomb>
   0x0000000000400f44 <+23>:	add    $0x8,%rsp
   0x0000000000400f48 <+27>:	retq   


Dump of assembler code for function strings_not_equal:
   0x000000000040143e <+0>:	push   %r12
   0x0000000000401440 <+2>:	push   %rbp
   0x0000000000401441 <+3>:	push   %rbx
   0x0000000000401442 <+4>:	mov    %rdi,%rbx
   0x0000000000401445 <+7>:	mov    %rsi,%rbp
   0x0000000000401448 <+10>:	callq  0x401420 <string_length>
   0x000000000040144d <+15>:	mov    %eax,%r12d
   0x0000000000401450 <+18>:	mov    %rbp,%rdi
   0x0000000000401453 <+21>:	callq  0x401420 <string_length>
   0x0000000000401458 <+26>:	mov    $0x1,%edx
   0x000000000040145d <+31>:	cmp    %eax,%r12d
   0x0000000000401460 <+34>:	jne    0x40149e <strings_not_equal+96>
   0x0000000000401462 <+36>:	movzbl (%rbx),%eax
   0x0000000000401465 <+39>:	test   %al,%al
   0x0000000000401467 <+41>:	je     0x40148b <strings_not_equal+77>
   0x0000000000401469 <+43>:	cmp    0x0(%rbp),%al
   0x000000000040146c <+46>:	je     0x401475 <strings_not_equal+55>
   0x000000000040146e <+48>:	jmp    0x401492 <strings_not_equal+84>
   0x0000000000401470 <+50>:	cmp    0x0(%rbp),%al
   0x0000000000401473 <+53>:	jne    0x401499 <strings_not_equal+91>
   0x0000000000401475 <+55>:	add    $0x1,%rbx
   0x0000000000401479 <+59>:	add    $0x1,%rbp
   0x000000000040147d <+63>:	movzbl (%rbx),%eax
   0x0000000000401480 <+66>:	test   %al,%al
   0x0000000000401482 <+68>:	jne    0x401470 <strings_not_equal+50>
   0x0000000000401484 <+70>:	mov    $0x0,%edx
   0x0000000000401489 <+75>:	jmp    0x40149e <strings_not_equal+96>
   0x000000000040148b <+77>:	mov    $0x0,%edx
   0x0000000000401490 <+82>:	jmp    0x40149e <strings_not_equal+96>
   0x0000000000401492 <+84>:	mov    $0x1,%edx
   0x0000000000401497 <+89>:	jmp    0x40149e <strings_not_equal+96>
   0x0000000000401499 <+91>:	mov    $0x1,%edx
   0x000000000040149e <+96>:	mov    %edx,%eax
   0x00000000004014a0 <+98>:	pop    %rbx
   0x00000000004014a1 <+99>:	pop    %rbp
   0x00000000004014a2 <+100>:	pop    %r12
   0x00000000004014a4 <+102>:	retq  
