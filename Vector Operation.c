/***********************************************************************************************
 
Vector Operation:
 
 The vectorOperations function gets as parameters 4 arrays of the same length and
 the number of elements in those arrays.
 
 For each pair of elements in first_array and second_array, it calls performOperation
 and stores the returned result in the same index of output_array.
 
 output_array[index] = performOperation(operation_array[index], first_array[index], second_array[index]).
 
 You also need to implement the body of performOperation function according to the provided
 C code.
 
 ************************************************************************************************/

__declspec(naked)
int performOperation(int operation, int first, int second)
{
    
    // C code to be converted to x86 assembly
    /*
     if (operation==0)
     return first - second;
     else if (operation==1)
     return first + second;
     else if (operation==2)
     return (first < second)? first : second;
     else if (operation==3)
     return (first > second)? first : second;
     else
     return first;
     */
    
    __asm {
        // BEGIN YOUR CODE HERE
        push ebp
        mov ebp, esp
        
        push edi
        push esi
        push ebx
        
        mov ebx, [ebp + 8]
        mov esi, [ebp + 12]
        mov edi, [ebp + 16]
        
        cmp ebx, 0
        je ret_1
        cmp ebx, 1
        je ret_2
        cmp ebx, 2
        je ret_3
        cmp ebx, 3
        je ret_4
        
        mov eax, esi
        jmp end
        
        ret_1 :
        sub esi, edi
        mov eax, esi
        jmp end
        
        ret_2 :
        add esi, edi
        mov eax, esi
        jmp end
        
        ret_3 :
        cmp esi, edi
        jge else_1
        mov eax, esi
        jmp end
        
        ret_4 :
        cmp esi, edi
        jle else_1
        mov eax, esi
        jmp end
        
        else_1 :
        mov eax, edi
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

void vectorOperations(int number_of_elements, int *first_array, int *second_array,
                      int *operation_array, int *output_array)
{
    // C code to be converted to x86 assembly
    /*
     int i;
     for (i=0; i<number_of_elements; i++)
     {
     output_array[i] = performOperation(operation_array[i], first_array[i], second_array[i]);
     }
     */
    
    __asm {
        // BEGIN YOUR CODE HERE
        mov ecx, 0 //counter=0
    begin_For:
        mov ebx, number_of_elements
        cmp ecx, ebx
        jge end_loop
        
        mov eax, operation_array
        mov eax, dword ptr[eax + ecx * 4]
        mov ebx, first_array
        mov ebx, dword ptr[ebx + ecx * 4]
        mov esi, second_array
        mov esi, dword ptr[esi + ecx * 4]
        
        push eax
        push ecx
        push edx
        
        push esi
        push ebx
        push eax
        
        call performOperation
        
        mov ebx, output_array
        mov dword ptr[ebx + ecx * 4], eax
        
        add esp, 12
        
        pop edx
        pop ecx
        pop eax
        
        
        inc ecx
        jmp begin_for
        
        end_loop :
        
        // END YOUR CODE HERE
    }
}
