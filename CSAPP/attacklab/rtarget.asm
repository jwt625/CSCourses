
rtarget:     file format elf64-x86-64


Disassembly of section .init:

0000000000400c48 <_init>:
  400c48:	48 83 ec 08          	sub    $0x8,%rsp
  400c4c:	48 8b 05 a5 43 20 00 	mov    0x2043a5(%rip),%rax        # 604ff8 <_DYNAMIC+0x1d0>
  400c53:	48 85 c0             	test   %rax,%rax
  400c56:	74 05                	je     400c5d <_init+0x15>
  400c58:	e8 43 02 00 00       	callq  400ea0 <socket@plt+0x10>
  400c5d:	48 83 c4 08          	add    $0x8,%rsp
  400c61:	c3                   	retq   

Disassembly of section .plt:

0000000000400c70 <strcasecmp@plt-0x10>:
  400c70:	ff 35 92 43 20 00    	pushq  0x204392(%rip)        # 605008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400c76:	ff 25 94 43 20 00    	jmpq   *0x204394(%rip)        # 605010 <_GLOBAL_OFFSET_TABLE_+0x10>
  400c7c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400c80 <strcasecmp@plt>:
  400c80:	ff 25 92 43 20 00    	jmpq   *0x204392(%rip)        # 605018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400c86:	68 00 00 00 00       	pushq  $0x0
  400c8b:	e9 e0 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400c90 <__errno_location@plt>:
  400c90:	ff 25 8a 43 20 00    	jmpq   *0x20438a(%rip)        # 605020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400c96:	68 01 00 00 00       	pushq  $0x1
  400c9b:	e9 d0 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400ca0 <srandom@plt>:
  400ca0:	ff 25 82 43 20 00    	jmpq   *0x204382(%rip)        # 605028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400ca6:	68 02 00 00 00       	pushq  $0x2
  400cab:	e9 c0 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400cb0 <strncmp@plt>:
  400cb0:	ff 25 7a 43 20 00    	jmpq   *0x20437a(%rip)        # 605030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400cb6:	68 03 00 00 00       	pushq  $0x3
  400cbb:	e9 b0 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400cc0 <strcpy@plt>:
  400cc0:	ff 25 72 43 20 00    	jmpq   *0x204372(%rip)        # 605038 <_GLOBAL_OFFSET_TABLE_+0x38>
  400cc6:	68 04 00 00 00       	pushq  $0x4
  400ccb:	e9 a0 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400cd0 <puts@plt>:
  400cd0:	ff 25 6a 43 20 00    	jmpq   *0x20436a(%rip)        # 605040 <_GLOBAL_OFFSET_TABLE_+0x40>
  400cd6:	68 05 00 00 00       	pushq  $0x5
  400cdb:	e9 90 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400ce0 <write@plt>:
  400ce0:	ff 25 62 43 20 00    	jmpq   *0x204362(%rip)        # 605048 <_GLOBAL_OFFSET_TABLE_+0x48>
  400ce6:	68 06 00 00 00       	pushq  $0x6
  400ceb:	e9 80 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400cf0 <__stack_chk_fail@plt>:
  400cf0:	ff 25 5a 43 20 00    	jmpq   *0x20435a(%rip)        # 605050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400cf6:	68 07 00 00 00       	pushq  $0x7
  400cfb:	e9 70 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400d00 <mmap@plt>:
  400d00:	ff 25 52 43 20 00    	jmpq   *0x204352(%rip)        # 605058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400d06:	68 08 00 00 00       	pushq  $0x8
  400d0b:	e9 60 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400d10 <memset@plt>:
  400d10:	ff 25 4a 43 20 00    	jmpq   *0x20434a(%rip)        # 605060 <_GLOBAL_OFFSET_TABLE_+0x60>
  400d16:	68 09 00 00 00       	pushq  $0x9
  400d1b:	e9 50 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400d20 <alarm@plt>:
  400d20:	ff 25 42 43 20 00    	jmpq   *0x204342(%rip)        # 605068 <_GLOBAL_OFFSET_TABLE_+0x68>
  400d26:	68 0a 00 00 00       	pushq  $0xa
  400d2b:	e9 40 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400d30 <close@plt>:
  400d30:	ff 25 3a 43 20 00    	jmpq   *0x20433a(%rip)        # 605070 <_GLOBAL_OFFSET_TABLE_+0x70>
  400d36:	68 0b 00 00 00       	pushq  $0xb
  400d3b:	e9 30 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400d40 <read@plt>:
  400d40:	ff 25 32 43 20 00    	jmpq   *0x204332(%rip)        # 605078 <_GLOBAL_OFFSET_TABLE_+0x78>
  400d46:	68 0c 00 00 00       	pushq  $0xc
  400d4b:	e9 20 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400d50 <__libc_start_main@plt>:
  400d50:	ff 25 2a 43 20 00    	jmpq   *0x20432a(%rip)        # 605080 <_GLOBAL_OFFSET_TABLE_+0x80>
  400d56:	68 0d 00 00 00       	pushq  $0xd
  400d5b:	e9 10 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400d60 <signal@plt>:
  400d60:	ff 25 22 43 20 00    	jmpq   *0x204322(%rip)        # 605088 <_GLOBAL_OFFSET_TABLE_+0x88>
  400d66:	68 0e 00 00 00       	pushq  $0xe
  400d6b:	e9 00 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400d70 <gethostbyname@plt>:
  400d70:	ff 25 1a 43 20 00    	jmpq   *0x20431a(%rip)        # 605090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400d76:	68 0f 00 00 00       	pushq  $0xf
  400d7b:	e9 f0 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400d80 <__memmove_chk@plt>:
  400d80:	ff 25 12 43 20 00    	jmpq   *0x204312(%rip)        # 605098 <_GLOBAL_OFFSET_TABLE_+0x98>
  400d86:	68 10 00 00 00       	pushq  $0x10
  400d8b:	e9 e0 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400d90 <strtol@plt>:
  400d90:	ff 25 0a 43 20 00    	jmpq   *0x20430a(%rip)        # 6050a0 <_GLOBAL_OFFSET_TABLE_+0xa0>
  400d96:	68 11 00 00 00       	pushq  $0x11
  400d9b:	e9 d0 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400da0 <memcpy@plt>:
  400da0:	ff 25 02 43 20 00    	jmpq   *0x204302(%rip)        # 6050a8 <_GLOBAL_OFFSET_TABLE_+0xa8>
  400da6:	68 12 00 00 00       	pushq  $0x12
  400dab:	e9 c0 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400db0 <time@plt>:
  400db0:	ff 25 fa 42 20 00    	jmpq   *0x2042fa(%rip)        # 6050b0 <_GLOBAL_OFFSET_TABLE_+0xb0>
  400db6:	68 13 00 00 00       	pushq  $0x13
  400dbb:	e9 b0 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400dc0 <random@plt>:
  400dc0:	ff 25 f2 42 20 00    	jmpq   *0x2042f2(%rip)        # 6050b8 <_GLOBAL_OFFSET_TABLE_+0xb8>
  400dc6:	68 14 00 00 00       	pushq  $0x14
  400dcb:	e9 a0 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400dd0 <_IO_getc@plt>:
  400dd0:	ff 25 ea 42 20 00    	jmpq   *0x2042ea(%rip)        # 6050c0 <_GLOBAL_OFFSET_TABLE_+0xc0>
  400dd6:	68 15 00 00 00       	pushq  $0x15
  400ddb:	e9 90 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400de0 <__isoc99_sscanf@plt>:
  400de0:	ff 25 e2 42 20 00    	jmpq   *0x2042e2(%rip)        # 6050c8 <_GLOBAL_OFFSET_TABLE_+0xc8>
  400de6:	68 16 00 00 00       	pushq  $0x16
  400deb:	e9 80 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400df0 <munmap@plt>:
  400df0:	ff 25 da 42 20 00    	jmpq   *0x2042da(%rip)        # 6050d0 <_GLOBAL_OFFSET_TABLE_+0xd0>
  400df6:	68 17 00 00 00       	pushq  $0x17
  400dfb:	e9 70 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400e00 <__printf_chk@plt>:
  400e00:	ff 25 d2 42 20 00    	jmpq   *0x2042d2(%rip)        # 6050d8 <_GLOBAL_OFFSET_TABLE_+0xd8>
  400e06:	68 18 00 00 00       	pushq  $0x18
  400e0b:	e9 60 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400e10 <fopen@plt>:
  400e10:	ff 25 ca 42 20 00    	jmpq   *0x2042ca(%rip)        # 6050e0 <_GLOBAL_OFFSET_TABLE_+0xe0>
  400e16:	68 19 00 00 00       	pushq  $0x19
  400e1b:	e9 50 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400e20 <getopt@plt>:
  400e20:	ff 25 c2 42 20 00    	jmpq   *0x2042c2(%rip)        # 6050e8 <_GLOBAL_OFFSET_TABLE_+0xe8>
  400e26:	68 1a 00 00 00       	pushq  $0x1a
  400e2b:	e9 40 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400e30 <strtoul@plt>:
  400e30:	ff 25 ba 42 20 00    	jmpq   *0x2042ba(%rip)        # 6050f0 <_GLOBAL_OFFSET_TABLE_+0xf0>
  400e36:	68 1b 00 00 00       	pushq  $0x1b
  400e3b:	e9 30 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400e40 <gethostname@plt>:
  400e40:	ff 25 b2 42 20 00    	jmpq   *0x2042b2(%rip)        # 6050f8 <_GLOBAL_OFFSET_TABLE_+0xf8>
  400e46:	68 1c 00 00 00       	pushq  $0x1c
  400e4b:	e9 20 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400e50 <exit@plt>:
  400e50:	ff 25 aa 42 20 00    	jmpq   *0x2042aa(%rip)        # 605100 <_GLOBAL_OFFSET_TABLE_+0x100>
  400e56:	68 1d 00 00 00       	pushq  $0x1d
  400e5b:	e9 10 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400e60 <connect@plt>:
  400e60:	ff 25 a2 42 20 00    	jmpq   *0x2042a2(%rip)        # 605108 <_GLOBAL_OFFSET_TABLE_+0x108>
  400e66:	68 1e 00 00 00       	pushq  $0x1e
  400e6b:	e9 00 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400e70 <__fprintf_chk@plt>:
  400e70:	ff 25 9a 42 20 00    	jmpq   *0x20429a(%rip)        # 605110 <_GLOBAL_OFFSET_TABLE_+0x110>
  400e76:	68 1f 00 00 00       	pushq  $0x1f
  400e7b:	e9 f0 fd ff ff       	jmpq   400c70 <_init+0x28>

0000000000400e80 <__sprintf_chk@plt>:
  400e80:	ff 25 92 42 20 00    	jmpq   *0x204292(%rip)        # 605118 <_GLOBAL_OFFSET_TABLE_+0x118>
  400e86:	68 20 00 00 00       	pushq  $0x20
  400e8b:	e9 e0 fd ff ff       	jmpq   400c70 <_init+0x28>

0000000000400e90 <socket@plt>:
  400e90:	ff 25 8a 42 20 00    	jmpq   *0x20428a(%rip)        # 605120 <_GLOBAL_OFFSET_TABLE_+0x120>
  400e96:	68 21 00 00 00       	pushq  $0x21
  400e9b:	e9 d0 fd ff ff       	jmpq   400c70 <_init+0x28>

Disassembly of section .plt.got:

0000000000400ea0 <.plt.got>:
  400ea0:	ff 25 52 41 20 00    	jmpq   *0x204152(%rip)        # 604ff8 <_DYNAMIC+0x1d0>
  400ea6:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

0000000000400eb0 <_start>:
  400eb0:	31 ed                	xor    %ebp,%ebp
  400eb2:	49 89 d1             	mov    %rdx,%r9
  400eb5:	5e                   	pop    %rsi
  400eb6:	48 89 e2             	mov    %rsp,%rdx
  400eb9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  400ebd:	50                   	push   %rax
  400ebe:	54                   	push   %rsp
  400ebf:	49 c7 c0 90 2f 40 00 	mov    $0x402f90,%r8
  400ec6:	48 c7 c1 20 2f 40 00 	mov    $0x402f20,%rcx
  400ecd:	48 c7 c7 b5 11 40 00 	mov    $0x4011b5,%rdi
  400ed4:	e8 77 fe ff ff       	callq  400d50 <__libc_start_main@plt>
  400ed9:	f4                   	hlt    
  400eda:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400ee0 <deregister_tm_clones>:
  400ee0:	b8 b7 54 60 00       	mov    $0x6054b7,%eax
  400ee5:	55                   	push   %rbp
  400ee6:	48 2d b0 54 60 00    	sub    $0x6054b0,%rax
  400eec:	48 83 f8 0e          	cmp    $0xe,%rax
  400ef0:	48 89 e5             	mov    %rsp,%rbp
  400ef3:	76 1b                	jbe    400f10 <deregister_tm_clones+0x30>
  400ef5:	b8 00 00 00 00       	mov    $0x0,%eax
  400efa:	48 85 c0             	test   %rax,%rax
  400efd:	74 11                	je     400f10 <deregister_tm_clones+0x30>
  400eff:	5d                   	pop    %rbp
  400f00:	bf b0 54 60 00       	mov    $0x6054b0,%edi
  400f05:	ff e0                	jmpq   *%rax
  400f07:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  400f0e:	00 00 
  400f10:	5d                   	pop    %rbp
  400f11:	c3                   	retq   
  400f12:	0f 1f 40 00          	nopl   0x0(%rax)
  400f16:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  400f1d:	00 00 00 

0000000000400f20 <register_tm_clones>:
  400f20:	be b0 54 60 00       	mov    $0x6054b0,%esi
  400f25:	55                   	push   %rbp
  400f26:	48 81 ee b0 54 60 00 	sub    $0x6054b0,%rsi
  400f2d:	48 c1 fe 03          	sar    $0x3,%rsi
  400f31:	48 89 e5             	mov    %rsp,%rbp
  400f34:	48 89 f0             	mov    %rsi,%rax
  400f37:	48 c1 e8 3f          	shr    $0x3f,%rax
  400f3b:	48 01 c6             	add    %rax,%rsi
  400f3e:	48 d1 fe             	sar    %rsi
  400f41:	74 15                	je     400f58 <register_tm_clones+0x38>
  400f43:	b8 00 00 00 00       	mov    $0x0,%eax
  400f48:	48 85 c0             	test   %rax,%rax
  400f4b:	74 0b                	je     400f58 <register_tm_clones+0x38>
  400f4d:	5d                   	pop    %rbp
  400f4e:	bf b0 54 60 00       	mov    $0x6054b0,%edi
  400f53:	ff e0                	jmpq   *%rax
  400f55:	0f 1f 00             	nopl   (%rax)
  400f58:	5d                   	pop    %rbp
  400f59:	c3                   	retq   
  400f5a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400f60 <__do_global_dtors_aux>:
  400f60:	80 3d 81 45 20 00 00 	cmpb   $0x0,0x204581(%rip)        # 6054e8 <completed.7585>
  400f67:	75 11                	jne    400f7a <__do_global_dtors_aux+0x1a>
  400f69:	55                   	push   %rbp
  400f6a:	48 89 e5             	mov    %rsp,%rbp
  400f6d:	e8 6e ff ff ff       	callq  400ee0 <deregister_tm_clones>
  400f72:	5d                   	pop    %rbp
  400f73:	c6 05 6e 45 20 00 01 	movb   $0x1,0x20456e(%rip)        # 6054e8 <completed.7585>
  400f7a:	f3 c3                	repz retq 
  400f7c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400f80 <frame_dummy>:
  400f80:	bf 20 4e 60 00       	mov    $0x604e20,%edi
  400f85:	48 83 3f 00          	cmpq   $0x0,(%rdi)
  400f89:	75 05                	jne    400f90 <frame_dummy+0x10>
  400f8b:	eb 93                	jmp    400f20 <register_tm_clones>
  400f8d:	0f 1f 00             	nopl   (%rax)
  400f90:	b8 00 00 00 00       	mov    $0x0,%eax
  400f95:	48 85 c0             	test   %rax,%rax
  400f98:	74 f1                	je     400f8b <frame_dummy+0xb>
  400f9a:	55                   	push   %rbp
  400f9b:	48 89 e5             	mov    %rsp,%rbp
  400f9e:	ff d0                	callq  *%rax
  400fa0:	5d                   	pop    %rbp
  400fa1:	e9 7a ff ff ff       	jmpq   400f20 <register_tm_clones>

0000000000400fa6 <usage>:
  400fa6:	48 83 ec 08          	sub    $0x8,%rsp
  400faa:	48 89 fa             	mov    %rdi,%rdx
  400fad:	83 3d 74 45 20 00 00 	cmpl   $0x0,0x204574(%rip)        # 605528 <is_checker>
  400fb4:	74 3e                	je     400ff4 <usage+0x4e>
  400fb6:	be a8 2f 40 00       	mov    $0x402fa8,%esi
  400fbb:	bf 01 00 00 00       	mov    $0x1,%edi
  400fc0:	b8 00 00 00 00       	mov    $0x0,%eax
  400fc5:	e8 36 fe ff ff       	callq  400e00 <__printf_chk@plt>
  400fca:	bf e0 2f 40 00       	mov    $0x402fe0,%edi
  400fcf:	e8 fc fc ff ff       	callq  400cd0 <puts@plt>
  400fd4:	bf 58 31 40 00       	mov    $0x403158,%edi
  400fd9:	e8 f2 fc ff ff       	callq  400cd0 <puts@plt>
  400fde:	bf 08 30 40 00       	mov    $0x403008,%edi
  400fe3:	e8 e8 fc ff ff       	callq  400cd0 <puts@plt>
  400fe8:	bf 72 31 40 00       	mov    $0x403172,%edi
  400fed:	e8 de fc ff ff       	callq  400cd0 <puts@plt>
  400ff2:	eb 32                	jmp    401026 <usage+0x80>
  400ff4:	be 8e 31 40 00       	mov    $0x40318e,%esi
  400ff9:	bf 01 00 00 00       	mov    $0x1,%edi
  400ffe:	b8 00 00 00 00       	mov    $0x0,%eax
  401003:	e8 f8 fd ff ff       	callq  400e00 <__printf_chk@plt>
  401008:	bf 30 30 40 00       	mov    $0x403030,%edi
  40100d:	e8 be fc ff ff       	callq  400cd0 <puts@plt>
  401012:	bf 58 30 40 00       	mov    $0x403058,%edi
  401017:	e8 b4 fc ff ff       	callq  400cd0 <puts@plt>
  40101c:	bf ac 31 40 00       	mov    $0x4031ac,%edi
  401021:	e8 aa fc ff ff       	callq  400cd0 <puts@plt>
  401026:	bf 00 00 00 00       	mov    $0x0,%edi
  40102b:	e8 20 fe ff ff       	callq  400e50 <exit@plt>

