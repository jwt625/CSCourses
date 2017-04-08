Dump of assembler code for function phase_6:
   0x000000000040120c <+0>:	push   %r13
   0x000000000040120e <+2>:	push   %r12
   0x0000000000401210 <+4>:	push   %rbp
   0x0000000000401211 <+5>:	push   %rbx
   0x0000000000401212 <+6>:	sub    $0x68,%rsp
   0x0000000000401216 <+10>:	mov    %fs:0x28,%rax
   0x000000000040121f <+19>:	mov    %rax,0x58(%rsp)
   0x0000000000401224 <+24>:	xor    %eax,%eax
   0x0000000000401226 <+26>:	mov    %rsp,%rsi
   0x0000000000401229 <+29>:	callq  0x401748 <read_six_numbers>
   0x000000000040122e <+34>:	mov    %rsp,%r12	$rsp points to input1
   0x0000000000401231 <+37>:	mov    $0x0,%r13d	$r13d = 0


   0x0000000000401237 <+43>:	mov    %r12,%rbp	$r12 will go over inputs
   0x000000000040123a <+46>:	mov    (%r12),%eax	$eax is current number
   0x000000000040123e <+50>:	sub    $0x1,%eax
   0x0000000000401241 <+53>:	cmp    $0x5,%eax
   0x0000000000401244 <+56>:	jbe    0x40124b <phase_6+63>   
				require $eax <= 5, ie, all numbers <= 6
   0x0000000000401246 <+58>:	callq  0x401712 <explode_bomb>
   0x000000000040124b <+63>:	add    $0x1,%r13d	counter $r13d increased
   0x000000000040124f <+67>:	cmp    $0x6,%r13d
   0x0000000000401253 <+71>:	je     0x401292 <phase_6+134>
   0x0000000000401255 <+73>:	mov    %r13d,%ebx	$ebx = count
loop until $ebx > 5, ie, all remaining numbers
   0x0000000000401258 <+76>:	movslq %ebx,%rax	$rax = count
   0x000000000040125b <+79>:	mov    (%rsp,%rax,4),%eax
   0x000000000040125e <+82>:	cmp    %eax,0x0(%rbp)
				require next number != current number
   0x0000000000401261 <+85>:	jne    0x401268 <phase_6+92>
   0x0000000000401263 <+87>:	callq  0x401712 <explode_bomb>
   0x0000000000401268 <+92>:	add    $0x1,%ebx
   0x000000000040126b <+95>:	cmp    $0x5,%ebx
   0x000000000040126e <+98>:	jle    0x401258 <phase_6+76>

   0x0000000000401270 <+100>:	add    $0x4,%r12	move $r12 to next input
   0x0000000000401274 <+104>:	jmp    0x401237 <phase_6+43>



   0x0000000000401276 <+106>:	mov    0x8(%rdx),%rdx	$rdx = 6308608
   0x000000000040127a <+110>:	add    $0x1,%eax
   0x000000000040127d <+113>:	cmp    %ecx,%eax
   0x000000000040127f <+115>:	jne    0x401276 <phase_6+106>
   0x0000000000401281 <+117>:	mov    %rdx,0x20(%rsp,%rsi,2)
   0x0000000000401286 <+122>:	add    $0x4,%rsi
   0x000000000040128a <+126>:	cmp    $0x18,%rsi	$rsi == 24?
   0x000000000040128e <+130>:	jne    0x401297 <phase_6+139>
   0x0000000000401290 <+132>:	jmp    0x4012ab <phase_6+159>


   0x0000000000401292 <+134>:	mov    $0x0,%esi	$esi = 0

   0x0000000000401297 <+139>:	mov    (%rsp,%rsi,1),%ecx	$ecx = in1
   0x000000000040129a <+142>:	mov    $0x1,%eax	$eax = 1
   0x000000000040129f <+147>:	mov    $0x6042f0,%edx	an address
   0x00000000004012a4 <+152>:	cmp    $0x1,%ecx	in1 > 1?
   0x00000000004012a7 <+155>:	jg     0x401276 <phase_6+106>

   0x00000000004012a9 <+157>:	jmp    0x401281 <phase_6+117>
   0x00000000004012ab <+159>:	mov    0x20(%rsp),%rbx
   0x00000000004012b0 <+164>:	lea    0x20(%rsp),%rax
   0x00000000004012b5 <+169>:	lea    0x48(%rsp),%rsi
   0x00000000004012ba <+174>:	mov    %rbx,%rcx
   0x00000000004012bd <+177>:	mov    0x8(%rax),%rdx
   0x00000000004012c1 <+181>:	mov    %rdx,0x8(%rcx)
   0x00000000004012c5 <+185>:	add    $0x8,%rax
   0x00000000004012c9 <+189>:	mov    %rdx,%rcx
   0x00000000004012cc <+192>:	cmp    %rsi,%rax
   0x00000000004012cf <+195>:	jne    0x4012bd <phase_6+177>
   0x00000000004012d1 <+197>:	movq   $0x0,0x8(%rdx)
   0x00000000004012d9 <+205>:	mov    $0x5,%ebp
   0x00000000004012de <+210>:	mov    0x8(%rbx),%rax
   0x00000000004012e2 <+214>:	mov    (%rax),%eax
   0x00000000004012e4 <+216>:	cmp    %eax,(%rbx)
   0x00000000004012e6 <+218>:	jle    0x4012ed <phase_6+225>
   0x00000000004012e8 <+220>:	callq  0x401712 <explode_bomb>
   0x00000000004012ed <+225>:	mov    0x8(%rbx),%rbx
   0x00000000004012f1 <+229>:	sub    $0x1,%ebp
   0x00000000004012f4 <+232>:	jne    0x4012de <phase_6+210>
   0x00000000004012f6 <+234>:	mov    0x58(%rsp),%rax
   0x00000000004012fb <+239>:	xor    %fs:0x28,%rax
   0x0000000000401304 <+248>:	je     0x40130b <phase_6+255>
   0x0000000000401306 <+250>:	callq  0x400b90 <__stack_chk_fail@plt>
   0x000000000040130b <+255>:	add    $0x68,%rsp
   0x000000000040130f <+259>:	pop    %rbx
   0x0000000000401310 <+260>:	pop    %rbp
   0x0000000000401311 <+261>:	pop    %r12
   0x0000000000401313 <+263>:	pop    %r13
   0x0000000000401315 <+265>:	retq   
