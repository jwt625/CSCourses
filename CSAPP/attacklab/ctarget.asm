ctarget:     file format elf64-x86-64


Disassembly of section .init:

0000000000400c48 <_init>:
  400c48:	48 83 ec 08          	sub    $0x8,%rsp
  400c4c:	48 8b 05 a5 33 20 00 	mov    0x2033a5(%rip),%rax        # 603ff8 <_DYNAMIC+0x1d0>
  400c53:	48 85 c0             	test   %rax,%rax
  400c56:	74 05                	je     400c5d <_init+0x15>
  400c58:	e8 43 02 00 00       	callq  400ea0 <socket@plt+0x10>
  400c5d:	48 83 c4 08          	add    $0x8,%rsp
  400c61:	c3                   	retq   

Disassembly of section .plt:

0000000000400c70 <strcasecmp@plt-0x10>:
  400c70:	ff 35 92 33 20 00    	pushq  0x203392(%rip)        # 604008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400c76:	ff 25 94 33 20 00    	jmpq   *0x203394(%rip)        # 604010 <_GLOBAL_OFFSET_TABLE_+0x10>
  400c7c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400c80 <strcasecmp@plt>:
  400c80:	ff 25 92 33 20 00    	jmpq   *0x203392(%rip)        # 604018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400c86:	68 00 00 00 00       	pushq  $0x0
  400c8b:	e9 e0 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400c90 <__errno_location@plt>:
  400c90:	ff 25 8a 33 20 00    	jmpq   *0x20338a(%rip)        # 604020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400c96:	68 01 00 00 00       	pushq  $0x1
  400c9b:	e9 d0 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400ca0 <srandom@plt>:
  400ca0:	ff 25 82 33 20 00    	jmpq   *0x203382(%rip)        # 604028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400ca6:	68 02 00 00 00       	pushq  $0x2
  400cab:	e9 c0 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400cb0 <strncmp@plt>:
  400cb0:	ff 25 7a 33 20 00    	jmpq   *0x20337a(%rip)        # 604030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400cb6:	68 03 00 00 00       	pushq  $0x3
  400cbb:	e9 b0 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400cc0 <strcpy@plt>:
  400cc0:	ff 25 72 33 20 00    	jmpq   *0x203372(%rip)        # 604038 <_GLOBAL_OFFSET_TABLE_+0x38>
  400cc6:	68 04 00 00 00       	pushq  $0x4
  400ccb:	e9 a0 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400cd0 <puts@plt>:
  400cd0:	ff 25 6a 33 20 00    	jmpq   *0x20336a(%rip)        # 604040 <_GLOBAL_OFFSET_TABLE_+0x40>
  400cd6:	68 05 00 00 00       	pushq  $0x5
  400cdb:	e9 90 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400ce0 <write@plt>:
  400ce0:	ff 25 62 33 20 00    	jmpq   *0x203362(%rip)        # 604048 <_GLOBAL_OFFSET_TABLE_+0x48>
  400ce6:	68 06 00 00 00       	pushq  $0x6
  400ceb:	e9 80 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400cf0 <__stack_chk_fail@plt>:
  400cf0:	ff 25 5a 33 20 00    	jmpq   *0x20335a(%rip)        # 604050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400cf6:	68 07 00 00 00       	pushq  $0x7
  400cfb:	e9 70 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400d00 <mmap@plt>:
  400d00:	ff 25 52 33 20 00    	jmpq   *0x203352(%rip)        # 604058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400d06:	68 08 00 00 00       	pushq  $0x8
  400d0b:	e9 60 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400d10 <memset@plt>:
  400d10:	ff 25 4a 33 20 00    	jmpq   *0x20334a(%rip)        # 604060 <_GLOBAL_OFFSET_TABLE_+0x60>
  400d16:	68 09 00 00 00       	pushq  $0x9
  400d1b:	e9 50 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400d20 <alarm@plt>:
  400d20:	ff 25 42 33 20 00    	jmpq   *0x203342(%rip)        # 604068 <_GLOBAL_OFFSET_TABLE_+0x68>
  400d26:	68 0a 00 00 00       	pushq  $0xa
  400d2b:	e9 40 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400d30 <close@plt>:
  400d30:	ff 25 3a 33 20 00    	jmpq   *0x20333a(%rip)        # 604070 <_GLOBAL_OFFSET_TABLE_+0x70>
  400d36:	68 0b 00 00 00       	pushq  $0xb
  400d3b:	e9 30 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400d40 <read@plt>:
  400d40:	ff 25 32 33 20 00    	jmpq   *0x203332(%rip)        # 604078 <_GLOBAL_OFFSET_TABLE_+0x78>
  400d46:	68 0c 00 00 00       	pushq  $0xc
  400d4b:	e9 20 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400d50 <__libc_start_main@plt>:
  400d50:	ff 25 2a 33 20 00    	jmpq   *0x20332a(%rip)        # 604080 <_GLOBAL_OFFSET_TABLE_+0x80>
  400d56:	68 0d 00 00 00       	pushq  $0xd
  400d5b:	e9 10 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400d60 <signal@plt>:
  400d60:	ff 25 22 33 20 00    	jmpq   *0x203322(%rip)        # 604088 <_GLOBAL_OFFSET_TABLE_+0x88>
  400d66:	68 0e 00 00 00       	pushq  $0xe
  400d6b:	e9 00 ff ff ff       	jmpq   400c70 <_init+0x28>

0000000000400d70 <gethostbyname@plt>:
  400d70:	ff 25 1a 33 20 00    	jmpq   *0x20331a(%rip)        # 604090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400d76:	68 0f 00 00 00       	pushq  $0xf
  400d7b:	e9 f0 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400d80 <__memmove_chk@plt>:
  400d80:	ff 25 12 33 20 00    	jmpq   *0x203312(%rip)        # 604098 <_GLOBAL_OFFSET_TABLE_+0x98>
  400d86:	68 10 00 00 00       	pushq  $0x10
  400d8b:	e9 e0 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400d90 <strtol@plt>:
  400d90:	ff 25 0a 33 20 00    	jmpq   *0x20330a(%rip)        # 6040a0 <_GLOBAL_OFFSET_TABLE_+0xa0>
  400d96:	68 11 00 00 00       	pushq  $0x11
  400d9b:	e9 d0 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400da0 <memcpy@plt>:
  400da0:	ff 25 02 33 20 00    	jmpq   *0x203302(%rip)        # 6040a8 <_GLOBAL_OFFSET_TABLE_+0xa8>
  400da6:	68 12 00 00 00       	pushq  $0x12
  400dab:	e9 c0 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400db0 <time@plt>:
  400db0:	ff 25 fa 32 20 00    	jmpq   *0x2032fa(%rip)        # 6040b0 <_GLOBAL_OFFSET_TABLE_+0xb0>
  400db6:	68 13 00 00 00       	pushq  $0x13
  400dbb:	e9 b0 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400dc0 <random@plt>:
  400dc0:	ff 25 f2 32 20 00    	jmpq   *0x2032f2(%rip)        # 6040b8 <_GLOBAL_OFFSET_TABLE_+0xb8>
  400dc6:	68 14 00 00 00       	pushq  $0x14
  400dcb:	e9 a0 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400dd0 <_IO_getc@plt>:
  400dd0:	ff 25 ea 32 20 00    	jmpq   *0x2032ea(%rip)        # 6040c0 <_GLOBAL_OFFSET_TABLE_+0xc0>
  400dd6:	68 15 00 00 00       	pushq  $0x15
  400ddb:	e9 90 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400de0 <__isoc99_sscanf@plt>:
  400de0:	ff 25 e2 32 20 00    	jmpq   *0x2032e2(%rip)        # 6040c8 <_GLOBAL_OFFSET_TABLE_+0xc8>
  400de6:	68 16 00 00 00       	pushq  $0x16
  400deb:	e9 80 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400df0 <munmap@plt>:
  400df0:	ff 25 da 32 20 00    	jmpq   *0x2032da(%rip)        # 6040d0 <_GLOBAL_OFFSET_TABLE_+0xd0>
  400df6:	68 17 00 00 00       	pushq  $0x17
  400dfb:	e9 70 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400e00 <__printf_chk@plt>:
  400e00:	ff 25 d2 32 20 00    	jmpq   *0x2032d2(%rip)        # 6040d8 <_GLOBAL_OFFSET_TABLE_+0xd8>
  400e06:	68 18 00 00 00       	pushq  $0x18
  400e0b:	e9 60 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400e10 <fopen@plt>:
  400e10:	ff 25 ca 32 20 00    	jmpq   *0x2032ca(%rip)        # 6040e0 <_GLOBAL_OFFSET_TABLE_+0xe0>
  400e16:	68 19 00 00 00       	pushq  $0x19
  400e1b:	e9 50 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400e20 <getopt@plt>:
  400e20:	ff 25 c2 32 20 00    	jmpq   *0x2032c2(%rip)        # 6040e8 <_GLOBAL_OFFSET_TABLE_+0xe8>
  400e26:	68 1a 00 00 00       	pushq  $0x1a
  400e2b:	e9 40 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400e30 <strtoul@plt>:
  400e30:	ff 25 ba 32 20 00    	jmpq   *0x2032ba(%rip)        # 6040f0 <_GLOBAL_OFFSET_TABLE_+0xf0>
  400e36:	68 1b 00 00 00       	pushq  $0x1b
  400e3b:	e9 30 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400e40 <gethostname@plt>:
  400e40:	ff 25 b2 32 20 00    	jmpq   *0x2032b2(%rip)        # 6040f8 <_GLOBAL_OFFSET_TABLE_+0xf8>
  400e46:	68 1c 00 00 00       	pushq  $0x1c
  400e4b:	e9 20 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400e50 <exit@plt>:
  400e50:	ff 25 aa 32 20 00    	jmpq   *0x2032aa(%rip)        # 604100 <_GLOBAL_OFFSET_TABLE_+0x100>
  400e56:	68 1d 00 00 00       	pushq  $0x1d
  400e5b:	e9 10 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400e60 <connect@plt>:
  400e60:	ff 25 a2 32 20 00    	jmpq   *0x2032a2(%rip)        # 604108 <_GLOBAL_OFFSET_TABLE_+0x108>
  400e66:	68 1e 00 00 00       	pushq  $0x1e
  400e6b:	e9 00 fe ff ff       	jmpq   400c70 <_init+0x28>

0000000000400e70 <__fprintf_chk@plt>:
  400e70:	ff 25 9a 32 20 00    	jmpq   *0x20329a(%rip)        # 604110 <_GLOBAL_OFFSET_TABLE_+0x110>
  400e76:	68 1f 00 00 00       	pushq  $0x1f
  400e7b:	e9 f0 fd ff ff       	jmpq   400c70 <_init+0x28>

0000000000400e80 <__sprintf_chk@plt>:
  400e80:	ff 25 92 32 20 00    	jmpq   *0x203292(%rip)        # 604118 <_GLOBAL_OFFSET_TABLE_+0x118>
  400e86:	68 20 00 00 00       	pushq  $0x20
  400e8b:	e9 e0 fd ff ff       	jmpq   400c70 <_init+0x28>

0000000000400e90 <socket@plt>:
  400e90:	ff 25 8a 32 20 00    	jmpq   *0x20328a(%rip)        # 604120 <_GLOBAL_OFFSET_TABLE_+0x120>
  400e96:	68 21 00 00 00       	pushq  $0x21
  400e9b:	e9 d0 fd ff ff       	jmpq   400c70 <_init+0x28>

Disassembly of section .plt.got:

0000000000400ea0 <.plt.got>:
  400ea0:	ff 25 52 31 20 00    	jmpq   *0x203152(%rip)        # 603ff8 <_DYNAMIC+0x1d0>
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
  400ebf:	49 c7 c0 70 2e 40 00 	mov    $0x402e70,%r8
  400ec6:	48 c7 c1 00 2e 40 00 	mov    $0x402e00,%rcx
  400ecd:	48 c7 c7 b5 11 40 00 	mov    $0x4011b5,%rdi
  400ed4:	e8 77 fe ff ff       	callq  400d50 <__libc_start_main@plt>
  400ed9:	f4                   	hlt    
  400eda:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400ee0 <deregister_tm_clones>:
  400ee0:	b8 b7 44 60 00       	mov    $0x6044b7,%eax
  400ee5:	55                   	push   %rbp
  400ee6:	48 2d b0 44 60 00    	sub    $0x6044b0,%rax
  400eec:	48 83 f8 0e          	cmp    $0xe,%rax
  400ef0:	48 89 e5             	mov    %rsp,%rbp
  400ef3:	76 1b                	jbe    400f10 <deregister_tm_clones+0x30>
  400ef5:	b8 00 00 00 00       	mov    $0x0,%eax
  400efa:	48 85 c0             	test   %rax,%rax
  400efd:	74 11                	je     400f10 <deregister_tm_clones+0x30>
  400eff:	5d                   	pop    %rbp
  400f00:	bf b0 44 60 00       	mov    $0x6044b0,%edi
  400f05:	ff e0                	jmpq   *%rax
  400f07:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  400f0e:	00 00 
  400f10:	5d                   	pop    %rbp
  400f11:	c3                   	retq   
  400f12:	0f 1f 40 00          	nopl   0x0(%rax)
  400f16:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  400f1d:	00 00 00 

