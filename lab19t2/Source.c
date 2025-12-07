#include <stdio.h>
#include <io.h>
#include <locale.h>
#include <math.h>

FILE* wdate(void) {
	char fname[20] = "temp.txt";
	printf("Работа с файлом %s\n", fname);
	puts("Запись в новый файл");
	FILE* out;
	if ((out = fopen(fname, "wt")) == NULL) {
		puts("Ошибка открытия файла для записи");
		return 0;
	}
	return out;
}

FILE* adate(void) {
	char fname[20] = "temp.txt";
	printf("Работа с файлом %s\n", fname);
	puts("Дозапись в существующий файл");
	FILE* out;
	if ((out = fopen(fname, "a")) == NULL) {
		puts("Ошибка открытия файла для записи");
		return 0;
	}
	return out;

}


float tab_func(float i) {
	return pow(i, 2) + 5 * sin(i);
}

int main(void) {
	setlocale(LC_CTYPE, "RUS");

	float dx, res;
	FILE* out = NULL;


	puts("Выберите действие: \n1) запись в новый файл \n2) дозапись в существующий");
	char a = getchar();
	while (getchar() != '\n');

	switch (a)
	{
	case '1':
		out = wdate();
		break;
	case '2':
		out = adate();
		break;
	default:
		puts("Ошибка выбора");
		return 0;
	}

	if (out == NULL) {
		puts("Ошибка: файл не открыт!");
		return 0;
	}

	puts("Введите шаг табуляции: ");
	scanf("%f", &dx);


	for (float i = 0.1; i <= 2.10001; i += dx) {
		res = tab_func(i);
		fprintf(out, "%f", res);
	}

	fclose(out);



	printf("Результат успешно записан в файл!");

	return 1;
}