0000000000401030 <initialize_target>:
  401030:	55                   	push   %rbp
  401031:	53                   	push   %rbx
  401032:	48 81 ec 18 21 00 00 	sub    $0x2118,%rsp
  401039:	89 f5                	mov    %esi,%ebp
  40103b:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  401042:	00 00 
  401044:	48 89 84 24 08 21 00 	mov    %rax,0x2108(%rsp)
  40104b:	00 
  40104c:	31 c0                	xor    %eax,%eax
  40104e:	89 3d c4 44 20 00    	mov    %edi,0x2044c4(%rip)        # 605518 <check_level>
  401054:	8b 3d 0e 41 20 00    	mov    0x20410e(%rip),%edi        # 605168 <target_id>
  40105a:	e8 99 1e 00 00       	callq  402ef8 <gencookie>
  40105f:	89 05 bf 44 20 00    	mov    %eax,0x2044bf(%rip)        # 605524 <cookie>
  401065:	89 c7                	mov    %eax,%edi
  401067:	e8 8c 1e 00 00       	callq  402ef8 <gencookie>
  40106c:	89 05 ae 44 20 00    	mov    %eax,0x2044ae(%rip)        # 605520 <authkey>
  401072:	8b 05 f0 40 20 00    	mov    0x2040f0(%rip),%eax        # 605168 <target_id>
  401078:	8d 78 01             	lea    0x1(%rax),%edi
  40107b:	e8 20 fc ff ff       	callq  400ca0 <srandom@plt>
  401080:	e8 3b fd ff ff       	callq  400dc0 <random@plt>
  401085:	89 c7                	mov    %eax,%edi
  401087:	e8 03 03 00 00       	callq  40138f <scramble>
  40108c:	89 c3                	mov    %eax,%ebx
  40108e:	85 ed                	test   %ebp,%ebp
  401090:	74 18                	je     4010aa <initialize_target+0x7a>
  401092:	bf 00 00 00 00       	mov    $0x0,%edi
  401097:	e8 14 fd ff ff       	callq  400db0 <time@plt>
  40109c:	89 c7                	mov    %eax,%edi
  40109e:	e8 fd fb ff ff       	callq  400ca0 <srandom@plt>
  4010a3:	e8 18 fd ff ff       	callq  400dc0 <random@plt>
  4010a8:	eb 05                	jmp    4010af <initialize_target+0x7f>
  4010aa:	b8 00 00 00 00       	mov    $0x0,%eax
  4010af:	01 c3                	add    %eax,%ebx
  4010b1:	0f b7 db             	movzwl %bx,%ebx
  4010b4:	8d 04 dd 00 01 00 00 	lea    0x100(,%rbx,8),%eax
  4010bb:	89 c0                	mov    %eax,%eax
  4010bd:	48 89 05 dc 43 20 00 	mov    %rax,0x2043dc(%rip)        # 6054a0 <buf_offset>
  4010c4:	c6 05 7d 50 20 00 72 	movb   $0x72,0x20507d(%rip)        # 606148 <target_prefix>
  4010cb:	83 3d d6 43 20 00 00 	cmpl   $0x0,0x2043d6(%rip)        # 6054a8 <notify>
  4010d2:	0f 84 bb 00 00 00    	je     401193 <initialize_target+0x163>
  4010d8:	83 3d 49 44 20 00 00 	cmpl   $0x0,0x204449(%rip)        # 605528 <is_checker>
  4010df:	0f 85 ae 00 00 00    	jne    401193 <initialize_target+0x163>
  4010e5:	be 00 01 00 00       	mov    $0x100,%esi
  4010ea:	48 89 e7             	mov    %rsp,%rdi
  4010ed:	e8 4e fd ff ff       	callq  400e40 <gethostname@plt>
  4010f2:	85 c0                	test   %eax,%eax
  4010f4:	74 25                	je     40111b <initialize_target+0xeb>
  4010f6:	bf 88 30 40 00       	mov    $0x403088,%edi
  4010fb:	e8 d0 fb ff ff       	callq  400cd0 <puts@plt>
  401100:	bf 08 00 00 00       	mov    $0x8,%edi
  401105:	e8 46 fd ff ff       	callq  400e50 <exit@plt>
  40110a:	48 89 e6             	mov    %rsp,%rsi
  40110d:	e8 6e fb ff ff       	callq  400c80 <strcasecmp@plt>
  401112:	85 c0                	test   %eax,%eax
  401114:	74 21                	je     401137 <initialize_target+0x107>
  401116:	83 c3 01             	add    $0x1,%ebx
  401119:	eb 05                	jmp    401120 <initialize_target+0xf0>
  40111b:	bb 00 00 00 00       	mov    $0x0,%ebx
  401120:	48 63 c3             	movslq %ebx,%rax
  401123:	48 8b 3c c5 80 51 60 	mov    0x605180(,%rax,8),%rdi
  40112a:	00 
  40112b:	48 85 ff             	test   %rdi,%rdi
  40112e:	75 da                	jne    40110a <initialize_target+0xda>
  401130:	b8 00 00 00 00       	mov    $0x0,%eax
  401135:	eb 05                	jmp    40113c <initialize_target+0x10c>
  401137:	b8 01 00 00 00       	mov    $0x1,%eax
  40113c:	85 c0                	test   %eax,%eax
  40113e:	75 1c                	jne    40115c <initialize_target+0x12c>
  401140:	48 89 e2             	mov    %rsp,%rdx
  401143:	be c0 30 40 00       	mov    $0x4030c0,%esi
  401148:	bf 01 00 00 00       	mov    $0x1,%edi
  40114d:	e8 ae fc ff ff       	callq  400e00 <__printf_chk@plt>
  401152:	bf 08 00 00 00       	mov    $0x8,%edi
  401157:	e8 f4 fc ff ff       	callq  400e50 <exit@plt>
  40115c:	48 8d bc 24 00 01 00 	lea    0x100(%rsp),%rdi
  401163:	00 
  401164:	e8 f9 1a 00 00       	callq  402c62 <init_driver>
  401169:	85 c0                	test   %eax,%eax
  40116b:	79 26                	jns    401193 <initialize_target+0x163>
  40116d:	48 8d 94 24 00 01 00 	lea    0x100(%rsp),%rdx
  401174:	00 
  401175:	be 00 31 40 00       	mov    $0x403100,%esi
  40117a:	bf 01 00 00 00       	mov    $0x1,%edi
  40117f:	b8 00 00 00 00       	mov    $0x0,%eax
  401184:	e8 77 fc ff ff       	callq  400e00 <__printf_chk@plt>
  401189:	bf 08 00 00 00       	mov    $0x8,%edi
  40118e:	e8 bd fc ff ff       	callq  400e50 <exit@plt>
  401193:	48 8b 84 24 08 21 00 	mov    0x2108(%rsp),%rax
  40119a:	00 
  40119b:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  4011a2:	00 00 
  4011a4:	74 05                	je     4011ab <initialize_target+0x17b>
  4011a6:	e8 45 fb ff ff       	callq  400cf0 <__stack_chk_fail@plt>
  4011ab:	48 81 c4 18 21 00 00 	add    $0x2118,%rsp
  4011b2:	5b                   	pop    %rbx
  4011b3:	5d                   	pop    %rbp
  4011b4:	c3                   	retq   

00000000004011b5 <main>:
  4011b5:	41 56                	push   %r14
  4011b7:	41 55                	push   %r13
  4011b9:	41 54                	push   %r12
  4011bb:	55                   	push   %rbp
  4011bc:	53                   	push   %rbx
  4011bd:	41 89 fc             	mov    %edi,%r12d
  4011c0:	48 89 f3             	mov    %rsi,%rbx
  4011c3:	be 9d 1f 40 00       	mov    $0x401f9d,%esi
  4011c8:	bf 0b 00 00 00       	mov    $0xb,%edi
  4011cd:	e8 8e fb ff ff       	callq  400d60 <signal@plt>
  4011d2:	be 4f 1f 40 00       	mov    $0x401f4f,%esi
  4011d7:	bf 07 00 00 00       	mov    $0x7,%edi
  4011dc:	e8 7f fb ff ff       	callq  400d60 <signal@plt>
  4011e1:	be eb 1f 40 00       	mov    $0x401feb,%esi
  4011e6:	bf 04 00 00 00       	mov    $0x4,%edi
  4011eb:	e8 70 fb ff ff       	callq  400d60 <signal@plt>
  4011f0:	83 3d 31 43 20 00 00 	cmpl   $0x0,0x204331(%rip)        # 605528 <is_checker>
  4011f7:	74 20                	je     401219 <main+0x64>
  4011f9:	be 39 20 40 00       	mov    $0x402039,%esi
  4011fe:	bf 0e 00 00 00       	mov    $0xe,%edi
  401203:	e8 58 fb ff ff       	callq  400d60 <signal@plt>
  401208:	bf 05 00 00 00       	mov    $0x5,%edi
  40120d:	e8 0e fb ff ff       	callq  400d20 <alarm@plt>
  401212:	bd ca 31 40 00       	mov    $0x4031ca,%ebp
  401217:	eb 05                	jmp    40121e <main+0x69>
  401219:	bd c5 31 40 00       	mov    $0x4031c5,%ebp
  40121e:	48 8b 05 9b 42 20 00 	mov    0x20429b(%rip),%rax        # 6054c0 <stdin@@GLIBC_2.2.5>
  401225:	48 89 05 e4 42 20 00 	mov    %rax,0x2042e4(%rip)        # 605510 <infile>
  40122c:	41 bd 00 00 00 00    	mov    $0x0,%r13d
  401232:	41 be 00 00 00 00    	mov    $0x0,%r14d
  401238:	e9 c6 00 00 00       	jmpq   401303 <main+0x14e>
  40123d:	83 e8 61             	sub    $0x61,%eax
  401240:	3c 10                	cmp    $0x10,%al
  401242:	0f 87 9c 00 00 00    	ja     4012e4 <main+0x12f>
  401248:	0f b6 c0             	movzbl %al,%eax
  40124b:	ff 24 c5 10 32 40 00 	jmpq   *0x403210(,%rax,8)
  401252:	48 8b 3b             	mov    (%rbx),%rdi
  401255:	e8 4c fd ff ff       	callq  400fa6 <usage>
  40125a:	be 9d 34 40 00       	mov    $0x40349d,%esi
  40125f:	48 8b 3d 62 42 20 00 	mov    0x204262(%rip),%rdi        # 6054c8 <optarg@@GLIBC_2.2.5>
  401266:	e8 a5 fb ff ff       	callq  400e10 <fopen@plt>
  40126b:	48 89 05 9e 42 20 00 	mov    %rax,0x20429e(%rip)        # 605510 <infile>
  401272:	48 85 c0             	test   %rax,%rax
  401275:	0f 85 88 00 00 00    	jne    401303 <main+0x14e>
  40127b:	48 8b 0d 46 42 20 00 	mov    0x204246(%rip),%rcx        # 6054c8 <optarg@@GLIBC_2.2.5>
  401282:	ba d2 31 40 00       	mov    $0x4031d2,%edx
  401287:	be 01 00 00 00       	mov    $0x1,%esi
  40128c:	48 8b 3d 4d 42 20 00 	mov    0x20424d(%rip),%rdi        # 6054e0 <stderr@@GLIBC_2.2.5>
  401293:	e8 d8 fb ff ff       	callq  400e70 <__fprintf_chk@plt>
  401298:	b8 01 00 00 00       	mov    $0x1,%eax
  40129d:	e9 e4 00 00 00       	jmpq   401386 <main+0x1d1>
  4012a2:	ba 10 00 00 00       	mov    $0x10,%edx
  4012a7:	be 00 00 00 00       	mov    $0x0,%esi
  4012ac:	48 8b 3d 15 42 20 00 	mov    0x204215(%rip),%rdi        # 6054c8 <optarg@@GLIBC_2.2.5>
  4012b3:	e8 78 fb ff ff       	callq  400e30 <strtoul@plt>
  4012b8:	41 89 c6             	mov    %eax,%r14d
  4012bb:	eb 46                	jmp    401303 <main+0x14e>
  4012bd:	ba 0a 00 00 00       	mov    $0xa,%edx
  4012c2:	be 00 00 00 00       	mov    $0x0,%esi
  4012c7:	48 8b 3d fa 41 20 00 	mov    0x2041fa(%rip),%rdi        # 6054c8 <optarg@@GLIBC_2.2.5>
  4012ce:	e8 bd fa ff ff       	callq  400d90 <strtol@plt>
  4012d3:	41 89 c5             	mov    %eax,%r13d
  4012d6:	eb 2b                	jmp    401303 <main+0x14e>
  4012d8:	c7 05 c6 41 20 00 00 	movl   $0x0,0x2041c6(%rip)        # 6054a8 <notify>
  4012df:	00 00 00 
  4012e2:	eb 1f                	jmp    401303 <main+0x14e>
  4012e4:	0f be d2             	movsbl %dl,%edx
  4012e7:	be ef 31 40 00       	mov    $0x4031ef,%esi
  4012ec:	bf 01 00 00 00       	mov    $0x1,%edi
  4012f1:	b8 00 00 00 00       	mov    $0x0,%eax
  4012f6:	e8 05 fb ff ff       	callq  400e00 <__printf_chk@plt>
  4012fb:	48 8b 3b             	mov    (%rbx),%rdi
  4012fe:	e8 a3 fc ff ff       	callq  400fa6 <usage>
  401303:	48 89 ea             	mov    %rbp,%rdx
  401306:	48 89 de             	mov    %rbx,%rsi
  401309:	44 89 e7             	mov    %r12d,%edi
  40130c:	e8 0f fb ff ff       	callq  400e20 <getopt@plt>
  401311:	89 c2                	mov    %eax,%edx
  401313:	3c ff                	cmp    $0xff,%al
  401315:	0f 85 22 ff ff ff    	jne    40123d <main+0x88>
  40131b:	be 01 00 00 00       	mov    $0x1,%esi
  401320:	44 89 ef             	mov    %r13d,%edi
  401323:	e8 08 fd ff ff       	callq  401030 <initialize_target>
  401328:	83 3d f9 41 20 00 00 	cmpl   $0x0,0x2041f9(%rip)        # 605528 <is_checker>
  40132f:	74 2a                	je     40135b <main+0x1a6>
  401331:	44 3b 35 e8 41 20 00 	cmp    0x2041e8(%rip),%r14d        # 605520 <authkey>
  401338:	74 21                	je     40135b <main+0x1a6>
  40133a:	44 89 f2             	mov    %r14d,%edx
  40133d:	be 28 31 40 00       	mov    $0x403128,%esi
  401342:	bf 01 00 00 00       	mov    $0x1,%edi
  401347:	b8 00 00 00 00       	mov    $0x0,%eax
  40134c:	e8 af fa ff ff       	callq  400e00 <__printf_chk@plt>
  401351:	b8 00 00 00 00       	mov    $0x0,%eax
  401356:	e8 90 08 00 00       	callq  401beb <check_fail>
  40135b:	8b 15 c3 41 20 00    	mov    0x2041c3(%rip),%edx        # 605524 <cookie>
  401361:	be 02 32 40 00       	mov    $0x403202,%esi
  401366:	bf 01 00 00 00       	mov    $0x1,%edi
  40136b:	b8 00 00 00 00       	mov    $0x0,%eax
  401370:	e8 8b fa ff ff       	callq  400e00 <__printf_chk@plt>
  401375:	48 8b 3d 24 41 20 00 	mov    0x204124(%rip),%rdi        # 6054a0 <buf_offset>
  40137c:	e8 0b 0d 00 00       	callq  40208c <launch>
  401381:	b8 00 00 00 00       	mov    $0x0,%eax
  401386:	5b                   	pop    %rbx
  401387:	5d                   	pop    %rbp
  401388:	41 5c                	pop    %r12
  40138a:	41 5d                	pop    %r13
  40138c:	41 5e                	pop    %r14
  40138e:	c3                   	retq   