0000000000400f20 <register_tm_clones>:
  400f20:	be b0 44 60 00       	mov    $0x6044b0,%esi
  400f25:	55                   	push   %rbp
  400f26:	48 81 ee b0 44 60 00 	sub    $0x6044b0,%rsi
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
  400f4e:	bf b0 44 60 00       	mov    $0x6044b0,%edi
  400f53:	ff e0                	jmpq   *%rax
  400f55:	0f 1f 00             	nopl   (%rax)
  400f58:	5d                   	pop    %rbp
  400f59:	c3                   	retq   
  400f5a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400f60 <__do_global_dtors_aux>:
  400f60:	80 3d 81 35 20 00 00 	cmpb   $0x0,0x203581(%rip)        # 6044e8 <completed.7585>
  400f67:	75 11                	jne    400f7a <__do_global_dtors_aux+0x1a>
  400f69:	55                   	push   %rbp
  400f6a:	48 89 e5             	mov    %rsp,%rbp
  400f6d:	e8 6e ff ff ff       	callq  400ee0 <deregister_tm_clones>
  400f72:	5d                   	pop    %rbp
  400f73:	c6 05 6e 35 20 00 01 	movb   $0x1,0x20356e(%rip)        # 6044e8 <completed.7585>
  400f7a:	f3 c3                	repz retq 
  400f7c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400f80 <frame_dummy>:
  400f80:	bf 20 3e 60 00       	mov    $0x603e20,%edi
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
  400fad:	83 3d 74 35 20 00 00 	cmpl   $0x0,0x203574(%rip)        # 604528 <is_checker>
  400fb4:	74 3e                	je     400ff4 <usage+0x4e>
  400fb6:	be 88 2e 40 00       	mov    $0x402e88,%esi
  400fbb:	bf 01 00 00 00       	mov    $0x1,%edi
  400fc0:	b8 00 00 00 00       	mov    $0x0,%eax
  400fc5:	e8 36 fe ff ff       	callq  400e00 <__printf_chk@plt>
  400fca:	bf c0 2e 40 00       	mov    $0x402ec0,%edi
  400fcf:	e8 fc fc ff ff       	callq  400cd0 <puts@plt>
  400fd4:	bf 38 30 40 00       	mov    $0x403038,%edi
  400fd9:	e8 f2 fc ff ff       	callq  400cd0 <puts@plt>
  400fde:	bf e8 2e 40 00       	mov    $0x402ee8,%edi
  400fe3:	e8 e8 fc ff ff       	callq  400cd0 <puts@plt>
  400fe8:	bf 52 30 40 00       	mov    $0x403052,%edi
  400fed:	e8 de fc ff ff       	callq  400cd0 <puts@plt>
  400ff2:	eb 32                	jmp    401026 <usage+0x80>
  400ff4:	be 6e 30 40 00       	mov    $0x40306e,%esi
  400ff9:	bf 01 00 00 00       	mov    $0x1,%edi
  400ffe:	b8 00 00 00 00       	mov    $0x0,%eax
  401003:	e8 f8 fd ff ff       	callq  400e00 <__printf_chk@plt>
  401008:	bf 10 2f 40 00       	mov    $0x402f10,%edi
  40100d:	e8 be fc ff ff       	callq  400cd0 <puts@plt>
  401012:	bf 38 2f 40 00       	mov    $0x402f38,%edi
  401017:	e8 b4 fc ff ff       	callq  400cd0 <puts@plt>
  40101c:	bf 8c 30 40 00       	mov    $0x40308c,%edi
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
  40104e:	89 3d c4 34 20 00    	mov    %edi,0x2034c4(%rip)        # 604518 <check_level>
  401054:	8b 3d 0e 31 20 00    	mov    0x20310e(%rip),%edi        # 604168 <target_id>
  40105a:	e8 78 1d 00 00       	callq  402dd7 <gencookie>
  40105f:	89 05 bf 34 20 00    	mov    %eax,0x2034bf(%rip)        # 604524 <cookie>
  401065:	89 c7                	mov    %eax,%edi
  401067:	e8 6b 1d 00 00       	callq  402dd7 <gencookie>
  40106c:	89 05 ae 34 20 00    	mov    %eax,0x2034ae(%rip)        # 604520 <authkey>
  401072:	8b 05 f0 30 20 00    	mov    0x2030f0(%rip),%eax        # 604168 <target_id>
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
  4010bd:	48 89 05 dc 33 20 00 	mov    %rax,0x2033dc(%rip)        # 6044a0 <buf_offset>
  4010c4:	c6 05 7d 40 20 00 63 	movb   $0x63,0x20407d(%rip)        # 605148 <target_prefix>
  4010cb:	83 3d d6 33 20 00 00 	cmpl   $0x0,0x2033d6(%rip)        # 6044a8 <notify>
  4010d2:	0f 84 bb 00 00 00    	je     401193 <initialize_target+0x163>
  4010d8:	83 3d 49 34 20 00 00 	cmpl   $0x0,0x203449(%rip)        # 604528 <is_checker>
  4010df:	0f 85 ae 00 00 00    	jne    401193 <initialize_target+0x163>
  4010e5:	be 00 01 00 00       	mov    $0x100,%esi
  4010ea:	48 89 e7             	mov    %rsp,%rdi
  4010ed:	e8 4e fd ff ff       	callq  400e40 <gethostname@plt>
  4010f2:	85 c0                	test   %eax,%eax
  4010f4:	74 25                	je     40111b <initialize_target+0xeb>
  4010f6:	bf 68 2f 40 00       	mov    $0x402f68,%edi
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
  401123:	48 8b 3c c5 80 41 60 	mov    0x604180(,%rax,8),%rdi
  40112a:	00 
  40112b:	48 85 ff             	test   %rdi,%rdi
  40112e:	75 da                	jne    40110a <initialize_target+0xda>
  401130:	b8 00 00 00 00       	mov    $0x0,%eax
  401135:	eb 05                	jmp    40113c <initialize_target+0x10c>
  401137:	b8 01 00 00 00       	mov    $0x1,%eax
  40113c:	85 c0                	test   %eax,%eax
  40113e:	75 1c                	jne    40115c <initialize_target+0x12c>
  401140:	48 89 e2             	mov    %rsp,%rdx
  401143:	be a0 2f 40 00       	mov    $0x402fa0,%esi
  401148:	bf 01 00 00 00       	mov    $0x1,%edi
  40114d:	e8 ae fc ff ff       	callq  400e00 <__printf_chk@plt>
  401152:	bf 08 00 00 00       	mov    $0x8,%edi
  401157:	e8 f4 fc ff ff       	callq  400e50 <exit@plt>
  40115c:	48 8d bc 24 00 01 00 	lea    0x100(%rsp),%rdi
  401163:	00 
  401164:	e8 d8 19 00 00       	callq  402b41 <init_driver>
  401169:	85 c0                	test   %eax,%eax
  40116b:	79 26                	jns    401193 <initialize_target+0x163>
  40116d:	48 8d 94 24 00 01 00 	lea    0x100(%rsp),%rdx
  401174:	00 
  401175:	be e0 2f 40 00       	mov    $0x402fe0,%esi
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
  4011c3:	be 7c 1e 40 00       	mov    $0x401e7c,%esi
  4011c8:	bf 0b 00 00 00       	mov    $0xb,%edi
  4011cd:	e8 8e fb ff ff       	callq  400d60 <signal@plt>
  4011d2:	be 2e 1e 40 00       	mov    $0x401e2e,%esi
  4011d7:	bf 07 00 00 00       	mov    $0x7,%edi
  4011dc:	e8 7f fb ff ff       	callq  400d60 <signal@plt>
  4011e1:	be ca 1e 40 00       	mov    $0x401eca,%esi
  4011e6:	bf 04 00 00 00       	mov    $0x4,%edi
  4011eb:	e8 70 fb ff ff       	callq  400d60 <signal@plt>
  4011f0:	83 3d 31 33 20 00 00 	cmpl   $0x0,0x203331(%rip)        # 604528 <is_checker>
  4011f7:	74 20                	je     401219 <main+0x64>
  4011f9:	be 18 1f 40 00       	mov    $0x401f18,%esi
  4011fe:	bf 0e 00 00 00       	mov    $0xe,%edi
  401203:	e8 58 fb ff ff       	callq  400d60 <signal@plt>
  401208:	bf 05 00 00 00       	mov    $0x5,%edi
  40120d:	e8 0e fb ff ff       	callq  400d20 <alarm@plt>
  401212:	bd aa 30 40 00       	mov    $0x4030aa,%ebp
  401217:	eb 05                	jmp    40121e <main+0x69>
  401219:	bd a5 30 40 00       	mov    $0x4030a5,%ebp
  40121e:	48 8b 05 9b 32 20 00 	mov    0x20329b(%rip),%rax        # 6044c0 <stdin@@GLIBC_2.2.5>
  401225:	48 89 05 e4 32 20 00 	mov    %rax,0x2032e4(%rip)        # 604510 <infile>
  40122c:	41 bd 00 00 00 00    	mov    $0x0,%r13d
  401232:	41 be 00 00 00 00    	mov    $0x0,%r14d
  401238:	e9 c6 00 00 00       	jmpq   401303 <main+0x14e>
  40123d:	83 e8 61             	sub    $0x61,%eax
  401240:	3c 10                	cmp    $0x10,%al
  401242:	0f 87 9c 00 00 00    	ja     4012e4 <main+0x12f>
  401248:	0f b6 c0             	movzbl %al,%eax
  40124b:	ff 24 c5 f0 30 40 00 	jmpq   *0x4030f0(,%rax,8)
  401252:	48 8b 3b             	mov    (%rbx),%rdi
  401255:	e8 4c fd ff ff       	callq  400fa6 <usage>
  40125a:	be 7d 33 40 00       	mov    $0x40337d,%esi
  40125f:	48 8b 3d 62 32 20 00 	mov    0x203262(%rip),%rdi        # 6044c8 <optarg@@GLIBC_2.2.5>
  401266:	e8 a5 fb ff ff       	callq  400e10 <fopen@plt>
  40126b:	48 89 05 9e 32 20 00 	mov    %rax,0x20329e(%rip)        # 604510 <infile>
  401272:	48 85 c0             	test   %rax,%rax
  401275:	0f 85 88 00 00 00    	jne    401303 <main+0x14e>
  40127b:	48 8b 0d 46 32 20 00 	mov    0x203246(%rip),%rcx        # 6044c8 <optarg@@GLIBC_2.2.5>
  401282:	ba b2 30 40 00       	mov    $0x4030b2,%edx
  401287:	be 01 00 00 00       	mov    $0x1,%esi
  40128c:	48 8b 3d 4d 32 20 00 	mov    0x20324d(%rip),%rdi        # 6044e0 <stderr@@GLIBC_2.2.5>
  401293:	e8 d8 fb ff ff       	callq  400e70 <__fprintf_chk@plt>
  401298:	b8 01 00 00 00       	mov    $0x1,%eax
  40129d:	e9 e4 00 00 00       	jmpq   401386 <main+0x1d1>
  4012a2:	ba 10 00 00 00       	mov    $0x10,%edx
  4012a7:	be 00 00 00 00       	mov    $0x0,%esi
  4012ac:	48 8b 3d 15 32 20 00 	mov    0x203215(%rip),%rdi        # 6044c8 <optarg@@GLIBC_2.2.5>
  4012b3:	e8 78 fb ff ff       	callq  400e30 <strtoul@plt>
  4012b8:	41 89 c6             	mov    %eax,%r14d
  4012bb:	eb 46                	jmp    401303 <main+0x14e>
  4012bd:	ba 0a 00 00 00       	mov    $0xa,%edx
  4012c2:	be 00 00 00 00       	mov    $0x0,%esi
  4012c7:	48 8b 3d fa 31 20 00 	mov    0x2031fa(%rip),%rdi        # 6044c8 <optarg@@GLIBC_2.2.5>
  4012ce:	e8 bd fa ff ff       	callq  400d90 <strtol@plt>
  4012d3:	41 89 c5             	mov    %eax,%r13d
  4012d6:	eb 2b                	jmp    401303 <main+0x14e>
  4012d8:	c7 05 c6 31 20 00 00 	movl   $0x0,0x2031c6(%rip)        # 6044a8 <notify>
  4012df:	00 00 00 
  4012e2:	eb 1f                	jmp    401303 <main+0x14e>
  4012e4:	0f be d2             	movsbl %dl,%edx
  4012e7:	be cf 30 40 00       	mov    $0x4030cf,%esi
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
  40131b:	be 00 00 00 00       	mov    $0x0,%esi
  401320:	44 89 ef             	mov    %r13d,%edi
  401323:	e8 08 fd ff ff       	callq  401030 <initialize_target>
  401328:	83 3d f9 31 20 00 00 	cmpl   $0x0,0x2031f9(%rip)        # 604528 <is_checker>
  40132f:	74 2a                	je     40135b <main+0x1a6>
  401331:	44 3b 35 e8 31 20 00 	cmp    0x2031e8(%rip),%r14d        # 604520 <authkey>
  401338:	74 21                	je     40135b <main+0x1a6>
  40133a:	44 89 f2             	mov    %r14d,%edx
  40133d:	be 08 30 40 00       	mov    $0x403008,%esi
  401342:	bf 01 00 00 00       	mov    $0x1,%edi
  401347:	b8 00 00 00 00       	mov    $0x0,%eax
  40134c:	e8 af fa ff ff       	callq  400e00 <__printf_chk@plt>
  401351:	b8 00 00 00 00       	mov    $0x0,%eax
  401356:	e8 6f 07 00 00       	callq  401aca <check_fail>
  40135b:	8b 15 c3 31 20 00    	mov    0x2031c3(%rip),%edx        # 604524 <cookie>
  401361:	be e2 30 40 00       	mov    $0x4030e2,%esi
  401366:	bf 01 00 00 00       	mov    $0x1,%edi
  40136b:	b8 00 00 00 00       	mov    $0x0,%eax
  401370:	e8 8b fa ff ff       	callq  400e00 <__printf_chk@plt>
  401375:	48 8b 3d 24 31 20 00 	mov    0x203124(%rip),%rdi        # 6044a0 <buf_offset>
  40137c:	e8 97 0c 00 00       	callq  402018 <stable_launch>
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
  40187c:	e8 7e 02 00 00       	callq  401aff <Gets>
  401881:	b8 01 00 00 00       	mov    $0x1,%eax
  401886:	48 83 c4 38          	add    $0x38,%rsp
  40188a:	c3                   	retq   

000000000040188b <touch1>:
  40188b:	48 83 ec 08          	sub    $0x8,%rsp
  40188f:	c7 05 83 2c 20 00 01 	movl   $0x1,0x202c83(%rip)        # 60451c <vlevel>
  401896:	00 00 00 
  401899:	bf d1 31 40 00       	mov    $0x4031d1,%edi
  40189e:	e8 2d f4 ff ff       	callq  400cd0 <puts@plt>
  4018a3:	bf 01 00 00 00       	mov    $0x1,%edi
  4018a8:	e8 97 04 00 00       	callq  401d44 <validate>
  4018ad:	bf 00 00 00 00       	mov    $0x0,%edi
  4018b2:	e8 99 f5 ff ff       	callq  400e50 <exit@plt>

00000000004018b7 <touch2>:
  4018b7:	48 83 ec 08          	sub    $0x8,%rsp
  4018bb:	89 fa                	mov    %edi,%edx
  4018bd:	c7 05 55 2c 20 00 02 	movl   $0x2,0x202c55(%rip)        # 60451c <vlevel>
  4018c4:	00 00 00 
  4018c7:	39 3d 57 2c 20 00    	cmp    %edi,0x202c57(%rip)        # 604524 <cookie>
  4018cd:	75 20                	jne    4018ef <touch2+0x38>
  4018cf:	be f8 31 40 00       	mov    $0x4031f8,%esi
  4018d4:	bf 01 00 00 00       	mov    $0x1,%edi
  4018d9:	b8 00 00 00 00       	mov    $0x0,%eax
  4018de:	e8 1d f5 ff ff       	callq  400e00 <__printf_chk@plt>
  4018e3:	bf 02 00 00 00       	mov    $0x2,%edi
  4018e8:	e8 57 04 00 00       	callq  401d44 <validate>
  4018ed:	eb 1e                	jmp    40190d <touch2+0x56>
  4018ef:	be 20 32 40 00       	mov    $0x403220,%esi
  4018f4:	bf 01 00 00 00       	mov    $0x1,%edi
  4018f9:	b8 00 00 00 00       	mov    $0x0,%eax
  4018fe:	e8 fd f4 ff ff       	callq  400e00 <__printf_chk@plt>
  401903:	bf 02 00 00 00       	mov    $0x2,%edi
  401908:	e8 f9 04 00 00       	callq  401e06 <fail>
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
  401974:	b9 ee 31 40 00       	mov    $0x4031ee,%ecx
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
  4019cc:	c7 05 46 2b 20 00 03 	movl   $0x3,0x202b46(%rip)        # 60451c <vlevel>
  4019d3:	00 00 00 
  4019d6:	48 89 fe             	mov    %rdi,%rsi
  4019d9:	8b 3d 45 2b 20 00    	mov    0x202b45(%rip),%edi        # 604524 <cookie>
  4019df:	e8 33 ff ff ff       	callq  401917 <hexmatch>
  4019e4:	85 c0                	test   %eax,%eax
  4019e6:	74 23                	je     401a0b <touch3+0x43>
  4019e8:	48 89 da             	mov    %rbx,%rdx
  4019eb:	be 48 32 40 00       	mov    $0x403248,%esi
  4019f0:	bf 01 00 00 00       	mov    $0x1,%edi
  4019f5:	b8 00 00 00 00       	mov    $0x0,%eax
  4019fa:	e8 01 f4 ff ff       	callq  400e00 <__printf_chk@plt>
  4019ff:	bf 03 00 00 00       	mov    $0x3,%edi
  401a04:	e8 3b 03 00 00       	callq  401d44 <validate>
  401a09:	eb 21                	jmp    401a2c <touch3+0x64>
  401a0b:	48 89 da             	mov    %rbx,%rdx
  401a0e:	be 70 32 40 00       	mov    $0x403270,%esi
  401a13:	bf 01 00 00 00       	mov    $0x1,%edi
  401a18:	b8 00 00 00 00       	mov    $0x0,%eax
  401a1d:	e8 de f3 ff ff       	callq  400e00 <__printf_chk@plt>
  401a22:	bf 03 00 00 00       	mov    $0x3,%edi
  401a27:	e8 da 03 00 00       	callq  401e06 <fail>
  401a2c:	bf 00 00 00 00       	mov    $0x0,%edi
  401a31:	e8 1a f4 ff ff       	callq  400e50 <exit@plt>

