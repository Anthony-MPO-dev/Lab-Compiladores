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

;le valor string
mov edx,16
mov ecx,nome
mov ebx,1
mov eax,3
int 0x80

;encerra programa
mov ebx,0
mov eax,1
int 0x80

	section .data
nota: dd "%lf", 16
nome: db "                " 
str0: db "Informe seu nome"