000000000040138f <scramble>:
  40138f:	48 83 ec 38          	sub    $0x38,%rsp
  401393:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  40139a:	00 00 
  40139c:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
  4013a1:	31 c0                	xor    %eax,%eax
  4013a3:	eb 10                	jmp    4013b5 <scramble+0x26>
  4013a5:	69 d0 55 e0 00 00    	imul   $0xe055,%eax,%edx
  4013ab:	01 fa                	add    %edi,%edx
  4013ad:	89 c1                	mov    %eax,%ecx
  4013af:	89 14 8c             	mov    %edx,(%rsp,%rcx,4)
  4013b2:	83 c0 01             	add    $0x1,%eax
  4013b5:	83 f8 09             	cmp    $0x9,%eax
  4013b8:	76 eb                	jbe    4013a5 <scramble+0x16>
  4013ba:	8b 44 24 1c          	mov    0x1c(%rsp),%eax
  4013be:	69 c0 50 12 00 00    	imul   $0x1250,%eax,%eax
  4013c4:	89 44 24 1c          	mov    %eax,0x1c(%rsp)
  4013c8:	8b 04 24             	mov    (%rsp),%eax
  4013cb:	69 c0 21 0b 00 00    	imul   $0xb21,%eax,%eax
  4013d1:	89 04 24             	mov    %eax,(%rsp)
  4013d4:	8b 44 24 0c          	mov    0xc(%rsp),%eax
  4013d8:	69 c0 89 2e 00 00    	imul   $0x2e89,%eax,%eax
  4013de:	89 44 24 0c          	mov    %eax,0xc(%rsp)
  4013e2:	8b 44 24 10          	mov    0x10(%rsp),%eax
  4013e6:	69 c0 bc 2b 00 00    	imul   $0x2bbc,%eax,%eax
  4013ec:	89 44 24 10          	mov    %eax,0x10(%rsp)
  4013f0:	8b 04 24             	mov    (%rsp),%eax
  4013f3:	69 c0 b6 db 00 00    	imul   $0xdbb6,%eax,%eax
  4013f9:	89 04 24             	mov    %eax,(%rsp)
  4013fc:	8b 44 24 1c          	mov    0x1c(%rsp),%eax
  401400:	69 c0 84 e0 00 00    	imul   $0xe084,%eax,%eax
  401406:	89 44 24 1c          	mov    %eax,0x1c(%rsp)
  40140a:	8b 44 24 1c          	mov    0x1c(%rsp),%eax
  40140e:	69 c0 48 3c 00 00    	imul   $0x3c48,%eax,%eax
  401414:	89 44 24 1c          	mov    %eax,0x1c(%rsp)
  401418:	8b 44 24 20          	mov    0x20(%rsp),%eax
  40141c:	69 c0 d3 05 00 00    	imul   $0x5d3,%eax,%eax
  401422:	89 44 24 20          	mov    %eax,0x20(%rsp)
  401426:	8b 44 24 18          	mov    0x18(%rsp),%eax
  40142a:	69 c0 b8 e2 00 00    	imul   $0xe2b8,%eax,%eax
  401430:	89 44 24 18          	mov    %eax,0x18(%rsp)
  401434:	8b 44 24 14          	mov    0x14(%rsp),%eax
  401438:	69 c0 ef 54 00 00    	imul   $0x54ef,%eax,%eax
  40143e:	89 44 24 14          	mov    %eax,0x14(%rsp)
  401442:	8b 44 24 10          	mov    0x10(%rsp),%eax
  401446:	69 c0 29 ed 00 00    	imul   $0xed29,%eax,%eax
  40144c:	89 44 24 10          	mov    %eax,0x10(%rsp)
  401450:	8b 44 24 18          	mov    0x18(%rsp),%eax
  401454:	69 c0 36 83 00 00    	imul   $0x8336,%eax,%eax
  40145a:	89 44 24 18          	mov    %eax,0x18(%rsp)
  40145e:	8b 44 24 1c          	mov    0x1c(%rsp),%eax
  401462:	69 c0 c1 87 00 00    	imul   $0x87c1,%eax,%eax
  401468:	89 44 24 1c          	mov    %eax,0x1c(%rsp)
  40146c:	8b 44 24 20          	mov    0x20(%rsp),%eax
  401470:	69 c0 f3 2f 00 00    	imul   $0x2ff3,%eax,%eax
  401476:	89 44 24 20          	mov    %eax,0x20(%rsp)
  40147a:	8b 44 24 14          	mov    0x14(%rsp),%eax
  40147e:	69 c0 c0 e8 00 00    	imul   $0xe8c0,%eax,%eax
  401484:	89 44 24 14          	mov    %eax,0x14(%rsp)
  401488:	8b 44 24 10          	mov    0x10(%rsp),%eax
  40148c:	69 c0 6b 6a 00 00    	imul   $0x6a6b,%eax,%eax
  401492:	89 44 24 10          	mov    %eax,0x10(%rsp)
  401496:	8b 44 24 14          	mov    0x14(%rsp),%eax
  40149a:	69 c0 98 7b 00 00    	imul   $0x7b98,%eax,%eax
  4014a0:	89 44 24 14          	mov    %eax,0x14(%rsp)
  4014a4:	8b 44 24 20          	mov    0x20(%rsp),%eax
  4014a8:	69 c0 7e 5e 00 00    	imul   $0x5e7e,%eax,%eax
  4014ae:	89 44 24 20          	mov    %eax,0x20(%rsp)
  4014b2:	8b 44 24 20          	mov    0x20(%rsp),%eax
  4014b6:	69 c0 e6 80 00 00    	imul   $0x80e6,%eax,%eax
  4014bc:	89 44 24 20          	mov    %eax,0x20(%rsp)
  4014c0:	8b 44 24 24          	mov    0x24(%rsp),%eax
  4014c4:	69 c0 92 c1 00 00    	imul   $0xc192,%eax,%eax
  4014ca:	89 44 24 24          	mov    %eax,0x24(%rsp)
  4014ce:	8b 44 24 10          	mov    0x10(%rsp),%eax
  4014d2:	69 c0 6c d2 00 00    	imul   $0xd26c,%eax,%eax
  4014d8:	89 44 24 10          	mov    %eax,0x10(%rsp)
  4014dc:	8b 44 24 04          	mov    0x4(%rsp),%eax
  4014e0:	69 c0 4a 65 00 00    	imul   $0x654a,%eax,%eax
  4014e6:	89 44 24 04          	mov    %eax,0x4(%rsp)
  4014ea:	8b 44 24 08          	mov    0x8(%rsp),%eax
  4014ee:	69 c0 19 79 00 00    	imul   $0x7919,%eax,%eax
  4014f4:	89 44 24 08          	mov    %eax,0x8(%rsp)
  4014f8:	8b 44 24 18          	mov    0x18(%rsp),%eax
  4014fc:	69 c0 49 87 00 00    	imul   $0x8749,%eax,%eax
  401502:	89 44 24 18          	mov    %eax,0x18(%rsp)
  401506:	8b 44 24 08          	mov    0x8(%rsp),%eax
  40150a:	69 c0 b6 f5 00 00    	imul   $0xf5b6,%eax,%eax
  401510:	89 44 24 08          	mov    %eax,0x8(%rsp)
  401514:	8b 44 24 0c          	mov    0xc(%rsp),%eax
  401518:	69 c0 2d 56 00 00    	imul   $0x562d,%eax,%eax
  40151e:	89 44 24 0c          	mov    %eax,0xc(%rsp)
  401522:	8b 44 24 24          	mov    0x24(%rsp),%eax
  401526:	69 c0 87 a4 00 00    	imul   $0xa487,%eax,%eax
  40152c:	89 44 24 24          	mov    %eax,0x24(%rsp)
  401530:	8b 04 24             	mov    (%rsp),%eax
  401533:	69 c0 79 0e 00 00    	imul   $0xe79,%eax,%eax
  401539:	89 04 24             	mov    %eax,(%rsp)
  40153c:	8b 44 24 0c          	mov    0xc(%rsp),%eax
  401540:	69 c0 e1 83 00 00    	imul   $0x83e1,%eax,%eax
  401546:	89 44 24 0c          	mov    %eax,0xc(%rsp)
  40154a:	8b 44 24 14          	mov    0x14(%rsp),%eax
  40154e:	69 c0 5e b6 00 00    	imul   $0xb65e,%eax,%eax
  401554:	89 44 24 14          	mov    %eax,0x14(%rsp)
  401558:	8b 44 24 18          	mov    0x18(%rsp),%eax
  40155c:	69 c0 48 4d 00 00    	imul   $0x4d48,%eax,%eax
  401562:	89 44 24 18          	mov    %eax,0x18(%rsp)
  401566:	8b 44 24 10          	mov    0x10(%rsp),%eax
  40156a:	69 c0 b1 67 00 00    	imul   $0x67b1,%eax,%eax
  401570:	89 44 24 10          	mov    %eax,0x10(%rsp)
  401574:	8b 44 24 0c          	mov    0xc(%rsp),%eax
  401578:	69 c0 57 96 00 00    	imul   $0x9657,%eax,%eax
  40157e:	89 44 24 0c          	mov    %eax,0xc(%rsp)
  401582:	8b 44 24 0c          	mov    0xc(%rsp),%eax
  401586:	69 c0 02 73 00 00    	imul   $0x7302,%eax,%eax
  40158c:	89 44 24 0c          	mov    %eax,0xc(%rsp)
  401590:	8b 44 24 1c          	mov    0x1c(%rsp),%eax
  401594:	69 c0 69 50 00 00    	imul   $0x5069,%eax,%eax
  40159a:	89 44 24 1c          	mov    %eax,0x1c(%rsp)
  40159e:	8b 44 24 0c          	mov    0xc(%rsp),%eax
  4015a2:	69 c0 da 73 00 00    	imul   $0x73da,%eax,%eax
  4015a8:	89 44 24 0c          	mov    %eax,0xc(%rsp)
  4015ac:	8b 44 24 04          	mov    0x4(%rsp),%eax
  4015b0:	69 c0 ab d6 00 00    	imul   $0xd6ab,%eax,%eax
  4015b6:	89 44 24 04          	mov    %eax,0x4(%rsp)
  4015ba:	8b 44 24 1c          	mov    0x1c(%rsp),%eax
  4015be:	69 c0 8a 31 00 00    	imul   $0x318a,%eax,%eax
  4015c4:	89 44 24 1c          	mov    %eax,0x1c(%rsp)
  4015c8:	8b 44 24 18          	mov    0x18(%rsp),%eax
  4015cc:	69 c0 43 44 00 00    	imul   $0x4443,%eax,%eax
  4015d2:	89 44 24 18          	mov    %eax,0x18(%rsp)
  4015d6:	8b 44 24 14          	mov    0x14(%rsp),%eax
  4015da:	69 c0 97 ab 00 00    	imul   $0xab97,%eax,%eax
  4015e0:	89 44 24 14          	mov    %eax,0x14(%rsp)
  4015e4:	8b 44 24 10          	mov    0x10(%rsp),%eax
  4015e8:	69 c0 0c 95 00 00    	imul   $0x950c,%eax,%eax
  4015ee:	89 44 24 10          	mov    %eax,0x10(%rsp)
  4015f2:	8b 44 24 1c          	mov    0x1c(%rsp),%eax
  4015f6:	69 c0 d8 1c 00 00    	imul   $0x1cd8,%eax,%eax
  4015fc:	89 44 24 1c          	mov    %eax,0x1c(%rsp)
  401600:	8b 44 24 04          	mov    0x4(%rsp),%eax
  401604:	69 c0 27 db 00 00    	imul   $0xdb27,%eax,%eax
  40160a:	89 44 24 04          	mov    %eax,0x4(%rsp)
  40160e:	8b 44 24 10          	mov    0x10(%rsp),%eax
  401612:	69 c0 dc 65 00 00    	imul   $0x65dc,%eax,%eax
  401618:	89 44 24 10          	mov    %eax,0x10(%rsp)
  40161c:	8b 44 24 18          	mov    0x18(%rsp),%eax
  401620:	69 c0 be 69 00 00    	imul   $0x69be,%eax,%eax
  401626:	89 44 24 18          	mov    %eax,0x18(%rsp)
  40162a:	8b 44 24 20          	mov    0x20(%rsp),%eax
  40162e:	69 c0 a9 cb 00 00    	imul   $0xcba9,%eax,%eax
  401634:	89 44 24 20          	mov    %eax,0x20(%rsp)
  401638:	8b 04 24             	mov    (%rsp),%eax
  40163b:	69 c0 04 3d 00 00    	imul   $0x3d04,%eax,%eax
  401641:	89 04 24             	mov    %eax,(%rsp)
  401644:	8b 44 24 14          	mov    0x14(%rsp),%eax
  401648:	69 c0 e7 7f 00 00    	imul   $0x7fe7,%eax,%eax
  40164e:	89 44 24 14          	mov    %eax,0x14(%rsp)
  401652:	8b 44 24 24          	mov    0x24(%rsp),%eax
  401656:	69 c0 89 f9 00 00    	imul   $0xf989,%eax,%eax
  40165c:	89 44 24 24          	mov    %eax,0x24(%rsp)
  401660:	8b 44 24 20          	mov    0x20(%rsp),%eax
  401664:	69 c0 99 ea 00 00    	imul   $0xea99,%eax,%eax
  40166a:	89 44 24 20          	mov    %eax,0x20(%rsp)
  40166e:	8b 44 24 14          	mov    0x14(%rsp),%eax
  401672:	69 c0 7e 27 00 00    	imul   $0x277e,%eax,%eax
  401678:	89 44 24 14          	mov    %eax,0x14(%rsp)
  40167c:	8b 44 24 08          	mov    0x8(%rsp),%eax
  401680:	69 c0 c8 6c 00 00    	imul   $0x6cc8,%eax,%eax
  401686:	89 44 24 08          	mov    %eax,0x8(%rsp)
  40168a:	8b 44 24 20          	mov    0x20(%rsp),%eax
  40168e:	69 c0 98 37 00 00    	imul   $0x3798,%eax,%eax
  401694:	89 44 24 20          	mov    %eax,0x20(%rsp)
  401698:	8b 44 24 0c          	mov    0xc(%rsp),%eax
  40169c:	69 c0 ef 4d 00 00    	imul   $0x4def,%eax,%eax
  4016a2:	89 44 24 0c          	mov    %eax,0xc(%rsp)
  4016a6:	8b 44 24 08          	mov    0x8(%rsp),%eax
  4016aa:	69 c0 26 57 00 00    	imul   $0x5726,%eax,%eax
  4016b0:	89 44 24 08          	mov    %eax,0x8(%rsp)
  4016b4:	8b 44 24 14          	mov    0x14(%rsp),%eax
  4016b8:	69 c0 d4 b5 00 00    	imul   $0xb5d4,%eax,%eax
  4016be:	89 44 24 14          	mov    %eax,0x14(%rsp)
  4016c2:	8b 04 24             	mov    (%rsp),%eax
  4016c5:	69 c0 4a fb 00 00    	imul   $0xfb4a,%eax,%eax
  4016cb:	89 04 24             	mov    %eax,(%rsp)
  4016ce:	8b 44 24 0c          	mov    0xc(%rsp),%eax
  4016d2:	69 c0 c6 25 00 00    	imul   $0x25c6,%eax,%eax
  4016d8:	89 44 24 0c          	mov    %eax,0xc(%rsp)
  4016dc:	8b 04 24             	mov    (%rsp),%eax
  4016df:	69 c0 fe fd 00 00    	imul   $0xfdfe,%eax,%eax
  4016e5:	89 04 24             	mov    %eax,(%rsp)
  4016e8:	8b 04 24             	mov    (%rsp),%eax
  4016eb:	69 c0 7a 35 00 00    	imul   $0x357a,%eax,%eax
  4016f1:	89 04 24             	mov    %eax,(%rsp)
  4016f4:	8b 44 24 04          	mov    0x4(%rsp),%eax
  4016f8:	69 c0 dd a7 00 00    	imul   $0xa7dd,%eax,%eax
  4016fe:	89 44 24 04          	mov    %eax,0x4(%rsp)
  401702:	8b 44 24 0c          	mov    0xc(%rsp),%eax
  401706:	69 c0 c3 1e 00 00    	imul   $0x1ec3,%eax,%eax
  40170c:	89 44 24 0c          	mov    %eax,0xc(%rsp)
  401710:	8b 44 24 10          	mov    0x10(%rsp),%eax
  401714:	69 c0 7e 34 00 00    	imul   $0x347e,%eax,%eax
  40171a:	89 44 24 10          	mov    %eax,0x10(%rsp)
  40171e:	8b 44 24 24          	mov    0x24(%rsp),%eax
  401722:	69 c0 3d b8 00 00    	imul   $0xb83d,%eax,%eax
  401728:	89 44 24 24          	mov    %eax,0x24(%rsp)
  40172c:	8b 44 24 08          	mov    0x8(%rsp),%eax
  401730:	69 c0 93 91 00 00    	imul   $0x9193,%eax,%eax
  401736:	89 44 24 08          	mov    %eax,0x8(%rsp)
  40173a:	8b 44 24 10          	mov    0x10(%rsp),%eax
  40173e:	69 c0 fa 77 00 00    	imul   $0x77fa,%eax,%eax
  401744:	89 44 24 10          	mov    %eax,0x10(%rsp)
  401748:	8b 44 24 10          	mov    0x10(%rsp),%eax
  40174c:	69 c0 49 01 00 00    	imul   $0x149,%eax,%eax
  401752:	89 44 24 10          	mov    %eax,0x10(%rsp)
  401756:	8b 44 24 18          	mov    0x18(%rsp),%eax
  40175a:	69 c0 3c b7 00 00    	imul   $0xb73c,%eax,%eax
  401760:	89 44 24 18          	mov    %eax,0x18(%rsp)
  401764:	8b 44 24 1c          	mov    0x1c(%rsp),%eax
  401768:	69 c0 14 83 00 00    	imul   $0x8314,%eax,%eax
  40176e:	89 44 24 1c          	mov    %eax,0x1c(%rsp)
  401772:	8b 44 24 24          	mov    0x24(%rsp),%eax
  401776:	69 c0 bd b4 00 00    	imul   $0xb4bd,%eax,%eax
  40177c:	89 44 24 24          	mov    %eax,0x24(%rsp)
  401780:	8b 04 24             	mov    (%rsp),%eax
  401783:	69 c0 b1 fe 00 00    	imul   $0xfeb1,%eax,%eax
  401789:	89 04 24             	mov    %eax,(%rsp)
  40178c:	8b 44 24 24          	mov    0x24(%rsp),%eax
  401790:	69 c0 6e c6 00 00    	imul   $0xc66e,%eax,%eax
  401796:	89 44 24 24          	mov    %eax,0x24(%rsp)
  40179a:	8b 44 24 20          	mov    0x20(%rsp),%eax
  40179e:	69 c0 3e 3d 00 00    	imul   $0x3d3e,%eax,%eax
  4017a4:	89 44 24 20          	mov    %eax,0x20(%rsp)
  4017a8:	8b 44 24 10          	mov    0x10(%rsp),%eax
  4017ac:	69 c0 6c d0 00 00    	imul   $0xd06c,%eax,%eax
  4017b2:	89 44 24 10          	mov    %eax,0x10(%rsp)
  4017b6:	8b 44 24 18          	mov    0x18(%rsp),%eax
  4017ba:	69 c0 d7 77 00 00    	imul   $0x77d7,%eax,%eax
  4017c0:	89 44 24 18          	mov    %eax,0x18(%rsp)
  4017c4:	8b 04 24             	mov    (%rsp),%eax
  4017c7:	69 c0 f9 a2 00 00    	imul   $0xa2f9,%eax,%eax
  4017cd:	89 04 24             	mov    %eax,(%rsp)
  4017d0:	8b 44 24 18          	mov    0x18(%rsp),%eax
  4017d4:	69 c0 0a 07 00 00    	imul   $0x70a,%eax,%eax
  4017da:	89 44 24 18          	mov    %eax,0x18(%rsp)
  4017de:	8b 44 24 10          	mov    0x10(%rsp),%eax
  4017e2:	69 c0 95 04 00 00    	imul   $0x495,%eax,%eax
  4017e8:	89 44 24 10          	mov    %eax,0x10(%rsp)
  4017ec:	8b 44 24 18          	mov    0x18(%rsp),%eax
  4017f0:	69 c0 66 60 00 00    	imul   $0x6066,%eax,%eax
  4017f6:	89 44 24 18          	mov    %eax,0x18(%rsp)
  4017fa:	8b 44 24 1c          	mov    0x1c(%rsp),%eax
  4017fe:	69 c0 8f 69 00 00    	imul   $0x698f,%eax,%eax
  401804:	89 44 24 1c          	mov    %eax,0x1c(%rsp)
  401808:	8b 44 24 1c          	mov    0x1c(%rsp),%eax
  40180c:	69 c0 a8 5f 00 00    	imul   $0x5fa8,%eax,%eax
  401812:	89 44 24 1c          	mov    %eax,0x1c(%rsp)
  401816:	8b 44 24 20          	mov    0x20(%rsp),%eax
  40181a:	69 c0 0b ab 00 00    	imul   $0xab0b,%eax,%eax
  401820:	89 44 24 20          	mov    %eax,0x20(%rsp)
  401824:	8b 44 24 04          	mov    0x4(%rsp),%eax
  401828:	69 c0 4b c6 00 00    	imul   $0xc64b,%eax,%eax
  40182e:	89 44 24 04          	mov    %eax,0x4(%rsp)
  401832:	8b 44 24 18          	mov    0x18(%rsp),%eax
  401836:	69 c0 d4 99 00 00    	imul   $0x99d4,%eax,%eax
  40183c:	89 44 24 18          	mov    %eax,0x18(%rsp)
  401840:	ba 00 00 00 00       	mov    $0x0,%edx
  401845:	b8 00 00 00 00       	mov    $0x0,%eax
  40184a:	eb 0a                	jmp    401856 <scramble+0x4c7>
  40184c:	89 d1                	mov    %edx,%ecx
  40184e:	8b 0c 8c             	mov    (%rsp,%rcx,4),%ecx
  401851:	01 c8                	add    %ecx,%eax
  401853:	83 c2 01             	add    $0x1,%edx
  401856:	83 fa 09             	cmp    $0x9,%edx
  401859:	76 f1                	jbe    40184c <scramble+0x4bd>
  40185b:	48 8b 74 24 28       	mov    0x28(%rsp),%rsi
  401860:	64 48 33 34 25 28 00 	xor    %fs:0x28,%rsi
  401867:	00 00 
  401869:	74 05                	je     401870 <scramble+0x4e1>
  40186b:	e8 80 f4 ff ff       	callq  400cf0 <__stack_chk_fail@plt>
  401870:	48 83 c4 38          	add    $0x38,%rsp
  401874:	c3                   	retq   

0000000000401875 <getbuf>:
  401875:	48 83 ec 38          	sub    $0x38,%rsp
  401879:	48 89 e7             	mov    %rsp,%rdi
  40187c:	e8 9f 03 00 00       	callq  401c20 <Gets>
  401881:	b8 01 00 00 00       	mov    $0x1,%eax
  401886:	48 83 c4 38          	add    $0x38,%rsp
  40188a:	c3                   	retq   

000000000040188b <touch1>:
  40188b:	48 83 ec 08          	sub    $0x8,%rsp
  40188f:	c7 05 83 3c 20 00 01 	movl   $0x1,0x203c83(%rip)        # 60551c <vlevel>
  401896:	00 00 00 
  401899:	bf f1 32 40 00       	mov    $0x4032f1,%edi
  40189e:	e8 2d f4 ff ff       	callq  400cd0 <puts@plt>
  4018a3:	bf 01 00 00 00       	mov    $0x1,%edi
  4018a8:	e8 b8 05 00 00       	callq  401e65 <validate>
  4018ad:	bf 00 00 00 00       	mov    $0x0,%edi
  4018b2:	e8 99 f5 ff ff       	callq  400e50 <exit@plt>

00000000004018b7 <touch2>:
  4018b7:	48 83 ec 08          	sub    $0x8,%rsp
  4018bb:	89 fa                	mov    %edi,%edx
  4018bd:	c7 05 55 3c 20 00 02 	movl   $0x2,0x203c55(%rip)        # 60551c <vlevel>
  4018c4:	00 00 00 
  4018c7:	39 3d 57 3c 20 00    	cmp    %edi,0x203c57(%rip)        # 605524 <cookie>
  4018cd:	75 20                	jne    4018ef <touch2+0x38>
  4018cf:	be 18 33 40 00       	mov    $0x403318,%esi
  4018d4:	bf 01 00 00 00       	mov    $0x1,%edi
  4018d9:	b8 00 00 00 00       	mov    $0x0,%eax
  4018de:	e8 1d f5 ff ff       	callq  400e00 <__printf_chk@plt>
  4018e3:	bf 02 00 00 00       	mov    $0x2,%edi
  4018e8:	e8 78 05 00 00       	callq  401e65 <validate>
  4018ed:	eb 1e                	jmp    40190d <touch2+0x56>
  4018ef:	be 40 33 40 00       	mov    $0x403340,%esi
  4018f4:	bf 01 00 00 00       	mov    $0x1,%edi
  4018f9:	b8 00 00 00 00       	mov    $0x0,%eax
  4018fe:	e8 fd f4 ff ff       	callq  400e00 <__printf_chk@plt>
  401903:	bf 02 00 00 00       	mov    $0x2,%edi
  401908:	e8 1a 06 00 00       	callq  401f27 <fail>
  40190d:	bf 00 00 00 00       	mov    $0x0,%edi
  401912:	e8 39 f5 ff ff       	callq  400e50 <exit@plt>

0000000000401917 <hexmatch>:
  401917:	41 54                	push   %r12
  401919:	55                   	push   %rbp
  40191a:	53                   	push   %rbx
  40191b:	48 83 c4 80          	add    $0xffffffffffffff80,%rsp
  40191f:	89 fd                	mov    %edi,%ebp
  401921:	48 89 f3             	mov    %rsi,%rbx
  401924:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  40192b:	00 00 
  40192d:	48 89 44 24 78       	mov    %rax,0x78(%rsp)
  401932:	31 c0                	xor    %eax,%eax
  401934:	e8 87 f4 ff ff       	callq  400dc0 <random@plt>
  401939:	48 89 c1             	mov    %rax,%rcx
  40193c:	48 ba 0b d7 a3 70 3d 	movabs $0xa3d70a3d70a3d70b,%rdx
  401943:	0a d7 a3 
  401946:	48 f7 ea             	imul   %rdx
  401949:	48 01 ca             	add    %rcx,%rdx
  40194c:	48 c1 fa 06          	sar    $0x6,%rdx
  401950:	48 89 c8             	mov    %rcx,%rax
  401953:	48 c1 f8 3f          	sar    $0x3f,%rax
  401957:	48 29 c2             	sub    %rax,%rdx
  40195a:	48 8d 04 92          	lea    (%rdx,%rdx,4),%rax
  40195e:	48 8d 14 80          	lea    (%rax,%rax,4),%rdx
  401962:	48 8d 04 95 00 00 00 	lea    0x0(,%rdx,4),%rax
  401969:	00 
  40196a:	48 29 c1             	sub    %rax,%rcx
  40196d:	4c 8d 24 0c          	lea    (%rsp,%rcx,1),%r12
  401971:	41 89 e8             	mov    %ebp,%r8d
  401974:	b9 0e 33 40 00       	mov    $0x40330e,%ecx
  401979:	48 c7 c2 ff ff ff ff 	mov    $0xffffffffffffffff,%rdx
  401980:	be 01 00 00 00       	mov    $0x1,%esi
  401985:	4c 89 e7             	mov    %r12,%rdi
  401988:	b8 00 00 00 00       	mov    $0x0,%eax
  40198d:	e8 ee f4 ff ff       	callq  400e80 <__sprintf_chk@plt>
  401992:	ba 09 00 00 00       	mov    $0x9,%edx
  401997:	4c 89 e6             	mov    %r12,%rsi
  40199a:	48 89 df             	mov    %rbx,%rdi
  40199d:	e8 0e f3 ff ff       	callq  400cb0 <strncmp@plt>
  4019a2:	85 c0                	test   %eax,%eax
  4019a4:	0f 94 c0             	sete   %al
  4019a7:	48 8b 5c 24 78       	mov    0x78(%rsp),%rbx
  4019ac:	64 48 33 1c 25 28 00 	xor    %fs:0x28,%rbx
  4019b3:	00 00 
  4019b5:	74 05                	je     4019bc <hexmatch+0xa5>
  4019b7:	e8 34 f3 ff ff       	callq  400cf0 <__stack_chk_fail@plt>
  4019bc:	0f b6 c0             	movzbl %al,%eax
  4019bf:	48 83 ec 80          	sub    $0xffffffffffffff80,%rsp
  4019c3:	5b                   	pop    %rbx
  4019c4:	5d                   	pop    %rbp
  4019c5:	41 5c                	pop    %r12
  4019c7:	c3                   	retq   

