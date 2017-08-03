/***********************************************************************************************
 
Palindrome:
 
 Given a string, complete the implementation of the recursive function isPalindrome() to check
 if the string is palindrome or not. A string is said to be palindrome if reverse of the
 string is same as string. For example, “abba” is palindrome, but “abbc” is not palindrome.
 
 ************************************************************************************************/

__declspec(naked)
int isPalindrome(char *input_string, int left_index, int right_index)
{
    
    // C code to be converted to x86 assembly
    /*
     // Input Validation
     if (NULL == input_string || left_index < 0 || right_index < 0){
     return -1;
     }
     // Recursion termination condition
     if (left_index >= right_index)
     return 1;
     if (input_string[left_index] == input_string[right_index]){
     return isPalindrome(input_string, left_index + 1, right_index - 1);
     }
     return -1;
     */
    
    __asm{
        mov eax, 0
        // BEGIN YOUR CODE HERE
        push ebp
        mov ebp, esp
        
        push edi
        push esi
        push ebx
        
        mov ebx, [ebp + 8] //first char
        mov esi, [ebp + 12] //left
        mov edi, [ebp + 16] //right
        
        //mov al, byte ptr[ebx]
        cmp ebx, 0
        je ret_1
        cmp esi, 0
        jl ret_1
        cmp edi, 0
        jl ret_1
        
        cmp esi, edi
        jge ret_2
        
        mov ebx, [ebp + 8]
        mov al, byte ptr[ebx + esi]
        mov bl, byte ptr[ebx + edi]
        cmp al, bl
        jne ret_1
        
        push eax
        push ecx
        push edx
        
        inc esi
        dec edi
        push edi
        push esi
        mov ebx, input_string
        push ebx
        
        call isPalindrome
        mov ebx, eax
        add esp, 12
        pop edx
        pop ecx
        pop eax
        
        mov eax, ebx
        jmp end
        
        ret_1 :
        mov eax, -1
        jmp end
        ret_2 :
        mov eax, 1
        jmp end
        end :
        pop ebx
        pop esi
        pop edi
        
        pop ebp
        
        // END YOUR CODE HERE
        ret
    }
}
