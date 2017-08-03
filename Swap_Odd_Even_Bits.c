#include <stdio.h>
#include <ctype.h>

/*
    Given a 32-bit integer, swap all odd bits with even bits.
	For example, if the given number is 23 (00010111), it should be
	converted to 43 (00101011). Every even position bit is swapped
	with adjacent bit on right side, and every odd position bit is
	swapped with adjacent on left side.
 
	Implementation details:
	The input integer is stored in registers ebx. You need to store the
	answer into register eax.
 
 */


int swapBits(int x)
{
    int result;
    
    __asm
    {
        mov ebx, x
        
        // YOUR CODE STARTS HERE
        
        mov ecx, ebx		//copy the input from ebx into ecx
        
        and ecx, 0x55555555 //clearing odd bits
        
        shl ecx, 1			//shifting left of one bit
        
        mov edx, ebx		//copy the input from ebx into edx
        
        and edx, 0xAAAAAAAA //clearing even bit
        
        shr edx, 1			//shifting right of one bit
        
        or ecx, edx			//combine generated odd and even bits
        
        mov eax, ecx
        
        // YOUR CODE ENDS HERE
        
        mov result, eax
    }
    return result;
    
}
