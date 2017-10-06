#include <stdio.h>

void increment(short int a) {
	printf("Incrementarea variabilei se face la adresa %p \n", &a);
	a++;
}
/*
void increment1(short int &a) {
	printf("Incrementarea variabilei se face la adresa %p \n", &a);
	a++;
}

void increment2(short int* a) {
	printf("Incrementarea variabilei se face la adresa %p \n", &a);
	(*a)++;
}
*/
void main() {
	short int x = 9;

	printf("Adresa lui x este %p \n", &x);
	printf("Before increment x=%d \n", x);
	increment(x);
	printf("After increment x=%d \n", x);
	/*
	printf("Before increment x=%d \n", x);
	increment1(x);
	printf("After increment x=%d \n", x);

	printf("Before increment x=%d \n", x);
	increment2(&x);
	printf("After increment x=%d \n", x);
	*/
}