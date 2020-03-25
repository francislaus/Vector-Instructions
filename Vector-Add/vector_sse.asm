; Implementation of the vector addition

; The parameters are expected in the following way
; parameter length: rdi
; parameter a:      rsi
; parameter b:      rdx
; parameter c:      rcx
; the parameter length is expected to be divisble by four
; furthermore we expect the parameters a, b, and c to be aligned
[BITS 64]

section .text
global _vector_add
_vector_add:
    ; we use rax and need to push it therefore
    push rax
    ; test whether rdi is zero
    ; if zero jump to funct_end
    test rdi, rdi
    je funct_end

    ; calculations
    xor rax, rax

iteration_step:
    movups xmm0, [rsi + rax*4]
    movups xmm1, [rdx + rax*4]
    addps xmm0, xmm1
    movups [rcx + rax*4], xmm0
    add rax, 4
    cmp rdi, rax
    jne iteration_step

funct_end:
    ; restore rax and jump back to the callee
    pop rax
    ret