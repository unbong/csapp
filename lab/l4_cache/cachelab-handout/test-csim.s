
test-csim:     file format elf64-x86-64


Disassembly of section .init:

00000000004007b0 <_init>:
  4007b0:	48 83 ec 08          	sub    $0x8,%rsp
  4007b4:	e8 53 01 00 00       	callq  40090c <call_gmon_start>
  4007b9:	48 83 c4 08          	add    $0x8,%rsp
  4007bd:	c3                   	retq   

Disassembly of section .plt:

00000000004007c0 <.plt>:
  4007c0:	ff 35 2a 18 20 00    	pushq  0x20182a(%rip)        # 601ff0 <_GLOBAL_OFFSET_TABLE_+0x8>
  4007c6:	ff 25 2c 18 20 00    	jmpq   *0x20182c(%rip)        # 601ff8 <_GLOBAL_OFFSET_TABLE_+0x10>
  4007cc:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004007d0 <__errno_location@plt>:
  4007d0:	ff 25 2a 18 20 00    	jmpq   *0x20182a(%rip)        # 602000 <__errno_location@GLIBC_2.2.5>
  4007d6:	68 00 00 00 00       	pushq  $0x0
  4007db:	e9 e0 ff ff ff       	jmpq   4007c0 <.plt>

00000000004007e0 <__isoc99_fscanf@plt>:
  4007e0:	ff 25 22 18 20 00    	jmpq   *0x201822(%rip)        # 602008 <__isoc99_fscanf@GLIBC_2.7>
  4007e6:	68 01 00 00 00       	pushq  $0x1
  4007eb:	e9 d0 ff ff ff       	jmpq   4007c0 <.plt>

00000000004007f0 <puts@plt>:
  4007f0:	ff 25 1a 18 20 00    	jmpq   *0x20181a(%rip)        # 602010 <puts@GLIBC_2.2.5>
  4007f6:	68 02 00 00 00       	pushq  $0x2
  4007fb:	e9 c0 ff ff ff       	jmpq   4007c0 <.plt>

0000000000400800 <fclose@plt>:
  400800:	ff 25 12 18 20 00    	jmpq   *0x201812(%rip)        # 602018 <fclose@GLIBC_2.2.5>
  400806:	68 03 00 00 00       	pushq  $0x3
  40080b:	e9 b0 ff ff ff       	jmpq   4007c0 <.plt>

0000000000400810 <__stack_chk_fail@plt>:
  400810:	ff 25 0a 18 20 00    	jmpq   *0x20180a(%rip)        # 602020 <__stack_chk_fail@GLIBC_2.4>
  400816:	68 04 00 00 00       	pushq  $0x4
  40081b:	e9 a0 ff ff ff       	jmpq   4007c0 <.plt>

0000000000400820 <system@plt>:
  400820:	ff 25 02 18 20 00    	jmpq   *0x201802(%rip)        # 602028 <system@GLIBC_2.2.5>
  400826:	68 05 00 00 00       	pushq  $0x5
  40082b:	e9 90 ff ff ff       	jmpq   4007c0 <.plt>

0000000000400830 <printf@plt>:
  400830:	ff 25 fa 17 20 00    	jmpq   *0x2017fa(%rip)        # 602030 <printf@GLIBC_2.2.5>
  400836:	68 06 00 00 00       	pushq  $0x6
  40083b:	e9 80 ff ff ff       	jmpq   4007c0 <.plt>

0000000000400840 <alarm@plt>:
  400840:	ff 25 f2 17 20 00    	jmpq   *0x2017f2(%rip)        # 602038 <alarm@GLIBC_2.2.5>
  400846:	68 07 00 00 00       	pushq  $0x7
  40084b:	e9 70 ff ff ff       	jmpq   4007c0 <.plt>

0000000000400850 <__libc_start_main@plt>:
  400850:	ff 25 ea 17 20 00    	jmpq   *0x2017ea(%rip)        # 602040 <__libc_start_main@GLIBC_2.2.5>
  400856:	68 08 00 00 00       	pushq  $0x8
  40085b:	e9 60 ff ff ff       	jmpq   4007c0 <.plt>

0000000000400860 <fprintf@plt>:
  400860:	ff 25 e2 17 20 00    	jmpq   *0x2017e2(%rip)        # 602048 <fprintf@GLIBC_2.2.5>
  400866:	68 09 00 00 00       	pushq  $0x9
  40086b:	e9 50 ff ff ff       	jmpq   4007c0 <.plt>

0000000000400870 <__sysv_signal@plt>:
  400870:	ff 25 da 17 20 00    	jmpq   *0x2017da(%rip)        # 602050 <__sysv_signal@GLIBC_2.2.5>
  400876:	68 0a 00 00 00       	pushq  $0xa
  40087b:	e9 40 ff ff ff       	jmpq   4007c0 <.plt>

0000000000400880 <fopen@plt>:
  400880:	ff 25 d2 17 20 00    	jmpq   *0x2017d2(%rip)        # 602058 <fopen@GLIBC_2.2.5>
  400886:	68 0b 00 00 00       	pushq  $0xb
  40088b:	e9 30 ff ff ff       	jmpq   4007c0 <.plt>

0000000000400890 <getopt@plt>:
  400890:	ff 25 ca 17 20 00    	jmpq   *0x2017ca(%rip)        # 602060 <getopt@GLIBC_2.2.5>
  400896:	68 0c 00 00 00       	pushq  $0xc
  40089b:	e9 20 ff ff ff       	jmpq   4007c0 <.plt>

00000000004008a0 <sprintf@plt>:
  4008a0:	ff 25 c2 17 20 00    	jmpq   *0x2017c2(%rip)        # 602068 <sprintf@GLIBC_2.2.5>
  4008a6:	68 0d 00 00 00       	pushq  $0xd
  4008ab:	e9 10 ff ff ff       	jmpq   4007c0 <.plt>

00000000004008b0 <exit@plt>:
  4008b0:	ff 25 ba 17 20 00    	jmpq   *0x2017ba(%rip)        # 602070 <exit@GLIBC_2.2.5>
  4008b6:	68 0e 00 00 00       	pushq  $0xe
  4008bb:	e9 00 ff ff ff       	jmpq   4007c0 <.plt>

00000000004008c0 <fwrite@plt>:
  4008c0:	ff 25 b2 17 20 00    	jmpq   *0x2017b2(%rip)        # 602078 <fwrite@GLIBC_2.2.5>
  4008c6:	68 0f 00 00 00       	pushq  $0xf
  4008cb:	e9 f0 fe ff ff       	jmpq   4007c0 <.plt>

00000000004008d0 <strerror@plt>:
  4008d0:	ff 25 aa 17 20 00    	jmpq   *0x2017aa(%rip)        # 602080 <strerror@GLIBC_2.2.5>
  4008d6:	68 10 00 00 00       	pushq  $0x10
  4008db:	e9 e0 fe ff ff       	jmpq   4007c0 <.plt>

Disassembly of section .text:

00000000004008e0 <_start>:
  4008e0:	31 ed                	xor    %ebp,%ebp
  4008e2:	49 89 d1             	mov    %rdx,%r9
  4008e5:	5e                   	pop    %rsi
  4008e6:	48 89 e2             	mov    %rsp,%rdx
  4008e9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  4008ed:	50                   	push   %rax
  4008ee:	54                   	push   %rsp
  4008ef:	49 c7 c0 60 16 40 00 	mov    $0x401660,%r8
  4008f6:	48 c7 c1 d0 15 40 00 	mov    $0x4015d0,%rcx
  4008fd:	48 c7 c7 0b 15 40 00 	mov    $0x40150b,%rdi
  400904:	e8 47 ff ff ff       	callq  400850 <__libc_start_main@plt>
  400909:	f4                   	hlt    
  40090a:	90                   	nop
  40090b:	90                   	nop