00000000004019c8 <touch3>:
  4019c8:	53                   	push   %rbx
  4019c9:	48 89 fb             	mov    %rdi,%rbx
  4019cc:	c7 05 46 3b 20 00 03 	movl   $0x3,0x203b46(%rip)        # 60551c <vlevel>
  4019d3:	00 00 00 
  4019d6:	48 89 fe             	mov    %rdi,%rsi
  4019d9:	8b 3d 45 3b 20 00    	mov    0x203b45(%rip),%edi        # 605524 <cookie>
  4019df:	e8 33 ff ff ff       	callq  401917 <hexmatch>
  4019e4:	85 c0                	test   %eax,%eax
  4019e6:	74 23                	je     401a0b <touch3+0x43>
  4019e8:	48 89 da             	mov    %rbx,%rdx
  4019eb:	be 68 33 40 00       	mov    $0x403368,%esi
  4019f0:	bf 01 00 00 00       	mov    $0x1,%edi
  4019f5:	b8 00 00 00 00       	mov    $0x0,%eax
  4019fa:	e8 01 f4 ff ff       	callq  400e00 <__printf_chk@plt>
  4019ff:	bf 03 00 00 00       	mov    $0x3,%edi
  401a04:	e8 5c 04 00 00       	callq  401e65 <validate>
  401a09:	eb 21                	jmp    401a2c <touch3+0x64>
  401a0b:	48 89 da             	mov    %rbx,%rdx
  401a0e:	be 90 33 40 00       	mov    $0x403390,%esi
  401a13:	bf 01 00 00 00       	mov    $0x1,%edi
  401a18:	b8 00 00 00 00       	mov    $0x0,%eax
  401a1d:	e8 de f3 ff ff       	callq  400e00 <__printf_chk@plt>
  401a22:	bf 03 00 00 00       	mov    $0x3,%edi
  401a27:	e8 fb 04 00 00       	callq  401f27 <fail>
  401a2c:	bf 00 00 00 00       	mov    $0x0,%edi
  401a31:	e8 1a f4 ff ff       	callq  400e50 <exit@plt>

0000000000401a36 <test>:
  401a36:	48 83 ec 08          	sub    $0x8,%rsp
  401a3a:	b8 00 00 00 00       	mov    $0x0,%eax
  401a3f:	e8 31 fe ff ff       	callq  401875 <getbuf>
  401a44:	89 c2                	mov    %eax,%edx
  401a46:	be b8 33 40 00       	mov    $0x4033b8,%esi
  401a4b:	bf 01 00 00 00       	mov    $0x1,%edi
  401a50:	b8 00 00 00 00       	mov    $0x0,%eax
  401a55:	e8 a6 f3 ff ff       	callq  400e00 <__printf_chk@plt>
  401a5a:	48 83 c4 08          	add    $0x8,%rsp
  401a5e:	c3                   	retq   

0000000000401a5f <start_farm>:
  401a5f:	b8 01 00 00 00       	mov    $0x1,%eax
  401a64:	c3                   	retq   

0000000000401a65 <getval_222>:
  401a65:	b8 48 89 c7 c3       	mov    $0xc3c78948,%eax
  401a6a:	c3                   	retq   

0000000000401a6b <setval_212>:
  401a6b:	c7 07 48 89 c7 c3    	movl   $0xc3c78948,(%rdi)
  401a71:	c3                   	retq   

0000000000401a72 <getval_214>:
  401a72:	b8 58 91 90 90       	mov    $0x90909158,%eax
  401a77:	c3                   	retq   

0000000000401a78 <setval_252>:
  401a78:	c7 07 48 89 c7 91    	movl   $0x91c78948,(%rdi)
  401a7e:	c3                   	retq   

0000000000401a7f <setval_495>:
  401a7f:	c7 07 40 89 c7 c3    	movl   $0xc3c78940,(%rdi)
  401a85:	c3                   	retq   

0000000000401a86 <getval_153>:
  401a86:	b8 d8 90 c3 24       	mov    $0x24c390d8,%eax
  401a8b:	c3                   	retq   

0000000000401a8c <addval_157>:
  401a8c:	8d 87 ed a5 58 90    	lea    -0x6fa75a13(%rdi),%eax
  401a92:	c3                   	retq   

0000000000401a93 <setval_451>:
  401a93:	c7 07 af 9d 58 c3    	movl   $0xc3589daf,(%rdi)
  401a99:	c3                   	retq   

0000000000401a9a <mid_farm>:
  401a9a:	b8 01 00 00 00       	mov    $0x1,%eax
  401a9f:	c3                   	retq   

0000000000401aa0 <add_xy>:
  401aa0:	48 8d 04 37          	lea    (%rdi,%rsi,1),%rax
  401aa4:	c3                   	retq   

0000000000401aa5 <setval_289>:
  401aa5:	c7 07 99 c1 90 90    	movl   $0x9090c199,(%rdi)
  401aab:	c3                   	retq   

0000000000401aac <setval_478>:
  401aac:	c7 07 89 ca c3 e3    	movl   $0xe3c3ca89,(%rdi)
  401ab2:	c3                   	retq   

0000000000401ab3 <addval_483>:
  401ab3:	8d 87 81 d6 38 d2    	lea    -0x2dc7297f(%rdi),%eax
  401ab9:	c3                   	retq   

0000000000401aba <addval_178>:
  401aba:	8d 87 89 c1 08 db    	lea    -0x24f73e77(%rdi),%eax
  401ac0:	c3                   	retq   

0000000000401ac1 <getval_101>:
  401ac1:	b8 ba 48 89 e0       	mov    $0xe08948ba,%eax
  401ac6:	c3                   	retq   

0000000000401ac7 <addval_216>:
  401ac7:	8d 87 89 d6 84 c0    	lea    -0x3f7b2977(%rdi),%eax
  401acd:	c3                   	retq   

0000000000401ace <addval_304>:
  401ace:	8d 87 a9 c1 08 db    	lea    -0x24f73e57(%rdi),%eax
  401ad4:	c3                   	retq   

0000000000401ad5 <addval_257>:
  401ad5:	8d 87 89 c1 60 db    	lea    -0x249f3e77(%rdi),%eax
  401adb:	c3                   	retq   

0000000000401adc <getval_326>:
  401adc:	b8 4d be 89 d6       	mov    $0xd689be4d,%eax
  401ae1:	c3                   	retq   

0000000000401ae2 <addval_259>:
  401ae2:	8d 87 88 ca 90 90    	lea    -0x6f6f3578(%rdi),%eax
  401ae8:	c3                   	retq   

0000000000401ae9 <setval_413>:
  401ae9:	c7 07 88 ca 84 c9    	movl   $0xc984ca88,(%rdi)
  401aef:	c3                   	retq   

0000000000401af0 <addval_255>:
  401af0:	8d 87 48 89 e0 91    	lea    -0x6e1f76b8(%rdi),%eax
  401af6:	c3                   	retq   

0000000000401af7 <addval_172>:
  401af7:	8d 87 81 c1 38 c9    	lea    -0x36c73e7f(%rdi),%eax
  401afd:	c3                   	retq   

0000000000401afe <getval_203>:
  401afe:	b8 8d c1 90 c3       	mov    $0xc390c18d,%eax
  401b03:	c3                   	retq   

0000000000401b04 <setval_448>:
  401b04:	c7 07 89 ca 92 90    	movl   $0x9092ca89,(%rdi)
  401b0a:	c3                   	retq   

0000000000401b0b <getval_376>:
  401b0b:	b8 e4 c8 89 e0       	mov    $0xe089c8e4,%eax
  401b10:	c3                   	retq   

0000000000401b11 <addval_309>:
  401b11:	8d 87 68 89 e0 c3    	lea    -0x3c1f7698(%rdi),%eax
  401b17:	c3                   	retq   

0000000000401b18 <getval_190>:
  401b18:	b8 89 d6 91 c3       	mov    $0xc391d689,%eax
  401b1d:	c3                   	retq   

0000000000401b1e <setval_455>:
  401b1e:	c7 07 89 d6 18 db    	movl   $0xdb18d689,(%rdi)
  401b24:	c3                   	retq   

0000000000401b25 <getval_486>:
  401b25:	b8 48 8b e0 90       	mov    $0x90e08b48,%eax
  401b2a:	c3                   	retq   

0000000000401b2b <addval_394>:
  401b2b:	8d 87 09 d6 90 c3    	lea    -0x3c6f29f7(%rdi),%eax
  401b31:	c3                   	retq   

0000000000401b32 <setval_273>:
  401b32:	c7 07 2b 48 89 e0    	movl   $0xe089482b,(%rdi)
  401b38:	c3                   	retq   

0000000000401b39 <setval_464>:
  401b39:	c7 07 89 c1 20 db    	movl   $0xdb20c189,(%rdi)
  401b3f:	c3                   	retq   

0000000000401b40 <addval_350>:
  401b40:	8d 87 89 ca 94 d2    	lea    -0x2d6b3577(%rdi),%eax
  401b46:	c3                   	retq   

0000000000401b47 <setval_351>:
  401b47:	c7 07 89 ca 38 c0    	movl   $0xc038ca89,(%rdi)
  401b4d:	c3                   	retq   

0000000000401b4e <addval_296>:
  401b4e:	8d 87 58 89 e0 90    	lea    -0x6f1f76a8(%rdi),%eax
  401b54:	c3                   	retq   

0000000000401b55 <getval_392>:
  401b55:	b8 b6 89 d6 91       	mov    $0x91d689b6,%eax
  401b5a:	c3                   	retq   

0000000000401b5b <getval_125>:
  401b5b:	b8 2d 4c 89 e0       	mov    $0xe0894c2d,%eax
  401b60:	c3                   	retq   

0000000000401b61 <getval_362>:
  401b61:	b8 c9 ca 20 d2       	mov    $0xd220cac9,%eax
  401b66:	c3                   	retq   

0000000000401b67 <getval_151>:
  401b67:	b8 8d ca 20 c9       	mov    $0xc920ca8d,%eax
  401b6c:	c3                   	retq   

0000000000401b6d <getval_410>:
  401b6d:	b8 89 d6 a4 c0       	mov    $0xc0a4d689,%eax
  401b72:	c3                   	retq   

0000000000401b73 <addval_417>:
  401b73:	8d 87 89 c1 78 d2    	lea    -0x2d873e77(%rdi),%eax
  401b79:	c3                   	retq   

0000000000401b7a <end_farm>:
  401b7a:	b8 01 00 00 00       	mov    $0x1,%eax
  401b7f:	c3                   	retq   

0000000000401b80 <save_char>:
  401b80:	8b 05 be 45 20 00    	mov    0x2045be(%rip),%eax        # 606144 <gets_cnt>
  401b86:	3d ff 03 00 00       	cmp    $0x3ff,%eax
  401b8b:	7f 49                	jg     401bd6 <save_char+0x56>
  401b8d:	8d 14 40             	lea    (%rax,%rax,2),%edx
  401b90:	89 f9                	mov    %edi,%ecx
  401b92:	c0 e9 04             	shr    $0x4,%cl
  401b95:	83 e1 0f             	and    $0xf,%ecx
  401b98:	0f b6 b1 e0 36 40 00 	movzbl 0x4036e0(%rcx),%esi
  401b9f:	48 63 ca             	movslq %edx,%rcx
  401ba2:	40 88 b1 40 55 60 00 	mov    %sil,0x605540(%rcx)
  401ba9:	8d 4a 01             	lea    0x1(%rdx),%ecx
  401bac:	83 e7 0f             	and    $0xf,%edi
  401baf:	0f b6 b7 e0 36 40 00 	movzbl 0x4036e0(%rdi),%esi
  401bb6:	48 63 c9             	movslq %ecx,%rcx
  401bb9:	40 88 b1 40 55 60 00 	mov    %sil,0x605540(%rcx)
  401bc0:	83 c2 02             	add    $0x2,%edx
  401bc3:	48 63 d2             	movslq %edx,%rdx
  401bc6:	c6 82 40 55 60 00 20 	movb   $0x20,0x605540(%rdx)
  401bcd:	83 c0 01             	add    $0x1,%eax
  401bd0:	89 05 6e 45 20 00    	mov    %eax,0x20456e(%rip)        # 606144 <gets_cnt>
  401bd6:	f3 c3                	repz retq 

0000000000401bd8 <save_term>:
  401bd8:	8b 05 66 45 20 00    	mov    0x204566(%rip),%eax        # 606144 <gets_cnt>
  401bde:	8d 04 40             	lea    (%rax,%rax,2),%eax
  401be1:	48 98                	cltq   
  401be3:	c6 80 40 55 60 00 00 	movb   $0x0,0x605540(%rax)
  401bea:	c3                   	retq   

0000000000401beb <check_fail>:
  401beb:	48 83 ec 08          	sub    $0x8,%rsp
  401bef:	0f be 15 52 45 20 00 	movsbl 0x204552(%rip),%edx        # 606148 <target_prefix>
  401bf6:	41 b8 40 55 60 00    	mov    $0x605540,%r8d
  401bfc:	8b 0d 16 39 20 00    	mov    0x203916(%rip),%ecx        # 605518 <check_level>
  401c02:	be db 33 40 00       	mov    $0x4033db,%esi
  401c07:	bf 01 00 00 00       	mov    $0x1,%edi
  401c0c:	b8 00 00 00 00       	mov    $0x0,%eax
  401c11:	e8 ea f1 ff ff       	callq  400e00 <__printf_chk@plt>
  401c16:	bf 01 00 00 00       	mov    $0x1,%edi
  401c1b:	e8 30 f2 ff ff       	callq  400e50 <exit@plt>

0000000000401c20 <Gets>:
  401c20:	41 54                	push   %r12
  401c22:	55                   	push   %rbp
  401c23:	53                   	push   %rbx
  401c24:	49 89 fc             	mov    %rdi,%r12
  401c27:	c7 05 13 45 20 00 00 	movl   $0x0,0x204513(%rip)        # 606144 <gets_cnt>
  401c2e:	00 00 00 
  401c31:	48 89 fb             	mov    %rdi,%rbx
  401c34:	eb 11                	jmp    401c47 <Gets+0x27>
  401c36:	48 8d 6b 01          	lea    0x1(%rbx),%rbp
  401c3a:	88 03                	mov    %al,(%rbx)
  401c3c:	0f b6 f8             	movzbl %al,%edi
  401c3f:	e8 3c ff ff ff       	callq  401b80 <save_char>
  401c44:	48 89 eb             	mov    %rbp,%rbx
  401c47:	48 8b 3d c2 38 20 00 	mov    0x2038c2(%rip),%rdi        # 605510 <infile>
  401c4e:	e8 7d f1 ff ff       	callq  400dd0 <_IO_getc@plt>
  401c53:	83 f8 ff             	cmp    $0xffffffff,%eax
  401c56:	74 05                	je     401c5d <Gets+0x3d>
  401c58:	83 f8 0a             	cmp    $0xa,%eax
  401c5b:	75 d9                	jne    401c36 <Gets+0x16>
  401c5d:	c6 03 00             	movb   $0x0,(%rbx)
  401c60:	b8 00 00 00 00       	mov    $0x0,%eax
  401c65:	e8 6e ff ff ff       	callq  401bd8 <save_term>
  401c6a:	4c 89 e0             	mov    %r12,%rax
  401c6d:	5b                   	pop    %rbx
  401c6e:	5d                   	pop    %rbp
  401c6f:	41 5c                	pop    %r12
  401c71:	c3                   	retq   

