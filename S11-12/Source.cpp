#include <iostream>
#include <fstream>
using namespace std;


class PiesaAuto {
private:
	char* denumire;
	float pret;
public:
	PiesaAuto();
	PiesaAuto(char* denumire, float pret);
	char* getDenumirePiesa();
	float getPretPiesa();
};

PiesaAuto::PiesaAuto() {
	this->denumire = new char[strlen("Necunoscut") + 1];
	strcpy(this->denumire, "Necunoscut");
	this->pret = 0;
}
PiesaAuto::PiesaAuto(char* denumire, float pret) {
	this->denumire = new char[strlen(denumire) + 1];
	strcpy(this->denumire, denumire);
	this->pret = pret;
}
char* PiesaAuto::getDenumirePiesa() {
	return this->denumire;
}
float PiesaAuto::getPretPiesa() {
	return this->pret;
}


class Autovehicul {
protected:
	int nrPieseAuto;
	PiesaAuto* pieseAuto;
public:
	Autovehicul();
	Autovehicul(int nrPiese, PiesaAuto* piese);

	void generareRaport();
	
	virtual void afiseazaPiese();
	
};

Autovehicul::Autovehicul() {
	this->nrPieseAuto = 0;
	this->pieseAuto = NULL;
}
Autovehicul::Autovehicul(int nrPiese, PiesaAuto* piese) {
	this->nrPieseAuto = nrPiese;
	this->pieseAuto = new PiesaAuto[this->nrPieseAuto];
	for (int i = 0; i < this->nrPieseAuto; i++) {
		this->pieseAuto[i] = piese[i];
	}
}
void Autovehicul::afiseazaPiese() {
	cout << "Am fost apelata din clasa Autovehicul";
	if (this->pieseAuto != NULL) {
		for (int i = 0; i < this->nrPieseAuto; i++) {
			cout << this->pieseAuto[i].getDenumirePiesa() << " " << this->pieseAuto[i].getPretPiesa() << endl;
		}
	}
}

void Autovehicul::generareRaport() {
	ofstream out;
	out.open("raport.txt", ios::out);
	if (out.is_open()) {
		for (int i = 0; i < this->nrPieseAuto; i++) {
			if (this->pieseAuto[i].getPretPiesa() < 290) {
				out << this->pieseAuto[i].getDenumirePiesa() << endl;
			}
		}
	}
	out.close();
}

class Masina :public Autovehicul {
private:
	char* marca;
public:
	Masina();
	Masina(char* marca, int nrPiese, PiesaAuto* piese);

	char* getMarca();
	void afiseazaPiese();
};

Masina::Masina() :Autovehicul() {
	this->marca = new char[strlen("Necunoscut") + 1];
	strcpy(this->marca, "Necunoscut");
}
Masina::Masina(char* marca, int nrPiese, PiesaAuto* piese) : Autovehicul(nrPiese, piese) {
	this->marca = new char[strlen(marca) + 1];
	strcpy(this->marca, marca);
}
char* Masina::getMarca() {
	return this->marca;
}
void Masina::afiseazaPiese() {
	cout << "Functie din clasa masina" << endl;
	cout << "Masina marca " << this->marca << " are urmatoarele piese" << endl;
	this->Autovehicul::afiseazaPiese();
}

void main() {
	PiesaAuto p1("Motor", 325.5);
	PiesaAuto p2("Portiera", 330);
	cout << p1.getDenumirePiesa() << " " << p1.getPretPiesa() << endl;
	cout << p2.getDenumirePiesa() << " " << p2.getPretPiesa() << endl;

	PiesaAuto* pa1 = new PiesaAuto[2];
	pa1[0] = p1;
	pa1[1] = p2;

	Masina m1("BMW", 2, pa1);
	m1.afiseazaPiese();

	PiesaAuto p3("CutieViteze", 280);
	PiesaAuto p4("Radiator", 270);
	PiesaAuto* pa2 = new PiesaAuto[2];
	pa2[0] = p3;
	pa2[1] = p4;
	Masina m2("KIA", 2, pa2);
	m2.generareRaport();


	
}