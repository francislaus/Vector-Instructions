ABIN = elf64
GCC_FLAGS = -O2 -no-pie

vector_c:
	gcc vector_c.c -o vector_c $(GCC_FLAGS)

vector_sse: vector_sse.c vector_sse.o
	gcc vector_sse.c vector_sse.o -o vector_sse $(GCC_FLAGS)

vector_sse.c:
	gcc vector_sse.c -o vector_sse $(GCC_FLAGS)

vector_sse.o:
	nasm -f $(ABIN) vector_sse.asm

clean:
	rm vector_sse.o vector_sse vector_c