0000000000401a36 <test>:
  401a36:	48 83 ec 08          	sub    $0x8,%rsp
  401a3a:	b8 00 00 00 00       	mov    $0x0,%eax
  401a3f:	e8 31 fe ff ff       	callq  401875 <getbuf>
  401a44:	89 c2                	mov    %eax,%edx
  401a46:	be 98 32 40 00       	mov    $0x403298,%esi
  401a4b:	bf 01 00 00 00       	mov    $0x1,%edi
  401a50:	b8 00 00 00 00       	mov    $0x0,%eax
  401a55:	e8 a6 f3 ff ff       	callq  400e00 <__printf_chk@plt>
  401a5a:	48 83 c4 08          	add    $0x8,%rsp
  401a5e:	c3                   	retq   

0000000000401a5f <save_char>:
  401a5f:	8b 05 df 36 20 00    	mov    0x2036df(%rip),%eax        # 605144 <gets_cnt>
  401a65:	3d ff 03 00 00       	cmp    $0x3ff,%eax
  401a6a:	7f 49                	jg     401ab5 <save_char+0x56>
  401a6c:	8d 14 40             	lea    (%rax,%rax,2),%edx
  401a6f:	89 f9                	mov    %edi,%ecx
  401a71:	c0 e9 04             	shr    $0x4,%cl
  401a74:	83 e1 0f             	and    $0xf,%ecx
  401a77:	0f b6 b1 c0 35 40 00 	movzbl 0x4035c0(%rcx),%esi
  401a7e:	48 63 ca             	movslq %edx,%rcx
  401a81:	40 88 b1 40 45 60 00 	mov    %sil,0x604540(%rcx)
  401a88:	8d 4a 01             	lea    0x1(%rdx),%ecx
  401a8b:	83 e7 0f             	and    $0xf,%edi
  401a8e:	0f b6 b7 c0 35 40 00 	movzbl 0x4035c0(%rdi),%esi
  401a95:	48 63 c9             	movslq %ecx,%rcx
  401a98:	40 88 b1 40 45 60 00 	mov    %sil,0x604540(%rcx)
  401a9f:	83 c2 02             	add    $0x2,%edx
  401aa2:	48 63 d2             	movslq %edx,%rdx
  401aa5:	c6 82 40 45 60 00 20 	movb   $0x20,0x604540(%rdx)
  401aac:	83 c0 01             	add    $0x1,%eax
  401aaf:	89 05 8f 36 20 00    	mov    %eax,0x20368f(%rip)        # 605144 <gets_cnt>
  401ab5:	f3 c3                	repz retq 

0000000000401ab7 <save_term>:
  401ab7:	8b 05 87 36 20 00    	mov    0x203687(%rip),%eax        # 605144 <gets_cnt>
  401abd:	8d 04 40             	lea    (%rax,%rax,2),%eax
  401ac0:	48 98                	cltq   
  401ac2:	c6 80 40 45 60 00 00 	movb   $0x0,0x604540(%rax)
  401ac9:	c3                   	retq   

0000000000401aca <check_fail>:
  401aca:	48 83 ec 08          	sub    $0x8,%rsp
  401ace:	0f be 15 73 36 20 00 	movsbl 0x203673(%rip),%edx        # 605148 <target_prefix>
  401ad5:	41 b8 40 45 60 00    	mov    $0x604540,%r8d
  401adb:	8b 0d 37 2a 20 00    	mov    0x202a37(%rip),%ecx        # 604518 <check_level>
  401ae1:	be bb 32 40 00       	mov    $0x4032bb,%esi
  401ae6:	bf 01 00 00 00       	mov    $0x1,%edi
  401aeb:	b8 00 00 00 00       	mov    $0x0,%eax
  401af0:	e8 0b f3 ff ff       	callq  400e00 <__printf_chk@plt>
  401af5:	bf 01 00 00 00       	mov    $0x1,%edi
  401afa:	e8 51 f3 ff ff       	callq  400e50 <exit@plt>

0000000000401aff <Gets>:
  401aff:	41 54                	push   %r12
  401b01:	55                   	push   %rbp
  401b02:	53                   	push   %rbx
  401b03:	49 89 fc             	mov    %rdi,%r12
  401b06:	c7 05 34 36 20 00 00 	movl   $0x0,0x203634(%rip)        # 605144 <gets_cnt>
  401b0d:	00 00 00 
  401b10:	48 89 fb             	mov    %rdi,%rbx
  401b13:	eb 11                	jmp    401b26 <Gets+0x27>
  401b15:	48 8d 6b 01          	lea    0x1(%rbx),%rbp
  401b19:	88 03                	mov    %al,(%rbx)
  401b1b:	0f b6 f8             	movzbl %al,%edi
  401b1e:	e8 3c ff ff ff       	callq  401a5f <save_char>
  401b23:	48 89 eb             	mov    %rbp,%rbx
  401b26:	48 8b 3d e3 29 20 00 	mov    0x2029e3(%rip),%rdi        # 604510 <infile>
  401b2d:	e8 9e f2 ff ff       	callq  400dd0 <_IO_getc@plt>
  401b32:	83 f8 ff             	cmp    $0xffffffff,%eax
  401b35:	74 05                	je     401b3c <Gets+0x3d>
  401b37:	83 f8 0a             	cmp    $0xa,%eax
  401b3a:	75 d9                	jne    401b15 <Gets+0x16>
  401b3c:	c6 03 00             	movb   $0x0,(%rbx)
  401b3f:	b8 00 00 00 00       	mov    $0x0,%eax
  401b44:	e8 6e ff ff ff       	callq  401ab7 <save_term>
  401b49:	4c 89 e0             	mov    %r12,%rax
  401b4c:	5b                   	pop    %rbx
  401b4d:	5d                   	pop    %rbp
  401b4e:	41 5c                	pop    %r12
  401b50:	c3                   	retq   

0000000000401b51 <notify_server>:
  401b51:	53                   	push   %rbx
  401b52:	48 81 ec 10 40 00 00 	sub    $0x4010,%rsp
  401b59:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  401b60:	00 00 
  401b62:	48 89 84 24 08 40 00 	mov    %rax,0x4008(%rsp)
  401b69:	00 
  401b6a:	31 c0                	xor    %eax,%eax
  401b6c:	83 3d b5 29 20 00 00 	cmpl   $0x0,0x2029b5(%rip)        # 604528 <is_checker>
  401b73:	0f 85 aa 01 00 00    	jne    401d23 <notify_server+0x1d2>
  401b79:	89 fb                	mov    %edi,%ebx
  401b7b:	8b 05 c3 35 20 00    	mov    0x2035c3(%rip),%eax        # 605144 <gets_cnt>
  401b81:	83 c0 64             	add    $0x64,%eax
  401b84:	3d 00 20 00 00       	cmp    $0x2000,%eax
  401b89:	7e 1e                	jle    401ba9 <notify_server+0x58>
  401b8b:	be f0 33 40 00       	mov    $0x4033f0,%esi
  401b90:	bf 01 00 00 00       	mov    $0x1,%edi
  401b95:	b8 00 00 00 00       	mov    $0x0,%eax
  401b9a:	e8 61 f2 ff ff       	callq  400e00 <__printf_chk@plt>
  401b9f:	bf 01 00 00 00       	mov    $0x1,%edi
  401ba4:	e8 a7 f2 ff ff       	callq  400e50 <exit@plt>
  401ba9:	0f be 05 98 35 20 00 	movsbl 0x203598(%rip),%eax        # 605148 <target_prefix>
  401bb0:	83 3d f1 28 20 00 00 	cmpl   $0x0,0x2028f1(%rip)        # 6044a8 <notify>
  401bb7:	74 08                	je     401bc1 <notify_server+0x70>
  401bb9:	8b 15 61 29 20 00    	mov    0x202961(%rip),%edx        # 604520 <authkey>
  401bbf:	eb 05                	jmp    401bc6 <notify_server+0x75>
  401bc1:	ba ff ff ff ff       	mov    $0xffffffff,%edx
  401bc6:	85 db                	test   %ebx,%ebx
  401bc8:	74 08                	je     401bd2 <notify_server+0x81>
  401bca:	41 b9 d1 32 40 00    	mov    $0x4032d1,%r9d
  401bd0:	eb 06                	jmp    401bd8 <notify_server+0x87>
  401bd2:	41 b9 d6 32 40 00    	mov    $0x4032d6,%r9d
  401bd8:	68 40 45 60 00       	pushq  $0x604540
  401bdd:	56                   	push   %rsi
  401bde:	50                   	push   %rax
  401bdf:	52                   	push   %rdx
  401be0:	44 8b 05 81 25 20 00 	mov    0x202581(%rip),%r8d        # 604168 <target_id>
  401be7:	b9 db 32 40 00       	mov    $0x4032db,%ecx
  401bec:	ba 00 20 00 00       	mov    $0x2000,%edx
  401bf1:	be 01 00 00 00       	mov    $0x1,%esi
  401bf6:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  401bfb:	b8 00 00 00 00       	mov    $0x0,%eax
  401c00:	e8 7b f2 ff ff       	callq  400e80 <__sprintf_chk@plt>
  401c05:	48 83 c4 20          	add    $0x20,%rsp
  401c09:	83 3d 98 28 20 00 00 	cmpl   $0x0,0x202898(%rip)        # 6044a8 <notify>
  401c10:	0f 84 81 00 00 00    	je     401c97 <notify_server+0x146>
  401c16:	85 db                	test   %ebx,%ebx
  401c18:	74 6e                	je     401c88 <notify_server+0x137>
  401c1a:	4c 8d 8c 24 00 20 00 	lea    0x2000(%rsp),%r9
  401c21:	00 
  401c22:	41 b8 00 00 00 00    	mov    $0x0,%r8d
  401c28:	48 89 e1             	mov    %rsp,%rcx
  401c2b:	48 8b 15 3e 25 20 00 	mov    0x20253e(%rip),%rdx        # 604170 <lab>
  401c32:	48 8b 35 3f 25 20 00 	mov    0x20253f(%rip),%rsi        # 604178 <course>
  401c39:	48 8b 3d 20 25 20 00 	mov    0x202520(%rip),%rdi        # 604160 <user_id>
  401c40:	e8 ef 10 00 00       	callq  402d34 <driver_post>
  401c45:	85 c0                	test   %eax,%eax
  401c47:	79 26                	jns    401c6f <notify_server+0x11e>
  401c49:	48 8d 94 24 00 20 00 	lea    0x2000(%rsp),%rdx
  401c50:	00 
  401c51:	be f7 32 40 00       	mov    $0x4032f7,%esi
  401c56:	bf 01 00 00 00       	mov    $0x1,%edi
  401c5b:	b8 00 00 00 00       	mov    $0x0,%eax
  401c60:	e8 9b f1 ff ff       	callq  400e00 <__printf_chk@plt>
  401c65:	bf 01 00 00 00       	mov    $0x1,%edi
  401c6a:	e8 e1 f1 ff ff       	callq  400e50 <exit@plt>
  401c6f:	bf 20 34 40 00       	mov    $0x403420,%edi
  401c74:	e8 57 f0 ff ff       	callq  400cd0 <puts@plt>
  401c79:	bf 03 33 40 00       	mov    $0x403303,%edi
  401c7e:	e8 4d f0 ff ff       	callq  400cd0 <puts@plt>
  401c83:	e9 9b 00 00 00       	jmpq   401d23 <notify_server+0x1d2>
  401c88:	bf 0d 33 40 00       	mov    $0x40330d,%edi
  401c8d:	e8 3e f0 ff ff       	callq  400cd0 <puts@plt>
  401c92:	e9 8c 00 00 00       	jmpq   401d23 <notify_server+0x1d2>
  401c97:	85 db                	test   %ebx,%ebx
  401c99:	74 07                	je     401ca2 <notify_server+0x151>
  401c9b:	ba d1 32 40 00       	mov    $0x4032d1,%edx
  401ca0:	eb 05                	jmp    401ca7 <notify_server+0x156>
  401ca2:	ba d6 32 40 00       	mov    $0x4032d6,%edx
  401ca7:	be 58 34 40 00       	mov    $0x403458,%esi
  401cac:	bf 01 00 00 00       	mov    $0x1,%edi
  401cb1:	b8 00 00 00 00       	mov    $0x0,%eax
  401cb6:	e8 45 f1 ff ff       	callq  400e00 <__printf_chk@plt>
  401cbb:	48 8b 15 9e 24 20 00 	mov    0x20249e(%rip),%rdx        # 604160 <user_id>
  401cc2:	be 14 33 40 00       	mov    $0x403314,%esi
  401cc7:	bf 01 00 00 00       	mov    $0x1,%edi
  401ccc:	b8 00 00 00 00       	mov    $0x0,%eax
  401cd1:	e8 2a f1 ff ff       	callq  400e00 <__printf_chk@plt>
  401cd6:	48 8b 15 9b 24 20 00 	mov    0x20249b(%rip),%rdx        # 604178 <course>
  401cdd:	be 21 33 40 00       	mov    $0x403321,%esi
  401ce2:	bf 01 00 00 00       	mov    $0x1,%edi
  401ce7:	b8 00 00 00 00       	mov    $0x0,%eax
  401cec:	e8 0f f1 ff ff       	callq  400e00 <__printf_chk@plt>
  401cf1:	48 8b 15 78 24 20 00 	mov    0x202478(%rip),%rdx        # 604170 <lab>
  401cf8:	be 2d 33 40 00       	mov    $0x40332d,%esi
  401cfd:	bf 01 00 00 00       	mov    $0x1,%edi
  401d02:	b8 00 00 00 00       	mov    $0x0,%eax
  401d07:	e8 f4 f0 ff ff       	callq  400e00 <__printf_chk@plt>
  401d0c:	48 89 e2             	mov    %rsp,%rdx
  401d0f:	be 36 33 40 00       	mov    $0x403336,%esi
  401d14:	bf 01 00 00 00       	mov    $0x1,%edi
  401d19:	b8 00 00 00 00       	mov    $0x0,%eax
  401d1e:	e8 dd f0 ff ff       	callq  400e00 <__printf_chk@plt>
  401d23:	48 8b 84 24 08 40 00 	mov    0x4008(%rsp),%rax
  401d2a:	00 
  401d2b:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  401d32:	00 00 
  401d34:	74 05                	je     401d3b <notify_server+0x1ea>
  401d36:	e8 b5 ef ff ff       	callq  400cf0 <__stack_chk_fail@plt>
  401d3b:	48 81 c4 10 40 00 00 	add    $0x4010,%rsp
  401d42:	5b                   	pop    %rbx
  401d43:	c3                   	retq   

