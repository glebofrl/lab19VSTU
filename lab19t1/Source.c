#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <io.h>


int main(void) {
    setlocale(LC_CTYPE, "RUS");

	char fname[20] = "number.txt";
	FILE* out;
	puts("Creating file");
	if ((out = fopen(fname, "a")) == NULL) {
		printf("Ошибка открытия файла для записи");
		return 0;
	}

	fprintf(out, "\n%.2f", 12.22);
	fclose(out);

	return 1;
}