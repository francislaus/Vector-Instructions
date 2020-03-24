ABIN = elf64
GCC_FLAGS = -O2 -no-pie

vector_c:
	gcc vector_c.c -o vector_c $(GCC_FLAGS)

vector_asm: vector_asm.c vector_asm.o
	gcc vector_asm.c vector_asm.o -o vector_asm $(GCC_FLAGS)

vector_asm.c:
	gcc vector_asm.c -o vector_asm $(GCC_FLAGS)

vector_asm.o:
	nasm -f $(ABIN) vector_asm.asm

clean:
	rm vector_asm.o vector_asm vector_c