#include <iostream>

using namespace std;

class Masina {
private:
	char* marca;
	char* model;
	const bool automata;
	int nrRevizii;
	int* aniRevizii;

public:
	static int nrMasini;

	Masina();
	Masina(char* mar, char* mod, int nr, int* ani);
	Masina(Masina &m);
	~Masina();

	int operator[](int index);
	operator int();
	//void operator+=(Masina &m);

	//int operator++(int x);
	//int& operator++();

	void setMarca(char* marca);
	void setModel(char* model);
	void setNrRevizii(int nrRevizii);
	void setAniRevizii(int* aniRevizii, int nr);

	char* getMarca();
	char* getModel();
	const bool getAutomata();
	int getNrRevizii();
	int* getAniRevizii();

	friend ostream& operator<<(ostream &out, const Masina &m);
	friend istream& operator >> (istream &in, Masina &m);

};


Masina::Masina() :automata(false) {
	this->marca = NULL;
	this->model = NULL;
	this->nrRevizii = 0;
	this->aniRevizii = NULL;

	nrMasini++;
}

Masina::Masina(char* mar, char* mod, int nr, int* ani) :automata(true) {
	this->marca = new char[strlen(mar) + 1];
	strcpy(this->marca, mar);
	this->model = new char[strlen(mod) + 1];
	strcpy(this->model, mod);

	this->nrRevizii = nr;
	this->aniRevizii = new int[this->nrRevizii];
	for (int i = 0; i < this->nrRevizii; i++) {
		this->aniRevizii[i] = ani[i];
	}

	nrMasini++;
}

Masina::Masina(Masina &copie) :automata(true) {
	if (copie.marca != NULL) {
		this->marca = new char[strlen(copie.marca) + 1];
		strcpy(this->marca, copie.marca);
	}
	if (copie.model != NULL) {
		this->model = new char[strlen(copie.model) + 1];
		strcpy(this->model, copie.model);
	}
	if (copie.aniRevizii != NULL) {
		this->nrRevizii = copie.nrRevizii;
		this->aniRevizii = new int[this->nrRevizii];
		for (int i = 0; i < this->nrRevizii; i++) {
			this->aniRevizii[i] = copie.aniRevizii[i];
		}
	}

	nrMasini++;
}

Masina::~Masina() {
	if (this->marca != NULL) {
		delete[] this->marca;
	}
	if (this->model != NULL) {
		delete[] this->model;
	}
	if (this->aniRevizii != NULL) {
		delete[] this->aniRevizii;
	}

	nrMasini--;
}

int Masina::operator[](int index) {
	return this->aniRevizii[index];
}

ostream& operator<<(ostream &out, const Masina &m) {
	out << "Masina " << m.marca << " " << m.model << " a efectuat " << m.nrRevizii << " revizii in anii:" << endl;
	for (int i = 0; i < m.nrRevizii; i++) {
		out << m.aniRevizii[i] << endl;
	}
	out << "Numarul de masini din service: " << m.nrMasini << endl;
	return out;
}

istream& operator >> (istream &in, Masina &m) {
	char bufferMarca[100], bufferModel[100];
	cout << "Introduceti marca masinii: ";
	in >> bufferMarca;
	m.marca = new char[strlen(bufferMarca) + 1];
	strcpy(m.marca, bufferMarca);

	cout << "Introduceti modelul masinii: ";
	in >> bufferModel;
	m.model = new char[strlen(bufferModel) + 1];
	strcpy(m.model, bufferModel);

	cout << "Introduceti numarul de revizii: ";
	in >> m.nrRevizii;
	m.aniRevizii = new int[m.nrRevizii];
	for (int i = 0; i < m.nrRevizii; i++) {
		cout << "Revizia " << i + 1 << " a avut loc in: ";
		in >> m.aniRevizii[i];
	}

	return in;
}

void Masina::setMarca(char* marca) {
	this->marca = new char[strlen(marca) + 1];
	strcpy(this->marca, marca);
}
void Masina::setModel(char* model) {
	this->model = new char[strlen(model) + 1];
	strcpy(this->model, model);
}
void Masina::setNrRevizii(int nr) {
	this->nrRevizii = nr;
}
void Masina::setAniRevizii(int* ani, int nr) {
	this->aniRevizii = new int[nr];
	for (int i = 0; i < nr; i++) {
		this->aniRevizii[i] = ani[i];
	}
}
char* Masina::getMarca() {
	return this->marca;
}
char* Masina::getModel() {
	return this->model;
}
int Masina::getNrRevizii() {
	return this->nrRevizii;
}
const bool Masina::getAutomata() {
	return this->automata;
}
int* Masina::getAniRevizii() {
	return this->aniRevizii;
}

Masina::operator int() {
	return this->nrRevizii;
}


int Masina::nrMasini = 0;

void main() {
	int * ani = new int[3]{ 2005,2007,2008 };
	Masina m1;
	Masina m2("Audi", "A5", 3, ani);
	Masina m3(m2);

	cout << m2 << endl;
	cout << m3 << endl;


	cout << int(m3) << endl;
	cout << m2[2] << endl;



}