0000000000401c72 <notify_server>:
  401c72:	53                   	push   %rbx
  401c73:	48 81 ec 10 40 00 00 	sub    $0x4010,%rsp
  401c7a:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  401c81:	00 00 
  401c83:	48 89 84 24 08 40 00 	mov    %rax,0x4008(%rsp)
  401c8a:	00 
  401c8b:	31 c0                	xor    %eax,%eax
  401c8d:	83 3d 94 38 20 00 00 	cmpl   $0x0,0x203894(%rip)        # 605528 <is_checker>
  401c94:	0f 85 aa 01 00 00    	jne    401e44 <notify_server+0x1d2>
  401c9a:	89 fb                	mov    %edi,%ebx
  401c9c:	8b 05 a2 44 20 00    	mov    0x2044a2(%rip),%eax        # 606144 <gets_cnt>
  401ca2:	83 c0 64             	add    $0x64,%eax
  401ca5:	3d 00 20 00 00       	cmp    $0x2000,%eax
  401caa:	7e 1e                	jle    401cca <notify_server+0x58>
  401cac:	be 10 35 40 00       	mov    $0x403510,%esi
  401cb1:	bf 01 00 00 00       	mov    $0x1,%edi
  401cb6:	b8 00 00 00 00       	mov    $0x0,%eax
  401cbb:	e8 40 f1 ff ff       	callq  400e00 <__printf_chk@plt>
  401cc0:	bf 01 00 00 00       	mov    $0x1,%edi
  401cc5:	e8 86 f1 ff ff       	callq  400e50 <exit@plt>
  401cca:	0f be 05 77 44 20 00 	movsbl 0x204477(%rip),%eax        # 606148 <target_prefix>
  401cd1:	83 3d d0 37 20 00 00 	cmpl   $0x0,0x2037d0(%rip)        # 6054a8 <notify>
  401cd8:	74 08                	je     401ce2 <notify_server+0x70>
  401cda:	8b 15 40 38 20 00    	mov    0x203840(%rip),%edx        # 605520 <authkey>
  401ce0:	eb 05                	jmp    401ce7 <notify_server+0x75>
  401ce2:	ba ff ff ff ff       	mov    $0xffffffff,%edx
  401ce7:	85 db                	test   %ebx,%ebx
  401ce9:	74 08                	je     401cf3 <notify_server+0x81>
  401ceb:	41 b9 f1 33 40 00    	mov    $0x4033f1,%r9d
  401cf1:	eb 06                	jmp    401cf9 <notify_server+0x87>
  401cf3:	41 b9 f6 33 40 00    	mov    $0x4033f6,%r9d
  401cf9:	68 40 55 60 00       	pushq  $0x605540
  401cfe:	56                   	push   %rsi
  401cff:	50                   	push   %rax
  401d00:	52                   	push   %rdx
  401d01:	44 8b 05 60 34 20 00 	mov    0x203460(%rip),%r8d        # 605168 <target_id>
  401d08:	b9 fb 33 40 00       	mov    $0x4033fb,%ecx
  401d0d:	ba 00 20 00 00       	mov    $0x2000,%edx
  401d12:	be 01 00 00 00       	mov    $0x1,%esi
  401d17:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  401d1c:	b8 00 00 00 00       	mov    $0x0,%eax
  401d21:	e8 5a f1 ff ff       	callq  400e80 <__sprintf_chk@plt>
  401d26:	48 83 c4 20          	add    $0x20,%rsp
  401d2a:	83 3d 77 37 20 00 00 	cmpl   $0x0,0x203777(%rip)        # 6054a8 <notify>
  401d31:	0f 84 81 00 00 00    	je     401db8 <notify_server+0x146>
  401d37:	85 db                	test   %ebx,%ebx
  401d39:	74 6e                	je     401da9 <notify_server+0x137>
  401d3b:	4c 8d 8c 24 00 20 00 	lea    0x2000(%rsp),%r9
  401d42:	00 
  401d43:	41 b8 00 00 00 00    	mov    $0x0,%r8d
  401d49:	48 89 e1             	mov    %rsp,%rcx
  401d4c:	48 8b 15 1d 34 20 00 	mov    0x20341d(%rip),%rdx        # 605170 <lab>
  401d53:	48 8b 35 1e 34 20 00 	mov    0x20341e(%rip),%rsi        # 605178 <course>
  401d5a:	48 8b 3d ff 33 20 00 	mov    0x2033ff(%rip),%rdi        # 605160 <user_id>
  401d61:	e8 ef 10 00 00       	callq  402e55 <driver_post>
  401d66:	85 c0                	test   %eax,%eax
  401d68:	79 26                	jns    401d90 <notify_server+0x11e>
  401d6a:	48 8d 94 24 00 20 00 	lea    0x2000(%rsp),%rdx
  401d71:	00 
  401d72:	be 17 34 40 00       	mov    $0x403417,%esi
  401d77:	bf 01 00 00 00       	mov    $0x1,%edi
  401d7c:	b8 00 00 00 00       	mov    $0x0,%eax
  401d81:	e8 7a f0 ff ff       	callq  400e00 <__printf_chk@plt>
  401d86:	bf 01 00 00 00       	mov    $0x1,%edi
  401d8b:	e8 c0 f0 ff ff       	callq  400e50 <exit@plt>
  401d90:	bf 40 35 40 00       	mov    $0x403540,%edi
  401d95:	e8 36 ef ff ff       	callq  400cd0 <puts@plt>
  401d9a:	bf 23 34 40 00       	mov    $0x403423,%edi
  401d9f:	e8 2c ef ff ff       	callq  400cd0 <puts@plt>
  401da4:	e9 9b 00 00 00       	jmpq   401e44 <notify_server+0x1d2>
  401da9:	bf 2d 34 40 00       	mov    $0x40342d,%edi
  401dae:	e8 1d ef ff ff       	callq  400cd0 <puts@plt>
  401db3:	e9 8c 00 00 00       	jmpq   401e44 <notify_server+0x1d2>
  401db8:	85 db                	test   %ebx,%ebx
  401dba:	74 07                	je     401dc3 <notify_server+0x151>
  401dbc:	ba f1 33 40 00       	mov    $0x4033f1,%edx
  401dc1:	eb 05                	jmp    401dc8 <notify_server+0x156>
  401dc3:	ba f6 33 40 00       	mov    $0x4033f6,%edx
  401dc8:	be 78 35 40 00       	mov    $0x403578,%esi
  401dcd:	bf 01 00 00 00       	mov    $0x1,%edi
  401dd2:	b8 00 00 00 00       	mov    $0x0,%eax
  401dd7:	e8 24 f0 ff ff       	callq  400e00 <__printf_chk@plt>
  401ddc:	48 8b 15 7d 33 20 00 	mov    0x20337d(%rip),%rdx        # 605160 <user_id>
  401de3:	be 34 34 40 00       	mov    $0x403434,%esi
  401de8:	bf 01 00 00 00       	mov    $0x1,%edi
  401ded:	b8 00 00 00 00       	mov    $0x0,%eax
  401df2:	e8 09 f0 ff ff       	callq  400e00 <__printf_chk@plt>
  401df7:	48 8b 15 7a 33 20 00 	mov    0x20337a(%rip),%rdx        # 605178 <course>
  401dfe:	be 41 34 40 00       	mov    $0x403441,%esi
  401e03:	bf 01 00 00 00       	mov    $0x1,%edi
  401e08:	b8 00 00 00 00       	mov    $0x0,%eax
  401e0d:	e8 ee ef ff ff       	callq  400e00 <__printf_chk@plt>
  401e12:	48 8b 15 57 33 20 00 	mov    0x203357(%rip),%rdx        # 605170 <lab>
  401e19:	be 4d 34 40 00       	mov    $0x40344d,%esi
  401e1e:	bf 01 00 00 00       	mov    $0x1,%edi
  401e23:	b8 00 00 00 00       	mov    $0x0,%eax
  401e28:	e8 d3 ef ff ff       	callq  400e00 <__printf_chk@plt>
  401e2d:	48 89 e2             	mov    %rsp,%rdx
  401e30:	be 56 34 40 00       	mov    $0x403456,%esi
  401e35:	bf 01 00 00 00       	mov    $0x1,%edi
  401e3a:	b8 00 00 00 00       	mov    $0x0,%eax
  401e3f:	e8 bc ef ff ff       	callq  400e00 <__printf_chk@plt>
  401e44:	48 8b 84 24 08 40 00 	mov    0x4008(%rsp),%rax
  401e4b:	00 
  401e4c:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  401e53:	00 00 
  401e55:	74 05                	je     401e5c <notify_server+0x1ea>
  401e57:	e8 94 ee ff ff       	callq  400cf0 <__stack_chk_fail@plt>
  401e5c:	48 81 c4 10 40 00 00 	add    $0x4010,%rsp
  401e63:	5b                   	pop    %rbx
  401e64:	c3                   	retq   

0000000000401e65 <validate>:
  401e65:	53                   	push   %rbx
  401e66:	89 fb                	mov    %edi,%ebx
  401e68:	83 3d b9 36 20 00 00 	cmpl   $0x0,0x2036b9(%rip)        # 605528 <is_checker>
  401e6f:	74 6b                	je     401edc <validate+0x77>
  401e71:	39 3d a5 36 20 00    	cmp    %edi,0x2036a5(%rip)        # 60551c <vlevel>
  401e77:	74 14                	je     401e8d <validate+0x28>
  401e79:	bf 62 34 40 00       	mov    $0x403462,%edi
  401e7e:	e8 4d ee ff ff       	callq  400cd0 <puts@plt>
  401e83:	b8 00 00 00 00       	mov    $0x0,%eax
  401e88:	e8 5e fd ff ff       	callq  401beb <check_fail>
  401e8d:	8b 15 85 36 20 00    	mov    0x203685(%rip),%edx        # 605518 <check_level>
  401e93:	39 d7                	cmp    %edx,%edi
  401e95:	74 20                	je     401eb7 <validate+0x52>
  401e97:	89 f9                	mov    %edi,%ecx
  401e99:	be a0 35 40 00       	mov    $0x4035a0,%esi
  401e9e:	bf 01 00 00 00       	mov    $0x1,%edi
  401ea3:	b8 00 00 00 00       	mov    $0x0,%eax
  401ea8:	e8 53 ef ff ff       	callq  400e00 <__printf_chk@plt>
  401ead:	b8 00 00 00 00       	mov    $0x0,%eax
  401eb2:	e8 34 fd ff ff       	callq  401beb <check_fail>
  401eb7:	0f be 15 8a 42 20 00 	movsbl 0x20428a(%rip),%edx        # 606148 <target_prefix>
  401ebe:	41 b8 40 55 60 00    	mov    $0x605540,%r8d
  401ec4:	89 f9                	mov    %edi,%ecx
  401ec6:	be 80 34 40 00       	mov    $0x403480,%esi
  401ecb:	bf 01 00 00 00       	mov    $0x1,%edi
  401ed0:	b8 00 00 00 00       	mov    $0x0,%eax
  401ed5:	e8 26 ef ff ff       	callq  400e00 <__printf_chk@plt>
  401eda:	eb 49                	jmp    401f25 <validate+0xc0>
  401edc:	3b 3d 3a 36 20 00    	cmp    0x20363a(%rip),%edi        # 60551c <vlevel>
  401ee2:	74 18                	je     401efc <validate+0x97>
  401ee4:	bf 62 34 40 00       	mov    $0x403462,%edi
  401ee9:	e8 e2 ed ff ff       	callq  400cd0 <puts@plt>
  401eee:	89 de                	mov    %ebx,%esi
  401ef0:	bf 00 00 00 00       	mov    $0x0,%edi
  401ef5:	e8 78 fd ff ff       	callq  401c72 <notify_server>
  401efa:	eb 29                	jmp    401f25 <validate+0xc0>
  401efc:	0f be 0d 45 42 20 00 	movsbl 0x204245(%rip),%ecx        # 606148 <target_prefix>
  401f03:	89 fa                	mov    %edi,%edx
  401f05:	be c8 35 40 00       	mov    $0x4035c8,%esi
  401f0a:	bf 01 00 00 00       	mov    $0x1,%edi
  401f0f:	b8 00 00 00 00       	mov    $0x0,%eax
  401f14:	e8 e7 ee ff ff       	callq  400e00 <__printf_chk@plt>
  401f19:	89 de                	mov    %ebx,%esi
  401f1b:	bf 01 00 00 00       	mov    $0x1,%edi
  401f20:	e8 4d fd ff ff       	callq  401c72 <notify_server>
  401f25:	5b                   	pop    %rbx
  401f26:	c3                   	retq   

0000000000401f27 <fail>:
  401f27:	48 83 ec 08          	sub    $0x8,%rsp
  401f2b:	83 3d f6 35 20 00 00 	cmpl   $0x0,0x2035f6(%rip)        # 605528 <is_checker>
  401f32:	74 0a                	je     401f3e <fail+0x17>
  401f34:	b8 00 00 00 00       	mov    $0x0,%eax
  401f39:	e8 ad fc ff ff       	callq  401beb <check_fail>
  401f3e:	89 fe                	mov    %edi,%esi
  401f40:	bf 00 00 00 00       	mov    $0x0,%edi
  401f45:	e8 28 fd ff ff       	callq  401c72 <notify_server>
  401f4a:	48 83 c4 08          	add    $0x8,%rsp
  401f4e:	c3                   	retq   

0000000000401f4f <bushandler>:
  401f4f:	48 83 ec 08          	sub    $0x8,%rsp
  401f53:	83 3d ce 35 20 00 00 	cmpl   $0x0,0x2035ce(%rip)        # 605528 <is_checker>
  401f5a:	74 14                	je     401f70 <bushandler+0x21>
  401f5c:	bf 95 34 40 00       	mov    $0x403495,%edi
  401f61:	e8 6a ed ff ff       	callq  400cd0 <puts@plt>
  401f66:	b8 00 00 00 00       	mov    $0x0,%eax
  401f6b:	e8 7b fc ff ff       	callq  401beb <check_fail>
  401f70:	bf 00 36 40 00       	mov    $0x403600,%edi
  401f75:	e8 56 ed ff ff       	callq  400cd0 <puts@plt>
  401f7a:	bf 9f 34 40 00       	mov    $0x40349f,%edi
  401f7f:	e8 4c ed ff ff       	callq  400cd0 <puts@plt>
  401f84:	be 00 00 00 00       	mov    $0x0,%esi
  401f89:	bf 00 00 00 00       	mov    $0x0,%edi
  401f8e:	e8 df fc ff ff       	callq  401c72 <notify_server>
  401f93:	bf 01 00 00 00       	mov    $0x1,%edi
  401f98:	e8 b3 ee ff ff       	callq  400e50 <exit@plt>

0000000000401f9d <seghandler>:
  401f9d:	48 83 ec 08          	sub    $0x8,%rsp
  401fa1:	83 3d 80 35 20 00 00 	cmpl   $0x0,0x203580(%rip)        # 605528 <is_checker>
  401fa8:	74 14                	je     401fbe <seghandler+0x21>
  401faa:	bf b5 34 40 00       	mov    $0x4034b5,%edi
  401faf:	e8 1c ed ff ff       	callq  400cd0 <puts@plt>
  401fb4:	b8 00 00 00 00       	mov    $0x0,%eax
  401fb9:	e8 2d fc ff ff       	callq  401beb <check_fail>
  401fbe:	bf 20 36 40 00       	mov    $0x403620,%edi
  401fc3:	e8 08 ed ff ff       	callq  400cd0 <puts@plt>
  401fc8:	bf 9f 34 40 00       	mov    $0x40349f,%edi
  401fcd:	e8 fe ec ff ff       	callq  400cd0 <puts@plt>
  401fd2:	be 00 00 00 00       	mov    $0x0,%esi
  401fd7:	bf 00 00 00 00       	mov    $0x0,%edi
  401fdc:	e8 91 fc ff ff       	callq  401c72 <notify_server>
  401fe1:	bf 01 00 00 00       	mov    $0x1,%edi
  401fe6:	e8 65 ee ff ff       	callq  400e50 <exit@plt>

0000000000401feb <illegalhandler>:
  401feb:	48 83 ec 08          	sub    $0x8,%rsp
  401fef:	83 3d 32 35 20 00 00 	cmpl   $0x0,0x203532(%rip)        # 605528 <is_checker>
  401ff6:	74 14                	je     40200c <illegalhandler+0x21>
  401ff8:	bf c8 34 40 00       	mov    $0x4034c8,%edi
  401ffd:	e8 ce ec ff ff       	callq  400cd0 <puts@plt>
  402002:	b8 00 00 00 00       	mov    $0x0,%eax
  402007:	e8 df fb ff ff       	callq  401beb <check_fail>
  40200c:	bf 48 36 40 00       	mov    $0x403648,%edi
  402011:	e8 ba ec ff ff       	callq  400cd0 <puts@plt>
  402016:	bf 9f 34 40 00       	mov    $0x40349f,%edi
  40201b:	e8 b0 ec ff ff       	callq  400cd0 <puts@plt>
  402020:	be 00 00 00 00       	mov    $0x0,%esi
  402025:	bf 00 00 00 00       	mov    $0x0,%edi
  40202a:	e8 43 fc ff ff       	callq  401c72 <notify_server>
  40202f:	bf 01 00 00 00       	mov    $0x1,%edi
  402034:	e8 17 ee ff ff       	callq  400e50 <exit@plt>

0000000000402039 <sigalrmhandler>:
  402039:	48 83 ec 08          	sub    $0x8,%rsp
  40203d:	83 3d e4 34 20 00 00 	cmpl   $0x0,0x2034e4(%rip)        # 605528 <is_checker>
  402044:	74 14                	je     40205a <sigalrmhandler+0x21>
  402046:	bf dc 34 40 00       	mov    $0x4034dc,%edi
  40204b:	e8 80 ec ff ff       	callq  400cd0 <puts@plt>
  402050:	b8 00 00 00 00       	mov    $0x0,%eax
  402055:	e8 91 fb ff ff       	callq  401beb <check_fail>
  40205a:	ba 05 00 00 00       	mov    $0x5,%edx
  40205f:	be 78 36 40 00       	mov    $0x403678,%esi
  402064:	bf 01 00 00 00       	mov    $0x1,%edi
  402069:	b8 00 00 00 00       	mov    $0x0,%eax
  40206e:	e8 8d ed ff ff       	callq  400e00 <__printf_chk@plt>
  402073:	be 00 00 00 00       	mov    $0x0,%esi
  402078:	bf 00 00 00 00       	mov    $0x0,%edi
  40207d:	e8 f0 fb ff ff       	callq  401c72 <notify_server>
  402082:	bf 01 00 00 00       	mov    $0x1,%edi
  402087:	e8 c4 ed ff ff       	callq  400e50 <exit@plt>

000000000040208c <launch>:
  40208c:	55                   	push   %rbp
  40208d:	48 89 e5             	mov    %rsp,%rbp
  402090:	48 83 ec 10          	sub    $0x10,%rsp
  402094:	48 89 fa             	mov    %rdi,%rdx
  402097:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  40209e:	00 00 
  4020a0:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  4020a4:	31 c0                	xor    %eax,%eax
  4020a6:	48 8d 47 1e          	lea    0x1e(%rdi),%rax
  4020aa:	48 83 e0 f0          	and    $0xfffffffffffffff0,%rax
  4020ae:	48 29 c4             	sub    %rax,%rsp
  4020b1:	48 8d 7c 24 0f       	lea    0xf(%rsp),%rdi
  4020b6:	48 83 e7 f0          	and    $0xfffffffffffffff0,%rdi
  4020ba:	be f4 00 00 00       	mov    $0xf4,%esi
  4020bf:	e8 4c ec ff ff       	callq  400d10 <memset@plt>
  4020c4:	48 8b 05 f5 33 20 00 	mov    0x2033f5(%rip),%rax        # 6054c0 <stdin@@GLIBC_2.2.5>
  4020cb:	48 39 05 3e 34 20 00 	cmp    %rax,0x20343e(%rip)        # 605510 <infile>
  4020d2:	75 14                	jne    4020e8 <launch+0x5c>
  4020d4:	be e4 34 40 00       	mov    $0x4034e4,%esi
  4020d9:	bf 01 00 00 00       	mov    $0x1,%edi
  4020de:	b8 00 00 00 00       	mov    $0x0,%eax
  4020e3:	e8 18 ed ff ff       	callq  400e00 <__printf_chk@plt>
  4020e8:	c7 05 2a 34 20 00 00 	movl   $0x0,0x20342a(%rip)        # 60551c <vlevel>
  4020ef:	00 00 00 
  4020f2:	b8 00 00 00 00       	mov    $0x0,%eax
  4020f7:	e8 3a f9 ff ff       	callq  401a36 <test>
  4020fc:	83 3d 25 34 20 00 00 	cmpl   $0x0,0x203425(%rip)        # 605528 <is_checker>
  402103:	74 14                	je     402119 <launch+0x8d>
  402105:	bf f1 34 40 00       	mov    $0x4034f1,%edi
  40210a:	e8 c1 eb ff ff       	callq  400cd0 <puts@plt>
  40210f:	b8 00 00 00 00       	mov    $0x0,%eax
  402114:	e8 d2 fa ff ff       	callq  401beb <check_fail>
  402119:	bf fc 34 40 00       	mov    $0x4034fc,%edi
  40211e:	e8 ad eb ff ff       	callq  400cd0 <puts@plt>
  402123:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  402127:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  40212e:	00 00 
  402130:	74 05                	je     402137 <launch+0xab>
  402132:	e8 b9 eb ff ff       	callq  400cf0 <__stack_chk_fail@plt>
  402137:	c9                   	leaveq 
  402138:	c3                   	retq   

0000000000402139 <stable_launch>:
  402139:	53                   	push   %rbx
  40213a:	48 89 3d c7 33 20 00 	mov    %rdi,0x2033c7(%rip)        # 605508 <global_offset>
  402141:	41 b9 00 00 00 00    	mov    $0x0,%r9d
  402147:	41 b8 00 00 00 00    	mov    $0x0,%r8d
  40214d:	b9 32 01 00 00       	mov    $0x132,%ecx
  402152:	ba 07 00 00 00       	mov    $0x7,%edx
  402157:	be 00 00 10 00       	mov    $0x100000,%esi
  40215c:	bf 00 60 58 55       	mov    $0x55586000,%edi
  402161:	e8 9a eb ff ff       	callq  400d00 <mmap@plt>
  402166:	48 89 c3             	mov    %rax,%rbx
  402169:	48 3d 00 60 58 55    	cmp    $0x55586000,%rax
  40216f:	74 37                	je     4021a8 <stable_launch+0x6f>
  402171:	be 00 00 10 00       	mov    $0x100000,%esi
  402176:	48 89 c7             	mov    %rax,%rdi
  402179:	e8 72 ec ff ff       	callq  400df0 <munmap@plt>
  40217e:	b9 00 60 58 55       	mov    $0x55586000,%ecx
  402183:	ba b0 36 40 00       	mov    $0x4036b0,%edx
  402188:	be 01 00 00 00       	mov    $0x1,%esi
  40218d:	48 8b 3d 4c 33 20 00 	mov    0x20334c(%rip),%rdi        # 6054e0 <stderr@@GLIBC_2.2.5>
  402194:	b8 00 00 00 00       	mov    $0x0,%eax
  402199:	e8 d2 ec ff ff       	callq  400e70 <__fprintf_chk@plt>
  40219e:	bf 01 00 00 00       	mov    $0x1,%edi
  4021a3:	e8 a8 ec ff ff       	callq  400e50 <exit@plt>
  4021a8:	48 8d 90 f8 ff 0f 00 	lea    0xffff8(%rax),%rdx
  4021af:	48 89 15 9a 3f 20 00 	mov    %rdx,0x203f9a(%rip)        # 606150 <stack_top>
  4021b6:	48 89 e0             	mov    %rsp,%rax
  4021b9:	48 89 d4             	mov    %rdx,%rsp
  4021bc:	48 89 c2             	mov    %rax,%rdx
  4021bf:	48 89 15 3a 33 20 00 	mov    %rdx,0x20333a(%rip)        # 605500 <global_save_stack>
  4021c6:	48 8b 3d 3b 33 20 00 	mov    0x20333b(%rip),%rdi        # 605508 <global_offset>
  4021cd:	e8 ba fe ff ff       	callq  40208c <launch>
  4021d2:	48 8b 05 27 33 20 00 	mov    0x203327(%rip),%rax        # 605500 <global_save_stack>
  4021d9:	48 89 c4             	mov    %rax,%rsp
  4021dc:	be 00 00 10 00       	mov    $0x100000,%esi
  4021e1:	48 89 df             	mov    %rbx,%rdi
  4021e4:	e8 07 ec ff ff       	callq  400df0 <munmap@plt>
  4021e9:	5b                   	pop    %rbx
  4021ea:	c3                   	retq   