0000000000401d44 <validate>:
  401d44:	53                   	push   %rbx
  401d45:	89 fb                	mov    %edi,%ebx
  401d47:	83 3d da 27 20 00 00 	cmpl   $0x0,0x2027da(%rip)        # 604528 <is_checker>
  401d4e:	74 6b                	je     401dbb <validate+0x77>
  401d50:	39 3d c6 27 20 00    	cmp    %edi,0x2027c6(%rip)        # 60451c <vlevel>
  401d56:	74 14                	je     401d6c <validate+0x28>
  401d58:	bf 42 33 40 00       	mov    $0x403342,%edi
  401d5d:	e8 6e ef ff ff       	callq  400cd0 <puts@plt>
  401d62:	b8 00 00 00 00       	mov    $0x0,%eax
  401d67:	e8 5e fd ff ff       	callq  401aca <check_fail>
  401d6c:	8b 15 a6 27 20 00    	mov    0x2027a6(%rip),%edx        # 604518 <check_level>
  401d72:	39 d7                	cmp    %edx,%edi
  401d74:	74 20                	je     401d96 <validate+0x52>
  401d76:	89 f9                	mov    %edi,%ecx
  401d78:	be 80 34 40 00       	mov    $0x403480,%esi
  401d7d:	bf 01 00 00 00       	mov    $0x1,%edi
  401d82:	b8 00 00 00 00       	mov    $0x0,%eax
  401d87:	e8 74 f0 ff ff       	callq  400e00 <__printf_chk@plt>
  401d8c:	b8 00 00 00 00       	mov    $0x0,%eax
  401d91:	e8 34 fd ff ff       	callq  401aca <check_fail>
  401d96:	0f be 15 ab 33 20 00 	movsbl 0x2033ab(%rip),%edx        # 605148 <target_prefix>
  401d9d:	41 b8 40 45 60 00    	mov    $0x604540,%r8d
  401da3:	89 f9                	mov    %edi,%ecx
  401da5:	be 60 33 40 00       	mov    $0x403360,%esi
  401daa:	bf 01 00 00 00       	mov    $0x1,%edi
  401daf:	b8 00 00 00 00       	mov    $0x0,%eax
  401db4:	e8 47 f0 ff ff       	callq  400e00 <__printf_chk@plt>
  401db9:	eb 49                	jmp    401e04 <validate+0xc0>
  401dbb:	3b 3d 5b 27 20 00    	cmp    0x20275b(%rip),%edi        # 60451c <vlevel>
  401dc1:	74 18                	je     401ddb <validate+0x97>
  401dc3:	bf 42 33 40 00       	mov    $0x403342,%edi
  401dc8:	e8 03 ef ff ff       	callq  400cd0 <puts@plt>
  401dcd:	89 de                	mov    %ebx,%esi
  401dcf:	bf 00 00 00 00       	mov    $0x0,%edi
  401dd4:	e8 78 fd ff ff       	callq  401b51 <notify_server>
  401dd9:	eb 29                	jmp    401e04 <validate+0xc0>
  401ddb:	0f be 0d 66 33 20 00 	movsbl 0x203366(%rip),%ecx        # 605148 <target_prefix>
  401de2:	89 fa                	mov    %edi,%edx
  401de4:	be a8 34 40 00       	mov    $0x4034a8,%esi
  401de9:	bf 01 00 00 00       	mov    $0x1,%edi
  401dee:	b8 00 00 00 00       	mov    $0x0,%eax
  401df3:	e8 08 f0 ff ff       	callq  400e00 <__printf_chk@plt>
  401df8:	89 de                	mov    %ebx,%esi
  401dfa:	bf 01 00 00 00       	mov    $0x1,%edi
  401dff:	e8 4d fd ff ff       	callq  401b51 <notify_server>
  401e04:	5b                   	pop    %rbx
  401e05:	c3                   	retq   

0000000000401e06 <fail>:
  401e06:	48 83 ec 08          	sub    $0x8,%rsp
  401e0a:	83 3d 17 27 20 00 00 	cmpl   $0x0,0x202717(%rip)        # 604528 <is_checker>
  401e11:	74 0a                	je     401e1d <fail+0x17>
  401e13:	b8 00 00 00 00       	mov    $0x0,%eax
  401e18:	e8 ad fc ff ff       	callq  401aca <check_fail>
  401e1d:	89 fe                	mov    %edi,%esi
  401e1f:	bf 00 00 00 00       	mov    $0x0,%edi
  401e24:	e8 28 fd ff ff       	callq  401b51 <notify_server>
  401e29:	48 83 c4 08          	add    $0x8,%rsp
  401e2d:	c3                   	retq   

0000000000401e2e <bushandler>:
  401e2e:	48 83 ec 08          	sub    $0x8,%rsp
  401e32:	83 3d ef 26 20 00 00 	cmpl   $0x0,0x2026ef(%rip)        # 604528 <is_checker>
  401e39:	74 14                	je     401e4f <bushandler+0x21>
  401e3b:	bf 75 33 40 00       	mov    $0x403375,%edi
  401e40:	e8 8b ee ff ff       	callq  400cd0 <puts@plt>
  401e45:	b8 00 00 00 00       	mov    $0x0,%eax
  401e4a:	e8 7b fc ff ff       	callq  401aca <check_fail>
  401e4f:	bf e0 34 40 00       	mov    $0x4034e0,%edi
  401e54:	e8 77 ee ff ff       	callq  400cd0 <puts@plt>
  401e59:	bf 7f 33 40 00       	mov    $0x40337f,%edi
  401e5e:	e8 6d ee ff ff       	callq  400cd0 <puts@plt>
  401e63:	be 00 00 00 00       	mov    $0x0,%esi
  401e68:	bf 00 00 00 00       	mov    $0x0,%edi
  401e6d:	e8 df fc ff ff       	callq  401b51 <notify_server>
  401e72:	bf 01 00 00 00       	mov    $0x1,%edi
  401e77:	e8 d4 ef ff ff       	callq  400e50 <exit@plt>

0000000000401e7c <seghandler>:
  401e7c:	48 83 ec 08          	sub    $0x8,%rsp
  401e80:	83 3d a1 26 20 00 00 	cmpl   $0x0,0x2026a1(%rip)        # 604528 <is_checker>
  401e87:	74 14                	je     401e9d <seghandler+0x21>
  401e89:	bf 95 33 40 00       	mov    $0x403395,%edi
  401e8e:	e8 3d ee ff ff       	callq  400cd0 <puts@plt>
  401e93:	b8 00 00 00 00       	mov    $0x0,%eax
  401e98:	e8 2d fc ff ff       	callq  401aca <check_fail>
  401e9d:	bf 00 35 40 00       	mov    $0x403500,%edi
  401ea2:	e8 29 ee ff ff       	callq  400cd0 <puts@plt>
  401ea7:	bf 7f 33 40 00       	mov    $0x40337f,%edi
  401eac:	e8 1f ee ff ff       	callq  400cd0 <puts@plt>
  401eb1:	be 00 00 00 00       	mov    $0x0,%esi
  401eb6:	bf 00 00 00 00       	mov    $0x0,%edi
  401ebb:	e8 91 fc ff ff       	callq  401b51 <notify_server>
  401ec0:	bf 01 00 00 00       	mov    $0x1,%edi
  401ec5:	e8 86 ef ff ff       	callq  400e50 <exit@plt>

0000000000401eca <illegalhandler>:
  401eca:	48 83 ec 08          	sub    $0x8,%rsp
  401ece:	83 3d 53 26 20 00 00 	cmpl   $0x0,0x202653(%rip)        # 604528 <is_checker>
  401ed5:	74 14                	je     401eeb <illegalhandler+0x21>
  401ed7:	bf a8 33 40 00       	mov    $0x4033a8,%edi
  401edc:	e8 ef ed ff ff       	callq  400cd0 <puts@plt>
  401ee1:	b8 00 00 00 00       	mov    $0x0,%eax
  401ee6:	e8 df fb ff ff       	callq  401aca <check_fail>
  401eeb:	bf 28 35 40 00       	mov    $0x403528,%edi
  401ef0:	e8 db ed ff ff       	callq  400cd0 <puts@plt>
  401ef5:	bf 7f 33 40 00       	mov    $0x40337f,%edi
  401efa:	e8 d1 ed ff ff       	callq  400cd0 <puts@plt>
  401eff:	be 00 00 00 00       	mov    $0x0,%esi
  401f04:	bf 00 00 00 00       	mov    $0x0,%edi
  401f09:	e8 43 fc ff ff       	callq  401b51 <notify_server>
  401f0e:	bf 01 00 00 00       	mov    $0x1,%edi
  401f13:	e8 38 ef ff ff       	callq  400e50 <exit@plt>

0000000000401f18 <sigalrmhandler>:
  401f18:	48 83 ec 08          	sub    $0x8,%rsp
  401f1c:	83 3d 05 26 20 00 00 	cmpl   $0x0,0x202605(%rip)        # 604528 <is_checker>
  401f23:	74 14                	je     401f39 <sigalrmhandler+0x21>
  401f25:	bf bc 33 40 00       	mov    $0x4033bc,%edi
  401f2a:	e8 a1 ed ff ff       	callq  400cd0 <puts@plt>
  401f2f:	b8 00 00 00 00       	mov    $0x0,%eax
  401f34:	e8 91 fb ff ff       	callq  401aca <check_fail>
  401f39:	ba 05 00 00 00       	mov    $0x5,%edx
  401f3e:	be 58 35 40 00       	mov    $0x403558,%esi
  401f43:	bf 01 00 00 00       	mov    $0x1,%edi
  401f48:	b8 00 00 00 00       	mov    $0x0,%eax
  401f4d:	e8 ae ee ff ff       	callq  400e00 <__printf_chk@plt>
  401f52:	be 00 00 00 00       	mov    $0x0,%esi
  401f57:	bf 00 00 00 00       	mov    $0x0,%edi
  401f5c:	e8 f0 fb ff ff       	callq  401b51 <notify_server>
  401f61:	bf 01 00 00 00       	mov    $0x1,%edi
  401f66:	e8 e5 ee ff ff       	callq  400e50 <exit@plt>

0000000000401f6b <launch>:
  401f6b:	55                   	push   %rbp
  401f6c:	48 89 e5             	mov    %rsp,%rbp
  401f6f:	48 83 ec 10          	sub    $0x10,%rsp
  401f73:	48 89 fa             	mov    %rdi,%rdx
  401f76:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  401f7d:	00 00 
  401f7f:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  401f83:	31 c0                	xor    %eax,%eax
  401f85:	48 8d 47 1e          	lea    0x1e(%rdi),%rax
  401f89:	48 83 e0 f0          	and    $0xfffffffffffffff0,%rax
  401f8d:	48 29 c4             	sub    %rax,%rsp
  401f90:	48 8d 7c 24 0f       	lea    0xf(%rsp),%rdi
  401f95:	48 83 e7 f0          	and    $0xfffffffffffffff0,%rdi
  401f99:	be f4 00 00 00       	mov    $0xf4,%esi
  401f9e:	e8 6d ed ff ff       	callq  400d10 <memset@plt>
  401fa3:	48 8b 05 16 25 20 00 	mov    0x202516(%rip),%rax        # 6044c0 <stdin@@GLIBC_2.2.5>
  401faa:	48 39 05 5f 25 20 00 	cmp    %rax,0x20255f(%rip)        # 604510 <infile>
  401fb1:	75 14                	jne    401fc7 <launch+0x5c>
  401fb3:	be c4 33 40 00       	mov    $0x4033c4,%esi
  401fb8:	bf 01 00 00 00       	mov    $0x1,%edi
  401fbd:	b8 00 00 00 00       	mov    $0x0,%eax
  401fc2:	e8 39 ee ff ff       	callq  400e00 <__printf_chk@plt>
  401fc7:	c7 05 4b 25 20 00 00 	movl   $0x0,0x20254b(%rip)        # 60451c <vlevel>
  401fce:	00 00 00 
  401fd1:	b8 00 00 00 00       	mov    $0x0,%eax
  401fd6:	e8 5b fa ff ff       	callq  401a36 <test>
  401fdb:	83 3d 46 25 20 00 00 	cmpl   $0x0,0x202546(%rip)        # 604528 <is_checker>
  401fe2:	74 14                	je     401ff8 <launch+0x8d>
  401fe4:	bf d1 33 40 00       	mov    $0x4033d1,%edi
  401fe9:	e8 e2 ec ff ff       	callq  400cd0 <puts@plt>
  401fee:	b8 00 00 00 00       	mov    $0x0,%eax
  401ff3:	e8 d2 fa ff ff       	callq  401aca <check_fail>
  401ff8:	bf dc 33 40 00       	mov    $0x4033dc,%edi
  401ffd:	e8 ce ec ff ff       	callq  400cd0 <puts@plt>
  402002:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  402006:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  40200d:	00 00 
  40200f:	74 05                	je     402016 <launch+0xab>
  402011:	e8 da ec ff ff       	callq  400cf0 <__stack_chk_fail@plt>
  402016:	c9                   	leaveq 
  402017:	c3                   	retq   

0000000000402018 <stable_launch>:
  402018:	53                   	push   %rbx
  402019:	48 89 3d e8 24 20 00 	mov    %rdi,0x2024e8(%rip)        # 604508 <global_offset>
  402020:	41 b9 00 00 00 00    	mov    $0x0,%r9d
  402026:	41 b8 00 00 00 00    	mov    $0x0,%r8d
  40202c:	b9 32 01 00 00       	mov    $0x132,%ecx
  402031:	ba 07 00 00 00       	mov    $0x7,%edx
  402036:	be 00 00 10 00       	mov    $0x100000,%esi
  40203b:	bf 00 60 58 55       	mov    $0x55586000,%edi
  402040:	e8 bb ec ff ff       	callq  400d00 <mmap@plt>
  402045:	48 89 c3             	mov    %rax,%rbx
  402048:	48 3d 00 60 58 55    	cmp    $0x55586000,%rax
  40204e:	74 37                	je     402087 <stable_launch+0x6f>
  402050:	be 00 00 10 00       	mov    $0x100000,%esi
  402055:	48 89 c7             	mov    %rax,%rdi
  402058:	e8 93 ed ff ff       	callq  400df0 <munmap@plt>
  40205d:	b9 00 60 58 55       	mov    $0x55586000,%ecx
  402062:	ba 90 35 40 00       	mov    $0x403590,%edx
  402067:	be 01 00 00 00       	mov    $0x1,%esi
  40206c:	48 8b 3d 6d 24 20 00 	mov    0x20246d(%rip),%rdi        # 6044e0 <stderr@@GLIBC_2.2.5>
  402073:	b8 00 00 00 00       	mov    $0x0,%eax
  402078:	e8 f3 ed ff ff       	callq  400e70 <__fprintf_chk@plt>
  40207d:	bf 01 00 00 00       	mov    $0x1,%edi
  402082:	e8 c9 ed ff ff       	callq  400e50 <exit@plt>
  402087:	48 8d 90 f8 ff 0f 00 	lea    0xffff8(%rax),%rdx
  40208e:	48 89 15 bb 30 20 00 	mov    %rdx,0x2030bb(%rip)        # 605150 <stack_top>
  402095:	48 89 e0             	mov    %rsp,%rax
  402098:	48 89 d4             	mov    %rdx,%rsp
  40209b:	48 89 c2             	mov    %rax,%rdx
  40209e:	48 89 15 5b 24 20 00 	mov    %rdx,0x20245b(%rip)        # 604500 <global_save_stack>
  4020a5:	48 8b 3d 5c 24 20 00 	mov    0x20245c(%rip),%rdi        # 604508 <global_offset>
  4020ac:	e8 ba fe ff ff       	callq  401f6b <launch>
  4020b1:	48 8b 05 48 24 20 00 	mov    0x202448(%rip),%rax        # 604500 <global_save_stack>
  4020b8:	48 89 c4             	mov    %rax,%rsp
  4020bb:	be 00 00 10 00       	mov    $0x100000,%esi
  4020c0:	48 89 df             	mov    %rbx,%rdi
  4020c3:	e8 28 ed ff ff       	callq  400df0 <munmap@plt>
  4020c8:	5b                   	pop    %rbx
  4020c9:	c3                   	retq   

