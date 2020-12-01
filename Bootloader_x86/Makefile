
all: kernel

kernel: kc.o boot.o link.ld
	ld -m elf_i386 -T link.ld -o kernel boot.o kc.o
boot.o: boot.asm
	nasm -f elf32 boot.asm -o boot.o
kc.o:kernel.c
	gcc -m32 -c kernel.c -o kc.o

clean:
	rm *.o

