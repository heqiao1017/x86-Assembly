/***********************************************************************************************
 
Dijkstra's Algorithm to calculate GCD.
 
 Implement a recursive function in assembly that calculates the greatest common divisor of
 two unsigned integers.
 
 Given two unsigned integers n and m, we can define GCD(m , n) as:
 
 GCD(m , n) = n                       ,    if (m % n) == 0
 GCD(m , n) = GCD(n , m % n)          ,    if (m % n) >  0
 
 ************************************************************************************************/

__declspec(naked)
unsigned int gcd(unsigned int m, unsigned int n) {
    
    // C code to be converted to x86 assembly
    /*
     if ((m % n) == 0)
     return n;
     else
     return gcd(n, m % n);
     */
    __asm{
        mov eax, 0
        // BEGIN YOUR CODE HERE
        
        push ebp
        mov ebp, esp
        
        push edi
        push esi
        push ebx
        
        //access the parameter
        mov edi, [ebp + 8] //edi=m
        mov esi, [ebp + 12] //esi=n
        
        //find the m modules n
        mov edx, 0
        mov eax, edi
        mov ebx, esi
        div ebx
        mov edi, edx
        
        cmp edi, 0
        je ret_1
        
        push eax
        push ecx
        push edx
        
        push edi //second parameter
        push esi //first parameter
        
        call gcd
        mov ebx, eax
        
        add esp, 8
        
        pop edx
        pop ecx
        pop eax
        
        mov eax, ebx
        jmp end
        
        ret_1 :
        mov eax, esi //eax=n
        
        end :
        pop ebx
        pop esi
        pop edi
        
        pop ebp
        
        // END YOUR CODE HERE
        ret
    }
}