00000000004020ca <rio_readinitb>:
  4020ca:	89 37                	mov    %esi,(%rdi)
  4020cc:	c7 47 04 00 00 00 00 	movl   $0x0,0x4(%rdi)
  4020d3:	48 8d 47 10          	lea    0x10(%rdi),%rax
  4020d7:	48 89 47 08          	mov    %rax,0x8(%rdi)
  4020db:	c3                   	retq   

00000000004020dc <sigalrm_handler>:
  4020dc:	48 83 ec 08          	sub    $0x8,%rsp
  4020e0:	b9 00 00 00 00       	mov    $0x0,%ecx
  4020e5:	ba d0 35 40 00       	mov    $0x4035d0,%edx
  4020ea:	be 01 00 00 00       	mov    $0x1,%esi
  4020ef:	48 8b 3d ea 23 20 00 	mov    0x2023ea(%rip),%rdi        # 6044e0 <stderr@@GLIBC_2.2.5>
  4020f6:	b8 00 00 00 00       	mov    $0x0,%eax
  4020fb:	e8 70 ed ff ff       	callq  400e70 <__fprintf_chk@plt>
  402100:	bf 01 00 00 00       	mov    $0x1,%edi
  402105:	e8 46 ed ff ff       	callq  400e50 <exit@plt>

000000000040210a <rio_writen>:
  40210a:	41 55                	push   %r13
  40210c:	41 54                	push   %r12
  40210e:	55                   	push   %rbp
  40210f:	53                   	push   %rbx
  402110:	48 83 ec 08          	sub    $0x8,%rsp
  402114:	41 89 fc             	mov    %edi,%r12d
  402117:	48 89 f5             	mov    %rsi,%rbp
  40211a:	49 89 d5             	mov    %rdx,%r13
  40211d:	48 89 d3             	mov    %rdx,%rbx
  402120:	eb 28                	jmp    40214a <rio_writen+0x40>
  402122:	48 89 da             	mov    %rbx,%rdx
  402125:	48 89 ee             	mov    %rbp,%rsi
  402128:	44 89 e7             	mov    %r12d,%edi
  40212b:	e8 b0 eb ff ff       	callq  400ce0 <write@plt>
  402130:	48 85 c0             	test   %rax,%rax
  402133:	7f 0f                	jg     402144 <rio_writen+0x3a>
  402135:	e8 56 eb ff ff       	callq  400c90 <__errno_location@plt>
  40213a:	83 38 04             	cmpl   $0x4,(%rax)
  40213d:	75 15                	jne    402154 <rio_writen+0x4a>
  40213f:	b8 00 00 00 00       	mov    $0x0,%eax
  402144:	48 29 c3             	sub    %rax,%rbx
  402147:	48 01 c5             	add    %rax,%rbp
  40214a:	48 85 db             	test   %rbx,%rbx
  40214d:	75 d3                	jne    402122 <rio_writen+0x18>
  40214f:	4c 89 e8             	mov    %r13,%rax
  402152:	eb 07                	jmp    40215b <rio_writen+0x51>
  402154:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
  40215b:	48 83 c4 08          	add    $0x8,%rsp
  40215f:	5b                   	pop    %rbx
  402160:	5d                   	pop    %rbp
  402161:	41 5c                	pop    %r12
  402163:	41 5d                	pop    %r13
  402165:	c3                   	retq   

0000000000402166 <rio_read>:
  402166:	41 55                	push   %r13
  402168:	41 54                	push   %r12
  40216a:	55                   	push   %rbp
  40216b:	53                   	push   %rbx
  40216c:	48 83 ec 08          	sub    $0x8,%rsp
  402170:	48 89 fb             	mov    %rdi,%rbx
  402173:	49 89 f5             	mov    %rsi,%r13
  402176:	49 89 d4             	mov    %rdx,%r12
  402179:	eb 2e                	jmp    4021a9 <rio_read+0x43>
  40217b:	48 8d 6b 10          	lea    0x10(%rbx),%rbp
  40217f:	8b 3b                	mov    (%rbx),%edi
  402181:	ba 00 20 00 00       	mov    $0x2000,%edx
  402186:	48 89 ee             	mov    %rbp,%rsi
  402189:	e8 b2 eb ff ff       	callq  400d40 <read@plt>
  40218e:	89 43 04             	mov    %eax,0x4(%rbx)
  402191:	85 c0                	test   %eax,%eax
  402193:	79 0c                	jns    4021a1 <rio_read+0x3b>
  402195:	e8 f6 ea ff ff       	callq  400c90 <__errno_location@plt>
  40219a:	83 38 04             	cmpl   $0x4,(%rax)
  40219d:	74 0a                	je     4021a9 <rio_read+0x43>
  40219f:	eb 37                	jmp    4021d8 <rio_read+0x72>
  4021a1:	85 c0                	test   %eax,%eax
  4021a3:	74 3c                	je     4021e1 <rio_read+0x7b>
  4021a5:	48 89 6b 08          	mov    %rbp,0x8(%rbx)
  4021a9:	8b 6b 04             	mov    0x4(%rbx),%ebp
  4021ac:	85 ed                	test   %ebp,%ebp
  4021ae:	7e cb                	jle    40217b <rio_read+0x15>
  4021b0:	89 e8                	mov    %ebp,%eax
  4021b2:	49 39 c4             	cmp    %rax,%r12
  4021b5:	77 03                	ja     4021ba <rio_read+0x54>
  4021b7:	44 89 e5             	mov    %r12d,%ebp
  4021ba:	4c 63 e5             	movslq %ebp,%r12
  4021bd:	48 8b 73 08          	mov    0x8(%rbx),%rsi
  4021c1:	4c 89 e2             	mov    %r12,%rdx
  4021c4:	4c 89 ef             	mov    %r13,%rdi
  4021c7:	e8 d4 eb ff ff       	callq  400da0 <memcpy@plt>
  4021cc:	4c 01 63 08          	add    %r12,0x8(%rbx)
  4021d0:	29 6b 04             	sub    %ebp,0x4(%rbx)
  4021d3:	4c 89 e0             	mov    %r12,%rax
  4021d6:	eb 0e                	jmp    4021e6 <rio_read+0x80>
  4021d8:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
  4021df:	eb 05                	jmp    4021e6 <rio_read+0x80>
  4021e1:	b8 00 00 00 00       	mov    $0x0,%eax
  4021e6:	48 83 c4 08          	add    $0x8,%rsp
  4021ea:	5b                   	pop    %rbx
  4021eb:	5d                   	pop    %rbp
  4021ec:	41 5c                	pop    %r12
  4021ee:	41 5d                	pop    %r13
  4021f0:	c3                   	retq   

00000000004021f1 <rio_readlineb>:
  4021f1:	41 55                	push   %r13
  4021f3:	41 54                	push   %r12
  4021f5:	55                   	push   %rbp
  4021f6:	53                   	push   %rbx
  4021f7:	48 83 ec 18          	sub    $0x18,%rsp
  4021fb:	49 89 fd             	mov    %rdi,%r13
  4021fe:	48 89 f5             	mov    %rsi,%rbp
  402201:	49 89 d4             	mov    %rdx,%r12
  402204:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  40220b:	00 00 
  40220d:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
  402212:	31 c0                	xor    %eax,%eax
  402214:	bb 01 00 00 00       	mov    $0x1,%ebx
  402219:	eb 3f                	jmp    40225a <rio_readlineb+0x69>
  40221b:	ba 01 00 00 00       	mov    $0x1,%edx
  402220:	48 8d 74 24 07       	lea    0x7(%rsp),%rsi
  402225:	4c 89 ef             	mov    %r13,%rdi
  402228:	e8 39 ff ff ff       	callq  402166 <rio_read>
  40222d:	83 f8 01             	cmp    $0x1,%eax
  402230:	75 15                	jne    402247 <rio_readlineb+0x56>
  402232:	48 8d 45 01          	lea    0x1(%rbp),%rax
  402236:	0f b6 54 24 07       	movzbl 0x7(%rsp),%edx
  40223b:	88 55 00             	mov    %dl,0x0(%rbp)
  40223e:	80 7c 24 07 0a       	cmpb   $0xa,0x7(%rsp)
  402243:	75 0e                	jne    402253 <rio_readlineb+0x62>
  402245:	eb 1a                	jmp    402261 <rio_readlineb+0x70>
  402247:	85 c0                	test   %eax,%eax
  402249:	75 22                	jne    40226d <rio_readlineb+0x7c>
  40224b:	48 83 fb 01          	cmp    $0x1,%rbx
  40224f:	75 13                	jne    402264 <rio_readlineb+0x73>
  402251:	eb 23                	jmp    402276 <rio_readlineb+0x85>
  402253:	48 83 c3 01          	add    $0x1,%rbx
  402257:	48 89 c5             	mov    %rax,%rbp
  40225a:	4c 39 e3             	cmp    %r12,%rbx
  40225d:	72 bc                	jb     40221b <rio_readlineb+0x2a>
  40225f:	eb 03                	jmp    402264 <rio_readlineb+0x73>
  402261:	48 89 c5             	mov    %rax,%rbp
  402264:	c6 45 00 00          	movb   $0x0,0x0(%rbp)
  402268:	48 89 d8             	mov    %rbx,%rax
  40226b:	eb 0e                	jmp    40227b <rio_readlineb+0x8a>
  40226d:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
  402274:	eb 05                	jmp    40227b <rio_readlineb+0x8a>
  402276:	b8 00 00 00 00       	mov    $0x0,%eax
  40227b:	48 8b 4c 24 08       	mov    0x8(%rsp),%rcx
  402280:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
  402287:	00 00 
  402289:	74 05                	je     402290 <rio_readlineb+0x9f>
  40228b:	e8 60 ea ff ff       	callq  400cf0 <__stack_chk_fail@plt>
  402290:	48 83 c4 18          	add    $0x18,%rsp
  402294:	5b                   	pop    %rbx
  402295:	5d                   	pop    %rbp
  402296:	41 5c                	pop    %r12
  402298:	41 5d                	pop    %r13
  40229a:	c3                   	retq   

000000000040229b <urlencode>:
  40229b:	41 54                	push   %r12
  40229d:	55                   	push   %rbp
  40229e:	53                   	push   %rbx
  40229f:	48 83 ec 10          	sub    $0x10,%rsp
  4022a3:	48 89 fb             	mov    %rdi,%rbx
  4022a6:	48 89 f5             	mov    %rsi,%rbp
  4022a9:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  4022b0:	00 00 
  4022b2:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
  4022b7:	31 c0                	xor    %eax,%eax
  4022b9:	48 c7 c1 ff ff ff ff 	mov    $0xffffffffffffffff,%rcx
  4022c0:	f2 ae                	repnz scas %es:(%rdi),%al
  4022c2:	48 f7 d1             	not    %rcx
  4022c5:	8d 41 ff             	lea    -0x1(%rcx),%eax
  4022c8:	e9 aa 00 00 00       	jmpq   402377 <urlencode+0xdc>
  4022cd:	44 0f b6 03          	movzbl (%rbx),%r8d
  4022d1:	41 80 f8 2a          	cmp    $0x2a,%r8b
  4022d5:	0f 94 c2             	sete   %dl
  4022d8:	41 80 f8 2d          	cmp    $0x2d,%r8b
  4022dc:	0f 94 c0             	sete   %al
  4022df:	08 c2                	or     %al,%dl
  4022e1:	75 24                	jne    402307 <urlencode+0x6c>
  4022e3:	41 80 f8 2e          	cmp    $0x2e,%r8b
  4022e7:	74 1e                	je     402307 <urlencode+0x6c>
  4022e9:	41 80 f8 5f          	cmp    $0x5f,%r8b
  4022ed:	74 18                	je     402307 <urlencode+0x6c>
  4022ef:	41 8d 40 d0          	lea    -0x30(%r8),%eax
  4022f3:	3c 09                	cmp    $0x9,%al
  4022f5:	76 10                	jbe    402307 <urlencode+0x6c>
  4022f7:	41 8d 40 bf          	lea    -0x41(%r8),%eax
  4022fb:	3c 19                	cmp    $0x19,%al
  4022fd:	76 08                	jbe    402307 <urlencode+0x6c>
  4022ff:	41 8d 40 9f          	lea    -0x61(%r8),%eax
  402303:	3c 19                	cmp    $0x19,%al
  402305:	77 0a                	ja     402311 <urlencode+0x76>
  402307:	44 88 45 00          	mov    %r8b,0x0(%rbp)
  40230b:	48 8d 6d 01          	lea    0x1(%rbp),%rbp
  40230f:	eb 5f                	jmp    402370 <urlencode+0xd5>
  402311:	41 80 f8 20          	cmp    $0x20,%r8b
  402315:	75 0a                	jne    402321 <urlencode+0x86>
  402317:	c6 45 00 2b          	movb   $0x2b,0x0(%rbp)
  40231b:	48 8d 6d 01          	lea    0x1(%rbp),%rbp
  40231f:	eb 4f                	jmp    402370 <urlencode+0xd5>
  402321:	41 8d 40 e0          	lea    -0x20(%r8),%eax
  402325:	3c 5f                	cmp    $0x5f,%al
  402327:	0f 96 c2             	setbe  %dl
  40232a:	41 80 f8 09          	cmp    $0x9,%r8b
  40232e:	0f 94 c0             	sete   %al
  402331:	08 c2                	or     %al,%dl
  402333:	74 50                	je     402385 <urlencode+0xea>
  402335:	45 0f b6 c0          	movzbl %r8b,%r8d
  402339:	b9 68 36 40 00       	mov    $0x403668,%ecx
  40233e:	ba 08 00 00 00       	mov    $0x8,%edx
  402343:	be 01 00 00 00       	mov    $0x1,%esi
  402348:	48 89 e7             	mov    %rsp,%rdi
  40234b:	b8 00 00 00 00       	mov    $0x0,%eax
  402350:	e8 2b eb ff ff       	callq  400e80 <__sprintf_chk@plt>
  402355:	0f b6 04 24          	movzbl (%rsp),%eax
  402359:	88 45 00             	mov    %al,0x0(%rbp)
  40235c:	0f b6 44 24 01       	movzbl 0x1(%rsp),%eax
  402361:	88 45 01             	mov    %al,0x1(%rbp)
  402364:	0f b6 44 24 02       	movzbl 0x2(%rsp),%eax
  402369:	88 45 02             	mov    %al,0x2(%rbp)
  40236c:	48 8d 6d 03          	lea    0x3(%rbp),%rbp
  402370:	48 83 c3 01          	add    $0x1,%rbx
  402374:	44 89 e0             	mov    %r12d,%eax
  402377:	44 8d 60 ff          	lea    -0x1(%rax),%r12d
  40237b:	85 c0                	test   %eax,%eax
  40237d:	0f 85 4a ff ff ff    	jne    4022cd <urlencode+0x32>
  402383:	eb 05                	jmp    40238a <urlencode+0xef>
  402385:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  40238a:	48 8b 74 24 08       	mov    0x8(%rsp),%rsi
  40238f:	64 48 33 34 25 28 00 	xor    %fs:0x28,%rsi
  402396:	00 00 
  402398:	74 05                	je     40239f <urlencode+0x104>
  40239a:	e8 51 e9 ff ff       	callq  400cf0 <__stack_chk_fail@plt>
  40239f:	48 83 c4 10          	add    $0x10,%rsp
  4023a3:	5b                   	pop    %rbx
  4023a4:	5d                   	pop    %rbp
  4023a5:	41 5c                	pop    %r12
  4023a7:	c3                   	retq   