000000000040090c <call_gmon_start>:
  40090c:	48 83 ec 08          	sub    $0x8,%rsp
  400910:	48 8b 05 c9 16 20 00 	mov    0x2016c9(%rip),%rax        # 601fe0 <__gmon_start__>
  400917:	48 85 c0             	test   %rax,%rax
  40091a:	74 02                	je     40091e <call_gmon_start+0x12>
  40091c:	ff d0                	callq  *%rax
  40091e:	48 83 c4 08          	add    $0x8,%rsp
  400922:	c3                   	retq   
  400923:	90                   	nop
  400924:	90                   	nop
  400925:	90                   	nop
  400926:	90                   	nop
  400927:	90                   	nop
  400928:	90                   	nop
  400929:	90                   	nop
  40092a:	90                   	nop
  40092b:	90                   	nop
  40092c:	90                   	nop
  40092d:	90                   	nop
  40092e:	90                   	nop
  40092f:	90                   	nop

0000000000400930 <deregister_tm_clones>:
  400930:	b8 9f 20 60 00       	mov    $0x60209f,%eax
  400935:	55                   	push   %rbp
  400936:	48 2d 98 20 60 00    	sub    $0x602098,%rax
  40093c:	48 83 f8 0e          	cmp    $0xe,%rax
  400940:	48 89 e5             	mov    %rsp,%rbp
  400943:	77 02                	ja     400947 <deregister_tm_clones+0x17>
  400945:	5d                   	pop    %rbp
  400946:	c3                   	retq   
  400947:	b8 00 00 00 00       	mov    $0x0,%eax
  40094c:	48 85 c0             	test   %rax,%rax
  40094f:	74 f4                	je     400945 <deregister_tm_clones+0x15>
  400951:	5d                   	pop    %rbp
  400952:	bf 98 20 60 00       	mov    $0x602098,%edi
  400957:	ff e0                	jmpq   *%rax
  400959:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000400960 <register_tm_clones>:
  400960:	b8 98 20 60 00       	mov    $0x602098,%eax
  400965:	55                   	push   %rbp
  400966:	48 2d 98 20 60 00    	sub    $0x602098,%rax
  40096c:	48 c1 f8 03          	sar    $0x3,%rax
  400970:	48 89 e5             	mov    %rsp,%rbp
  400973:	48 89 c2             	mov    %rax,%rdx
  400976:	48 c1 ea 3f          	shr    $0x3f,%rdx
  40097a:	48 01 d0             	add    %rdx,%rax
  40097d:	48 d1 f8             	sar    %rax
  400980:	75 02                	jne    400984 <register_tm_clones+0x24>
  400982:	5d                   	pop    %rbp
  400983:	c3                   	retq   
  400984:	ba 00 00 00 00       	mov    $0x0,%edx
  400989:	48 85 d2             	test   %rdx,%rdx
  40098c:	74 f4                	je     400982 <register_tm_clones+0x22>
  40098e:	5d                   	pop    %rbp
  40098f:	48 89 c6             	mov    %rax,%rsi
  400992:	bf 98 20 60 00       	mov    $0x602098,%edi
  400997:	ff e2                	jmpq   *%rdx
  400999:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000004009a0 <__do_global_dtors_aux>:
  4009a0:	80 3d f9 16 20 00 00 	cmpb   $0x0,0x2016f9(%rip)        # 6020a0 <completed.6976>
  4009a7:	75 11                	jne    4009ba <__do_global_dtors_aux+0x1a>
  4009a9:	55                   	push   %rbp
  4009aa:	48 89 e5             	mov    %rsp,%rbp
  4009ad:	e8 7e ff ff ff       	callq  400930 <deregister_tm_clones>
  4009b2:	5d                   	pop    %rbp
  4009b3:	c6 05 e6 16 20 00 01 	movb   $0x1,0x2016e6(%rip)        # 6020a0 <completed.6976>
  4009ba:	f3 c3                	repz retq 
  4009bc:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004009c0 <frame_dummy>:
  4009c0:	48 83 3d 40 14 20 00 	cmpq   $0x0,0x201440(%rip)        # 601e08 <__JCR_END__>
  4009c7:	00 
  4009c8:	74 1e                	je     4009e8 <frame_dummy+0x28>
  4009ca:	b8 00 00 00 00       	mov    $0x0,%eax
  4009cf:	48 85 c0             	test   %rax,%rax
  4009d2:	74 14                	je     4009e8 <frame_dummy+0x28>
  4009d4:	55                   	push   %rbp
  4009d5:	bf 08 1e 60 00       	mov    $0x601e08,%edi
  4009da:	48 89 e5             	mov    %rsp,%rbp
  4009dd:	ff d0                	callq  *%rax
  4009df:	5d                   	pop    %rbp
  4009e0:	e9 7b ff ff ff       	jmpq   400960 <register_tm_clones>
  4009e5:	0f 1f 00             	nopl   (%rax)
  4009e8:	e9 73 ff ff ff       	jmpq   400960 <register_tm_clones>
  4009ed:	90                   	nop
  4009ee:	90                   	nop
  4009ef:	90                   	nop

00000000004009f0 <usage>:
  4009f0:	55                   	push   %rbp
  4009f1:	48 89 e5             	mov    %rsp,%rbp
  4009f4:	48 83 ec 10          	sub    $0x10,%rsp
  4009f8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  4009fc:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  400a00:	48 8b 00             	mov    (%rax),%rax
  400a03:	48 89 c6             	mov    %rax,%rsi
  400a06:	bf 78 16 40 00       	mov    $0x401678,%edi
  400a0b:	b8 00 00 00 00       	mov    $0x0,%eax
  400a10:	e8 1b fe ff ff       	callq  400830 <printf@plt>
  400a15:	bf 89 16 40 00       	mov    $0x401689,%edi
  400a1a:	e8 d1 fd ff ff       	callq  4007f0 <puts@plt>
  400a1f:	bf 98 16 40 00       	mov    $0x401698,%edi
  400a24:	e8 c7 fd ff ff       	callq  4007f0 <puts@plt>
  400a29:	c9                   	leaveq 
  400a2a:	c3                   	retq   

0000000000400a2b <sigalrm_handler>:
  400a2b:	55                   	push   %rbp
  400a2c:	48 89 e5             	mov    %rsp,%rbp
  400a2f:	48 83 ec 10          	sub    $0x10,%rsp
  400a33:	89 7d fc             	mov    %edi,-0x4(%rbp)
  400a36:	bf b9 16 40 00       	mov    $0x4016b9,%edi
  400a3b:	e8 b0 fd ff ff       	callq  4007f0 <puts@plt>
  400a40:	bf d3 16 40 00       	mov    $0x4016d3,%edi
  400a45:	e8 a6 fd ff ff       	callq  4007f0 <puts@plt>
  400a4a:	bf 01 00 00 00       	mov    $0x1,%edi
  400a4f:	e8 5c fe ff ff       	callq  4008b0 <exit@plt>