00000000004021eb <rio_readinitb>:
  4021eb:	89 37                	mov    %esi,(%rdi)
  4021ed:	c7 47 04 00 00 00 00 	movl   $0x0,0x4(%rdi)
  4021f4:	48 8d 47 10          	lea    0x10(%rdi),%rax
  4021f8:	48 89 47 08          	mov    %rax,0x8(%rdi)
  4021fc:	c3                   	retq   

00000000004021fd <sigalrm_handler>:
  4021fd:	48 83 ec 08          	sub    $0x8,%rsp
  402201:	b9 00 00 00 00       	mov    $0x0,%ecx
  402206:	ba f0 36 40 00       	mov    $0x4036f0,%edx
  40220b:	be 01 00 00 00       	mov    $0x1,%esi
  402210:	48 8b 3d c9 32 20 00 	mov    0x2032c9(%rip),%rdi        # 6054e0 <stderr@@GLIBC_2.2.5>
  402217:	b8 00 00 00 00       	mov    $0x0,%eax
  40221c:	e8 4f ec ff ff       	callq  400e70 <__fprintf_chk@plt>
  402221:	bf 01 00 00 00       	mov    $0x1,%edi
  402226:	e8 25 ec ff ff       	callq  400e50 <exit@plt>

000000000040222b <rio_writen>:
  40222b:	41 55                	push   %r13
  40222d:	41 54                	push   %r12
  40222f:	55                   	push   %rbp
  402230:	53                   	push   %rbx
  402231:	48 83 ec 08          	sub    $0x8,%rsp
  402235:	41 89 fc             	mov    %edi,%r12d
  402238:	48 89 f5             	mov    %rsi,%rbp
  40223b:	49 89 d5             	mov    %rdx,%r13
  40223e:	48 89 d3             	mov    %rdx,%rbx
  402241:	eb 28                	jmp    40226b <rio_writen+0x40>
  402243:	48 89 da             	mov    %rbx,%rdx
  402246:	48 89 ee             	mov    %rbp,%rsi
  402249:	44 89 e7             	mov    %r12d,%edi
  40224c:	e8 8f ea ff ff       	callq  400ce0 <write@plt>
  402251:	48 85 c0             	test   %rax,%rax
  402254:	7f 0f                	jg     402265 <rio_writen+0x3a>
  402256:	e8 35 ea ff ff       	callq  400c90 <__errno_location@plt>
  40225b:	83 38 04             	cmpl   $0x4,(%rax)
  40225e:	75 15                	jne    402275 <rio_writen+0x4a>
  402260:	b8 00 00 00 00       	mov    $0x0,%eax
  402265:	48 29 c3             	sub    %rax,%rbx
  402268:	48 01 c5             	add    %rax,%rbp
  40226b:	48 85 db             	test   %rbx,%rbx
  40226e:	75 d3                	jne    402243 <rio_writen+0x18>
  402270:	4c 89 e8             	mov    %r13,%rax
  402273:	eb 07                	jmp    40227c <rio_writen+0x51>
  402275:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
  40227c:	48 83 c4 08          	add    $0x8,%rsp
  402280:	5b                   	pop    %rbx
  402281:	5d                   	pop    %rbp
  402282:	41 5c                	pop    %r12
  402284:	41 5d                	pop    %r13
  402286:	c3                   	retq   

0000000000402287 <rio_read>:
  402287:	41 55                	push   %r13
  402289:	41 54                	push   %r12
  40228b:	55                   	push   %rbp
  40228c:	53                   	push   %rbx
  40228d:	48 83 ec 08          	sub    $0x8,%rsp
  402291:	48 89 fb             	mov    %rdi,%rbx
  402294:	49 89 f5             	mov    %rsi,%r13
  402297:	49 89 d4             	mov    %rdx,%r12
  40229a:	eb 2e                	jmp    4022ca <rio_read+0x43>
  40229c:	48 8d 6b 10          	lea    0x10(%rbx),%rbp
  4022a0:	8b 3b                	mov    (%rbx),%edi
  4022a2:	ba 00 20 00 00       	mov    $0x2000,%edx
  4022a7:	48 89 ee             	mov    %rbp,%rsi
  4022aa:	e8 91 ea ff ff       	callq  400d40 <read@plt>
  4022af:	89 43 04             	mov    %eax,0x4(%rbx)
  4022b2:	85 c0                	test   %eax,%eax
  4022b4:	79 0c                	jns    4022c2 <rio_read+0x3b>
  4022b6:	e8 d5 e9 ff ff       	callq  400c90 <__errno_location@plt>
  4022bb:	83 38 04             	cmpl   $0x4,(%rax)
  4022be:	74 0a                	je     4022ca <rio_read+0x43>
  4022c0:	eb 37                	jmp    4022f9 <rio_read+0x72>
  4022c2:	85 c0                	test   %eax,%eax
  4022c4:	74 3c                	je     402302 <rio_read+0x7b>
  4022c6:	48 89 6b 08          	mov    %rbp,0x8(%rbx)
  4022ca:	8b 6b 04             	mov    0x4(%rbx),%ebp
  4022cd:	85 ed                	test   %ebp,%ebp
  4022cf:	7e cb                	jle    40229c <rio_read+0x15>
  4022d1:	89 e8                	mov    %ebp,%eax
  4022d3:	49 39 c4             	cmp    %rax,%r12
  4022d6:	77 03                	ja     4022db <rio_read+0x54>
  4022d8:	44 89 e5             	mov    %r12d,%ebp
  4022db:	4c 63 e5             	movslq %ebp,%r12
  4022de:	48 8b 73 08          	mov    0x8(%rbx),%rsi
  4022e2:	4c 89 e2             	mov    %r12,%rdx
  4022e5:	4c 89 ef             	mov    %r13,%rdi
  4022e8:	e8 b3 ea ff ff       	callq  400da0 <memcpy@plt>
  4022ed:	4c 01 63 08          	add    %r12,0x8(%rbx)
  4022f1:	29 6b 04             	sub    %ebp,0x4(%rbx)
  4022f4:	4c 89 e0             	mov    %r12,%rax
  4022f7:	eb 0e                	jmp    402307 <rio_read+0x80>
  4022f9:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
  402300:	eb 05                	jmp    402307 <rio_read+0x80>
  402302:	b8 00 00 00 00       	mov    $0x0,%eax
  402307:	48 83 c4 08          	add    $0x8,%rsp
  40230b:	5b                   	pop    %rbx
  40230c:	5d                   	pop    %rbp
  40230d:	41 5c                	pop    %r12
  40230f:	41 5d                	pop    %r13
  402311:	c3                   	retq   

0000000000402312 <rio_readlineb>:
  402312:	41 55                	push   %r13
  402314:	41 54                	push   %r12
  402316:	55                   	push   %rbp
  402317:	53                   	push   %rbx
  402318:	48 83 ec 18          	sub    $0x18,%rsp
  40231c:	49 89 fd             	mov    %rdi,%r13
  40231f:	48 89 f5             	mov    %rsi,%rbp
  402322:	49 89 d4             	mov    %rdx,%r12
  402325:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  40232c:	00 00 
  40232e:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
  402333:	31 c0                	xor    %eax,%eax
  402335:	bb 01 00 00 00       	mov    $0x1,%ebx
  40233a:	eb 3f                	jmp    40237b <rio_readlineb+0x69>
  40233c:	ba 01 00 00 00       	mov    $0x1,%edx
  402341:	48 8d 74 24 07       	lea    0x7(%rsp),%rsi
  402346:	4c 89 ef             	mov    %r13,%rdi
  402349:	e8 39 ff ff ff       	callq  402287 <rio_read>
  40234e:	83 f8 01             	cmp    $0x1,%eax
  402351:	75 15                	jne    402368 <rio_readlineb+0x56>
  402353:	48 8d 45 01          	lea    0x1(%rbp),%rax
  402357:	0f b6 54 24 07       	movzbl 0x7(%rsp),%edx
  40235c:	88 55 00             	mov    %dl,0x0(%rbp)
  40235f:	80 7c 24 07 0a       	cmpb   $0xa,0x7(%rsp)
  402364:	75 0e                	jne    402374 <rio_readlineb+0x62>
  402366:	eb 1a                	jmp    402382 <rio_readlineb+0x70>
  402368:	85 c0                	test   %eax,%eax
  40236a:	75 22                	jne    40238e <rio_readlineb+0x7c>
  40236c:	48 83 fb 01          	cmp    $0x1,%rbx
  402370:	75 13                	jne    402385 <rio_readlineb+0x73>
  402372:	eb 23                	jmp    402397 <rio_readlineb+0x85>
  402374:	48 83 c3 01          	add    $0x1,%rbx
  402378:	48 89 c5             	mov    %rax,%rbp
  40237b:	4c 39 e3             	cmp    %r12,%rbx
  40237e:	72 bc                	jb     40233c <rio_readlineb+0x2a>
  402380:	eb 03                	jmp    402385 <rio_readlineb+0x73>
  402382:	48 89 c5             	mov    %rax,%rbp
  402385:	c6 45 00 00          	movb   $0x0,0x0(%rbp)
  402389:	48 89 d8             	mov    %rbx,%rax
  40238c:	eb 0e                	jmp    40239c <rio_readlineb+0x8a>
  40238e:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
  402395:	eb 05                	jmp    40239c <rio_readlineb+0x8a>
  402397:	b8 00 00 00 00       	mov    $0x0,%eax
  40239c:	48 8b 4c 24 08       	mov    0x8(%rsp),%rcx
  4023a1:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
  4023a8:	00 00 
  4023aa:	74 05                	je     4023b1 <rio_readlineb+0x9f>
  4023ac:	e8 3f e9 ff ff       	callq  400cf0 <__stack_chk_fail@plt>
  4023b1:	48 83 c4 18          	add    $0x18,%rsp
  4023b5:	5b                   	pop    %rbx
  4023b6:	5d                   	pop    %rbp
  4023b7:	41 5c                	pop    %r12
  4023b9:	41 5d                	pop    %r13
  4023bb:	c3                   	retq   

00000000004023bc <urlencode>:
  4023bc:	41 54                	push   %r12
  4023be:	55                   	push   %rbp
  4023bf:	53                   	push   %rbx
  4023c0:	48 83 ec 10          	sub    $0x10,%rsp
  4023c4:	48 89 fb             	mov    %rdi,%rbx
  4023c7:	48 89 f5             	mov    %rsi,%rbp
  4023ca:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  4023d1:	00 00 
  4023d3:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
  4023d8:	31 c0                	xor    %eax,%eax
  4023da:	48 c7 c1 ff ff ff ff 	mov    $0xffffffffffffffff,%rcx
  4023e1:	f2 ae                	repnz scas %es:(%rdi),%al
  4023e3:	48 f7 d1             	not    %rcx
  4023e6:	8d 41 ff             	lea    -0x1(%rcx),%eax
  4023e9:	e9 aa 00 00 00       	jmpq   402498 <urlencode+0xdc>
  4023ee:	44 0f b6 03          	movzbl (%rbx),%r8d
  4023f2:	41 80 f8 2a          	cmp    $0x2a,%r8b
  4023f6:	0f 94 c2             	sete   %dl
  4023f9:	41 80 f8 2d          	cmp    $0x2d,%r8b
  4023fd:	0f 94 c0             	sete   %al
  402400:	08 c2                	or     %al,%dl
  402402:	75 24                	jne    402428 <urlencode+0x6c>
  402404:	41 80 f8 2e          	cmp    $0x2e,%r8b
  402408:	74 1e                	je     402428 <urlencode+0x6c>
  40240a:	41 80 f8 5f          	cmp    $0x5f,%r8b
  40240e:	74 18                	je     402428 <urlencode+0x6c>
  402410:	41 8d 40 d0          	lea    -0x30(%r8),%eax
  402414:	3c 09                	cmp    $0x9,%al
  402416:	76 10                	jbe    402428 <urlencode+0x6c>
  402418:	41 8d 40 bf          	lea    -0x41(%r8),%eax
  40241c:	3c 19                	cmp    $0x19,%al
  40241e:	76 08                	jbe    402428 <urlencode+0x6c>
  402420:	41 8d 40 9f          	lea    -0x61(%r8),%eax
  402424:	3c 19                	cmp    $0x19,%al
  402426:	77 0a                	ja     402432 <urlencode+0x76>
  402428:	44 88 45 00          	mov    %r8b,0x0(%rbp)
  40242c:	48 8d 6d 01          	lea    0x1(%rbp),%rbp
  402430:	eb 5f                	jmp    402491 <urlencode+0xd5>
  402432:	41 80 f8 20          	cmp    $0x20,%r8b
  402436:	75 0a                	jne    402442 <urlencode+0x86>
  402438:	c6 45 00 2b          	movb   $0x2b,0x0(%rbp)
  40243c:	48 8d 6d 01          	lea    0x1(%rbp),%rbp
  402440:	eb 4f                	jmp    402491 <urlencode+0xd5>
  402442:	41 8d 40 e0          	lea    -0x20(%r8),%eax
  402446:	3c 5f                	cmp    $0x5f,%al
  402448:	0f 96 c2             	setbe  %dl
  40244b:	41 80 f8 09          	cmp    $0x9,%r8b
  40244f:	0f 94 c0             	sete   %al
  402452:	08 c2                	or     %al,%dl
  402454:	74 50                	je     4024a6 <urlencode+0xea>
  402456:	45 0f b6 c0          	movzbl %r8b,%r8d
  40245a:	b9 88 37 40 00       	mov    $0x403788,%ecx
  40245f:	ba 08 00 00 00       	mov    $0x8,%edx
  402464:	be 01 00 00 00       	mov    $0x1,%esi
  402469:	48 89 e7             	mov    %rsp,%rdi
  40246c:	b8 00 00 00 00       	mov    $0x0,%eax
  402471:	e8 0a ea ff ff       	callq  400e80 <__sprintf_chk@plt>
  402476:	0f b6 04 24          	movzbl (%rsp),%eax
  40247a:	88 45 00             	mov    %al,0x0(%rbp)
  40247d:	0f b6 44 24 01       	movzbl 0x1(%rsp),%eax
  402482:	88 45 01             	mov    %al,0x1(%rbp)
  402485:	0f b6 44 24 02       	movzbl 0x2(%rsp),%eax
  40248a:	88 45 02             	mov    %al,0x2(%rbp)
  40248d:	48 8d 6d 03          	lea    0x3(%rbp),%rbp
  402491:	48 83 c3 01          	add    $0x1,%rbx
  402495:	44 89 e0             	mov    %r12d,%eax
  402498:	44 8d 60 ff          	lea    -0x1(%rax),%r12d
  40249c:	85 c0                	test   %eax,%eax
  40249e:	0f 85 4a ff ff ff    	jne    4023ee <urlencode+0x32>
  4024a4:	eb 05                	jmp    4024ab <urlencode+0xef>
  4024a6:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  4024ab:	48 8b 74 24 08       	mov    0x8(%rsp),%rsi
  4024b0:	64 48 33 34 25 28 00 	xor    %fs:0x28,%rsi
  4024b7:	00 00 
  4024b9:	74 05                	je     4024c0 <urlencode+0x104>
  4024bb:	e8 30 e8 ff ff       	callq  400cf0 <__stack_chk_fail@plt>
  4024c0:	48 83 c4 10          	add    $0x10,%rsp
  4024c4:	5b                   	pop    %rbx
  4024c5:	5d                   	pop    %rbp
  4024c6:	41 5c                	pop    %r12
  4024c8:	c3                   	retq   

