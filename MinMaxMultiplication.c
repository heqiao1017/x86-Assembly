#include <stdio.h>
#include <ctype.h>

/*
    You are given three 32-bit signed integers. You need to add the
	smallest number to the largest number and multiply that sum by 2017.
	You cannot use mul/imul instructions.
 
	Implementation details:
	The three integers are stored in registers eax, ebx, and ecx. You
	need to store the answer into register eax.
 
	Hint:
	One way of finding minimum and maximum number is to sort the numbers.
 
 */

void minMax(int a, int b, int c, int *result)
{
    __asm
    {
        mov esi, result
        
        mov eax, a
        mov ebx, b
        mov ecx, c
        
        // YOUR CODE STARTS HERE
        mov edx, eax // edx <- a, find max
        cmp ebx, edx
        jle second_if
        mov edx, ebx
        
    second_if:
        cmp ecx, edx
        jle after_second_if
        mov edx, ecx
        
    after_second_if:
        mov edi, eax // edi <- a, find min
        cmp ebx, edi
        jge third_if
        mov edi, ebx
        
    third_if:
        cmp ecx, edi
        jge after_third_if
        mov edi, ecx
        
    after_third_if:
        
        add edx, edi		//add max and min integer to edx
        
        mov edi, edx
        mov ebx, edx
        
        shl edi, 11			// multiply edi by 2^11
        shl ebx, 5			// multiply ebx by 2^5
        sub edi, ebx			//edi=(2^11*edx - 2^5*edx = 2016*edx)
        add edx, edi		// 2016*edx + 1* edx = 2017* edx
        mov eax, edx
        
        // YOUR CODE ENDS HERE
        
        mov [esi][0], eax
    }
    
    return;
}
