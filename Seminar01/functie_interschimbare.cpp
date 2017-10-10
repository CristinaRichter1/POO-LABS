#include <stdio.h>

void interschimb(int a, int b) {
	int aux = 0;
	aux = a;
	a = b;
	b = aux;
}

void interschimb1(int &a, int &b) {
	int aux = 0;
	aux = a;
	a = b;
	b = aux;
}

void interschimb2(int *a, int *b) {
	int aux = 0;
	aux = *a;
	*a = *b;
	*b = aux;
}

void main() {
	int x = 10, y = -5;

	printf("Valorile inainte de interschimbare: x=%d y=%d \n", x, y);
	interschimb(x, y);
	printf("Valorile dupa interschimbare: x=%d y=%d \n", x, y);

	printf("Valorile inainte de interschimbare: x=%d y=%d \n", x, y);
	interschimb1(x, y);
	printf("Valorile dupa interschimbare: x=%d y=%d \n", x, y);

	printf("Valorile inainte de interschimbare: x=%d y=%d \n", x, y);
	interschimb2(&x, &y);
	printf("Valorile dupa interschimbare: x=%d y=%d \n", x, y);
}