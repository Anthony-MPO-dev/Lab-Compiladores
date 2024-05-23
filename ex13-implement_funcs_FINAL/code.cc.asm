;UFMT-Compiladores
;Prof. Ivairton
;Academico Anthony M. P. de Oliveira
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
label2:
;Aplica operador booleano/exp.logica
pop rbx
pop rax
mov rcx,1
cmp eax,ebxjg label0
mov rcx,0
label0:
mov rax, rcx
push rax
;jump condicional
pop rax
cmp rax, 0
jz label3

;escreve valor string
mov edx,16
mov ecx,str1
mov ebx,1
mov eax,4
int 0x80

;escreve valor inteiro
mov edx,4
mov ecx,valor
mov ebx,1
mov eax,4
int 0x80
;Amarzenamento de numero
mov rax,5
push rax
;Amarzenamento de numero
mov rax,4
push rax
;Adicao
pop rax
pop rbx
add rax,rbx
push rax

;atribui valor inteiro
pop rax
mov [valor], rax
label4:
;jump incondicional
jmp label0
;jump incondicional
jmp label2
label3:
label0:
;Amarzenamento de numero
mov rax,x
push rax
;Amarzenamento de numero
mov rax,y
push rax
;Adicao
pop rax
pop rbx
add rax,rbx
push rax

;atribui valor inteiro
pop rax
mov [x], rax
;jump incondicional
jmp label4
label1:

;escreve valor string
mov edx,16
mov ecx,str2
mov ebx,1
mov eax,4
int 0x80

;le valor inteiro
mov edx,4
mov ecx,valor
mov ebx,1
mov eax,3
int 0x80
;jump incondicional
jmp 

;encerra programa
mov ebx,0
mov eax,1
int 0x80

	section .data
valor: dd "%d", 4
value: dd "%d", 4
x: dd "%d", 4
y: dd "%d", 4
str0: db "Informe um valor"
str1: db "\nvalor"
str2: db "Informe um valor"