00000000004023a8 <submitr>:
  4023a8:	41 57                	push   %r15
  4023aa:	41 56                	push   %r14
  4023ac:	41 55                	push   %r13
  4023ae:	41 54                	push   %r12
  4023b0:	55                   	push   %rbp
  4023b1:	53                   	push   %rbx
  4023b2:	48 81 ec 58 a0 00 00 	sub    $0xa058,%rsp
  4023b9:	49 89 fc             	mov    %rdi,%r12
  4023bc:	89 74 24 04          	mov    %esi,0x4(%rsp)
  4023c0:	49 89 d7             	mov    %rdx,%r15
  4023c3:	49 89 ce             	mov    %rcx,%r14
  4023c6:	4c 89 44 24 08       	mov    %r8,0x8(%rsp)
  4023cb:	4d 89 cd             	mov    %r9,%r13
  4023ce:	48 8b 9c 24 90 a0 00 	mov    0xa090(%rsp),%rbx
  4023d5:	00 
  4023d6:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  4023dd:	00 00 
  4023df:	48 89 84 24 48 a0 00 	mov    %rax,0xa048(%rsp)
  4023e6:	00 
  4023e7:	31 c0                	xor    %eax,%eax
  4023e9:	c7 44 24 1c 00 00 00 	movl   $0x0,0x1c(%rsp)
  4023f0:	00 
  4023f1:	ba 00 00 00 00       	mov    $0x0,%edx
  4023f6:	be 01 00 00 00       	mov    $0x1,%esi
  4023fb:	bf 02 00 00 00       	mov    $0x2,%edi
  402400:	e8 8b ea ff ff       	callq  400e90 <socket@plt>
  402405:	85 c0                	test   %eax,%eax
  402407:	79 4e                	jns    402457 <submitr+0xaf>
  402409:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  402410:	3a 20 43 
  402413:	48 89 03             	mov    %rax,(%rbx)
  402416:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  40241d:	20 75 6e 
  402420:	48 89 43 08          	mov    %rax,0x8(%rbx)
  402424:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  40242b:	74 6f 20 
  40242e:	48 89 43 10          	mov    %rax,0x10(%rbx)
  402432:	48 b8 63 72 65 61 74 	movabs $0x7320657461657263,%rax
  402439:	65 20 73 
  40243c:	48 89 43 18          	mov    %rax,0x18(%rbx)
  402440:	c7 43 20 6f 63 6b 65 	movl   $0x656b636f,0x20(%rbx)
  402447:	66 c7 43 24 74 00    	movw   $0x74,0x24(%rbx)
  40244d:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402452:	e9 97 06 00 00       	jmpq   402aee <submitr+0x746>
  402457:	89 c5                	mov    %eax,%ebp
  402459:	4c 89 e7             	mov    %r12,%rdi
  40245c:	e8 0f e9 ff ff       	callq  400d70 <gethostbyname@plt>
  402461:	48 85 c0             	test   %rax,%rax
  402464:	75 67                	jne    4024cd <submitr+0x125>
  402466:	48 b8 45 72 72 6f 72 	movabs $0x44203a726f727245,%rax
  40246d:	3a 20 44 
  402470:	48 89 03             	mov    %rax,(%rbx)
  402473:	48 b8 4e 53 20 69 73 	movabs $0x6e7520736920534e,%rax
  40247a:	20 75 6e 
  40247d:	48 89 43 08          	mov    %rax,0x8(%rbx)
  402481:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  402488:	74 6f 20 
  40248b:	48 89 43 10          	mov    %rax,0x10(%rbx)
  40248f:	48 b8 72 65 73 6f 6c 	movabs $0x2065766c6f736572,%rax
  402496:	76 65 20 
  402499:	48 89 43 18          	mov    %rax,0x18(%rbx)
  40249d:	48 b8 73 65 72 76 65 	movabs $0x6120726576726573,%rax
  4024a4:	72 20 61 
  4024a7:	48 89 43 20          	mov    %rax,0x20(%rbx)
  4024ab:	c7 43 28 64 64 72 65 	movl   $0x65726464,0x28(%rbx)
  4024b2:	66 c7 43 2c 73 73    	movw   $0x7373,0x2c(%rbx)
  4024b8:	c6 43 2e 00          	movb   $0x0,0x2e(%rbx)
  4024bc:	89 ef                	mov    %ebp,%edi
  4024be:	e8 6d e8 ff ff       	callq  400d30 <close@plt>
  4024c3:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  4024c8:	e9 21 06 00 00       	jmpq   402aee <submitr+0x746>
  4024cd:	48 c7 44 24 20 00 00 	movq   $0x0,0x20(%rsp)
  4024d4:	00 00 
  4024d6:	48 c7 44 24 28 00 00 	movq   $0x0,0x28(%rsp)
  4024dd:	00 00 
  4024df:	66 c7 44 24 20 02 00 	movw   $0x2,0x20(%rsp)
  4024e6:	48 63 50 14          	movslq 0x14(%rax),%rdx
  4024ea:	48 8b 40 18          	mov    0x18(%rax),%rax
  4024ee:	48 8b 30             	mov    (%rax),%rsi
  4024f1:	48 8d 7c 24 24       	lea    0x24(%rsp),%rdi
  4024f6:	b9 0c 00 00 00       	mov    $0xc,%ecx
  4024fb:	e8 80 e8 ff ff       	callq  400d80 <__memmove_chk@plt>
  402500:	0f b7 44 24 04       	movzwl 0x4(%rsp),%eax
  402505:	66 c1 c8 08          	ror    $0x8,%ax
  402509:	66 89 44 24 22       	mov    %ax,0x22(%rsp)
  40250e:	ba 10 00 00 00       	mov    $0x10,%edx
  402513:	48 8d 74 24 20       	lea    0x20(%rsp),%rsi
  402518:	89 ef                	mov    %ebp,%edi
  40251a:	e8 41 e9 ff ff       	callq  400e60 <connect@plt>
  40251f:	85 c0                	test   %eax,%eax
  402521:	79 59                	jns    40257c <submitr+0x1d4>
  402523:	48 b8 45 72 72 6f 72 	movabs $0x55203a726f727245,%rax
  40252a:	3a 20 55 
  40252d:	48 89 03             	mov    %rax,(%rbx)
  402530:	48 b8 6e 61 62 6c 65 	movabs $0x6f7420656c62616e,%rax
  402537:	20 74 6f 
  40253a:	48 89 43 08          	mov    %rax,0x8(%rbx)
  40253e:	48 b8 20 63 6f 6e 6e 	movabs $0x7463656e6e6f6320,%rax
  402545:	65 63 74 
  402548:	48 89 43 10          	mov    %rax,0x10(%rbx)
  40254c:	48 b8 20 74 6f 20 74 	movabs $0x20656874206f7420,%rax
  402553:	68 65 20 
  402556:	48 89 43 18          	mov    %rax,0x18(%rbx)
  40255a:	c7 43 20 73 65 72 76 	movl   $0x76726573,0x20(%rbx)
  402561:	66 c7 43 24 65 72    	movw   $0x7265,0x24(%rbx)
  402567:	c6 43 26 00          	movb   $0x0,0x26(%rbx)
  40256b:	89 ef                	mov    %ebp,%edi
  40256d:	e8 be e7 ff ff       	callq  400d30 <close@plt>
  402572:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402577:	e9 72 05 00 00       	jmpq   402aee <submitr+0x746>
  40257c:	48 c7 c6 ff ff ff ff 	mov    $0xffffffffffffffff,%rsi
  402583:	b8 00 00 00 00       	mov    $0x0,%eax
  402588:	48 89 f1             	mov    %rsi,%rcx
  40258b:	4c 89 ef             	mov    %r13,%rdi
  40258e:	f2 ae                	repnz scas %es:(%rdi),%al
  402590:	48 f7 d1             	not    %rcx
  402593:	48 89 ca             	mov    %rcx,%rdx
  402596:	48 89 f1             	mov    %rsi,%rcx
  402599:	4c 89 ff             	mov    %r15,%rdi
  40259c:	f2 ae                	repnz scas %es:(%rdi),%al
  40259e:	48 f7 d1             	not    %rcx
  4025a1:	49 89 c8             	mov    %rcx,%r8
  4025a4:	48 89 f1             	mov    %rsi,%rcx
  4025a7:	4c 89 f7             	mov    %r14,%rdi
  4025aa:	f2 ae                	repnz scas %es:(%rdi),%al
  4025ac:	48 f7 d1             	not    %rcx
  4025af:	4d 8d 44 08 fe       	lea    -0x2(%r8,%rcx,1),%r8
  4025b4:	48 89 f1             	mov    %rsi,%rcx
  4025b7:	48 8b 7c 24 08       	mov    0x8(%rsp),%rdi
  4025bc:	f2 ae                	repnz scas %es:(%rdi),%al
  4025be:	48 89 c8             	mov    %rcx,%rax
  4025c1:	48 f7 d0             	not    %rax
  4025c4:	49 8d 4c 00 ff       	lea    -0x1(%r8,%rax,1),%rcx
  4025c9:	48 8d 44 52 fd       	lea    -0x3(%rdx,%rdx,2),%rax
  4025ce:	48 8d 84 01 80 00 00 	lea    0x80(%rcx,%rax,1),%rax
  4025d5:	00 
  4025d6:	48 3d 00 20 00 00    	cmp    $0x2000,%rax
  4025dc:	76 72                	jbe    402650 <submitr+0x2a8>
  4025de:	48 b8 45 72 72 6f 72 	movabs $0x52203a726f727245,%rax
  4025e5:	3a 20 52 
  4025e8:	48 89 03             	mov    %rax,(%rbx)
  4025eb:	48 b8 65 73 75 6c 74 	movabs $0x747320746c757365,%rax
  4025f2:	20 73 74 
  4025f5:	48 89 43 08          	mov    %rax,0x8(%rbx)
  4025f9:	48 b8 72 69 6e 67 20 	movabs $0x6f6f7420676e6972,%rax
  402600:	74 6f 6f 
  402603:	48 89 43 10          	mov    %rax,0x10(%rbx)
  402607:	48 b8 20 6c 61 72 67 	movabs $0x202e656772616c20,%rax
  40260e:	65 2e 20 
  402611:	48 89 43 18          	mov    %rax,0x18(%rbx)
  402615:	48 b8 49 6e 63 72 65 	movabs $0x6573616572636e49,%rax
  40261c:	61 73 65 
  40261f:	48 89 43 20          	mov    %rax,0x20(%rbx)
  402623:	48 b8 20 53 55 42 4d 	movabs $0x5254494d42555320,%rax
  40262a:	49 54 52 
  40262d:	48 89 43 28          	mov    %rax,0x28(%rbx)
  402631:	48 b8 5f 4d 41 58 42 	movabs $0x46554258414d5f,%rax
  402638:	55 46 00 
  40263b:	48 89 43 30          	mov    %rax,0x30(%rbx)
  40263f:	89 ef                	mov    %ebp,%edi
  402641:	e8 ea e6 ff ff       	callq  400d30 <close@plt>
  402646:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  40264b:	e9 9e 04 00 00       	jmpq   402aee <submitr+0x746>
  402650:	48 8d b4 24 40 40 00 	lea    0x4040(%rsp),%rsi
  402657:	00 
  402658:	b9 00 04 00 00       	mov    $0x400,%ecx
  40265d:	b8 00 00 00 00       	mov    $0x0,%eax
  402662:	48 89 f7             	mov    %rsi,%rdi
  402665:	f3 48 ab             	rep stos %rax,%es:(%rdi)
  402668:	4c 89 ef             	mov    %r13,%rdi
  40266b:	e8 2b fc ff ff       	callq  40229b <urlencode>
  402670:	85 c0                	test   %eax,%eax
  402672:	0f 89 8a 00 00 00    	jns    402702 <submitr+0x35a>
  402678:	48 b8 45 72 72 6f 72 	movabs $0x52203a726f727245,%rax
  40267f:	3a 20 52 
  402682:	48 89 03             	mov    %rax,(%rbx)
  402685:	48 b8 65 73 75 6c 74 	movabs $0x747320746c757365,%rax
  40268c:	20 73 74 
  40268f:	48 89 43 08          	mov    %rax,0x8(%rbx)
  402693:	48 b8 72 69 6e 67 20 	movabs $0x6e6f6320676e6972,%rax
  40269a:	63 6f 6e 
  40269d:	48 89 43 10          	mov    %rax,0x10(%rbx)
  4026a1:	48 b8 74 61 69 6e 73 	movabs $0x6e6120736e696174,%rax
  4026a8:	20 61 6e 
  4026ab:	48 89 43 18          	mov    %rax,0x18(%rbx)
  4026af:	48 b8 20 69 6c 6c 65 	movabs $0x6c6167656c6c6920,%rax
  4026b6:	67 61 6c 
  4026b9:	48 89 43 20          	mov    %rax,0x20(%rbx)
  4026bd:	48 b8 20 6f 72 20 75 	movabs $0x72706e7520726f20,%rax
  4026c4:	6e 70 72 
  4026c7:	48 89 43 28          	mov    %rax,0x28(%rbx)
  4026cb:	48 b8 69 6e 74 61 62 	movabs $0x20656c6261746e69,%rax
  4026d2:	6c 65 20 
  4026d5:	48 89 43 30          	mov    %rax,0x30(%rbx)
  4026d9:	48 b8 63 68 61 72 61 	movabs $0x6574636172616863,%rax
  4026e0:	63 74 65 
  4026e3:	48 89 43 38          	mov    %rax,0x38(%rbx)
  4026e7:	66 c7 43 40 72 2e    	movw   $0x2e72,0x40(%rbx)
  4026ed:	c6 43 42 00          	movb   $0x0,0x42(%rbx)
  4026f1:	89 ef                	mov    %ebp,%edi
  4026f3:	e8 38 e6 ff ff       	callq  400d30 <close@plt>
  4026f8:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  4026fd:	e9 ec 03 00 00       	jmpq   402aee <submitr+0x746>
  402702:	4c 8d ac 24 40 20 00 	lea    0x2040(%rsp),%r13
  402709:	00 
  40270a:	41 54                	push   %r12
  40270c:	48 8d 84 24 48 40 00 	lea    0x4048(%rsp),%rax
  402713:	00 
  402714:	50                   	push   %rax
  402715:	4d 89 f9             	mov    %r15,%r9
  402718:	4d 89 f0             	mov    %r14,%r8
  40271b:	b9 f8 35 40 00       	mov    $0x4035f8,%ecx
  402720:	ba 00 20 00 00       	mov    $0x2000,%edx
  402725:	be 01 00 00 00       	mov    $0x1,%esi
  40272a:	4c 89 ef             	mov    %r13,%rdi
  40272d:	b8 00 00 00 00       	mov    $0x0,%eax
  402732:	e8 49 e7 ff ff       	callq  400e80 <__sprintf_chk@plt>
  402737:	b8 00 00 00 00       	mov    $0x0,%eax
  40273c:	48 c7 c1 ff ff ff ff 	mov    $0xffffffffffffffff,%rcx
  402743:	4c 89 ef             	mov    %r13,%rdi
  402746:	f2 ae                	repnz scas %es:(%rdi),%al
  402748:	48 f7 d1             	not    %rcx
  40274b:	48 8d 51 ff          	lea    -0x1(%rcx),%rdx
  40274f:	4c 89 ee             	mov    %r13,%rsi
  402752:	89 ef                	mov    %ebp,%edi
  402754:	e8 b1 f9 ff ff       	callq  40210a <rio_writen>
  402759:	48 83 c4 10          	add    $0x10,%rsp
  40275d:	48 85 c0             	test   %rax,%rax
  402760:	79 6e                	jns    4027d0 <submitr+0x428>
  402762:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  402769:	3a 20 43 
  40276c:	48 89 03             	mov    %rax,(%rbx)
  40276f:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  402776:	20 75 6e 
  402779:	48 89 43 08          	mov    %rax,0x8(%rbx)
  40277d:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  402784:	74 6f 20 
  402787:	48 89 43 10          	mov    %rax,0x10(%rbx)
  40278b:	48 b8 77 72 69 74 65 	movabs $0x6f74206574697277,%rax
  402792:	20 74 6f 
  402795:	48 89 43 18          	mov    %rax,0x18(%rbx)
  402799:	48 b8 20 74 68 65 20 	movabs $0x7365722065687420,%rax
  4027a0:	72 65 73 
  4027a3:	48 89 43 20          	mov    %rax,0x20(%rbx)
  4027a7:	48 b8 75 6c 74 20 73 	movabs $0x7672657320746c75,%rax
  4027ae:	65 72 76 
  4027b1:	48 89 43 28          	mov    %rax,0x28(%rbx)
  4027b5:	66 c7 43 30 65 72    	movw   $0x7265,0x30(%rbx)
  4027bb:	c6 43 32 00          	movb   $0x0,0x32(%rbx)
  4027bf:	89 ef                	mov    %ebp,%edi
  4027c1:	e8 6a e5 ff ff       	callq  400d30 <close@plt>
  4027c6:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  4027cb:	e9 1e 03 00 00       	jmpq   402aee <submitr+0x746>
  4027d0:	89 ee                	mov    %ebp,%esi
  4027d2:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  4027d7:	e8 ee f8 ff ff       	callq  4020ca <rio_readinitb>
  4027dc:	ba 00 20 00 00       	mov    $0x2000,%edx
  4027e1:	48 8d b4 24 40 20 00 	lea    0x2040(%rsp),%rsi
  4027e8:	00 
  4027e9:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  4027ee:	e8 fe f9 ff ff       	callq  4021f1 <rio_readlineb>
  4027f3:	48 85 c0             	test   %rax,%rax
  4027f6:	7f 7d                	jg     402875 <submitr+0x4cd>
  4027f8:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  4027ff:	3a 20 43 
  402802:	48 89 03             	mov    %rax,(%rbx)
  402805:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  40280c:	20 75 6e 
  40280f:	48 89 43 08          	mov    %rax,0x8(%rbx)
  402813:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  40281a:	74 6f 20 
  40281d:	48 89 43 10          	mov    %rax,0x10(%rbx)
  402821:	48 b8 72 65 61 64 20 	movabs $0x7269662064616572,%rax
  402828:	66 69 72 
  40282b:	48 89 43 18          	mov    %rax,0x18(%rbx)
  40282f:	48 b8 73 74 20 68 65 	movabs $0x6564616568207473,%rax
  402836:	61 64 65 
  402839:	48 89 43 20          	mov    %rax,0x20(%rbx)
  40283d:	48 b8 72 20 66 72 6f 	movabs $0x72206d6f72662072,%rax
  402844:	6d 20 72 
  402847:	48 89 43 28          	mov    %rax,0x28(%rbx)
  40284b:	48 b8 65 73 75 6c 74 	movabs $0x657320746c757365,%rax
  402852:	20 73 65 
  402855:	48 89 43 30          	mov    %rax,0x30(%rbx)
  402859:	c7 43 38 72 76 65 72 	movl   $0x72657672,0x38(%rbx)
  402860:	c6 43 3c 00          	movb   $0x0,0x3c(%rbx)
  402864:	89 ef                	mov    %ebp,%edi
  402866:	e8 c5 e4 ff ff       	callq  400d30 <close@plt>
  40286b:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402870:	e9 79 02 00 00       	jmpq   402aee <submitr+0x746>
  402875:	4c 8d 84 24 40 80 00 	lea    0x8040(%rsp),%r8
  40287c:	00 
  40287d:	48 8d 4c 24 1c       	lea    0x1c(%rsp),%rcx
  402882:	48 8d 94 24 40 60 00 	lea    0x6040(%rsp),%rdx
  402889:	00 
  40288a:	be 6f 36 40 00       	mov    $0x40366f,%esi
  40288f:	48 8d bc 24 40 20 00 	lea    0x2040(%rsp),%rdi
  402896:	00 
  402897:	b8 00 00 00 00       	mov    $0x0,%eax
  40289c:	e8 3f e5 ff ff       	callq  400de0 <__isoc99_sscanf@plt>
  4028a1:	e9 95 00 00 00       	jmpq   40293b <submitr+0x593>
  4028a6:	ba 00 20 00 00       	mov    $0x2000,%edx
  4028ab:	48 8d b4 24 40 20 00 	lea    0x2040(%rsp),%rsi
  4028b2:	00 
  4028b3:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  4028b8:	e8 34 f9 ff ff       	callq  4021f1 <rio_readlineb>
  4028bd:	48 85 c0             	test   %rax,%rax
  4028c0:	7f 79                	jg     40293b <submitr+0x593>
  4028c2:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  4028c9:	3a 20 43 
  4028cc:	48 89 03             	mov    %rax,(%rbx)
  4028cf:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  4028d6:	20 75 6e 
  4028d9:	48 89 43 08          	mov    %rax,0x8(%rbx)
  4028dd:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  4028e4:	74 6f 20 
  4028e7:	48 89 43 10          	mov    %rax,0x10(%rbx)
  4028eb:	48 b8 72 65 61 64 20 	movabs $0x6165682064616572,%rax
  4028f2:	68 65 61 
  4028f5:	48 89 43 18          	mov    %rax,0x18(%rbx)
  4028f9:	48 b8 64 65 72 73 20 	movabs $0x6f72662073726564,%rax
  402900:	66 72 6f 
  402903:	48 89 43 20          	mov    %rax,0x20(%rbx)
  402907:	48 b8 6d 20 74 68 65 	movabs $0x657220656874206d,%rax
  40290e:	20 72 65 
  402911:	48 89 43 28          	mov    %rax,0x28(%rbx)
  402915:	48 b8 73 75 6c 74 20 	movabs $0x72657320746c7573,%rax
  40291c:	73 65 72 
  40291f:	48 89 43 30          	mov    %rax,0x30(%rbx)
  402923:	c7 43 38 76 65 72 00 	movl   $0x726576,0x38(%rbx)
  40292a:	89 ef                	mov    %ebp,%edi
  40292c:	e8 ff e3 ff ff       	callq  400d30 <close@plt>
  402931:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402936:	e9 b3 01 00 00       	jmpq   402aee <submitr+0x746>
  40293b:	0f b6 94 24 40 20 00 	movzbl 0x2040(%rsp),%edx
  402942:	00 
  402943:	b8 0d 00 00 00       	mov    $0xd,%eax
  402948:	29 d0                	sub    %edx,%eax
  40294a:	75 1b                	jne    402967 <submitr+0x5bf>
  40294c:	0f b6 94 24 41 20 00 	movzbl 0x2041(%rsp),%edx
  402953:	00 
  402954:	b8 0a 00 00 00       	mov    $0xa,%eax
  402959:	29 d0                	sub    %edx,%eax
  40295b:	75 0a                	jne    402967 <submitr+0x5bf>
  40295d:	0f b6 84 24 42 20 00 	movzbl 0x2042(%rsp),%eax
  402964:	00 
  402965:	f7 d8                	neg    %eax
  402967:	85 c0                	test   %eax,%eax
  402969:	0f 85 37 ff ff ff    	jne    4028a6 <submitr+0x4fe>
  40296f:	ba 00 20 00 00       	mov    $0x2000,%edx
  402974:	48 8d b4 24 40 20 00 	lea    0x2040(%rsp),%rsi
  40297b:	00 
  40297c:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  402981:	e8 6b f8 ff ff       	callq  4021f1 <rio_readlineb>
  402986:	48 85 c0             	test   %rax,%rax
  402989:	0f 8f 83 00 00 00    	jg     402a12 <submitr+0x66a>
  40298f:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  402996:	3a 20 43 
  402999:	48 89 03             	mov    %rax,(%rbx)
  40299c:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  4029a3:	20 75 6e 
  4029a6:	48 89 43 08          	mov    %rax,0x8(%rbx)
  4029aa:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  4029b1:	74 6f 20 
  4029b4:	48 89 43 10          	mov    %rax,0x10(%rbx)
  4029b8:	48 b8 72 65 61 64 20 	movabs $0x6174732064616572,%rax
  4029bf:	73 74 61 
  4029c2:	48 89 43 18          	mov    %rax,0x18(%rbx)
  4029c6:	48 b8 74 75 73 20 6d 	movabs $0x7373656d20737574,%rax
  4029cd:	65 73 73 
  4029d0:	48 89 43 20          	mov    %rax,0x20(%rbx)
  4029d4:	48 b8 61 67 65 20 66 	movabs $0x6d6f726620656761,%rax
  4029db:	72 6f 6d 
  4029de:	48 89 43 28          	mov    %rax,0x28(%rbx)
  4029e2:	48 b8 20 72 65 73 75 	movabs $0x20746c7573657220,%rax
  4029e9:	6c 74 20 
  4029ec:	48 89 43 30          	mov    %rax,0x30(%rbx)
  4029f0:	c7 43 38 73 65 72 76 	movl   $0x76726573,0x38(%rbx)
  4029f7:	66 c7 43 3c 65 72    	movw   $0x7265,0x3c(%rbx)
  4029fd:	c6 43 3e 00          	movb   $0x0,0x3e(%rbx)
  402a01:	89 ef                	mov    %ebp,%edi
  402a03:	e8 28 e3 ff ff       	callq  400d30 <close@plt>
  402a08:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402a0d:	e9 dc 00 00 00       	jmpq   402aee <submitr+0x746>
  402a12:	44 8b 44 24 1c       	mov    0x1c(%rsp),%r8d
  402a17:	41 81 f8 c8 00 00 00 	cmp    $0xc8,%r8d
  402a1e:	74 37                	je     402a57 <submitr+0x6af>
  402a20:	4c 8d 8c 24 40 80 00 	lea    0x8040(%rsp),%r9
  402a27:	00 
  402a28:	b9 38 36 40 00       	mov    $0x403638,%ecx
  402a2d:	48 c7 c2 ff ff ff ff 	mov    $0xffffffffffffffff,%rdx
  402a34:	be 01 00 00 00       	mov    $0x1,%esi
  402a39:	48 89 df             	mov    %rbx,%rdi
  402a3c:	b8 00 00 00 00       	mov    $0x0,%eax
  402a41:	e8 3a e4 ff ff       	callq  400e80 <__sprintf_chk@plt>
  402a46:	89 ef                	mov    %ebp,%edi
  402a48:	e8 e3 e2 ff ff       	callq  400d30 <close@plt>
  402a4d:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402a52:	e9 97 00 00 00       	jmpq   402aee <submitr+0x746>
  402a57:	48 8d b4 24 40 20 00 	lea    0x2040(%rsp),%rsi
  402a5e:	00 
  402a5f:	48 89 df             	mov    %rbx,%rdi
  402a62:	e8 59 e2 ff ff       	callq  400cc0 <strcpy@plt>
  402a67:	89 ef                	mov    %ebp,%edi
  402a69:	e8 c2 e2 ff ff       	callq  400d30 <close@plt>
  402a6e:	0f b6 03             	movzbl (%rbx),%eax
  402a71:	ba 4f 00 00 00       	mov    $0x4f,%edx
  402a76:	29 c2                	sub    %eax,%edx
  402a78:	75 22                	jne    402a9c <submitr+0x6f4>
  402a7a:	0f b6 4b 01          	movzbl 0x1(%rbx),%ecx
  402a7e:	b8 4b 00 00 00       	mov    $0x4b,%eax
  402a83:	29 c8                	sub    %ecx,%eax
  402a85:	75 17                	jne    402a9e <submitr+0x6f6>
  402a87:	0f b6 4b 02          	movzbl 0x2(%rbx),%ecx
  402a8b:	b8 0a 00 00 00       	mov    $0xa,%eax
  402a90:	29 c8                	sub    %ecx,%eax
  402a92:	75 0a                	jne    402a9e <submitr+0x6f6>
  402a94:	0f b6 43 03          	movzbl 0x3(%rbx),%eax
  402a98:	f7 d8                	neg    %eax
  402a9a:	eb 02                	jmp    402a9e <submitr+0x6f6>
  402a9c:	89 d0                	mov    %edx,%eax
  402a9e:	85 c0                	test   %eax,%eax
  402aa0:	74 40                	je     402ae2 <submitr+0x73a>
  402aa2:	bf 80 36 40 00       	mov    $0x403680,%edi
  402aa7:	b9 05 00 00 00       	mov    $0x5,%ecx
  402aac:	48 89 de             	mov    %rbx,%rsi
  402aaf:	f3 a6                	repz cmpsb %es:(%rdi),%ds:(%rsi)
  402ab1:	0f 97 c0             	seta   %al
  402ab4:	0f 92 c1             	setb   %cl
  402ab7:	29 c8                	sub    %ecx,%eax
  402ab9:	0f be c0             	movsbl %al,%eax
  402abc:	85 c0                	test   %eax,%eax
  402abe:	74 2e                	je     402aee <submitr+0x746>
  402ac0:	85 d2                	test   %edx,%edx
  402ac2:	75 13                	jne    402ad7 <submitr+0x72f>
  402ac4:	0f b6 43 01          	movzbl 0x1(%rbx),%eax
  402ac8:	ba 4b 00 00 00       	mov    $0x4b,%edx
  402acd:	29 c2                	sub    %eax,%edx
  402acf:	75 06                	jne    402ad7 <submitr+0x72f>
  402ad1:	0f b6 53 02          	movzbl 0x2(%rbx),%edx
  402ad5:	f7 da                	neg    %edx
  402ad7:	85 d2                	test   %edx,%edx
  402ad9:	75 0e                	jne    402ae9 <submitr+0x741>
  402adb:	b8 00 00 00 00       	mov    $0x0,%eax
  402ae0:	eb 0c                	jmp    402aee <submitr+0x746>
  402ae2:	b8 00 00 00 00       	mov    $0x0,%eax
  402ae7:	eb 05                	jmp    402aee <submitr+0x746>
  402ae9:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402aee:	48 8b 9c 24 48 a0 00 	mov    0xa048(%rsp),%rbx
  402af5:	00 
  402af6:	64 48 33 1c 25 28 00 	xor    %fs:0x28,%rbx
  402afd:	00 00 
  402aff:	74 05                	je     402b06 <submitr+0x75e>
  402b01:	e8 ea e1 ff ff       	callq  400cf0 <__stack_chk_fail@plt>
  402b06:	48 81 c4 58 a0 00 00 	add    $0xa058,%rsp
  402b0d:	5b                   	pop    %rbx
  402b0e:	5d                   	pop    %rbp
  402b0f:	41 5c                	pop    %r12
  402b11:	41 5d                	pop    %r13
  402b13:	41 5e                	pop    %r14
  402b15:	41 5f                	pop    %r15
  402b17:	c3                   	retq   

