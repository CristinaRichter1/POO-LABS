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

	//int operator[](int index);
	//void *operator new(size_t size);
	//void operator delete(void *m);
	//operator int();

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


int Masina::nrMasini = 0;

void main() {
	int * ani = new int[3]{ 2005,2007,2008 };
	Masina m1;
	Masina m2("Audi", "A5", 3, ani);
	Masina m3(m2);

	cout << m2;
	cout << m3;

	cin >> m1;
	cout << m1;
	


}