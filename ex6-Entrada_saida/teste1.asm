extern printf
extern scanf
section .data
fmt_d: db "%ld", 0
fmt_f: db "%f", 0
fmt_s: db "%s", 0
fmt_dln: db "%ld", 10, 0
fmt_fln: db "%f", 10, 0
fmt_sln: db "%s", 10, 0

a: dq 0
b: dq 0
c: dq 0

section .text
global main

main:
mov rdi,fmt_d
mov rsi,a
mov rax,0
call scanf
mov rdi,fmt_d
mov rsi,b
mov rax,0
call scanf
mov rbx,[b]
push rbx
pop rbx
mov [a],rbx
mov rdi,fmt_d
mov rsi,[a]
mov rax,0
call printf
mov rax,0
ret