00000000004024c9 <submitr>:
  4024c9:	41 57                	push   %r15
  4024cb:	41 56                	push   %r14
  4024cd:	41 55                	push   %r13
  4024cf:	41 54                	push   %r12
  4024d1:	55                   	push   %rbp
  4024d2:	53                   	push   %rbx
  4024d3:	48 81 ec 58 a0 00 00 	sub    $0xa058,%rsp
  4024da:	49 89 fc             	mov    %rdi,%r12
  4024dd:	89 74 24 04          	mov    %esi,0x4(%rsp)
  4024e1:	49 89 d7             	mov    %rdx,%r15
  4024e4:	49 89 ce             	mov    %rcx,%r14
  4024e7:	4c 89 44 24 08       	mov    %r8,0x8(%rsp)
  4024ec:	4d 89 cd             	mov    %r9,%r13
  4024ef:	48 8b 9c 24 90 a0 00 	mov    0xa090(%rsp),%rbx
  4024f6:	00 
  4024f7:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  4024fe:	00 00 
  402500:	48 89 84 24 48 a0 00 	mov    %rax,0xa048(%rsp)
  402507:	00 
  402508:	31 c0                	xor    %eax,%eax
  40250a:	c7 44 24 1c 00 00 00 	movl   $0x0,0x1c(%rsp)
  402511:	00 
  402512:	ba 00 00 00 00       	mov    $0x0,%edx
  402517:	be 01 00 00 00       	mov    $0x1,%esi
  40251c:	bf 02 00 00 00       	mov    $0x2,%edi
  402521:	e8 6a e9 ff ff       	callq  400e90 <socket@plt>
  402526:	85 c0                	test   %eax,%eax
  402528:	79 4e                	jns    402578 <submitr+0xaf>
  40252a:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  402531:	3a 20 43 
  402534:	48 89 03             	mov    %rax,(%rbx)
  402537:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  40253e:	20 75 6e 
  402541:	48 89 43 08          	mov    %rax,0x8(%rbx)
  402545:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  40254c:	74 6f 20 
  40254f:	48 89 43 10          	mov    %rax,0x10(%rbx)
  402553:	48 b8 63 72 65 61 74 	movabs $0x7320657461657263,%rax
  40255a:	65 20 73 
  40255d:	48 89 43 18          	mov    %rax,0x18(%rbx)
  402561:	c7 43 20 6f 63 6b 65 	movl   $0x656b636f,0x20(%rbx)
  402568:	66 c7 43 24 74 00    	movw   $0x74,0x24(%rbx)
  40256e:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402573:	e9 97 06 00 00       	jmpq   402c0f <submitr+0x746>
  402578:	89 c5                	mov    %eax,%ebp
  40257a:	4c 89 e7             	mov    %r12,%rdi
  40257d:	e8 ee e7 ff ff       	callq  400d70 <gethostbyname@plt>
  402582:	48 85 c0             	test   %rax,%rax
  402585:	75 67                	jne    4025ee <submitr+0x125>
  402587:	48 b8 45 72 72 6f 72 	movabs $0x44203a726f727245,%rax
  40258e:	3a 20 44 
  402591:	48 89 03             	mov    %rax,(%rbx)
  402594:	48 b8 4e 53 20 69 73 	movabs $0x6e7520736920534e,%rax
  40259b:	20 75 6e 
  40259e:	48 89 43 08          	mov    %rax,0x8(%rbx)
  4025a2:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  4025a9:	74 6f 20 
  4025ac:	48 89 43 10          	mov    %rax,0x10(%rbx)
  4025b0:	48 b8 72 65 73 6f 6c 	movabs $0x2065766c6f736572,%rax
  4025b7:	76 65 20 
  4025ba:	48 89 43 18          	mov    %rax,0x18(%rbx)
  4025be:	48 b8 73 65 72 76 65 	movabs $0x6120726576726573,%rax
  4025c5:	72 20 61 
  4025c8:	48 89 43 20          	mov    %rax,0x20(%rbx)
  4025cc:	c7 43 28 64 64 72 65 	movl   $0x65726464,0x28(%rbx)
  4025d3:	66 c7 43 2c 73 73    	movw   $0x7373,0x2c(%rbx)
  4025d9:	c6 43 2e 00          	movb   $0x0,0x2e(%rbx)
  4025dd:	89 ef                	mov    %ebp,%edi
  4025df:	e8 4c e7 ff ff       	callq  400d30 <close@plt>
  4025e4:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  4025e9:	e9 21 06 00 00       	jmpq   402c0f <submitr+0x746>
  4025ee:	48 c7 44 24 20 00 00 	movq   $0x0,0x20(%rsp)
  4025f5:	00 00 
  4025f7:	48 c7 44 24 28 00 00 	movq   $0x0,0x28(%rsp)
  4025fe:	00 00 
  402600:	66 c7 44 24 20 02 00 	movw   $0x2,0x20(%rsp)
  402607:	48 63 50 14          	movslq 0x14(%rax),%rdx
  40260b:	48 8b 40 18          	mov    0x18(%rax),%rax
  40260f:	48 8b 30             	mov    (%rax),%rsi
  402612:	48 8d 7c 24 24       	lea    0x24(%rsp),%rdi
  402617:	b9 0c 00 00 00       	mov    $0xc,%ecx
  40261c:	e8 5f e7 ff ff       	callq  400d80 <__memmove_chk@plt>
  402621:	0f b7 44 24 04       	movzwl 0x4(%rsp),%eax
  402626:	66 c1 c8 08          	ror    $0x8,%ax
  40262a:	66 89 44 24 22       	mov    %ax,0x22(%rsp)
  40262f:	ba 10 00 00 00       	mov    $0x10,%edx
  402634:	48 8d 74 24 20       	lea    0x20(%rsp),%rsi
  402639:	89 ef                	mov    %ebp,%edi
  40263b:	e8 20 e8 ff ff       	callq  400e60 <connect@plt>
  402640:	85 c0                	test   %eax,%eax
  402642:	79 59                	jns    40269d <submitr+0x1d4>
  402644:	48 b8 45 72 72 6f 72 	movabs $0x55203a726f727245,%rax
  40264b:	3a 20 55 
  40264e:	48 89 03             	mov    %rax,(%rbx)
  402651:	48 b8 6e 61 62 6c 65 	movabs $0x6f7420656c62616e,%rax
  402658:	20 74 6f 
  40265b:	48 89 43 08          	mov    %rax,0x8(%rbx)
  40265f:	48 b8 20 63 6f 6e 6e 	movabs $0x7463656e6e6f6320,%rax
  402666:	65 63 74 
  402669:	48 89 43 10          	mov    %rax,0x10(%rbx)
  40266d:	48 b8 20 74 6f 20 74 	movabs $0x20656874206f7420,%rax
  402674:	68 65 20 
  402677:	48 89 43 18          	mov    %rax,0x18(%rbx)
  40267b:	c7 43 20 73 65 72 76 	movl   $0x76726573,0x20(%rbx)
  402682:	66 c7 43 24 65 72    	movw   $0x7265,0x24(%rbx)
  402688:	c6 43 26 00          	movb   $0x0,0x26(%rbx)
  40268c:	89 ef                	mov    %ebp,%edi
  40268e:	e8 9d e6 ff ff       	callq  400d30 <close@plt>
  402693:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402698:	e9 72 05 00 00       	jmpq   402c0f <submitr+0x746>
  40269d:	48 c7 c6 ff ff ff ff 	mov    $0xffffffffffffffff,%rsi
  4026a4:	b8 00 00 00 00       	mov    $0x0,%eax
  4026a9:	48 89 f1             	mov    %rsi,%rcx
  4026ac:	4c 89 ef             	mov    %r13,%rdi
  4026af:	f2 ae                	repnz scas %es:(%rdi),%al
  4026b1:	48 f7 d1             	not    %rcx
  4026b4:	48 89 ca             	mov    %rcx,%rdx
  4026b7:	48 89 f1             	mov    %rsi,%rcx
  4026ba:	4c 89 ff             	mov    %r15,%rdi
  4026bd:	f2 ae                	repnz scas %es:(%rdi),%al
  4026bf:	48 f7 d1             	not    %rcx
  4026c2:	49 89 c8             	mov    %rcx,%r8
  4026c5:	48 89 f1             	mov    %rsi,%rcx
  4026c8:	4c 89 f7             	mov    %r14,%rdi
  4026cb:	f2 ae                	repnz scas %es:(%rdi),%al
  4026cd:	48 f7 d1             	not    %rcx
  4026d0:	4d 8d 44 08 fe       	lea    -0x2(%r8,%rcx,1),%r8
  4026d5:	48 89 f1             	mov    %rsi,%rcx
  4026d8:	48 8b 7c 24 08       	mov    0x8(%rsp),%rdi
  4026dd:	f2 ae                	repnz scas %es:(%rdi),%al
  4026df:	48 89 c8             	mov    %rcx,%rax
  4026e2:	48 f7 d0             	not    %rax
  4026e5:	49 8d 4c 00 ff       	lea    -0x1(%r8,%rax,1),%rcx
  4026ea:	48 8d 44 52 fd       	lea    -0x3(%rdx,%rdx,2),%rax
  4026ef:	48 8d 84 01 80 00 00 	lea    0x80(%rcx,%rax,1),%rax
  4026f6:	00 
  4026f7:	48 3d 00 20 00 00    	cmp    $0x2000,%rax
  4026fd:	76 72                	jbe    402771 <submitr+0x2a8>
  4026ff:	48 b8 45 72 72 6f 72 	movabs $0x52203a726f727245,%rax
  402706:	3a 20 52 
  402709:	48 89 03             	mov    %rax,(%rbx)
  40270c:	48 b8 65 73 75 6c 74 	movabs $0x747320746c757365,%rax
  402713:	20 73 74 
  402716:	48 89 43 08          	mov    %rax,0x8(%rbx)
  40271a:	48 b8 72 69 6e 67 20 	movabs $0x6f6f7420676e6972,%rax
  402721:	74 6f 6f 
  402724:	48 89 43 10          	mov    %rax,0x10(%rbx)
  402728:	48 b8 20 6c 61 72 67 	movabs $0x202e656772616c20,%rax
  40272f:	65 2e 20 
  402732:	48 89 43 18          	mov    %rax,0x18(%rbx)
  402736:	48 b8 49 6e 63 72 65 	movabs $0x6573616572636e49,%rax
  40273d:	61 73 65 
  402740:	48 89 43 20          	mov    %rax,0x20(%rbx)
  402744:	48 b8 20 53 55 42 4d 	movabs $0x5254494d42555320,%rax
  40274b:	49 54 52 
  40274e:	48 89 43 28          	mov    %rax,0x28(%rbx)
  402752:	48 b8 5f 4d 41 58 42 	movabs $0x46554258414d5f,%rax
  402759:	55 46 00 
  40275c:	48 89 43 30          	mov    %rax,0x30(%rbx)
  402760:	89 ef                	mov    %ebp,%edi
  402762:	e8 c9 e5 ff ff       	callq  400d30 <close@plt>
  402767:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  40276c:	e9 9e 04 00 00       	jmpq   402c0f <submitr+0x746>
  402771:	48 8d b4 24 40 40 00 	lea    0x4040(%rsp),%rsi
  402778:	00 
  402779:	b9 00 04 00 00       	mov    $0x400,%ecx
  40277e:	b8 00 00 00 00       	mov    $0x0,%eax
  402783:	48 89 f7             	mov    %rsi,%rdi
  402786:	f3 48 ab             	rep stos %rax,%es:(%rdi)
  402789:	4c 89 ef             	mov    %r13,%rdi
  40278c:	e8 2b fc ff ff       	callq  4023bc <urlencode>
  402791:	85 c0                	test   %eax,%eax
  402793:	0f 89 8a 00 00 00    	jns    402823 <submitr+0x35a>
  402799:	48 b8 45 72 72 6f 72 	movabs $0x52203a726f727245,%rax
  4027a0:	3a 20 52 
  4027a3:	48 89 03             	mov    %rax,(%rbx)
  4027a6:	48 b8 65 73 75 6c 74 	movabs $0x747320746c757365,%rax
  4027ad:	20 73 74 
  4027b0:	48 89 43 08          	mov    %rax,0x8(%rbx)
  4027b4:	48 b8 72 69 6e 67 20 	movabs $0x6e6f6320676e6972,%rax
  4027bb:	63 6f 6e 
  4027be:	48 89 43 10          	mov    %rax,0x10(%rbx)
  4027c2:	48 b8 74 61 69 6e 73 	movabs $0x6e6120736e696174,%rax
  4027c9:	20 61 6e 
  4027cc:	48 89 43 18          	mov    %rax,0x18(%rbx)
  4027d0:	48 b8 20 69 6c 6c 65 	movabs $0x6c6167656c6c6920,%rax
  4027d7:	67 61 6c 
  4027da:	48 89 43 20          	mov    %rax,0x20(%rbx)
  4027de:	48 b8 20 6f 72 20 75 	movabs $0x72706e7520726f20,%rax
  4027e5:	6e 70 72 
  4027e8:	48 89 43 28          	mov    %rax,0x28(%rbx)
  4027ec:	48 b8 69 6e 74 61 62 	movabs $0x20656c6261746e69,%rax
  4027f3:	6c 65 20 
  4027f6:	48 89 43 30          	mov    %rax,0x30(%rbx)
  4027fa:	48 b8 63 68 61 72 61 	movabs $0x6574636172616863,%rax
  402801:	63 74 65 
  402804:	48 89 43 38          	mov    %rax,0x38(%rbx)
  402808:	66 c7 43 40 72 2e    	movw   $0x2e72,0x40(%rbx)
  40280e:	c6 43 42 00          	movb   $0x0,0x42(%rbx)
  402812:	89 ef                	mov    %ebp,%edi
  402814:	e8 17 e5 ff ff       	callq  400d30 <close@plt>
  402819:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  40281e:	e9 ec 03 00 00       	jmpq   402c0f <submitr+0x746>
  402823:	4c 8d ac 24 40 20 00 	lea    0x2040(%rsp),%r13
  40282a:	00 
  40282b:	41 54                	push   %r12
  40282d:	48 8d 84 24 48 40 00 	lea    0x4048(%rsp),%rax
  402834:	00 
  402835:	50                   	push   %rax
  402836:	4d 89 f9             	mov    %r15,%r9
  402839:	4d 89 f0             	mov    %r14,%r8
  40283c:	b9 18 37 40 00       	mov    $0x403718,%ecx
  402841:	ba 00 20 00 00       	mov    $0x2000,%edx
  402846:	be 01 00 00 00       	mov    $0x1,%esi
  40284b:	4c 89 ef             	mov    %r13,%rdi
  40284e:	b8 00 00 00 00       	mov    $0x0,%eax
  402853:	e8 28 e6 ff ff       	callq  400e80 <__sprintf_chk@plt>
  402858:	b8 00 00 00 00       	mov    $0x0,%eax
  40285d:	48 c7 c1 ff ff ff ff 	mov    $0xffffffffffffffff,%rcx
  402864:	4c 89 ef             	mov    %r13,%rdi
  402867:	f2 ae                	repnz scas %es:(%rdi),%al
  402869:	48 f7 d1             	not    %rcx
  40286c:	48 8d 51 ff          	lea    -0x1(%rcx),%rdx
  402870:	4c 89 ee             	mov    %r13,%rsi
  402873:	89 ef                	mov    %ebp,%edi
  402875:	e8 b1 f9 ff ff       	callq  40222b <rio_writen>
  40287a:	48 83 c4 10          	add    $0x10,%rsp
  40287e:	48 85 c0             	test   %rax,%rax
  402881:	79 6e                	jns    4028f1 <submitr+0x428>
  402883:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  40288a:	3a 20 43 
  40288d:	48 89 03             	mov    %rax,(%rbx)
  402890:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  402897:	20 75 6e 
  40289a:	48 89 43 08          	mov    %rax,0x8(%rbx)
  40289e:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  4028a5:	74 6f 20 
  4028a8:	48 89 43 10          	mov    %rax,0x10(%rbx)
  4028ac:	48 b8 77 72 69 74 65 	movabs $0x6f74206574697277,%rax
  4028b3:	20 74 6f 
  4028b6:	48 89 43 18          	mov    %rax,0x18(%rbx)
  4028ba:	48 b8 20 74 68 65 20 	movabs $0x7365722065687420,%rax
  4028c1:	72 65 73 
  4028c4:	48 89 43 20          	mov    %rax,0x20(%rbx)
  4028c8:	48 b8 75 6c 74 20 73 	movabs $0x7672657320746c75,%rax
  4028cf:	65 72 76 
  4028d2:	48 89 43 28          	mov    %rax,0x28(%rbx)
  4028d6:	66 c7 43 30 65 72    	movw   $0x7265,0x30(%rbx)
  4028dc:	c6 43 32 00          	movb   $0x0,0x32(%rbx)
  4028e0:	89 ef                	mov    %ebp,%edi
  4028e2:	e8 49 e4 ff ff       	callq  400d30 <close@plt>
  4028e7:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  4028ec:	e9 1e 03 00 00       	jmpq   402c0f <submitr+0x746>
  4028f1:	89 ee                	mov    %ebp,%esi
  4028f3:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  4028f8:	e8 ee f8 ff ff       	callq  4021eb <rio_readinitb>
  4028fd:	ba 00 20 00 00       	mov    $0x2000,%edx
  402902:	48 8d b4 24 40 20 00 	lea    0x2040(%rsp),%rsi
  402909:	00 
  40290a:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  40290f:	e8 fe f9 ff ff       	callq  402312 <rio_readlineb>
  402914:	48 85 c0             	test   %rax,%rax
  402917:	7f 7d                	jg     402996 <submitr+0x4cd>
  402919:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  402920:	3a 20 43 
  402923:	48 89 03             	mov    %rax,(%rbx)
  402926:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  40292d:	20 75 6e 
  402930:	48 89 43 08          	mov    %rax,0x8(%rbx)
  402934:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  40293b:	74 6f 20 
  40293e:	48 89 43 10          	mov    %rax,0x10(%rbx)
  402942:	48 b8 72 65 61 64 20 	movabs $0x7269662064616572,%rax
  402949:	66 69 72 
  40294c:	48 89 43 18          	mov    %rax,0x18(%rbx)
  402950:	48 b8 73 74 20 68 65 	movabs $0x6564616568207473,%rax
  402957:	61 64 65 
  40295a:	48 89 43 20          	mov    %rax,0x20(%rbx)
  40295e:	48 b8 72 20 66 72 6f 	movabs $0x72206d6f72662072,%rax
  402965:	6d 20 72 
  402968:	48 89 43 28          	mov    %rax,0x28(%rbx)
  40296c:	48 b8 65 73 75 6c 74 	movabs $0x657320746c757365,%rax
  402973:	20 73 65 
  402976:	48 89 43 30          	mov    %rax,0x30(%rbx)
  40297a:	c7 43 38 72 76 65 72 	movl   $0x72657672,0x38(%rbx)
  402981:	c6 43 3c 00          	movb   $0x0,0x3c(%rbx)
  402985:	89 ef                	mov    %ebp,%edi
  402987:	e8 a4 e3 ff ff       	callq  400d30 <close@plt>
  40298c:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402991:	e9 79 02 00 00       	jmpq   402c0f <submitr+0x746>
  402996:	4c 8d 84 24 40 80 00 	lea    0x8040(%rsp),%r8
  40299d:	00 
  40299e:	48 8d 4c 24 1c       	lea    0x1c(%rsp),%rcx
  4029a3:	48 8d 94 24 40 60 00 	lea    0x6040(%rsp),%rdx
  4029aa:	00 
  4029ab:	be 8f 37 40 00       	mov    $0x40378f,%esi
  4029b0:	48 8d bc 24 40 20 00 	lea    0x2040(%rsp),%rdi
  4029b7:	00 
  4029b8:	b8 00 00 00 00       	mov    $0x0,%eax
  4029bd:	e8 1e e4 ff ff       	callq  400de0 <__isoc99_sscanf@plt>
  4029c2:	e9 95 00 00 00       	jmpq   402a5c <submitr+0x593>
  4029c7:	ba 00 20 00 00       	mov    $0x2000,%edx
  4029cc:	48 8d b4 24 40 20 00 	lea    0x2040(%rsp),%rsi
  4029d3:	00 
  4029d4:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  4029d9:	e8 34 f9 ff ff       	callq  402312 <rio_readlineb>
  4029de:	48 85 c0             	test   %rax,%rax
  4029e1:	7f 79                	jg     402a5c <submitr+0x593>
  4029e3:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  4029ea:	3a 20 43 
  4029ed:	48 89 03             	mov    %rax,(%rbx)
  4029f0:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  4029f7:	20 75 6e 
  4029fa:	48 89 43 08          	mov    %rax,0x8(%rbx)
  4029fe:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  402a05:	74 6f 20 
  402a08:	48 89 43 10          	mov    %rax,0x10(%rbx)
  402a0c:	48 b8 72 65 61 64 20 	movabs $0x6165682064616572,%rax
  402a13:	68 65 61 
  402a16:	48 89 43 18          	mov    %rax,0x18(%rbx)
  402a1a:	48 b8 64 65 72 73 20 	movabs $0x6f72662073726564,%rax
  402a21:	66 72 6f 
  402a24:	48 89 43 20          	mov    %rax,0x20(%rbx)
  402a28:	48 b8 6d 20 74 68 65 	movabs $0x657220656874206d,%rax
  402a2f:	20 72 65 
  402a32:	48 89 43 28          	mov    %rax,0x28(%rbx)
  402a36:	48 b8 73 75 6c 74 20 	movabs $0x72657320746c7573,%rax
  402a3d:	73 65 72 
  402a40:	48 89 43 30          	mov    %rax,0x30(%rbx)
  402a44:	c7 43 38 76 65 72 00 	movl   $0x726576,0x38(%rbx)
  402a4b:	89 ef                	mov    %ebp,%edi
  402a4d:	e8 de e2 ff ff       	callq  400d30 <close@plt>
  402a52:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402a57:	e9 b3 01 00 00       	jmpq   402c0f <submitr+0x746>
  402a5c:	0f b6 94 24 40 20 00 	movzbl 0x2040(%rsp),%edx
  402a63:	00 
  402a64:	b8 0d 00 00 00       	mov    $0xd,%eax
  402a69:	29 d0                	sub    %edx,%eax
  402a6b:	75 1b                	jne    402a88 <submitr+0x5bf>
  402a6d:	0f b6 94 24 41 20 00 	movzbl 0x2041(%rsp),%edx
  402a74:	00 
  402a75:	b8 0a 00 00 00       	mov    $0xa,%eax
  402a7a:	29 d0                	sub    %edx,%eax
  402a7c:	75 0a                	jne    402a88 <submitr+0x5bf>
  402a7e:	0f b6 84 24 42 20 00 	movzbl 0x2042(%rsp),%eax
  402a85:	00 
  402a86:	f7 d8                	neg    %eax
  402a88:	85 c0                	test   %eax,%eax
  402a8a:	0f 85 37 ff ff ff    	jne    4029c7 <submitr+0x4fe>
  402a90:	ba 00 20 00 00       	mov    $0x2000,%edx
  402a95:	48 8d b4 24 40 20 00 	lea    0x2040(%rsp),%rsi
  402a9c:	00 
  402a9d:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  402aa2:	e8 6b f8 ff ff       	callq  402312 <rio_readlineb>
  402aa7:	48 85 c0             	test   %rax,%rax
  402aaa:	0f 8f 83 00 00 00    	jg     402b33 <submitr+0x66a>
  402ab0:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  402ab7:	3a 20 43 
  402aba:	48 89 03             	mov    %rax,(%rbx)
  402abd:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  402ac4:	20 75 6e 
  402ac7:	48 89 43 08          	mov    %rax,0x8(%rbx)
  402acb:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  402ad2:	74 6f 20 
  402ad5:	48 89 43 10          	mov    %rax,0x10(%rbx)
  402ad9:	48 b8 72 65 61 64 20 	movabs $0x6174732064616572,%rax
  402ae0:	73 74 61 
  402ae3:	48 89 43 18          	mov    %rax,0x18(%rbx)
  402ae7:	48 b8 74 75 73 20 6d 	movabs $0x7373656d20737574,%rax
  402aee:	65 73 73 
  402af1:	48 89 43 20          	mov    %rax,0x20(%rbx)
  402af5:	48 b8 61 67 65 20 66 	movabs $0x6d6f726620656761,%rax
  402afc:	72 6f 6d 
  402aff:	48 89 43 28          	mov    %rax,0x28(%rbx)
  402b03:	48 b8 20 72 65 73 75 	movabs $0x20746c7573657220,%rax
  402b0a:	6c 74 20 
  402b0d:	48 89 43 30          	mov    %rax,0x30(%rbx)
  402b11:	c7 43 38 73 65 72 76 	movl   $0x76726573,0x38(%rbx)
  402b18:	66 c7 43 3c 65 72    	movw   $0x7265,0x3c(%rbx)
  402b1e:	c6 43 3e 00          	movb   $0x0,0x3e(%rbx)
  402b22:	89 ef                	mov    %ebp,%edi
  402b24:	e8 07 e2 ff ff       	callq  400d30 <close@plt>
  402b29:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402b2e:	e9 dc 00 00 00       	jmpq   402c0f <submitr+0x746>
  402b33:	44 8b 44 24 1c       	mov    0x1c(%rsp),%r8d
  402b38:	41 81 f8 c8 00 00 00 	cmp    $0xc8,%r8d
  402b3f:	74 37                	je     402b78 <submitr+0x6af>
  402b41:	4c 8d 8c 24 40 80 00 	lea    0x8040(%rsp),%r9
  402b48:	00 
  402b49:	b9 58 37 40 00       	mov    $0x403758,%ecx
  402b4e:	48 c7 c2 ff ff ff ff 	mov    $0xffffffffffffffff,%rdx
  402b55:	be 01 00 00 00       	mov    $0x1,%esi
  402b5a:	48 89 df             	mov    %rbx,%rdi
  402b5d:	b8 00 00 00 00       	mov    $0x0,%eax
  402b62:	e8 19 e3 ff ff       	callq  400e80 <__sprintf_chk@plt>
  402b67:	89 ef                	mov    %ebp,%edi
  402b69:	e8 c2 e1 ff ff       	callq  400d30 <close@plt>
  402b6e:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402b73:	e9 97 00 00 00       	jmpq   402c0f <submitr+0x746>
  402b78:	48 8d b4 24 40 20 00 	lea    0x2040(%rsp),%rsi
  402b7f:	00 
  402b80:	48 89 df             	mov    %rbx,%rdi
  402b83:	e8 38 e1 ff ff       	callq  400cc0 <strcpy@plt>
  402b88:	89 ef                	mov    %ebp,%edi
  402b8a:	e8 a1 e1 ff ff       	callq  400d30 <close@plt>
  402b8f:	0f b6 03             	movzbl (%rbx),%eax
  402b92:	ba 4f 00 00 00       	mov    $0x4f,%edx
  402b97:	29 c2                	sub    %eax,%edx
  402b99:	75 22                	jne    402bbd <submitr+0x6f4>
  402b9b:	0f b6 4b 01          	movzbl 0x1(%rbx),%ecx
  402b9f:	b8 4b 00 00 00       	mov    $0x4b,%eax
  402ba4:	29 c8                	sub    %ecx,%eax
  402ba6:	75 17                	jne    402bbf <submitr+0x6f6>
  402ba8:	0f b6 4b 02          	movzbl 0x2(%rbx),%ecx
  402bac:	b8 0a 00 00 00       	mov    $0xa,%eax
  402bb1:	29 c8                	sub    %ecx,%eax
  402bb3:	75 0a                	jne    402bbf <submitr+0x6f6>
  402bb5:	0f b6 43 03          	movzbl 0x3(%rbx),%eax
  402bb9:	f7 d8                	neg    %eax
  402bbb:	eb 02                	jmp    402bbf <submitr+0x6f6>
  402bbd:	89 d0                	mov    %edx,%eax
  402bbf:	85 c0                	test   %eax,%eax
  402bc1:	74 40                	je     402c03 <submitr+0x73a>
  402bc3:	bf a0 37 40 00       	mov    $0x4037a0,%edi
  402bc8:	b9 05 00 00 00       	mov    $0x5,%ecx
  402bcd:	48 89 de             	mov    %rbx,%rsi
  402bd0:	f3 a6                	repz cmpsb %es:(%rdi),%ds:(%rsi)
  402bd2:	0f 97 c0             	seta   %al
  402bd5:	0f 92 c1             	setb   %cl
  402bd8:	29 c8                	sub    %ecx,%eax
  402bda:	0f be c0             	movsbl %al,%eax
  402bdd:	85 c0                	test   %eax,%eax
  402bdf:	74 2e                	je     402c0f <submitr+0x746>
  402be1:	85 d2                	test   %edx,%edx
  402be3:	75 13                	jne    402bf8 <submitr+0x72f>
  402be5:	0f b6 43 01          	movzbl 0x1(%rbx),%eax
  402be9:	ba 4b 00 00 00       	mov    $0x4b,%edx
  402bee:	29 c2                	sub    %eax,%edx
  402bf0:	75 06                	jne    402bf8 <submitr+0x72f>
  402bf2:	0f b6 53 02          	movzbl 0x2(%rbx),%edx
  402bf6:	f7 da                	neg    %edx
  402bf8:	85 d2                	test   %edx,%edx
  402bfa:	75 0e                	jne    402c0a <submitr+0x741>
  402bfc:	b8 00 00 00 00       	mov    $0x0,%eax
  402c01:	eb 0c                	jmp    402c0f <submitr+0x746>
  402c03:	b8 00 00 00 00       	mov    $0x0,%eax
  402c08:	eb 05                	jmp    402c0f <submitr+0x746>
  402c0a:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402c0f:	48 8b 9c 24 48 a0 00 	mov    0xa048(%rsp),%rbx
  402c16:	00 
  402c17:	64 48 33 1c 25 28 00 	xor    %fs:0x28,%rbx
  402c1e:	00 00 
  402c20:	74 05                	je     402c27 <submitr+0x75e>
  402c22:	e8 c9 e0 ff ff       	callq  400cf0 <__stack_chk_fail@plt>
  402c27:	48 81 c4 58 a0 00 00 	add    $0xa058,%rsp
  402c2e:	5b                   	pop    %rbx
  402c2f:	5d                   	pop    %rbp
  402c30:	41 5c                	pop    %r12
  402c32:	41 5d                	pop    %r13
  402c34:	41 5e                	pop    %r14
  402c36:	41 5f                	pop    %r15
  402c38:	c3                   	retq   

