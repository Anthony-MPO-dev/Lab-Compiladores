segment .data
Message: db "Hello Linux Mint!",0
Format: db "%s",10,0

segment .text

global main

extern printf

main:

push RBP

lea RDI, [rel Format]	; changed
lea RSI, [rel Message]	; changed
call printf wrt ..plt	; changed

mov RAX,0
pop RBP

ret