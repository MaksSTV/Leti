
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>

void print_short(unsigned short int x) {
	int i, bit;
	int pairs, right_pair, start, end, tmp;
	int Reverse_short[16];
	bit = 0;
	for (i = 8 * sizeof(x) - 1; i > -1; i--) {
		Reverse_short[bit] = x >> i & 1;
		printf("%d", x >> i & 1);
		bit++;
	}
	printf("\n");

	printf("%s\n", "Enter the number of pairs and the number of the lowest digit of the right pair: ");
	scanf("%d", &pairs);
	scanf("%d", &right_pair);
	if ((pairs <= 0) && (right_pair > 15)) {
		printf("%s\n", "Invalid values!!");
		printf("%s\n", "Enter the number of pairs and the number of the lowest digit of the right pair: ");
		scanf("%d", &pairs);
		scanf("%d", &right_pair);
	}
	start = 16 - right_pair;
	end = start - pairs * 2;
	if (end < 0) {
		printf("%s\n", "Too many pairs!! Enter other values.");
		printf("%s\n", "Enter the number of pairs and the number of the lowest digit of the right pair: ");
		scanf("%d", &pairs);
		scanf("%d", &right_pair);
	}
	i = start;
	while (i != end) {
		tmp = Reverse_short[i];
		Reverse_short[i] = Reverse_short[i - 1];
		Reverse_short[i - 1] = tmp;
		i = i - 2;
	}
	for (i = 0; i < 16; i++)
		printf("%u", Reverse_short[i]);
	printf("\n");
}
void sign(int* x) {
	int i;
	printf("%s", "Sign: ");
	printf("%d", x[0]);
	printf("\n");
}
void exponenta(int* x) {
	int i;
	printf("%s", "Exponenta: ");
	for (i = 1; i < 12; i++) {
		printf("%d", x[i]);
	}
	printf("\n");
}
void mantisa(int* x) {
	int i;
	printf("%s", "Mantisa: ");
	for (i = 12; i < 64; i++) {
		printf("%d", x[i]);
	}
	printf("\n");
}
void print_double(double x) {
	int i, j, bit;
	int pairs, right_pair, start, end, temp;
	int Reverse_double[64];
	unsigned char* gg = (unsigned char*)&x;
	unsigned char tmp;
	bit = 64;
	for (i = 0; i < 8; i++) {
		tmp = *gg;
		for (j = 0; j < 8; j++) {
			Reverse_double[bit - 1] = tmp & 1;
			bit--;
			tmp >>= 1;
		}
		gg++;
	}
	printf("\n");
	for (i = 0; i < 64; i++)
		printf("%u", Reverse_double[i]);
	printf("\n");
	sign(Reverse_double);
	exponenta(Reverse_double);
	mantisa(Reverse_double);

	printf("%s\n", "Enter the number of pairs and the number of the lowest digit of the right pair: ");
	scanf("%d", &pairs);
	scanf("%d", &right_pair);
	if ((pairs <= 0) && (right_pair > 63)) {
		printf("%s\n", "Invalid values!!");
		printf("%s\n", "Enter the number of pairs and the number of the lowest digit of the right pair: ");
		scanf("%d", &pairs);
		scanf("%d", &right_pair);
	}
	start = 64 - right_pair;
	end = start - pairs * 2;
	if (end < 0) {
		printf("%s\n", "Too many pairs!! Enter other values.");
		printf("%s\n", "Enter the number of pairs and the number of the lowest digit of the right pair: ");
		scanf("%d", &pairs);
		scanf("%d", &right_pair);
	}
	i = start;
	while (i != end) {
		temp = Reverse_double[i];
		Reverse_double[i] = Reverse_double[i - 1];
		Reverse_double[i - 1] = temp;
		i = i - 2;
	}
	for (i = 0; i < 64; i++)
		printf("%u", Reverse_double[i]);
	printf("\n");
}

void menu(){
	unsigned short int short_number;
	double double_number;
	int variant = -1;
	printf("%d\n%d\n",sizeof(unsigned short int),sizeof(unsigned int));
	while (variant != 0) {
		printf("%s\n", "What type of data do you want to use? 1 - unsigned short, 2 - double, 0 - exit.");
		scanf("%d", &variant);
		if (variant == 1) {
			printf("%s\n", "Enter number: ");
			scanf("%hu", &short_number);
			printf("%s%hu\n", "Number: ", short_number);
			print_short(short_number);
		}
		else if (variant == 2) {
			printf("%s\n", "Enter number: ");
			scanf("%lf", &double_number);
			printf("%s%d\n", "Number: ", sizeof(double_number));
			print_double(double_number);
		}
		else if ((variant != 1) && (variant != 2) && (variant != 0)) {
			printf("%s\n", "Debil!!! This case not found. ");
		}
	}
}
int main() {
	menu();
	system("pause");
	return 0;
}