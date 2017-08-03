
// - This function takes in a square sized grayscale image and applies thresholding on each pixel.
//   i.e. it should change pixel values according to this formula:
//                     0xFF       if x >= threshold
//                     0x00       if x <  threshold
// - The width and height of the image are equal to dim. 
// - You are not allowed to define additional variables.
//
void imageThresholding(unsigned char* image, int dim, unsigned char threshold) {
    __asm {
    
            // YOUR CODE STARTS HERE
		mov esi, 0; //row counter
	outer_loop:
		cmp esi, dim;
		jge end_outer_loop;

		mov edi, 0; //col counter
	inner_loop:
		cmp edi, dim;
		jge end_inner_loop;

		mov eax, dim;
		mov ebx, esi;
		imul eax, ebx; // row*dim
		add eax, edi; // row*dim + col
		mov ebx, eax;
		add ebx, image; 
		mov al, byte ptr[ebx];

		cmp al, threshold;
		jb else_if;
		mov al, 0xFF;
		mov byte ptr[ebx], al;
		jmp end_if;
	else_if:
		mov al, 0x00;
		mov byte ptr[ebx], al;
	end_if:

		inc edi;
		jmp inner_loop;
	end_inner_loop:

		inc esi;
		jmp outer_loop;
	end_outer_loop:
            // YOUR CODE ENDS HERE
    }
}



// - This function rotates a square sized color image 90 degress counterclockwise.
// - The width and height of the image are both equal to dim.
// - Four variables (i0, i90, i180, i270) are defined that you may use in your implementation for
//   temporary data storage. You are not allowed to define additional variables.
//
void imageRotation(unsigned int* image, int dim) {
  
    unsigned int i0, i90, i180, i270;
  
    __asm {
    
            // YOUR CODE STARTS HERE

            // Iterate over the red triangle (row by row starting from top left)

                // compute index of pixel p0, find the corresponding memory address and store it in i0

                // compute index of pixel 90, find the corresponding memory address and store it in i270

                // compute index of pixel p180, find the corresponding memory address and store it in i180

                // compute index of pixel 270, find the corresponding memory address and store it in i90

                // rotationaly swap pixel values: p0 -> p90 -> p180 -> p270 -> p0

		mov esi, 0; //row counter
	outer_loop:
		mov eax, dim;
		shr eax, 1;
		cmp esi, eax;
		jge end_outer_loop;

		mov edi, esi; //col counter
	inner_loop:
		mov eax, dim;
		sub eax, esi;
		dec eax;
		cmp edi, eax;
		jge end_inner_loop;

		// compute index of pixel p0, find the corresponding memory address and store it in i0
		mov eax, dim;
		mov ebx, esi;
		imul eax, ebx;
		add eax, edi;
		shl eax, 2;
		add eax, image;
		mov i0, eax;

		// compute index of pixel 90, find the corresponding memory address and store it in i270
		mov eax, dim;
		dec eax;
		sub eax, edi; //row, col=esi
		mov ecx, eax //save the row of pixel 90, col of pixel 90 is the esi
		mov ebx, dim;
		imul eax, ebx; //row * dim
		add eax, esi;
		shl eax, 2;
		add eax, image;
		mov i270, eax;


		// compute index of pixel p180, find the corresponding memory address and store it in i180
		mov eax, dim;
		dec eax;
		sub eax, esi; //row of pixel 180 = dim -1 - col of pixel 90
		mov edx, eax; //save the row of pixel 180, col of pixel 180 is ecx
		mov ebx, dim;
		imul eax, ebx;
		add eax, ecx;
		shl eax, 2;
		add eax, image;
		mov i180, eax;

		

		// compute index of pixel 270, find the corresponding memory address and store it in i90
		mov eax, dim;
		dec eax;
		sub eax, ecx; // row of 270 = dim -1 - col of pixel 180
		mov ecx, edx; // col of 270 = row of 180
		//mov edx, eax; // save the row of 270
		mov ebx, dim;
		imul eax, ebx;
		add eax, ecx;
		shl eax, 2;
		add eax, image;
		mov i90, eax;

		// rotationaly swap pixel values: p0 -> p90 -> p180 -> p270 -> p0
		mov eax, i0;
		mov eax, dword ptr[eax];

		mov ebx, i270;
		mov ecx, dword ptr[ebx]; //save p90

		mov dword ptr[ebx], eax; // p0->p90

		mov eax, i180;
		mov ebx, dword ptr[eax]; // save p180

		mov dword ptr[eax], ecx; //p90->p180

		mov eax, i90;
		mov ecx, dword ptr[eax]; //save p270

		mov dword ptr[eax], ebx; //p180->p270

		mov eax, i0;
		mov dword ptr[eax], ecx; //p7-->p0

		inc edi;
		jmp inner_loop;
	end_inner_loop:

		inc esi;
		jmp outer_loop;
	end_outer_loop:


            // YOUR CODE ENDS HERE
    }
}
