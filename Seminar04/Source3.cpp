#include <iostream>

using namespace std;

class Masina {
private:
	char* marca;
	char* model;
	int nrProprietari;
	int* aniVanzare;
	int anFabricatie;
public:
	Masina();
	Masina(char* model, char* marca, int nrProprietari, int* aniVanzare, int anFabricatie);
	Masina(Masina &copie);
	~Masina();
	void operator=(Masina &copie);

	void setMarca(char* marca);
	void setModel(char* model);
	void setNrProprietari(int nr);
	void setAniVanzare(int* ani);
	void setAnFabricatie(int anFabricatie);

	char* getMarca();
	char* getModel();
	int getNrProprietari();
	int* getAniVanzare();
	int getAnFabricatie();

	void afisareMasina();
};

Masina::Masina() {
	this->marca = NULL;
	this->model = NULL;
	this->aniVanzare = NULL;
	this->anFabricatie = 0;
}
Masina::Masina(char* mar, char* mod, int nr, int* ani, int anFab) {
	this->marca = new char[strlen(mar) + 1];
	strcpy(this->marca, mar);

	this->model = new char[strlen(mod) + 1];
	strcpy(this->model, mod);

	this->nrProprietari = nr;
	this->aniVanzare = new int[this->nrProprietari];
	for (int i = 0; i < this->nrProprietari; i++) {
		this->aniVanzare[i] = ani[i];
	}
	this->anFabricatie = anFab;
}

Masina::Masina(Masina &copie) {
	if (copie.getMarca() != NULL) {
		this->marca = new char[strlen(copie.getMarca()) + 1];
		strcpy(this->marca, copie.getMarca());
	}
	if (copie.getModel() != NULL) {
		this->model = new char[strlen(copie.getModel()) + 1];
		strcpy(this->model, copie.getModel());
	}
	this->nrProprietari = copie.getNrProprietari();
	this->aniVanzare = new int[this->nrProprietari];
	for (int i = 0; i < this->nrProprietari; i++) {
		this->aniVanzare[i] = copie.getAniVanzare()[i];
	}
	this->anFabricatie = copie.getAnFabricatie();
}
Masina::~Masina() {
	if (this->marca != NULL)
		delete[] this->marca;
	if (this->model != NULL)
		delete[] this->model;
	if (this->aniVanzare != NULL)
		delete[] this->aniVanzare;
	this->nrProprietari = 0;
	this->anFabricatie = 0;

}
void Masina::setMarca(char* marca) {
	this->marca = new char[strlen(marca) + 1];
	strcpy(this->marca, marca);
}
void Masina::setModel(char* model) {
	this->model = new char[strlen(model) + 1];
	strcpy(this->model, model);
}
void Masina::setNrProprietari(int nrProprietari) {
	this->nrProprietari = nrProprietari;
}
void Masina::setAniVanzare(int * aniVanzare) {
	this->aniVanzare = new int[this->nrProprietari];
	for (int i = 0; i < this->nrProprietari; i++) {
		this->aniVanzare[i] = aniVanzare[i];
	}
}
void Masina::setAnFabricatie(int anFabricatie) {
	this->anFabricatie = anFabricatie;
}

char* Masina::getMarca() {
	return this->marca;
}
char* Masina::getModel() {
	return this->model;
}
int Masina::getNrProprietari() {
	return this->nrProprietari;
}
int* Masina::getAniVanzare() {
	return this->aniVanzare;
}
int Masina::getAnFabricatie() {
	return this->anFabricatie;
}
void Masina::afisareMasina() {
	cout << "Masina marca: " << this->marca << endl;
	cout << "Model: " << this->model << endl;
	cout << "Nr proprietari: " << this->nrProprietari << endl;
	for (int i = 0; i < this->nrProprietari; i++) {
		cout << "Anul vanzarii " << i + 1 << " a fost " << this->aniVanzare[i];
	}
	cout << this->anFabricatie;
}

void main() {
	char* marca1 = "Audi";
	char* model = "A5";
	int nrProprietari = 2;
	int* aniVanzare = new int[nrProprietari];
	for (int i = 0; i < nrProprietari; i++) {
		cin >> aniVanzare[i];
	}
	int anFabricatie = 2013;

	Masina m1();
	Masina m2(marca1, model, nrProprietari, aniVanzare, anFabricatie);
	Masina m3(m2);

	m2.afisareMasina();
}