0000000000400a54 <runtrace>:
  400a54:	55                   	push   %rbp
  400a55:	48 89 e5             	mov    %rsp,%rbp
  400a58:	53                   	push   %rbx
  400a59:	48 81 ec 78 04 00 00 	sub    $0x478,%rsp
  400a60:	89 bd cc fb ff ff    	mov    %edi,-0x434(%rbp)
  400a66:	89 b5 c8 fb ff ff    	mov    %esi,-0x438(%rbp)
  400a6c:	89 95 c4 fb ff ff    	mov    %edx,-0x43c(%rbp)
  400a72:	48 89 8d b8 fb ff ff 	mov    %rcx,-0x448(%rbp)
  400a79:	4c 89 85 b0 fb ff ff 	mov    %r8,-0x450(%rbp)
  400a80:	4c 89 8d a8 fb ff ff 	mov    %r9,-0x458(%rbp)
  400a87:	48 8b 45 10          	mov    0x10(%rbp),%rax
  400a8b:	48 89 85 a0 fb ff ff 	mov    %rax,-0x460(%rbp)
  400a92:	48 8b 45 18          	mov    0x18(%rbp),%rax
  400a96:	48 89 85 98 fb ff ff 	mov    %rax,-0x468(%rbp)
  400a9d:	48 8b 45 20          	mov    0x20(%rbp),%rax
  400aa1:	48 89 85 90 fb ff ff 	mov    %rax,-0x470(%rbp)
  400aa8:	48 8b 45 28          	mov    0x28(%rbp),%rax
  400aac:	48 89 85 88 fb ff ff 	mov    %rax,-0x478(%rbp)
  400ab3:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  400aba:	00 00 
  400abc:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  400ac0:	31 c0                	xor    %eax,%eax
  400ac2:	48 8b bd b8 fb ff ff 	mov    -0x448(%rbp),%rdi
  400ac9:	8b b5 c4 fb ff ff    	mov    -0x43c(%rbp),%esi
  400acf:	8b 8d c8 fb ff ff    	mov    -0x438(%rbp),%ecx
  400ad5:	8b 95 cc fb ff ff    	mov    -0x434(%rbp),%edx
  400adb:	48 8d 85 e0 fb ff ff 	lea    -0x420(%rbp),%rax
  400ae2:	49 89 f9             	mov    %rdi,%r9
  400ae5:	41 89 f0             	mov    %esi,%r8d
  400ae8:	be f8 16 40 00       	mov    $0x4016f8,%esi
  400aed:	48 89 c7             	mov    %rax,%rdi
  400af0:	b8 00 00 00 00       	mov    $0x0,%eax
  400af5:	e8 a6 fd ff ff       	callq  4008a0 <sprintf@plt>
  400afa:	bf 27 17 40 00       	mov    $0x401727,%edi
  400aff:	e8 1c fd ff ff       	callq  400820 <system@plt>
  400b04:	48 8d 85 e0 fb ff ff 	lea    -0x420(%rbp),%rax
  400b0b:	48 89 c7             	mov    %rax,%rdi
  400b0e:	e8 0d fd ff ff       	callq  400820 <system@plt>
  400b13:	89 85 d4 fb ff ff    	mov    %eax,-0x42c(%rbp)
  400b19:	83 bd d4 fb ff ff ff 	cmpl   $0xffffffff,-0x42c(%rbp)
  400b20:	75 34                	jne    400b56 <runtrace+0x102>
  400b22:	e8 a9 fc ff ff       	callq  4007d0 <__errno_location@plt>
  400b27:	8b 00                	mov    (%rax),%eax
  400b29:	89 c7                	mov    %eax,%edi
  400b2b:	e8 a0 fd ff ff       	callq  4008d0 <strerror@plt>
  400b30:	48 89 c2             	mov    %rax,%rdx
  400b33:	48 8b 05 5e 15 20 00 	mov    0x20155e(%rip),%rax        # 602098 <stderr@@GLIBC_2.2.5>
  400b3a:	be 40 17 40 00       	mov    $0x401740,%esi
  400b3f:	48 89 c7             	mov    %rax,%rdi
  400b42:	b8 00 00 00 00       	mov    $0x0,%eax
  400b47:	e8 14 fd ff ff       	callq  400860 <fprintf@plt>
  400b4c:	b8 00 00 00 00       	mov    $0x0,%eax
  400b51:	e9 4a 02 00 00       	jmpq   400da0 <runtrace+0x34c>
  400b56:	8b 85 d4 fb ff ff    	mov    -0x42c(%rbp),%eax
  400b5c:	83 e0 7f             	and    $0x7f,%eax
  400b5f:	85 c0                	test   %eax,%eax
  400b61:	75 45                	jne    400ba8 <runtrace+0x154>
  400b63:	8b 85 d4 fb ff ff    	mov    -0x42c(%rbp),%eax
  400b69:	25 00 ff 00 00       	and    $0xff00,%eax
  400b6e:	c1 f8 08             	sar    $0x8,%eax
  400b71:	85 c0                	test   %eax,%eax
  400b73:	74 33                	je     400ba8 <runtrace+0x154>
  400b75:	8b 85 d4 fb ff ff    	mov    -0x42c(%rbp),%eax
  400b7b:	25 00 ff 00 00       	and    $0xff00,%eax
  400b80:	c1 f8 08             	sar    $0x8,%eax
  400b83:	89 c2                	mov    %eax,%edx
  400b85:	48 8b 05 0c 15 20 00 	mov    0x20150c(%rip),%rax        # 602098 <stderr@@GLIBC_2.2.5>
  400b8c:	be 70 17 40 00       	mov    $0x401770,%esi
  400b91:	48 89 c7             	mov    %rax,%rdi
  400b94:	b8 00 00 00 00       	mov    $0x0,%eax
  400b99:	e8 c2 fc ff ff       	callq  400860 <fprintf@plt>
  400b9e:	b8 00 00 00 00       	mov    $0x0,%eax
  400ba3:	e9 f8 01 00 00       	jmpq   400da0 <runtrace+0x34c>
  400ba8:	be 9e 17 40 00       	mov    $0x40179e,%esi
  400bad:	bf a0 17 40 00       	mov    $0x4017a0,%edi
  400bb2:	e8 c9 fc ff ff       	callq  400880 <fopen@plt>
  400bb7:	48 89 85 d8 fb ff ff 	mov    %rax,-0x428(%rbp)
  400bbe:	48 83 bd d8 fb ff ff 	cmpq   $0x0,-0x428(%rbp)
  400bc5:	00 
  400bc6:	75 28                	jne    400bf0 <runtrace+0x19c>
  400bc8:	48 8b 05 c9 14 20 00 	mov    0x2014c9(%rip),%rax        # 602098 <stderr@@GLIBC_2.2.5>
  400bcf:	48 89 c1             	mov    %rax,%rcx
  400bd2:	ba 52 00 00 00       	mov    $0x52,%edx
  400bd7:	be 01 00 00 00       	mov    $0x1,%esi
  400bdc:	bf b0 17 40 00       	mov    $0x4017b0,%edi
  400be1:	e8 da fc ff ff       	callq  4008c0 <fwrite@plt>
  400be6:	b8 00 00 00 00       	mov    $0x0,%eax
  400beb:	e9 b0 01 00 00       	jmpq   400da0 <runtrace+0x34c>
  400bf0:	48 8b b5 a0 fb ff ff 	mov    -0x460(%rbp),%rsi
  400bf7:	48 8b 8d a8 fb ff ff 	mov    -0x458(%rbp),%rcx
  400bfe:	48 8b 95 b0 fb ff ff 	mov    -0x450(%rbp),%rdx
  400c05:	48 8b 85 d8 fb ff ff 	mov    -0x428(%rbp),%rax
  400c0c:	49 89 f0             	mov    %rsi,%r8
  400c0f:	be 03 18 40 00       	mov    $0x401803,%esi
  400c14:	48 89 c7             	mov    %rax,%rdi
  400c17:	b8 00 00 00 00       	mov    $0x0,%eax
  400c1c:	e8 bf fb ff ff       	callq  4007e0 <__isoc99_fscanf@plt>
  400c21:	48 8b 85 d8 fb ff ff 	mov    -0x428(%rbp),%rax
  400c28:	48 89 c7             	mov    %rax,%rdi
  400c2b:	e8 d0 fb ff ff       	callq  400800 <fclose@plt>
  400c30:	48 8b bd b8 fb ff ff 	mov    -0x448(%rbp),%rdi
  400c37:	8b b5 c4 fb ff ff    	mov    -0x43c(%rbp),%esi
  400c3d:	8b 8d c8 fb ff ff    	mov    -0x438(%rbp),%ecx
  400c43:	8b 95 cc fb ff ff    	mov    -0x434(%rbp),%edx
  400c49:	48 8d 85 e0 fb ff ff 	lea    -0x420(%rbp),%rax
  400c50:	49 89 f9             	mov    %rdi,%r9
  400c53:	41 89 f0             	mov    %esi,%r8d
  400c56:	be 10 18 40 00       	mov    $0x401810,%esi
  400c5b:	48 89 c7             	mov    %rax,%rdi
  400c5e:	b8 00 00 00 00       	mov    $0x0,%eax
  400c63:	e8 38 fc ff ff       	callq  4008a0 <sprintf@plt>
  400c68:	bf 27 17 40 00       	mov    $0x401727,%edi
  400c6d:	e8 ae fb ff ff       	callq  400820 <system@plt>
  400c72:	48 8d 85 e0 fb ff ff 	lea    -0x420(%rbp),%rax
  400c79:	48 89 c7             	mov    %rax,%rdi
  400c7c:	e8 9f fb ff ff       	callq  400820 <system@plt>
  400c81:	89 85 d4 fb ff ff    	mov    %eax,-0x42c(%rbp)
  400c87:	83 bd d4 fb ff ff ff 	cmpl   $0xffffffff,-0x42c(%rbp)
  400c8e:	75 34                	jne    400cc4 <runtrace+0x270>
  400c90:	e8 3b fb ff ff       	callq  4007d0 <__errno_location@plt>
  400c95:	8b 00                	mov    (%rax),%eax
  400c97:	89 c7                	mov    %eax,%edi
  400c99:	e8 32 fc ff ff       	callq  4008d0 <strerror@plt>
  400c9e:	48 89 c2             	mov    %rax,%rdx
  400ca1:	48 8b 05 f0 13 20 00 	mov    0x2013f0(%rip),%rax        # 602098 <stderr@@GLIBC_2.2.5>
  400ca8:	be 40 18 40 00       	mov    $0x401840,%esi
  400cad:	48 89 c7             	mov    %rax,%rdi
  400cb0:	b8 00 00 00 00       	mov    $0x0,%eax
  400cb5:	e8 a6 fb ff ff       	callq  400860 <fprintf@plt>
  400cba:	b8 00 00 00 00       	mov    $0x0,%eax
  400cbf:	e9 dc 00 00 00       	jmpq   400da0 <runtrace+0x34c>
  400cc4:	8b 85 d4 fb ff ff    	mov    -0x42c(%rbp),%eax
  400cca:	83 e0 7f             	and    $0x7f,%eax
  400ccd:	85 c0                	test   %eax,%eax
  400ccf:	75 45                	jne    400d16 <runtrace+0x2c2>
  400cd1:	8b 85 d4 fb ff ff    	mov    -0x42c(%rbp),%eax
  400cd7:	25 00 ff 00 00       	and    $0xff00,%eax
  400cdc:	c1 f8 08             	sar    $0x8,%eax
  400cdf:	85 c0                	test   %eax,%eax
  400ce1:	74 33                	je     400d16 <runtrace+0x2c2>
  400ce3:	8b 85 d4 fb ff ff    	mov    -0x42c(%rbp),%eax
  400ce9:	25 00 ff 00 00       	and    $0xff00,%eax
  400cee:	c1 f8 08             	sar    $0x8,%eax
  400cf1:	89 c2                	mov    %eax,%edx
  400cf3:	48 8b 05 9e 13 20 00 	mov    0x20139e(%rip),%rax        # 602098 <stderr@@GLIBC_2.2.5>
  400cfa:	be 70 18 40 00       	mov    $0x401870,%esi
  400cff:	48 89 c7             	mov    %rax,%rdi
  400d02:	b8 00 00 00 00       	mov    $0x0,%eax
  400d07:	e8 54 fb ff ff       	callq  400860 <fprintf@plt>
  400d0c:	b8 00 00 00 00       	mov    $0x0,%eax
  400d11:	e9 8a 00 00 00       	jmpq   400da0 <runtrace+0x34c>
  400d16:	be 9e 17 40 00       	mov    $0x40179e,%esi
  400d1b:	bf a0 17 40 00       	mov    $0x4017a0,%edi
  400d20:	e8 5b fb ff ff       	callq  400880 <fopen@plt>
  400d25:	48 89 85 d8 fb ff ff 	mov    %rax,-0x428(%rbp)
  400d2c:	48 83 bd d8 fb ff ff 	cmpq   $0x0,-0x428(%rbp)
  400d33:	00 
  400d34:	75 25                	jne    400d5b <runtrace+0x307>
  400d36:	48 8b 05 5b 13 20 00 	mov    0x20135b(%rip),%rax        # 602098 <stderr@@GLIBC_2.2.5>
  400d3d:	48 89 c1             	mov    %rax,%rcx
  400d40:	ba 4d 00 00 00       	mov    $0x4d,%edx
  400d45:	be 01 00 00 00       	mov    $0x1,%esi
  400d4a:	bf a0 18 40 00       	mov    $0x4018a0,%edi
  400d4f:	e8 6c fb ff ff       	callq  4008c0 <fwrite@plt>
  400d54:	b8 00 00 00 00       	mov    $0x0,%eax
  400d59:	eb 45                	jmp    400da0 <runtrace+0x34c>
  400d5b:	48 8b b5 88 fb ff ff 	mov    -0x478(%rbp),%rsi
  400d62:	48 8b 8d 90 fb ff ff 	mov    -0x470(%rbp),%rcx
  400d69:	48 8b 95 98 fb ff ff 	mov    -0x468(%rbp),%rdx
  400d70:	48 8b 85 d8 fb ff ff 	mov    -0x428(%rbp),%rax
  400d77:	49 89 f0             	mov    %rsi,%r8
  400d7a:	be 03 18 40 00       	mov    $0x401803,%esi
  400d7f:	48 89 c7             	mov    %rax,%rdi
  400d82:	b8 00 00 00 00       	mov    $0x0,%eax
  400d87:	e8 54 fa ff ff       	callq  4007e0 <__isoc99_fscanf@plt>
  400d8c:	48 8b 85 d8 fb ff ff 	mov    -0x428(%rbp),%rax
  400d93:	48 89 c7             	mov    %rax,%rdi
  400d96:	e8 65 fa ff ff       	callq  400800 <fclose@plt>
  400d9b:	b8 01 00 00 00       	mov    $0x1,%eax
  400da0:	48 8b 5d e8          	mov    -0x18(%rbp),%rbx
  400da4:	64 48 33 1c 25 28 00 	xor    %fs:0x28,%rbx
  400dab:	00 00 
  400dad:	74 05                	je     400db4 <runtrace+0x360>
  400daf:	e8 5c fa ff ff       	callq  400810 <__stack_chk_fail@plt>
  400db4:	48 81 c4 78 04 00 00 	add    $0x478,%rsp
  400dbb:	5b                   	pop    %rbx
  400dbc:	5d                   	pop    %rbp
  400dbd:	c3                   	retq   

