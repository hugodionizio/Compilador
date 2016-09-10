#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <link.h>
#include <elf.h>

int main(int argc, char **argv) {
	ElfW(Ehdr) *header;
	unsigned char *mem;
	struct stat st;
	int fd;

	fd = open(argv[1], O_RDWR | O_FSYNC);
	
	if (fd == -1) {
		printf("Erro ao abrir arquivo!\n");
		exit(1);
	}

	fstat(fd, &st);

	mem = mmap(0, st.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	
	if (mem == MAP_FAILED) {
		printf("mmap falhou!\n");
		exit(1);
	}
	
	header = (ElfW(Ehdr)*) mem;

	printf("Número de seções: %hd\n", header->e_shnum);
	
	munmap(mem, st.st_size);
	close(fd);
	
	return 0;
}
