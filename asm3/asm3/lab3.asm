.586
.MODEL FLAT, STDCALL
includelib kernel32.lib
includelib user32.lib

ExitProcess PROTO : DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD

.stack 4096

.data
myBytes BYTE 10h, 20h, 30h, 40h
myWords WORD 8Ah, 3Bh, 44h, 5Fh, 99h
myDoubles DWORD 1, 2, 3, 4, 5, 6
myPointer DWORD myDoubles
myArr DWORD 1, 2, 3, 0, 5, 6, 7

; 
STR_SUM  BYTE "Сумма элементов массива = ",0
BUF      BYTE 16 DUP(0)

.code
main PROC
    mov ESI, 0
    mov EAX, myDoubles[ESI + 1]        ; EAX = 2
    mov EDX, [myDoubles + ESI]         ; EDX = 1

    ; 
    xor eax, eax
    mov esi, offset myArr
    mov ecx, lengthof myArr

CYCLE1:
    add eax, [esi]      ; 
    add esi, type myArr
    loop CYCLE1
    ; 

    ; 
    mov ebx, 10
    lea edi, BUF+15
    mov byte ptr [edi], 0
    dec edi

CONVERT:
    xor edx, edx
    div ebx
    add dl, '0'
    mov [edi], dl
    dec edi
    test eax, eax
    jnz CONVERT

    inc edi    ; 

    ; 
    invoke MessageBoxA, 0, edi, offset STR_SUM, 0

    ; 
    xor eax, eax
    mov ebx, 1
    mov esi, offset myArr
    mov ecx, lengthof myArr

CYCLE2:
    cmp dword ptr [esi], 0
    je FOUND_ZERO
    add esi, type myArr
    loop CYCLE2
    jmp NOT_FOUND_ZERO

FOUND_ZERO:
    mov ebx, 0
    jmp END_PROGRAM

NOT_FOUND_ZERO:
    jmp END_PROGRAM

END_PROGRAM:
    push 0
    call ExitProcess
main ENDP

end main
