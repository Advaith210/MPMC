/*
*  kernel.c
*/
void kmain(void)
{
	const char *str = "x86 Bootloader";
	const char *name1 = "Advaith Aduri";
	const char *name2 = "Ajmeera Girish";
	char *vidptr = (char*)0xb8000; 	//video mem begins here.
	unsigned int i = 0;
	unsigned int j = 0;

	/* this loops clears the screen
	* there are 25 lines each of 80 columns; each element takes 2 bytes */
	while(j < 80 * 25 * 2) {
		/* blank character */
		vidptr[j] = ' ';
		/* attribute-byte - light green on black screen */
		vidptr[j+1] = 0xa0; 		
		j = j + 2;
	}

	j = 0;
	i = 80*2*4 + 66;
	/* this loop writes the string to video memory */
	while(str[j] != '\0') {
		/* the character's ascii */
		vidptr[i] = str[j];
		/* attribute-byte: give character black bg and light green fg */
		vidptr[i+1] = 0xa0;
		++j;
		i = i + 2;
	}
	i = 80*2*8 + 68;
	j = 0;
	while(name1[j] != '\0') {
		/* the character's ascii */
		vidptr[i] = name1[j];
		/* attribute-byte: give character black bg and light green fg */
		vidptr[i+1] = 0xa0;
		++j;
		i = i + 2;
	}
	i = 80*2*12 + 68;
	j = 0;
	while(name2[j] != '\0') {
		/* the character's ascii */
		vidptr[i] = name2[j];
		/* attribute-byte: give character black bg and light green fg */
		vidptr[i+1] = 0xa0;
		++j;
		i = i + 2;
	}
	return;
}