0000000000400dbe <test_csim>:
  400dbe:	55                   	push   %rbp
  400dbf:	48 89 e5             	mov    %rsp,%rbp
  400dc2:	53                   	push   %rbx
  400dc3:	48 81 ec 08 06 00 00 	sub    $0x608,%rsp
  400dca:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  400dd1:	00 00 
  400dd3:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  400dd7:	31 c0                	xor    %eax,%eax
  400dd9:	c7 85 20 fa ff ff 01 	movl   $0x1,-0x5e0(%rbp)
  400de0:	00 00 00 
  400de3:	c7 85 24 fa ff ff 04 	movl   $0x4,-0x5dc(%rbp)
  400dea:	00 00 00 
  400ded:	c7 85 28 fa ff ff 02 	movl   $0x2,-0x5d8(%rbp)
  400df4:	00 00 00 
  400df7:	c7 85 2c fa ff ff 02 	movl   $0x2,-0x5d4(%rbp)
  400dfe:	00 00 00 
  400e01:	c7 85 30 fa ff ff 02 	movl   $0x2,-0x5d0(%rbp)
  400e08:	00 00 00 
  400e0b:	c7 85 34 fa ff ff 02 	movl   $0x2,-0x5cc(%rbp)
  400e12:	00 00 00 
  400e15:	c7 85 38 fa ff ff 05 	movl   $0x5,-0x5c8(%rbp)
  400e1c:	00 00 00 
  400e1f:	c7 85 3c fa ff ff 05 	movl   $0x5,-0x5c4(%rbp)
  400e26:	00 00 00 
  400e29:	c7 85 40 fa ff ff 01 	movl   $0x1,-0x5c0(%rbp)
  400e30:	00 00 00 
  400e33:	c7 85 44 fa ff ff 02 	movl   $0x2,-0x5bc(%rbp)
  400e3a:	00 00 00 
  400e3d:	c7 85 48 fa ff ff 01 	movl   $0x1,-0x5b8(%rbp)
  400e44:	00 00 00 
  400e47:	c7 85 4c fa ff ff 01 	movl   $0x1,-0x5b4(%rbp)
  400e4e:	00 00 00 
  400e51:	c7 85 50 fa ff ff 02 	movl   $0x2,-0x5b0(%rbp)
  400e58:	00 00 00 
  400e5b:	c7 85 54 fa ff ff 04 	movl   $0x4,-0x5ac(%rbp)
  400e62:	00 00 00 
  400e65:	c7 85 58 fa ff ff 01 	movl   $0x1,-0x5a8(%rbp)
  400e6c:	00 00 00 
  400e6f:	c7 85 5c fa ff ff 01 	movl   $0x1,-0x5a4(%rbp)
  400e76:	00 00 00 
  400e79:	c7 85 60 fa ff ff 01 	movl   $0x1,-0x5a0(%rbp)
  400e80:	00 00 00 
  400e83:	c7 85 64 fa ff ff 04 	movl   $0x4,-0x59c(%rbp)
  400e8a:	00 00 00 
  400e8d:	c7 85 68 fa ff ff 04 	movl   $0x4,-0x598(%rbp)
  400e94:	00 00 00 
  400e97:	c7 85 6c fa ff ff 03 	movl   $0x3,-0x594(%rbp)
  400e9e:	00 00 00 
  400ea1:	c7 85 70 fa ff ff 03 	movl   $0x3,-0x590(%rbp)
  400ea8:	00 00 00 
  400eab:	c7 85 74 fa ff ff 03 	movl   $0x3,-0x58c(%rbp)
  400eb2:	00 00 00 
  400eb5:	c7 85 78 fa ff ff 05 	movl   $0x5,-0x588(%rbp)
  400ebc:	00 00 00 
  400ebf:	c7 85 7c fa ff ff 05 	movl   $0x5,-0x584(%rbp)
  400ec6:	00 00 00 
  400ec9:	c7 85 80 fa ff ff 01 	movl   $0x1,-0x580(%rbp)
  400ed0:	00 00 00 
  400ed3:	c7 85 84 fa ff ff 01 	movl   $0x1,-0x57c(%rbp)
  400eda:	00 00 00 
  400edd:	c7 85 88 fa ff ff 01 	movl   $0x1,-0x578(%rbp)
  400ee4:	00 00 00 
  400ee7:	c7 85 8c fa ff ff 01 	movl   $0x1,-0x574(%rbp)
  400eee:	00 00 00 
  400ef1:	c7 85 90 fa ff ff 01 	movl   $0x1,-0x570(%rbp)
  400ef8:	00 00 00 
  400efb:	c7 85 94 fa ff ff 01 	movl   $0x1,-0x56c(%rbp)
  400f02:	00 00 00 
  400f05:	c7 85 98 fa ff ff 01 	movl   $0x1,-0x568(%rbp)
  400f0c:	00 00 00 
  400f0f:	c7 85 9c fa ff ff 02 	movl   $0x2,-0x564(%rbp)
  400f16:	00 00 00 
  400f19:	48 c7 85 a0 fb ff ff 	movq   $0x4018ee,-0x460(%rbp)
  400f20:	ee 18 40 00 
  400f24:	48 c7 85 a8 fb ff ff 	movq   $0x4018ff,-0x458(%rbp)
  400f2b:	ff 18 40 00 
  400f2f:	48 c7 85 b0 fb ff ff 	movq   $0x40190f,-0x450(%rbp)
  400f36:	0f 19 40 00 
  400f3a:	48 c7 85 b8 fb ff ff 	movq   $0x401921,-0x448(%rbp)
  400f41:	21 19 40 00 
  400f45:	48 c7 85 c0 fb ff ff 	movq   $0x401921,-0x440(%rbp)
  400f4c:	21 19 40 00 
  400f50:	48 c7 85 c8 fb ff ff 	movq   $0x401921,-0x438(%rbp)
  400f57:	21 19 40 00 
  400f5b:	48 c7 85 d0 fb ff ff 	movq   $0x401921,-0x430(%rbp)
  400f62:	21 19 40 00 
  400f66:	48 c7 85 d8 fb ff ff 	movq   $0x401934,-0x428(%rbp)
  400f6d:	34 19 40 00 
  400f71:	c7 85 1c fa ff ff 00 	movl   $0x0,-0x5e4(%rbp)
  400f78:	00 00 00 
  400f7b:	c7 85 18 fa ff ff 00 	movl   $0x0,-0x5e8(%rbp)
  400f82:	00 00 00 
  400f85:	e9 b9 01 00 00       	jmpq   401143 <test_csim+0x385>
  400f8a:	48 8d 85 40 fb ff ff 	lea    -0x4c0(%rbp),%rax
  400f91:	8b 95 18 fa ff ff    	mov    -0x5e8(%rbp),%edx
  400f97:	48 63 d2             	movslq %edx,%rdx
  400f9a:	48 c1 e2 02          	shl    $0x2,%rdx
  400f9e:	4c 8d 14 10          	lea    (%rax,%rdx,1),%r10
  400fa2:	48 8d 85 20 fb ff ff 	lea    -0x4e0(%rbp),%rax
  400fa9:	8b 95 18 fa ff ff    	mov    -0x5e8(%rbp),%edx
  400faf:	48 63 d2             	movslq %edx,%rdx
  400fb2:	48 c1 e2 02          	shl    $0x2,%rdx
  400fb6:	4c 8d 0c 10          	lea    (%rax,%rdx,1),%r9
  400fba:	48 8d 85 00 fb ff ff 	lea    -0x500(%rbp),%rax
  400fc1:	8b 95 18 fa ff ff    	mov    -0x5e8(%rbp),%edx
  400fc7:	48 63 d2             	movslq %edx,%rdx
  400fca:	48 c1 e2 02          	shl    $0x2,%rdx
  400fce:	4c 8d 04 10          	lea    (%rax,%rdx,1),%r8
  400fd2:	48 8d 85 e0 fa ff ff 	lea    -0x520(%rbp),%rax
  400fd9:	8b 95 18 fa ff ff    	mov    -0x5e8(%rbp),%edx
  400fdf:	48 63 d2             	movslq %edx,%rdx
  400fe2:	48 c1 e2 02          	shl    $0x2,%rdx
  400fe6:	48 8d 3c 10          	lea    (%rax,%rdx,1),%rdi
  400fea:	48 8d 85 c0 fa ff ff 	lea    -0x540(%rbp),%rax
  400ff1:	8b 95 18 fa ff ff    	mov    -0x5e8(%rbp),%edx
  400ff7:	48 63 d2             	movslq %edx,%rdx
  400ffa:	48 c1 e2 02          	shl    $0x2,%rdx
  400ffe:	48 8d 1c 10          	lea    (%rax,%rdx,1),%rbx
  401002:	48 8d 85 a0 fa ff ff 	lea    -0x560(%rbp),%rax
  401009:	8b 95 18 fa ff ff    	mov    -0x5e8(%rbp),%edx
  40100f:	48 63 d2             	movslq %edx,%rdx
  401012:	48 c1 e2 02          	shl    $0x2,%rdx
  401016:	4c 8d 1c 10          	lea    (%rax,%rdx,1),%r11
  40101a:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  401020:	48 98                	cltq   
  401022:	48 8b 8c c5 a0 fb ff 	mov    -0x460(%rbp,%rax,8),%rcx
  401029:	ff 
  40102a:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  401030:	48 98                	cltq   
  401032:	8b 94 85 60 fa ff ff 	mov    -0x5a0(%rbp,%rax,4),%edx
  401039:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  40103f:	48 98                	cltq   
  401041:	8b b4 85 40 fa ff ff 	mov    -0x5c0(%rbp,%rax,4),%esi
  401048:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  40104e:	48 98                	cltq   
  401050:	8b 84 85 20 fa ff ff 	mov    -0x5e0(%rbp,%rax,4),%eax
  401057:	4c 89 54 24 18       	mov    %r10,0x18(%rsp)
  40105c:	4c 89 4c 24 10       	mov    %r9,0x10(%rsp)
  401061:	4c 89 44 24 08       	mov    %r8,0x8(%rsp)
  401066:	48 89 3c 24          	mov    %rdi,(%rsp)
  40106a:	49 89 d9             	mov    %rbx,%r9
  40106d:	4d 89 d8             	mov    %r11,%r8
  401070:	89 c7                	mov    %eax,%edi
  401072:	e8 dd f9 ff ff       	callq  400a54 <runtrace>
  401077:	8b 95 18 fa ff ff    	mov    -0x5e8(%rbp),%edx
  40107d:	48 63 d2             	movslq %edx,%rdx
  401080:	89 84 95 60 fb ff ff 	mov    %eax,-0x4a0(%rbp,%rdx,4)
  401087:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  40108d:	48 98                	cltq   
  40108f:	8b 84 85 60 fb ff ff 	mov    -0x4a0(%rbp,%rax,4),%eax
  401096:	85 c0                	test   %eax,%eax
  401098:	0f 85 9e 00 00 00    	jne    40113c <test_csim+0x37e>
  40109e:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  4010a4:	48 98                	cltq   
  4010a6:	c7 84 85 e0 fa ff ff 	movl   $0xffffffff,-0x520(%rbp,%rax,4)
  4010ad:	ff ff ff ff 
  4010b1:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  4010b7:	48 98                	cltq   
  4010b9:	8b 94 85 e0 fa ff ff 	mov    -0x520(%rbp,%rax,4),%edx
  4010c0:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  4010c6:	48 98                	cltq   
  4010c8:	89 94 85 c0 fa ff ff 	mov    %edx,-0x540(%rbp,%rax,4)
  4010cf:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  4010d5:	48 98                	cltq   
  4010d7:	8b 94 85 c0 fa ff ff 	mov    -0x540(%rbp,%rax,4),%edx
  4010de:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  4010e4:	48 98                	cltq   
  4010e6:	89 94 85 a0 fa ff ff 	mov    %edx,-0x560(%rbp,%rax,4)
  4010ed:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  4010f3:	48 98                	cltq   
  4010f5:	c7 84 85 40 fb ff ff 	movl   $0xffffffff,-0x4c0(%rbp,%rax,4)
  4010fc:	ff ff ff ff 
  401100:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  401106:	48 98                	cltq   
  401108:	8b 94 85 40 fb ff ff 	mov    -0x4c0(%rbp,%rax,4),%edx
  40110f:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  401115:	48 98                	cltq   
  401117:	89 94 85 20 fb ff ff 	mov    %edx,-0x4e0(%rbp,%rax,4)
  40111e:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  401124:	48 98                	cltq   
  401126:	8b 94 85 20 fb ff ff 	mov    -0x4e0(%rbp,%rax,4),%edx
  40112d:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  401133:	48 98                	cltq   
  401135:	89 94 85 00 fb ff ff 	mov    %edx,-0x500(%rbp,%rax,4)
  40113c:	83 85 18 fa ff ff 01 	addl   $0x1,-0x5e8(%rbp)
  401143:	83 bd 18 fa ff ff 07 	cmpl   $0x7,-0x5e8(%rbp)
  40114a:	0f 8e 3a fe ff ff    	jle    400f8a <test_csim+0x1cc>
  401150:	c7 85 18 fa ff ff 00 	movl   $0x0,-0x5e8(%rbp)
  401157:	00 00 00 
  40115a:	e9 de 01 00 00       	jmpq   40133d <test_csim+0x57f>
  40115f:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  401165:	48 98                	cltq   
  401167:	c7 84 85 80 fb ff ff 	movl   $0x0,-0x480(%rbp,%rax,4)
  40116e:	00 00 00 00 
  401172:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  401178:	48 98                	cltq   
  40117a:	8b 84 85 60 fb ff ff 	mov    -0x4a0(%rbp,%rax,4),%eax
  401181:	85 c0                	test   %eax,%eax
  401183:	0f 84 98 01 00 00    	je     401321 <test_csim+0x563>
  401189:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  40118f:	48 98                	cltq   
  401191:	8b 84 85 a0 fa ff ff 	mov    -0x560(%rbp,%rax,4),%eax
  401198:	83 f8 ff             	cmp    $0xffffffff,%eax
  40119b:	0f 84 80 01 00 00    	je     401321 <test_csim+0x563>
  4011a1:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  4011a7:	48 98                	cltq   
  4011a9:	8b 84 85 c0 fa ff ff 	mov    -0x540(%rbp,%rax,4),%eax
  4011b0:	83 f8 ff             	cmp    $0xffffffff,%eax
  4011b3:	0f 84 68 01 00 00    	je     401321 <test_csim+0x563>
  4011b9:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  4011bf:	48 98                	cltq   
  4011c1:	8b 84 85 e0 fa ff ff 	mov    -0x520(%rbp,%rax,4),%eax
  4011c8:	83 f8 ff             	cmp    $0xffffffff,%eax
  4011cb:	0f 84 50 01 00 00    	je     401321 <test_csim+0x563>
  4011d1:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  4011d7:	48 98                	cltq   
  4011d9:	8b 84 85 00 fb ff ff 	mov    -0x500(%rbp,%rax,4),%eax
  4011e0:	83 f8 ff             	cmp    $0xffffffff,%eax
  4011e3:	0f 84 38 01 00 00    	je     401321 <test_csim+0x563>
  4011e9:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  4011ef:	48 98                	cltq   
  4011f1:	8b 84 85 20 fb ff ff 	mov    -0x4e0(%rbp,%rax,4),%eax
  4011f8:	83 f8 ff             	cmp    $0xffffffff,%eax
  4011fb:	0f 84 20 01 00 00    	je     401321 <test_csim+0x563>
  401201:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  401207:	48 98                	cltq   
  401209:	8b 84 85 40 fb ff ff 	mov    -0x4c0(%rbp,%rax,4),%eax
  401210:	83 f8 ff             	cmp    $0xffffffff,%eax
  401213:	0f 84 08 01 00 00    	je     401321 <test_csim+0x563>
  401219:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  40121f:	48 98                	cltq   
  401221:	8b 94 85 80 fb ff ff 	mov    -0x480(%rbp,%rax,4),%edx
  401228:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  40122e:	48 98                	cltq   
  401230:	8b 8c 85 a0 fa ff ff 	mov    -0x560(%rbp,%rax,4),%ecx
  401237:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  40123d:	48 98                	cltq   
  40123f:	8b 84 85 00 fb ff ff 	mov    -0x500(%rbp,%rax,4),%eax
  401246:	39 c1                	cmp    %eax,%ecx
  401248:	0f 94 c0             	sete   %al
  40124b:	0f b6 c8             	movzbl %al,%ecx
  40124e:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  401254:	48 98                	cltq   
  401256:	8b 84 85 80 fa ff ff 	mov    -0x580(%rbp,%rax,4),%eax
  40125d:	0f af c1             	imul   %ecx,%eax
  401260:	01 c2                	add    %eax,%edx
  401262:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  401268:	48 98                	cltq   
  40126a:	89 94 85 80 fb ff ff 	mov    %edx,-0x480(%rbp,%rax,4)
  401271:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  401277:	48 98                	cltq   
  401279:	8b 94 85 80 fb ff ff 	mov    -0x480(%rbp,%rax,4),%edx
  401280:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  401286:	48 98                	cltq   
  401288:	8b 8c 85 c0 fa ff ff 	mov    -0x540(%rbp,%rax,4),%ecx
  40128f:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  401295:	48 98                	cltq   
  401297:	8b 84 85 20 fb ff ff 	mov    -0x4e0(%rbp,%rax,4),%eax
  40129e:	39 c1                	cmp    %eax,%ecx
  4012a0:	0f 94 c0             	sete   %al
  4012a3:	0f b6 c8             	movzbl %al,%ecx
  4012a6:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  4012ac:	48 98                	cltq   
  4012ae:	8b 84 85 80 fa ff ff 	mov    -0x580(%rbp,%rax,4),%eax
  4012b5:	0f af c1             	imul   %ecx,%eax
  4012b8:	01 c2                	add    %eax,%edx
  4012ba:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  4012c0:	48 98                	cltq   
  4012c2:	89 94 85 80 fb ff ff 	mov    %edx,-0x480(%rbp,%rax,4)
  4012c9:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  4012cf:	48 98                	cltq   
  4012d1:	8b 94 85 80 fb ff ff 	mov    -0x480(%rbp,%rax,4),%edx
  4012d8:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  4012de:	48 98                	cltq   
  4012e0:	8b 8c 85 e0 fa ff ff 	mov    -0x520(%rbp,%rax,4),%ecx
  4012e7:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  4012ed:	48 98                	cltq   
  4012ef:	8b 84 85 40 fb ff ff 	mov    -0x4c0(%rbp,%rax,4),%eax
  4012f6:	39 c1                	cmp    %eax,%ecx
  4012f8:	0f 94 c0             	sete   %al
  4012fb:	0f b6 c8             	movzbl %al,%ecx
  4012fe:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  401304:	48 98                	cltq   
  401306:	8b 84 85 80 fa ff ff 	mov    -0x580(%rbp,%rax,4),%eax
  40130d:	0f af c1             	imul   %ecx,%eax
  401310:	01 c2                	add    %eax,%edx
  401312:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  401318:	48 98                	cltq   
  40131a:	89 94 85 80 fb ff ff 	mov    %edx,-0x480(%rbp,%rax,4)
  401321:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  401327:	48 98                	cltq   
  401329:	8b 84 85 80 fb ff ff 	mov    -0x480(%rbp,%rax,4),%eax
  401330:	01 85 1c fa ff ff    	add    %eax,-0x5e4(%rbp)
  401336:	83 85 18 fa ff ff 01 	addl   $0x1,-0x5e8(%rbp)
  40133d:	83 bd 18 fa ff ff 07 	cmpl   $0x7,-0x5e8(%rbp)
  401344:	0f 8e 15 fe ff ff    	jle    40115f <test_csim+0x3a1>
  40134a:	ba 46 19 40 00       	mov    $0x401946,%edx
  40134f:	be 5a 19 40 00       	mov    $0x40195a,%esi
  401354:	bf 69 19 40 00       	mov    $0x401969,%edi
  401359:	b8 00 00 00 00       	mov    $0x0,%eax
  40135e:	e8 cd f4 ff ff       	callq  400830 <printf@plt>
  401363:	48 c7 44 24 10 73 19 	movq   $0x401973,0x10(%rsp)
  40136a:	40 00 
  40136c:	48 c7 44 24 08 7a 19 	movq   $0x40197a,0x8(%rsp)
  401373:	40 00 
  401375:	48 c7 04 24 81 19 40 	movq   $0x401981,(%rsp)
  40137c:	00 
  40137d:	41 b9 73 19 40 00    	mov    $0x401973,%r9d
  401383:	41 b8 7a 19 40 00    	mov    $0x40197a,%r8d
  401389:	b9 81 19 40 00       	mov    $0x401981,%ecx
  40138e:	ba 86 19 40 00       	mov    $0x401986,%edx
  401393:	be 8e 19 40 00       	mov    $0x40198e,%esi
  401398:	bf 95 19 40 00       	mov    $0x401995,%edi
  40139d:	b8 00 00 00 00       	mov    $0x0,%eax
  4013a2:	e8 89 f4 ff ff       	callq  400830 <printf@plt>
  4013a7:	c7 85 18 fa ff ff 00 	movl   $0x0,-0x5e8(%rbp)
  4013ae:	00 00 00 
  4013b1:	e9 fc 00 00 00       	jmpq   4014b2 <test_csim+0x6f4>
  4013b6:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  4013bc:	48 98                	cltq   
  4013be:	8b b4 85 60 fa ff ff 	mov    -0x5a0(%rbp,%rax,4),%esi
  4013c5:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  4013cb:	48 98                	cltq   
  4013cd:	8b 8c 85 40 fa ff ff 	mov    -0x5c0(%rbp,%rax,4),%ecx
  4013d4:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  4013da:	48 98                	cltq   
  4013dc:	8b 94 85 20 fa ff ff 	mov    -0x5e0(%rbp,%rax,4),%edx
  4013e3:	48 8d 85 e0 fb ff ff 	lea    -0x420(%rbp),%rax
  4013ea:	41 89 f0             	mov    %esi,%r8d
  4013ed:	be af 19 40 00       	mov    $0x4019af,%esi
  4013f2:	48 89 c7             	mov    %rax,%rdi
  4013f5:	b8 00 00 00 00       	mov    $0x0,%eax
  4013fa:	e8 a1 f4 ff ff       	callq  4008a0 <sprintf@plt>
  4013ff:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  401405:	48 98                	cltq   
  401407:	8b 84 85 80 fb ff ff 	mov    -0x480(%rbp,%rax,4),%eax
  40140e:	48 8d 95 e0 fb ff ff 	lea    -0x420(%rbp),%rdx
  401415:	89 c6                	mov    %eax,%esi
  401417:	bf ba 19 40 00       	mov    $0x4019ba,%edi
  40141c:	b8 00 00 00 00       	mov    $0x0,%eax
  401421:	e8 0a f4 ff ff       	callq  400830 <printf@plt>
  401426:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  40142c:	48 98                	cltq   
  40142e:	48 8b bc c5 a0 fb ff 	mov    -0x460(%rbp,%rax,8),%rdi
  401435:	ff 
  401436:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  40143c:	48 98                	cltq   
  40143e:	8b b4 85 e0 fa ff ff 	mov    -0x520(%rbp,%rax,4),%esi
  401445:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  40144b:	48 98                	cltq   
  40144d:	44 8b 8c 85 c0 fa ff 	mov    -0x540(%rbp,%rax,4),%r9d
  401454:	ff 
  401455:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  40145b:	48 98                	cltq   
  40145d:	44 8b 84 85 a0 fa ff 	mov    -0x560(%rbp,%rax,4),%r8d
  401464:	ff 
  401465:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  40146b:	48 98                	cltq   
  40146d:	8b 8c 85 40 fb ff ff 	mov    -0x4c0(%rbp,%rax,4),%ecx
  401474:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  40147a:	48 98                	cltq   
  40147c:	8b 94 85 20 fb ff ff 	mov    -0x4e0(%rbp,%rax,4),%edx
  401483:	8b 85 18 fa ff ff    	mov    -0x5e8(%rbp),%eax
  401489:	48 98                	cltq   
  40148b:	8b 84 85 00 fb ff ff 	mov    -0x500(%rbp,%rax,4),%eax
  401492:	48 89 7c 24 08       	mov    %rdi,0x8(%rsp)
  401497:	89 34 24             	mov    %esi,(%rsp)
  40149a:	89 c6                	mov    %eax,%esi
  40149c:	bf c1 19 40 00       	mov    $0x4019c1,%edi
  4014a1:	b8 00 00 00 00       	mov    $0x0,%eax
  4014a6:	e8 85 f3 ff ff       	callq  400830 <printf@plt>
  4014ab:	83 85 18 fa ff ff 01 	addl   $0x1,-0x5e8(%rbp)
  4014b2:	83 bd 18 fa ff ff 07 	cmpl   $0x7,-0x5e8(%rbp)
  4014b9:	0f 8e f7 fe ff ff    	jle    4013b6 <test_csim+0x5f8>
  4014bf:	8b 85 1c fa ff ff    	mov    -0x5e4(%rbp),%eax
  4014c5:	89 c6                	mov    %eax,%esi
  4014c7:	bf d9 19 40 00       	mov    $0x4019d9,%edi
  4014cc:	b8 00 00 00 00       	mov    $0x0,%eax
  4014d1:	e8 5a f3 ff ff       	callq  400830 <printf@plt>
  4014d6:	8b 85 1c fa ff ff    	mov    -0x5e4(%rbp),%eax
  4014dc:	89 c6                	mov    %eax,%esi
  4014de:	bf de 19 40 00       	mov    $0x4019de,%edi
  4014e3:	b8 00 00 00 00       	mov    $0x0,%eax
  4014e8:	e8 43 f3 ff ff       	callq  400830 <printf@plt>
  4014ed:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4014f1:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  4014f8:	00 00 
  4014fa:	74 05                	je     401501 <test_csim+0x743>
  4014fc:	e8 0f f3 ff ff       	callq  400810 <__stack_chk_fail@plt>
  401501:	48 81 c4 08 06 00 00 	add    $0x608,%rsp
  401508:	5b                   	pop    %rbx
  401509:	5d                   	pop    %rbp
  40150a:	c3                   	retq   

