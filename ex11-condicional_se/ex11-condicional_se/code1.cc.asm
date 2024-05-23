;UFMT-Compiladores
;Prof. Ivairton
;Procedimento para geracao do executavel apos compilacao (em Linux):
;(1) compilacao do Assembly com nasm: $ nasm -f elf64 <nome_do_arquivo>
;(2) likedicao: $ ld -m elf_x86_64 <nome_arquivo_objeto>

extern printf
extern scanf

	section .text
	global main,_start
main:
_start:

;escreve valor string
mov edx,16
mov ecx,str0
mov ebx,1
mov eax,4
int 0x80

;le valor inteiro
mov edx,4
mov ecx,valor
mov ebx,1
mov eax,3
int 0x80
;Aplica operador booleano/exp.logica
pop rbx
pop rax
mov rcx,1
cmp eax,ebxje label0
mov rcx,0
label0:
mov rax, rcx
push rax
;jump condicional
pop rax
cmp rax, 0
jz label0

;escreve valor string
mov edx,16
mov ecx,str1
mov ebx,1
mov eax,4
int 0x80
;jump incondicional
jmp label1
label0:
label1:

;encerra programa
mov ebx,0
mov eax,1
int 0x80

	section .data
valor: dd "%d", 4
valor2: dd "%d", 4
str0: db "Informe um valor"
str1: db "Impressao interna ao IF!\"
