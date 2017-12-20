#include <iostream>
#include <fstream>

using namespace std;

class Produs {

private:
	char* denumire;
	float pret;

public:
	Produs();
	Produs(char* denumire, float pret);

	char* getDenumireProdus();
	float getPretProdus();
};

Produs::Produs() {
	this->denumire = new char[strlen("Necunoscut") + 1];
	strcpy(this->denumire, "Necunoscut");
	this->pret = 0;
}
Produs::Produs(char* denumire, float pret) {
	this->denumire = new char[strlen(denumire) + 1];
	strcpy(this->denumire, denumire);
	this->pret = pret;
}
char* Produs::getDenumireProdus() {
	return this->denumire;
}
float Produs::getPretProdus() {
	return this->pret;
}

class Magazin {

private:
	int nrProduse;
	Produs* produse;
public:
	Magazin();
	Magazin(int nrProduse, Produs* produse);

	void afiseazaProduse();
	void genereazaRaport(char* numeFisier);
};

Magazin::Magazin() {
	this->nrProduse = 0;
	this->produse = NULL;
}

Magazin::Magazin(int nrProduse, Produs* produse) {
	this->nrProduse = nrProduse;
	this->produse = new Produs[this->nrProduse];
	for (int i = 0; i<this->nrProduse; i++) {
		this->produse[i] = produse[i];
	}
}
void Magazin::afiseazaProduse() {
	if (this->produse != NULL) {
		for (int i = 0; i<this->nrProduse; i++) {
			cout << "Produsul " << this->produse[i].getDenumireProdus() << " are pretul " << this->produse[i].getPretProdus() << endl;
		}
	}
	else {
		cout << "Nu exista produse!";
	}
}
void Magazin::genereazaRaport(char* numeFisier) {
	ofstream out;
	out.open(numeFisier, ios::out);
	if (out.is_open()) {
		for (int i = 0; i < this->nrProduse; i++) {
			if (this->produse[i].getPretProdus() > 15) {
				out << this->produse[i].getDenumireProdus()<<endl;
			}
		}
	}
	out.close();
}

class MagazinOnline : public Magazin {

private:
	char* website;

public:
	MagazinOnline();
	MagazinOnline(int nrProduse, Produs* produse, char* website);

	char* getWebsite();
};

MagazinOnline::MagazinOnline() :Magazin() {
	this->website = new char[strlen("Necunoscut") + 1];
	strcpy(this->website, "Necunoscut");
}

MagazinOnline::MagazinOnline(int nrProduse, Produs* produse, char* website) : Magazin(nrProduse, produse) {
	this->website = new char[strlen(website) + 1];
	strcpy(this->website, website);
}
char* MagazinOnline::getWebsite() {
	return this->website;
}

class Supermarket : public Magazin {
private:
	char* nume;
public:
	Supermarket();
	Supermarket(int nrProduse, Produs* produse, char* nume);

	char* getNumeSupermarket();
};

Supermarket::Supermarket() :Magazin() {
	this->nume = new char[strlen("Necunoscut") + 1];
	strcpy(this->nume, "Necunoscut");

}
Supermarket::Supermarket(int nrProduse, Produs* produse, char* nume) : Magazin(nrProduse, produse) {
	this->nume = new char[strlen(nume)+1];
	strcpy(this->nume, nume);
}

int main() {
	Produs p1("Pizza", 23.3);
	Produs p2("Cola", 15.5);

	Produs* ptr = new Produs[2];
	ptr[0] = p1;
	ptr[1] = p2;

	Magazin m1(2, ptr);
	m1.afiseazaProduse();

	MagazinOnline m2(2, ptr, "https://cctech.com");

	m2.afiseazaProduse();
	m2.genereazaRaport("raport.txt"); // genereaza raport cu produsele cu pretul mai mare de 15

}