000000000040150b <main>:
  40150b:	55                   	push   %rbp
  40150c:	48 89 e5             	mov    %rsp,%rbp
  40150f:	48 83 ec 20          	sub    $0x20,%rsp
  401513:	89 7d ec             	mov    %edi,-0x14(%rbp)
  401516:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  40151a:	90                   	nop
  40151b:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
  40151f:	8b 45 ec             	mov    -0x14(%rbp),%eax
  401522:	ba f5 19 40 00       	mov    $0x4019f5,%edx
  401527:	48 89 ce             	mov    %rcx,%rsi
  40152a:	89 c7                	mov    %eax,%edi
  40152c:	e8 5f f3 ff ff       	callq  400890 <getopt@plt>
  401531:	88 45 ff             	mov    %al,-0x1(%rbp)
  401534:	80 7d ff ff          	cmpb   $0xff,-0x1(%rbp)
  401538:	74 35                	je     40156f <main+0x64>
  40153a:	0f be 45 ff          	movsbl -0x1(%rbp),%eax
  40153e:	83 f8 68             	cmp    $0x68,%eax
  401541:	75 16                	jne    401559 <main+0x4e>
  401543:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  401547:	48 89 c7             	mov    %rax,%rdi
  40154a:	e8 a1 f4 ff ff       	callq  4009f0 <usage>
  40154f:	bf 00 00 00 00       	mov    $0x0,%edi
  401554:	e8 57 f3 ff ff       	callq  4008b0 <exit@plt>
  401559:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  40155d:	48 89 c7             	mov    %rax,%rdi
  401560:	e8 8b f4 ff ff       	callq  4009f0 <usage>
  401565:	bf 01 00 00 00       	mov    $0x1,%edi
  40156a:	e8 41 f3 ff ff       	callq  4008b0 <exit@plt>
  40156f:	be 2b 0a 40 00       	mov    $0x400a2b,%esi
  401574:	bf 0e 00 00 00       	mov    $0xe,%edi
  401579:	e8 f2 f2 ff ff       	callq  400870 <__sysv_signal@plt>
  40157e:	48 83 f8 ff          	cmp    $0xffffffffffffffff,%rax
  401582:	75 28                	jne    4015ac <main+0xa1>
  401584:	48 8b 05 0d 0b 20 00 	mov    0x200b0d(%rip),%rax        # 602098 <stderr@@GLIBC_2.2.5>
  40158b:	48 89 c1             	mov    %rax,%rcx
  40158e:	ba 22 00 00 00       	mov    $0x22,%edx
  401593:	be 01 00 00 00       	mov    $0x1,%esi
  401598:	bf f8 19 40 00       	mov    $0x4019f8,%edi
  40159d:	e8 1e f3 ff ff       	callq  4008c0 <fwrite@plt>
  4015a2:	bf 01 00 00 00       	mov    $0x1,%edi
  4015a7:	e8 04 f3 ff ff       	callq  4008b0 <exit@plt>
  4015ac:	bf 14 00 00 00       	mov    $0x14,%edi
  4015b1:	e8 8a f2 ff ff       	callq  400840 <alarm@plt>
  4015b6:	b8 00 00 00 00       	mov    $0x0,%eax
  4015bb:	e8 fe f7 ff ff       	callq  400dbe <test_csim>
  4015c0:	bf 00 00 00 00       	mov    $0x0,%edi
  4015c5:	e8 e6 f2 ff ff       	callq  4008b0 <exit@plt>
  4015ca:	90                   	nop
  4015cb:	90                   	nop
  4015cc:	90                   	nop
  4015cd:	90                   	nop
  4015ce:	90                   	nop
  4015cf:	90                   	nop

