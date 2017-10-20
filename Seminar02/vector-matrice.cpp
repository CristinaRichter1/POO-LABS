#include <iostream>

using namespace std;

void inregistrareStudent1(char name[100], int grades[4], int report[2][4]) {

	cout << "Introduceti numele studentului:";
	cin >> name;
	cout << "Introduceti notele studentului" << endl;
	for (int i = 0; i < 4; i++) {
		cout << "Nota la materia " << i + 1 << ": ";
		cin >> grades[i];
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			cout << "Nota de pe semestrul " << i + 1 << " la materia " << j + 1 << ": ";
			cin >> report[i][j];
		}
	}
	
}


void afisareSituatieSemestriala1(char name[100], int grades[4]) {
	cout << "Situatia studentului " << name<<" este: "<<endl;
	for (int i = 0; i < 4; i++) {
		cout << "Nota la materia " << i + 1 << " este: " << grades[i]<<endl;
	}
}

void afisareRaportAnual1(char name[100], int report[2][4]) {
	cout << "Numele studentului este " << name << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			cout << "Nota de pe semestrul " << i + 1 << " la materia " << j + 1<<" este: " << report[i][j] << endl;
		}
	}
}

void main() {
	char nume1[100];
	int note1[4];
	int situatie1[2][4];

	inregistrareStudent1(nume1, note1,situatie1);
	afisareSituatieSemestriala1(nume1, note1);
	afisareRaportAnual1(nume1, situatie1); 
}