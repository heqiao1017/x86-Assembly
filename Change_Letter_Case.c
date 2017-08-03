
/***********************************************************************************************
 
Change Letter Case:
 
 You are given a string (null-terminated array of characters) that may contain numbers,
 upper andlower case letters, punctuations symbols, etc. Implement a function to convert all
 uppercase letters to lowercase and vice versa.
 For example "ThisIsTheFinalLabOf51" should be converted to "tHISiStHEfINALlABoF51".
 The string should be modifed in place. There is no explicit output for this function.
 
 Tips:
 
 - Note that each element of the arrays is a char (1 byte). You can NOT use a 32-bit register
 to read/write from/to a memory location. Instead you should use the 8-bit version of the x86
 general-purpose registers.
 
 - The link to the ASCII codes is here: http://www.asciitable.com/
 
 ************************************************************************************************/

void changeCase(char *string) {
    
    __asm{
        // BEGIN YOUR CODE HERE
        mov eax, string
        mov bl, byte ptr[eax]
        mov ecx, 0
    while_loop:
        cmp bl, 0
        je end
        cmp bl, 122
        jg next_iter
        cmp bl, 97
        jl else_if
        sub bl, 32
        mov byte ptr[eax + ecx], bl
        jmp next_iter
        else_if :
        cmp bl, 65
        jl next_iter
        add bl, 32
        mov byte ptr[eax + ecx], bl
        next_iter :
        inc ecx
        mov bl, byte ptr[eax + ecx]
        jmp while_loop
        end :
        // END YOUR CODE HERE
    }
}
