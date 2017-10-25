#include <iostream>
using namespace std;

char* alocareDimNume(int dim) {
	char* tempNume = new char[dim];
	return tempNume;
}
int* alocareDimNote(int dim) {
	int* tempNote = new int[dim];
	return tempNote;
}
int ** alocareDimSituatie(int lin, int col) {
	int ** tempSituatie = new int*[lin];
	for (int i = 0; i < lin; i++) {
		tempSituatie[i] = new int[col];
	}
	return tempSituatie;
}
void inregistrareStudent2(char * nume, int* note, int** situatie, int y, int z, int t) {
	cout << "Introduceti numele studentului: ";
	cin >> nume;
	for (int i = 0; i < y; i++) {
		cout << "Introduceti nota " << i + 1 << " :";
		cin >> note[i];
	}
	for (int i = 0; i < z; i++) {
		for (int j = 0; j < t; j++) {
			cout << "Semestrul " << i + 1 << " nota " << j + 1 << " :";
			cin >> situatie[i][j];
		}
	}

}

void afisareSemestriala2(char * name, int * grades, int y) {
	cout << "Numele studentului este " << name;
	for (int i = 0; i < y; i++) {
		cout << "Nota " << i + 1 << " este: " << grades[i] << endl;
	}
}
void afisareRaportAnual2(char * name, int ** report, int lin, int col) {
	cout << "Numele studentului este " << name << endl;
	for (int i = 0; i < lin; i++) {
		for (int j = 0; j < col; j++) {
			cout << "Nota de pe semestrul " << i + 1 << " la materia " << j + 1 << " este: " << report[i][j] << endl;
		}
	}
}
void dezalocareVector(char *name) {
	if (name != NULL) {
		delete[] name;
	}
}
void dezalocareMatrice(int ** report, int lin) {
	for (int i = 0; i < lin; i++) {
		delete[] report[i];
	}
	delete[] report;
}
void main() {
	int x, y, lin, col;
	cout << "Introduceti dimensiunea numelui studentului: ";
	cin >> x;
	cout << "Introduceti numarul de note: ";
	cin >> y;
	cout << "Introduceti numarul de linii: ";
	cin >> lin;
	cout << "Introduceti numarul de coloane: ";
	cin >> col;
	char * nume = alocareDimNume(x);
	int * note = alocareDimNote(y);
	int ** situatie = alocareDimSituatie(lin, col);
	inregistrareStudent2(nume, note, situatie, y, lin, col);
	afisareSemestriala2(nume, note, y);
	afisareRaportAnual2(nume, situatie, lin, col);

	dezalocareVector(nume);
	dezalocareMatrice(situatie, lin);
}