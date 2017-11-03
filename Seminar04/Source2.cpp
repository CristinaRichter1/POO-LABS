#include <iostream>

using namespace std;

class Hotel {
private:
	char* nume;
	char* adresa;
	int nrCamere;

public:
	Hotel();
	Hotel(char* n, char* a, int nr);
	Hotel(Hotel &copie);
	~Hotel();
	void operator=(Hotel &copie);

	void setNume(char* n);
	void setAdresa(char* a);
	void setNrCamere(int nr);

	char* getNume();
	char* getAdresa();
	int getNrCamere();

	void afisareHotel();
};

Hotel::Hotel() {

	this->nume = NULL;
	this->adresa = NULL;
	this->nrCamere = 0;
}

Hotel::Hotel(char* n, char* a, int nr) {

	this->nume = new char[strlen(n) + 1];
	strcpy(this->nume, n);

	this->adresa = new char[strlen(a) + 1];
	strcpy(this->adresa, a);

	this->nrCamere = nr;
}

Hotel::Hotel(Hotel &copie) {
	if (copie.getNume() != NULL) {
		this->nume = new char[strlen(copie.getNume()) + 1];
		strcpy(this->nume, copie.getNume());
	}
	if (copie.getAdresa() != NULL) {
		this->adresa = new char[strlen(copie.getAdresa()) + 1];
		strcpy(this->adresa, copie.getAdresa());
	}
	this->nrCamere = copie.getNrCamere();
}

Hotel::~Hotel() {
	if (this->nume != NULL)
		delete[] this->nume;
	if (this->adresa != NULL)
		delete[] this->adresa;
}

void Hotel::operator=(Hotel &copie) {
	if (copie.getNume() != NULL) {
		this->nume = new char[strlen(copie.getNume()) + 1];
		strcpy(this->nume, copie.getNume());
	}
	if (copie.getAdresa() != NULL) {
		this->adresa = new char[strlen(copie.getAdresa()) + 1];
		strcpy(this->adresa, copie.getAdresa());
	}
	this->nrCamere = copie.getNrCamere();
}

void Hotel::setNume(char* n) {
	this->nume = new char[strlen(n) + 1];
	strcpy(this->nume, n);
}
void Hotel::setAdresa(char* a) {
	this->adresa = new char[strlen(a) + 1];
	strcpy(this->adresa, a);
}
void Hotel::setNrCamere(int nr) {
	this->nrCamere = nr;
}
char* Hotel::getNume() {
	return this->nume;
}
char* Hotel::getAdresa() {
	return this->adresa;
}
int Hotel::getNrCamere() {
	return this->nrCamere;
}

void Hotel::afisareHotel() {
	cout << "Hotelul " << this->nume << endl;
	cout << "Este situat in " << this->adresa << endl;
	cout << "Are " << this->nrCamere << " camere" << endl;
}

void main() {
	char* nume1 = "Radisson";
	char* nume2 = "Hilton";
	char* adresa1 = "Bucuresti";
	char* adresa2 = "Cluj";
	int nr1 = 30, nr2 = 40;

	Hotel h1();
	Hotel h2(nume1, adresa1, nr1);
	Hotel h3(nume2, adresa2, nr2);

	h2.afisareHotel();
	h3.afisareHotel();
}