0000000000402b18 <init_timeout>:
  402b18:	85 ff                	test   %edi,%edi
  402b1a:	74 23                	je     402b3f <init_timeout+0x27>
  402b1c:	53                   	push   %rbx
  402b1d:	89 fb                	mov    %edi,%ebx
  402b1f:	85 ff                	test   %edi,%edi
  402b21:	79 05                	jns    402b28 <init_timeout+0x10>
  402b23:	bb 00 00 00 00       	mov    $0x0,%ebx
  402b28:	be dc 20 40 00       	mov    $0x4020dc,%esi
  402b2d:	bf 0e 00 00 00       	mov    $0xe,%edi
  402b32:	e8 29 e2 ff ff       	callq  400d60 <signal@plt>
  402b37:	89 df                	mov    %ebx,%edi
  402b39:	e8 e2 e1 ff ff       	callq  400d20 <alarm@plt>
  402b3e:	5b                   	pop    %rbx
  402b3f:	f3 c3                	repz retq 

0000000000402b41 <init_driver>:
  402b41:	55                   	push   %rbp
  402b42:	53                   	push   %rbx
  402b43:	48 83 ec 28          	sub    $0x28,%rsp
  402b47:	48 89 fd             	mov    %rdi,%rbp
  402b4a:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  402b51:	00 00 
  402b53:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
  402b58:	31 c0                	xor    %eax,%eax
  402b5a:	be 01 00 00 00       	mov    $0x1,%esi
  402b5f:	bf 0d 00 00 00       	mov    $0xd,%edi
  402b64:	e8 f7 e1 ff ff       	callq  400d60 <signal@plt>
  402b69:	be 01 00 00 00       	mov    $0x1,%esi
  402b6e:	bf 1d 00 00 00       	mov    $0x1d,%edi
  402b73:	e8 e8 e1 ff ff       	callq  400d60 <signal@plt>
  402b78:	be 01 00 00 00       	mov    $0x1,%esi
  402b7d:	bf 1d 00 00 00       	mov    $0x1d,%edi
  402b82:	e8 d9 e1 ff ff       	callq  400d60 <signal@plt>
  402b87:	ba 00 00 00 00       	mov    $0x0,%edx
  402b8c:	be 01 00 00 00       	mov    $0x1,%esi
  402b91:	bf 02 00 00 00       	mov    $0x2,%edi
  402b96:	e8 f5 e2 ff ff       	callq  400e90 <socket@plt>
  402b9b:	85 c0                	test   %eax,%eax
  402b9d:	79 4f                	jns    402bee <init_driver+0xad>
  402b9f:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  402ba6:	3a 20 43 
  402ba9:	48 89 45 00          	mov    %rax,0x0(%rbp)
  402bad:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  402bb4:	20 75 6e 
  402bb7:	48 89 45 08          	mov    %rax,0x8(%rbp)
  402bbb:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  402bc2:	74 6f 20 
  402bc5:	48 89 45 10          	mov    %rax,0x10(%rbp)
  402bc9:	48 b8 63 72 65 61 74 	movabs $0x7320657461657263,%rax
  402bd0:	65 20 73 
  402bd3:	48 89 45 18          	mov    %rax,0x18(%rbp)
  402bd7:	c7 45 20 6f 63 6b 65 	movl   $0x656b636f,0x20(%rbp)
  402bde:	66 c7 45 24 74 00    	movw   $0x74,0x24(%rbp)
  402be4:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402be9:	e9 2a 01 00 00       	jmpq   402d18 <init_driver+0x1d7>
  402bee:	89 c3                	mov    %eax,%ebx
  402bf0:	bf ca 31 40 00       	mov    $0x4031ca,%edi
  402bf5:	e8 76 e1 ff ff       	callq  400d70 <gethostbyname@plt>
  402bfa:	48 85 c0             	test   %rax,%rax
  402bfd:	75 68                	jne    402c67 <init_driver+0x126>
  402bff:	48 b8 45 72 72 6f 72 	movabs $0x44203a726f727245,%rax
  402c06:	3a 20 44 
  402c09:	48 89 45 00          	mov    %rax,0x0(%rbp)
  402c0d:	48 b8 4e 53 20 69 73 	movabs $0x6e7520736920534e,%rax
  402c14:	20 75 6e 
  402c17:	48 89 45 08          	mov    %rax,0x8(%rbp)
  402c1b:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  402c22:	74 6f 20 
  402c25:	48 89 45 10          	mov    %rax,0x10(%rbp)
  402c29:	48 b8 72 65 73 6f 6c 	movabs $0x2065766c6f736572,%rax
  402c30:	76 65 20 
  402c33:	48 89 45 18          	mov    %rax,0x18(%rbp)
  402c37:	48 b8 73 65 72 76 65 	movabs $0x6120726576726573,%rax
  402c3e:	72 20 61 
  402c41:	48 89 45 20          	mov    %rax,0x20(%rbp)
  402c45:	c7 45 28 64 64 72 65 	movl   $0x65726464,0x28(%rbp)
  402c4c:	66 c7 45 2c 73 73    	movw   $0x7373,0x2c(%rbp)
  402c52:	c6 45 2e 00          	movb   $0x0,0x2e(%rbp)
  402c56:	89 df                	mov    %ebx,%edi
  402c58:	e8 d3 e0 ff ff       	callq  400d30 <close@plt>
  402c5d:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402c62:	e9 b1 00 00 00       	jmpq   402d18 <init_driver+0x1d7>
  402c67:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
  402c6e:	00 
  402c6f:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  402c76:	00 00 
  402c78:	66 c7 04 24 02 00    	movw   $0x2,(%rsp)
  402c7e:	48 63 50 14          	movslq 0x14(%rax),%rdx
  402c82:	48 8b 40 18          	mov    0x18(%rax),%rax
  402c86:	48 8b 30             	mov    (%rax),%rsi
  402c89:	48 8d 7c 24 04       	lea    0x4(%rsp),%rdi
  402c8e:	b9 0c 00 00 00       	mov    $0xc,%ecx
  402c93:	e8 e8 e0 ff ff       	callq  400d80 <__memmove_chk@plt>
  402c98:	66 c7 44 24 02 3c 9a 	movw   $0x9a3c,0x2(%rsp)
  402c9f:	ba 10 00 00 00       	mov    $0x10,%edx
  402ca4:	48 89 e6             	mov    %rsp,%rsi
  402ca7:	89 df                	mov    %ebx,%edi
  402ca9:	e8 b2 e1 ff ff       	callq  400e60 <connect@plt>
  402cae:	85 c0                	test   %eax,%eax
  402cb0:	79 50                	jns    402d02 <init_driver+0x1c1>
  402cb2:	48 b8 45 72 72 6f 72 	movabs $0x55203a726f727245,%rax
  402cb9:	3a 20 55 
  402cbc:	48 89 45 00          	mov    %rax,0x0(%rbp)
  402cc0:	48 b8 6e 61 62 6c 65 	movabs $0x6f7420656c62616e,%rax
  402cc7:	20 74 6f 
  402cca:	48 89 45 08          	mov    %rax,0x8(%rbp)
  402cce:	48 b8 20 63 6f 6e 6e 	movabs $0x7463656e6e6f6320,%rax
  402cd5:	65 63 74 
  402cd8:	48 89 45 10          	mov    %rax,0x10(%rbp)
  402cdc:	48 b8 20 74 6f 20 73 	movabs $0x76726573206f7420,%rax
  402ce3:	65 72 76 
  402ce6:	48 89 45 18          	mov    %rax,0x18(%rbp)
  402cea:	66 c7 45 20 65 72    	movw   $0x7265,0x20(%rbp)
  402cf0:	c6 45 22 00          	movb   $0x0,0x22(%rbp)
  402cf4:	89 df                	mov    %ebx,%edi
  402cf6:	e8 35 e0 ff ff       	callq  400d30 <close@plt>
  402cfb:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402d00:	eb 16                	jmp    402d18 <init_driver+0x1d7>
  402d02:	89 df                	mov    %ebx,%edi
  402d04:	e8 27 e0 ff ff       	callq  400d30 <close@plt>
  402d09:	66 c7 45 00 4f 4b    	movw   $0x4b4f,0x0(%rbp)
  402d0f:	c6 45 02 00          	movb   $0x0,0x2(%rbp)
  402d13:	b8 00 00 00 00       	mov    $0x0,%eax
  402d18:	48 8b 4c 24 18       	mov    0x18(%rsp),%rcx
  402d1d:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
  402d24:	00 00 
  402d26:	74 05                	je     402d2d <init_driver+0x1ec>
  402d28:	e8 c3 df ff ff       	callq  400cf0 <__stack_chk_fail@plt>
  402d2d:	48 83 c4 28          	add    $0x28,%rsp
  402d31:	5b                   	pop    %rbx
  402d32:	5d                   	pop    %rbp
  402d33:	c3                   	retq   

