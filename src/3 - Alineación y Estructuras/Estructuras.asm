

;########### ESTOS SON LOS OFFSETS Y TAMAÑO DE LOS STRUCTS
; Completar las definiciones (serán revisadas por ABI enforcer):
NODO_OFFSET_NEXT EQU 0
NODO_OFFSET_CATEGORIA EQU 8 
NODO_OFFSET_ARREGLO EQU 16
NODO_OFFSET_LONGITUD EQU 24
NODO_SIZE EQU 32
PACKED_NODO_OFFSET_NEXT EQU 0 
PACKED_NODO_OFFSET_CATEGORIA EQU 8
PACKED_NODO_OFFSET_ARREGLO EQU 9
PACKED_NODO_OFFSET_LONGITUD EQU 17
PACKED_NODO_SIZE EQU 21
LISTA_OFFSET_HEAD EQU 0
LISTA_SIZE EQU 8
PACKED_LISTA_OFFSET_HEAD EQU 0
PACKED_LISTA_SIZE EQU 8

;########### SECCION DE DATOS
section .data

;########### SECCION DE TEXTO (PROGRAMA)
section .text

;########### LISTA DE FUNCIONES EXPORTADAS
global cantidad_total_de_elementos
global cantidad_total_de_elementos_packed

;########### DEFINICION DE FUNCIONES
;extern uint32_t cantidad_total_de_elementos(lista_t* lista);
;registros: lista[RDI]
cantidad_total_de_elementos:
    ; prólogo
    push rbp
    mov rbp, rsp

    xor rax, rax            ; acumulador en EAX = 0
    mov rsi, [rdi]          ; rsi = lista->head (puntero al primer nodo)

.loop:
    cmp rsi, 0          ; si es NULL, terminamos
    je .end

    add rax, [rsi + NODO_OFFSET_LONGITUD] ; sumamos longitud al acumulador
    mov rsi, [rsi + NODO_OFFSET_NEXT] ; avanzar al siguiente nodo
    jmp .loop

.end:
	;epilogo
    pop rbp
    ret

;extern uint32_t cantidad_total_de_elementos_packed(packed_lista_t* lista);
;registros: lista[rdi]
cantidad_total_de_elementos_packed:
	;prologo 
	push rbp
	mov rbp, rsp 

	xor rax, rax ; acumulador en 0
	mov rsi, [rdi]

.loop_packed:
	cmp rsi, 0 
	je .end_packed

	add eax, [rsi+PACKED_NODO_OFFSET_LONGITUD]
	mov rsi, [rsi+PACKED_NODO_OFFSET_NEXT]
	jmp .loop_packed

.end_packed:
	;epilogo
	pop rbp
	ret