0000000000402c39 <init_timeout>:
  402c39:	85 ff                	test   %edi,%edi
  402c3b:	74 23                	je     402c60 <init_timeout+0x27>
  402c3d:	53                   	push   %rbx
  402c3e:	89 fb                	mov    %edi,%ebx
  402c40:	85 ff                	test   %edi,%edi
  402c42:	79 05                	jns    402c49 <init_timeout+0x10>
  402c44:	bb 00 00 00 00       	mov    $0x0,%ebx
  402c49:	be fd 21 40 00       	mov    $0x4021fd,%esi
  402c4e:	bf 0e 00 00 00       	mov    $0xe,%edi
  402c53:	e8 08 e1 ff ff       	callq  400d60 <signal@plt>
  402c58:	89 df                	mov    %ebx,%edi
  402c5a:	e8 c1 e0 ff ff       	callq  400d20 <alarm@plt>
  402c5f:	5b                   	pop    %rbx
  402c60:	f3 c3                	repz retq 

0000000000402c62 <init_driver>:
  402c62:	55                   	push   %rbp
  402c63:	53                   	push   %rbx
  402c64:	48 83 ec 28          	sub    $0x28,%rsp
  402c68:	48 89 fd             	mov    %rdi,%rbp
  402c6b:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  402c72:	00 00 
  402c74:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
  402c79:	31 c0                	xor    %eax,%eax
  402c7b:	be 01 00 00 00       	mov    $0x1,%esi
  402c80:	bf 0d 00 00 00       	mov    $0xd,%edi
  402c85:	e8 d6 e0 ff ff       	callq  400d60 <signal@plt>
  402c8a:	be 01 00 00 00       	mov    $0x1,%esi
  402c8f:	bf 1d 00 00 00       	mov    $0x1d,%edi
  402c94:	e8 c7 e0 ff ff       	callq  400d60 <signal@plt>
  402c99:	be 01 00 00 00       	mov    $0x1,%esi
  402c9e:	bf 1d 00 00 00       	mov    $0x1d,%edi
  402ca3:	e8 b8 e0 ff ff       	callq  400d60 <signal@plt>
  402ca8:	ba 00 00 00 00       	mov    $0x0,%edx
  402cad:	be 01 00 00 00       	mov    $0x1,%esi
  402cb2:	bf 02 00 00 00       	mov    $0x2,%edi
  402cb7:	e8 d4 e1 ff ff       	callq  400e90 <socket@plt>
  402cbc:	85 c0                	test   %eax,%eax
  402cbe:	79 4f                	jns    402d0f <init_driver+0xad>
  402cc0:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  402cc7:	3a 20 43 
  402cca:	48 89 45 00          	mov    %rax,0x0(%rbp)
  402cce:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  402cd5:	20 75 6e 
  402cd8:	48 89 45 08          	mov    %rax,0x8(%rbp)
  402cdc:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  402ce3:	74 6f 20 
  402ce6:	48 89 45 10          	mov    %rax,0x10(%rbp)
  402cea:	48 b8 63 72 65 61 74 	movabs $0x7320657461657263,%rax
  402cf1:	65 20 73 
  402cf4:	48 89 45 18          	mov    %rax,0x18(%rbp)
  402cf8:	c7 45 20 6f 63 6b 65 	movl   $0x656b636f,0x20(%rbp)
  402cff:	66 c7 45 24 74 00    	movw   $0x74,0x24(%rbp)
  402d05:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402d0a:	e9 2a 01 00 00       	jmpq   402e39 <init_driver+0x1d7>
  402d0f:	89 c3                	mov    %eax,%ebx
  402d11:	bf ea 32 40 00       	mov    $0x4032ea,%edi
  402d16:	e8 55 e0 ff ff       	callq  400d70 <gethostbyname@plt>
  402d1b:	48 85 c0             	test   %rax,%rax
  402d1e:	75 68                	jne    402d88 <init_driver+0x126>
  402d20:	48 b8 45 72 72 6f 72 	movabs $0x44203a726f727245,%rax
  402d27:	3a 20 44 
  402d2a:	48 89 45 00          	mov    %rax,0x0(%rbp)
  402d2e:	48 b8 4e 53 20 69 73 	movabs $0x6e7520736920534e,%rax
  402d35:	20 75 6e 
  402d38:	48 89 45 08          	mov    %rax,0x8(%rbp)
  402d3c:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  402d43:	74 6f 20 
  402d46:	48 89 45 10          	mov    %rax,0x10(%rbp)
  402d4a:	48 b8 72 65 73 6f 6c 	movabs $0x2065766c6f736572,%rax
  402d51:	76 65 20 
  402d54:	48 89 45 18          	mov    %rax,0x18(%rbp)
  402d58:	48 b8 73 65 72 76 65 	movabs $0x6120726576726573,%rax
  402d5f:	72 20 61 
  402d62:	48 89 45 20          	mov    %rax,0x20(%rbp)
  402d66:	c7 45 28 64 64 72 65 	movl   $0x65726464,0x28(%rbp)
  402d6d:	66 c7 45 2c 73 73    	movw   $0x7373,0x2c(%rbp)
  402d73:	c6 45 2e 00          	movb   $0x0,0x2e(%rbp)
  402d77:	89 df                	mov    %ebx,%edi
  402d79:	e8 b2 df ff ff       	callq  400d30 <close@plt>
  402d7e:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402d83:	e9 b1 00 00 00       	jmpq   402e39 <init_driver+0x1d7>
  402d88:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
  402d8f:	00 
  402d90:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  402d97:	00 00 
  402d99:	66 c7 04 24 02 00    	movw   $0x2,(%rsp)
  402d9f:	48 63 50 14          	movslq 0x14(%rax),%rdx
  402da3:	48 8b 40 18          	mov    0x18(%rax),%rax
  402da7:	48 8b 30             	mov    (%rax),%rsi
  402daa:	48 8d 7c 24 04       	lea    0x4(%rsp),%rdi
  402daf:	b9 0c 00 00 00       	mov    $0xc,%ecx
  402db4:	e8 c7 df ff ff       	callq  400d80 <__memmove_chk@plt>
  402db9:	66 c7 44 24 02 3c 9a 	movw   $0x9a3c,0x2(%rsp)
  402dc0:	ba 10 00 00 00       	mov    $0x10,%edx
  402dc5:	48 89 e6             	mov    %rsp,%rsi
  402dc8:	89 df                	mov    %ebx,%edi
  402dca:	e8 91 e0 ff ff       	callq  400e60 <connect@plt>
  402dcf:	85 c0                	test   %eax,%eax
  402dd1:	79 50                	jns    402e23 <init_driver+0x1c1>
  402dd3:	48 b8 45 72 72 6f 72 	movabs $0x55203a726f727245,%rax
  402dda:	3a 20 55 
  402ddd:	48 89 45 00          	mov    %rax,0x0(%rbp)
  402de1:	48 b8 6e 61 62 6c 65 	movabs $0x6f7420656c62616e,%rax
  402de8:	20 74 6f 
  402deb:	48 89 45 08          	mov    %rax,0x8(%rbp)
  402def:	48 b8 20 63 6f 6e 6e 	movabs $0x7463656e6e6f6320,%rax
  402df6:	65 63 74 
  402df9:	48 89 45 10          	mov    %rax,0x10(%rbp)
  402dfd:	48 b8 20 74 6f 20 73 	movabs $0x76726573206f7420,%rax
  402e04:	65 72 76 
  402e07:	48 89 45 18          	mov    %rax,0x18(%rbp)
  402e0b:	66 c7 45 20 65 72    	movw   $0x7265,0x20(%rbp)
  402e11:	c6 45 22 00          	movb   $0x0,0x22(%rbp)
  402e15:	89 df                	mov    %ebx,%edi
  402e17:	e8 14 df ff ff       	callq  400d30 <close@plt>
  402e1c:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402e21:	eb 16                	jmp    402e39 <init_driver+0x1d7>
  402e23:	89 df                	mov    %ebx,%edi
  402e25:	e8 06 df ff ff       	callq  400d30 <close@plt>
  402e2a:	66 c7 45 00 4f 4b    	movw   $0x4b4f,0x0(%rbp)
  402e30:	c6 45 02 00          	movb   $0x0,0x2(%rbp)
  402e34:	b8 00 00 00 00       	mov    $0x0,%eax
  402e39:	48 8b 4c 24 18       	mov    0x18(%rsp),%rcx
  402e3e:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
  402e45:	00 00 
  402e47:	74 05                	je     402e4e <init_driver+0x1ec>
  402e49:	e8 a2 de ff ff       	callq  400cf0 <__stack_chk_fail@plt>
  402e4e:	48 83 c4 28          	add    $0x28,%rsp
  402e52:	5b                   	pop    %rbx
  402e53:	5d                   	pop    %rbp
  402e54:	c3                   	retq   

0000000000402e55 <driver_post>:
  402e55:	53                   	push   %rbx
  402e56:	4c 89 cb             	mov    %r9,%rbx
  402e59:	45 85 c0             	test   %r8d,%r8d
  402e5c:	74 27                	je     402e85 <driver_post+0x30>
  402e5e:	48 89 ca             	mov    %rcx,%rdx
  402e61:	be a5 37 40 00       	mov    $0x4037a5,%esi
  402e66:	bf 01 00 00 00       	mov    $0x1,%edi
  402e6b:	b8 00 00 00 00       	mov    $0x0,%eax
  402e70:	e8 8b df ff ff       	callq  400e00 <__printf_chk@plt>
  402e75:	66 c7 03 4f 4b       	movw   $0x4b4f,(%rbx)
  402e7a:	c6 43 02 00          	movb   $0x0,0x2(%rbx)
  402e7e:	b8 00 00 00 00       	mov    $0x0,%eax
  402e83:	eb 3f                	jmp    402ec4 <driver_post+0x6f>
  402e85:	48 85 ff             	test   %rdi,%rdi
  402e88:	74 2c                	je     402eb6 <driver_post+0x61>
  402e8a:	80 3f 00             	cmpb   $0x0,(%rdi)
  402e8d:	74 27                	je     402eb6 <driver_post+0x61>
  402e8f:	48 83 ec 08          	sub    $0x8,%rsp
  402e93:	41 51                	push   %r9
  402e95:	49 89 c9             	mov    %rcx,%r9
  402e98:	49 89 d0             	mov    %rdx,%r8
  402e9b:	48 89 f9             	mov    %rdi,%rcx
  402e9e:	48 89 f2             	mov    %rsi,%rdx
  402ea1:	be 9a 3c 00 00       	mov    $0x3c9a,%esi
  402ea6:	bf ea 32 40 00       	mov    $0x4032ea,%edi
  402eab:	e8 19 f6 ff ff       	callq  4024c9 <submitr>
  402eb0:	48 83 c4 10          	add    $0x10,%rsp
  402eb4:	eb 0e                	jmp    402ec4 <driver_post+0x6f>
  402eb6:	66 c7 03 4f 4b       	movw   $0x4b4f,(%rbx)
  402ebb:	c6 43 02 00          	movb   $0x0,0x2(%rbx)
  402ebf:	b8 00 00 00 00       	mov    $0x0,%eax
  402ec4:	5b                   	pop    %rbx
  402ec5:	c3                   	retq   

0000000000402ec6 <check>:
  402ec6:	89 f8                	mov    %edi,%eax
  402ec8:	c1 e8 1c             	shr    $0x1c,%eax
  402ecb:	85 c0                	test   %eax,%eax
  402ecd:	74 1d                	je     402eec <check+0x26>
  402ecf:	b9 00 00 00 00       	mov    $0x0,%ecx
  402ed4:	eb 0b                	jmp    402ee1 <check+0x1b>
  402ed6:	89 f8                	mov    %edi,%eax
  402ed8:	d3 e8                	shr    %cl,%eax
  402eda:	3c 0a                	cmp    $0xa,%al
  402edc:	74 14                	je     402ef2 <check+0x2c>
  402ede:	83 c1 08             	add    $0x8,%ecx
  402ee1:	83 f9 1f             	cmp    $0x1f,%ecx
  402ee4:	7e f0                	jle    402ed6 <check+0x10>
  402ee6:	b8 01 00 00 00       	mov    $0x1,%eax
  402eeb:	c3                   	retq   
  402eec:	b8 00 00 00 00       	mov    $0x0,%eax
  402ef1:	c3                   	retq   
  402ef2:	b8 00 00 00 00       	mov    $0x0,%eax
  402ef7:	c3                   	retq   

0000000000402ef8 <gencookie>:
  402ef8:	53                   	push   %rbx
  402ef9:	83 c7 01             	add    $0x1,%edi
  402efc:	e8 9f dd ff ff       	callq  400ca0 <srandom@plt>
  402f01:	e8 ba de ff ff       	callq  400dc0 <random@plt>
  402f06:	89 c3                	mov    %eax,%ebx
  402f08:	89 c7                	mov    %eax,%edi
  402f0a:	e8 b7 ff ff ff       	callq  402ec6 <check>
  402f0f:	85 c0                	test   %eax,%eax
  402f11:	74 ee                	je     402f01 <gencookie+0x9>
  402f13:	89 d8                	mov    %ebx,%eax
  402f15:	5b                   	pop    %rbx
  402f16:	c3                   	retq   
  402f17:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  402f1e:	00 00 

0000000000402f20 <__libc_csu_init>:
  402f20:	41 57                	push   %r15
  402f22:	41 56                	push   %r14
  402f24:	41 89 ff             	mov    %edi,%r15d
  402f27:	41 55                	push   %r13
  402f29:	41 54                	push   %r12
  402f2b:	4c 8d 25 de 1e 20 00 	lea    0x201ede(%rip),%r12        # 604e10 <__frame_dummy_init_array_entry>
  402f32:	55                   	push   %rbp
  402f33:	48 8d 2d de 1e 20 00 	lea    0x201ede(%rip),%rbp        # 604e18 <__init_array_end>
  402f3a:	53                   	push   %rbx
  402f3b:	49 89 f6             	mov    %rsi,%r14
  402f3e:	49 89 d5             	mov    %rdx,%r13
  402f41:	4c 29 e5             	sub    %r12,%rbp
  402f44:	48 83 ec 08          	sub    $0x8,%rsp
  402f48:	48 c1 fd 03          	sar    $0x3,%rbp
  402f4c:	e8 f7 dc ff ff       	callq  400c48 <_init>
  402f51:	48 85 ed             	test   %rbp,%rbp
  402f54:	74 20                	je     402f76 <__libc_csu_init+0x56>
  402f56:	31 db                	xor    %ebx,%ebx
  402f58:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  402f5f:	00 
  402f60:	4c 89 ea             	mov    %r13,%rdx
  402f63:	4c 89 f6             	mov    %r14,%rsi
  402f66:	44 89 ff             	mov    %r15d,%edi
  402f69:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  402f6d:	48 83 c3 01          	add    $0x1,%rbx
  402f71:	48 39 eb             	cmp    %rbp,%rbx
  402f74:	75 ea                	jne    402f60 <__libc_csu_init+0x40>
  402f76:	48 83 c4 08          	add    $0x8,%rsp
  402f7a:	5b                   	pop    %rbx
  402f7b:	5d                   	pop    %rbp
  402f7c:	41 5c                	pop    %r12
  402f7e:	41 5d                	pop    %r13
  402f80:	41 5e                	pop    %r14
  402f82:	41 5f                	pop    %r15
  402f84:	c3                   	retq   
  402f85:	90                   	nop
  402f86:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  402f8d:	00 00 00 

0000000000402f90 <__libc_csu_fini>:
  402f90:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000402f94 <_fini>:
  402f94:	48 83 ec 08          	sub    $0x8,%rsp
  402f98:	48 83 c4 08          	add    $0x8,%rsp
  402f9c:	c3                   	retq   