0000000000402d34 <driver_post>:
  402d34:	53                   	push   %rbx
  402d35:	4c 89 cb             	mov    %r9,%rbx
  402d38:	45 85 c0             	test   %r8d,%r8d
  402d3b:	74 27                	je     402d64 <driver_post+0x30>
  402d3d:	48 89 ca             	mov    %rcx,%rdx
  402d40:	be 85 36 40 00       	mov    $0x403685,%esi
  402d45:	bf 01 00 00 00       	mov    $0x1,%edi
  402d4a:	b8 00 00 00 00       	mov    $0x0,%eax
  402d4f:	e8 ac e0 ff ff       	callq  400e00 <__printf_chk@plt>
  402d54:	66 c7 03 4f 4b       	movw   $0x4b4f,(%rbx)
  402d59:	c6 43 02 00          	movb   $0x0,0x2(%rbx)
  402d5d:	b8 00 00 00 00       	mov    $0x0,%eax
  402d62:	eb 3f                	jmp    402da3 <driver_post+0x6f>
  402d64:	48 85 ff             	test   %rdi,%rdi
  402d67:	74 2c                	je     402d95 <driver_post+0x61>
  402d69:	80 3f 00             	cmpb   $0x0,(%rdi)
  402d6c:	74 27                	je     402d95 <driver_post+0x61>
  402d6e:	48 83 ec 08          	sub    $0x8,%rsp
  402d72:	41 51                	push   %r9
  402d74:	49 89 c9             	mov    %rcx,%r9
  402d77:	49 89 d0             	mov    %rdx,%r8
  402d7a:	48 89 f9             	mov    %rdi,%rcx
  402d7d:	48 89 f2             	mov    %rsi,%rdx
  402d80:	be 9a 3c 00 00       	mov    $0x3c9a,%esi
  402d85:	bf ca 31 40 00       	mov    $0x4031ca,%edi
  402d8a:	e8 19 f6 ff ff       	callq  4023a8 <submitr>
  402d8f:	48 83 c4 10          	add    $0x10,%rsp
  402d93:	eb 0e                	jmp    402da3 <driver_post+0x6f>
  402d95:	66 c7 03 4f 4b       	movw   $0x4b4f,(%rbx)
  402d9a:	c6 43 02 00          	movb   $0x0,0x2(%rbx)
  402d9e:	b8 00 00 00 00       	mov    $0x0,%eax
  402da3:	5b                   	pop    %rbx
  402da4:	c3                   	retq   

0000000000402da5 <check>:
  402da5:	89 f8                	mov    %edi,%eax
  402da7:	c1 e8 1c             	shr    $0x1c,%eax
  402daa:	85 c0                	test   %eax,%eax
  402dac:	74 1d                	je     402dcb <check+0x26>
  402dae:	b9 00 00 00 00       	mov    $0x0,%ecx
  402db3:	eb 0b                	jmp    402dc0 <check+0x1b>
  402db5:	89 f8                	mov    %edi,%eax
  402db7:	d3 e8                	shr    %cl,%eax
  402db9:	3c 0a                	cmp    $0xa,%al
  402dbb:	74 14                	je     402dd1 <check+0x2c>
  402dbd:	83 c1 08             	add    $0x8,%ecx
  402dc0:	83 f9 1f             	cmp    $0x1f,%ecx
  402dc3:	7e f0                	jle    402db5 <check+0x10>
  402dc5:	b8 01 00 00 00       	mov    $0x1,%eax
  402dca:	c3                   	retq   
  402dcb:	b8 00 00 00 00       	mov    $0x0,%eax
  402dd0:	c3                   	retq   
  402dd1:	b8 00 00 00 00       	mov    $0x0,%eax
  402dd6:	c3                   	retq   

0000000000402dd7 <gencookie>:
  402dd7:	53                   	push   %rbx
  402dd8:	83 c7 01             	add    $0x1,%edi
  402ddb:	e8 c0 de ff ff       	callq  400ca0 <srandom@plt>
  402de0:	e8 db df ff ff       	callq  400dc0 <random@plt>
  402de5:	89 c3                	mov    %eax,%ebx
  402de7:	89 c7                	mov    %eax,%edi
  402de9:	e8 b7 ff ff ff       	callq  402da5 <check>
  402dee:	85 c0                	test   %eax,%eax
  402df0:	74 ee                	je     402de0 <gencookie+0x9>
  402df2:	89 d8                	mov    %ebx,%eax
  402df4:	5b                   	pop    %rbx
  402df5:	c3                   	retq   
  402df6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  402dfd:	00 00 00 

0000000000402e00 <__libc_csu_init>:
  402e00:	41 57                	push   %r15
  402e02:	41 56                	push   %r14
  402e04:	41 89 ff             	mov    %edi,%r15d
  402e07:	41 55                	push   %r13
  402e09:	41 54                	push   %r12
  402e0b:	4c 8d 25 fe 0f 20 00 	lea    0x200ffe(%rip),%r12        # 603e10 <__frame_dummy_init_array_entry>
  402e12:	55                   	push   %rbp
  402e13:	48 8d 2d fe 0f 20 00 	lea    0x200ffe(%rip),%rbp        # 603e18 <__init_array_end>
  402e1a:	53                   	push   %rbx
  402e1b:	49 89 f6             	mov    %rsi,%r14
  402e1e:	49 89 d5             	mov    %rdx,%r13
  402e21:	4c 29 e5             	sub    %r12,%rbp
  402e24:	48 83 ec 08          	sub    $0x8,%rsp
  402e28:	48 c1 fd 03          	sar    $0x3,%rbp
  402e2c:	e8 17 de ff ff       	callq  400c48 <_init>
  402e31:	48 85 ed             	test   %rbp,%rbp
  402e34:	74 20                	je     402e56 <__libc_csu_init+0x56>
  402e36:	31 db                	xor    %ebx,%ebx
  402e38:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  402e3f:	00 
  402e40:	4c 89 ea             	mov    %r13,%rdx
  402e43:	4c 89 f6             	mov    %r14,%rsi
  402e46:	44 89 ff             	mov    %r15d,%edi
  402e49:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  402e4d:	48 83 c3 01          	add    $0x1,%rbx
  402e51:	48 39 eb             	cmp    %rbp,%rbx
  402e54:	75 ea                	jne    402e40 <__libc_csu_init+0x40>
  402e56:	48 83 c4 08          	add    $0x8,%rsp
  402e5a:	5b                   	pop    %rbx
  402e5b:	5d                   	pop    %rbp
  402e5c:	41 5c                	pop    %r12
  402e5e:	41 5d                	pop    %r13
  402e60:	41 5e                	pop    %r14
  402e62:	41 5f                	pop    %r15
  402e64:	c3                   	retq   
  402e65:	90                   	nop
  402e66:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  402e6d:	00 00 00 

0000000000402e70 <__libc_csu_fini>:
  402e70:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000402e74 <_fini>:
  402e74:	48 83 ec 08          	sub    $0x8,%rsp
  402e78:	48 83 c4 08          	add    $0x8,%rsp
  402e7c:	c3                   	retq   
