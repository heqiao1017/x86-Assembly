/***********************************************************************************************
 
Selection Sort:
 
 Selection sort is an in-place comparison sort algorithm that works by dividing the input list
 into two parts: the sublist of items already sorted, which is built up from left to right of
 the list, and the sublist of items remaining to be sorted that occupy the rest of the list.
 Initially, the sorted sublist is empty and the unsorted sublist is the entire input list.
 The algorithm proceeds by finding the smallest element in the unsorted sublist, exchanging it
 with the leftmost unsorted element (putting it in sorted order), and moving the sublist
 boundaries one element to the right. To learn more, read:
 https://en.wikipedia.org/wiki/Selection_sort#Example
 
 Our implementation here uses a function called "findMinIndex" to find the index of smallest
 element between ith index and jth index of the array. The function "selectionSort" uses
 this function to find the smallest number and exchanges it with the leftmost unsorted element
 in each iteration. You need to implement the behavior of both functions in x86 assembly.
 
 ************************************************************************************************/

__declspec(naked)
int findMinIndex(int integer_array[], int i, int j)
{
    
    // C code to be converted to x86 assembly
    /*
     int iMin = i;
     // test against elements after i and before j to find the smallest
     for ( i ; i < j; i++) {
     // if this element is less, then it is the new minimum
     if (integer_array[i] < integer_array[iMin]) {
     // found new minimum; remember its index
     iMin = i;
     }
     }
     
     return iMin;
     */
    
    __asm{
        mov eax, 0
        // BEGIN YOUR CODE HERE
        push ebp
        mov ebp, esp
        
        sub esp, 4
        
        push edi
        push esi
        push ebx
        
        mov ebx, [ebp + 8] //arr
        mov esi, [ebp + 12]  //i
        mov edi, [ebp + 16]   //j
        mov[ebp - 4], esi
        
        begin_for :
        cmp esi, edi
        jge end_loop
        
        mov eax, dword ptr[ebx + esi * 4]
        mov ecx, [ebp - 4]
        mov ecx, dword ptr[ebx + ecx * 4]
        cmp eax, ecx
        jge next_iter
        mov[ebp - 4], esi
        
        next_iter :
        inc esi
        jmp begin_for
        end_loop :
        mov eax, [ebp - 4]
        
        pop ebx
        pop esi
        pop edi
        
        mov esp, ebp
        pop ebp
        
        // END YOUR CODE HERE
        ret
    }
    
}

void selectionSort(int integer_array[], int array_size)
{
    
    // C code to be converted to x86 assembly
    /*
     int j;
     int iMin;
     int temp;
     
     // advance the position through the entire array //
     // (could do j < n-1 because single element is also min element) //
     for (j = 0; j < array_size-1; j++) {
     
     // find the index of min element in the unsorted a[j .. n-1] //
     iMin = findMinIndex (integer_array, j, array_size);
     
     if(iMin != j) { // swap values
     temp = integer_array[iMin];
     integer_array[iMin] = integer_array [j];
     integer_array[j] = temp;
     }
     }
     */
    
    __asm{
        // BEGIN YOUR CODE HERE
        mov ecx, 0
        mov ebx, integer_array
        for_loop :
        mov eax, array_size
        dec eax
        cmp ecx, eax
        jge end_loop
        
        push eax
        push ecx
        push edx
        
        inc eax
        push eax
        push ecx
        push ebx
        
        call findMinIndex
        mov esi, eax
        
        add esp, 12
        
        pop edx
        pop ecx
        pop eax
        
        cmp esi, ecx
        je next_iter
        mov edi, dword ptr[ebx + esi * 4]
        mov edx, dword ptr[ebx + ecx * 4]
        mov dword ptr[ebx + esi * 4], edx
        mov dword ptr[ebx + ecx * 4], edi
        
        next_iter :
        inc ecx
        jmp for_loop
        end_loop :
        
        // END YOUR CODE HERE
    }
    
}