00000000004015d0 <__libc_csu_init>:
  4015d0:	48 89 6c 24 d8       	mov    %rbp,-0x28(%rsp)
  4015d5:	4c 89 64 24 e0       	mov    %r12,-0x20(%rsp)
  4015da:	48 8d 2d 1f 08 20 00 	lea    0x20081f(%rip),%rbp        # 601e00 <__do_global_dtors_aux_fini_array_entry>
  4015e1:	4c 8d 25 10 08 20 00 	lea    0x200810(%rip),%r12        # 601df8 <__frame_dummy_init_array_entry>
  4015e8:	4c 89 6c 24 e8       	mov    %r13,-0x18(%rsp)
  4015ed:	4c 89 74 24 f0       	mov    %r14,-0x10(%rsp)
  4015f2:	4c 89 7c 24 f8       	mov    %r15,-0x8(%rsp)
  4015f7:	48 89 5c 24 d0       	mov    %rbx,-0x30(%rsp)
  4015fc:	48 83 ec 38          	sub    $0x38,%rsp
  401600:	4c 29 e5             	sub    %r12,%rbp
  401603:	41 89 fd             	mov    %edi,%r13d
  401606:	49 89 f6             	mov    %rsi,%r14
  401609:	48 c1 fd 03          	sar    $0x3,%rbp
  40160d:	49 89 d7             	mov    %rdx,%r15
  401610:	e8 9b f1 ff ff       	callq  4007b0 <_init>
  401615:	48 85 ed             	test   %rbp,%rbp
  401618:	74 1c                	je     401636 <__libc_csu_init+0x66>
  40161a:	31 db                	xor    %ebx,%ebx
  40161c:	0f 1f 40 00          	nopl   0x0(%rax)
  401620:	4c 89 fa             	mov    %r15,%rdx
  401623:	4c 89 f6             	mov    %r14,%rsi
  401626:	44 89 ef             	mov    %r13d,%edi
  401629:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  40162d:	48 83 c3 01          	add    $0x1,%rbx
  401631:	48 39 eb             	cmp    %rbp,%rbx
  401634:	75 ea                	jne    401620 <__libc_csu_init+0x50>
  401636:	48 8b 5c 24 08       	mov    0x8(%rsp),%rbx
  40163b:	48 8b 6c 24 10       	mov    0x10(%rsp),%rbp
  401640:	4c 8b 64 24 18       	mov    0x18(%rsp),%r12
  401645:	4c 8b 6c 24 20       	mov    0x20(%rsp),%r13
  40164a:	4c 8b 74 24 28       	mov    0x28(%rsp),%r14
  40164f:	4c 8b 7c 24 30       	mov    0x30(%rsp),%r15
  401654:	48 83 c4 38          	add    $0x38,%rsp
  401658:	c3                   	retq   
  401659:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000401660 <__libc_csu_fini>:
  401660:	f3 c3                	repz retq 
  401662:	90                   	nop
  401663:	90                   	nop

Disassembly of section .fini:

0000000000401664 <_fini>:
  401664:	48 83 ec 08          	sub    $0x8,%rsp
  401668:	48 83 c4 08          	add    $0x8,%rsp
  40166c:	c3                   	retq   
