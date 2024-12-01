; Karl Andrei L. Ordinario and Oliver Aldrin H. Arucan
; S14


section .data
    conversion_factor dq 0.277777778  


section .text
    global compute_acceleration

compute_acceleration:
    

   
    mov r9, r8                
    xor r10, r10              

.loop_start:
    
    mov rax, r10
    imul rax, 24              

   
    movsd xmm0, qword [rcx + rax]       
    movsd xmm1, qword [rcx + rax + 8]   
    movsd xmm2, qword [rcx + rax + 16]  

    
    movsd xmm3, qword [conversion_factor]    
    mulsd xmm0, xmm3                        
    mulsd xmm1, xmm3                        

    
    subsd xmm1, xmm0                        
    divsd xmm1, xmm2                        

    
    cvtsd2si r11, xmm1                      

    
    mov dword [rdx + r10 * 4], r11d         

    
    inc r10
    cmp r10, r9
    jl .loop_start

    ret
