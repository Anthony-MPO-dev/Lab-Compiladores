extern printf
extern scanf

section .data
fmtstr0 db "%d", 0
a: dd 0
b: dd 0
c: dd 0
d: dd 0
e: dd 0
f: dd 0
g: dd 0
h: dd 0
i: dd 0
j: dd 0
k: dd 0
l: dd 0
m: dd 0
n: dd 0
o: dd 0
p: dd 0
q: dd 0
r: dd 0
s: dd 0
t: dd 0
u: dd 0
ab: dd 0
hj: dd 0
ad: dd 0
be: dd 0
af: dd 0
bg: dd 0
ah: dd 0
bi: dd 0
da: dd 0
bc: dd 0
bd: dd 0
bf: dd 0

section .text
  global main
main:
mov rdi, fmtstr0
mov rsi, [rel a]
mov rax, 0
call printf
mov rdi, fmtstr0
mov rsi, [rel a]
mov rax, 0
call printf

ret
