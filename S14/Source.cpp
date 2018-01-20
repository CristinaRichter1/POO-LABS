#include <iostream>
#include <vector>

using namespace std;

class PiesaAuto {

public:
	char* denumire;
	int id;

	PiesaAuto();
	PiesaAuto(char* denumire, int id);

	friend ostream& operator<<(ostream& out, const PiesaAuto &pa);
};

PiesaAuto::PiesaAuto() {
	this->denumire = new char[strlen("Necunoscut") + 1];
	strcpy(this->denumire, "Necunoscut");
	this->id = 0;
}
PiesaAuto::PiesaAuto(char* denumire, int id) {
	this->denumire = new char[strlen(denumire) + 1];
	strcpy(this->denumire, denumire);
	this->id = id;
}

ostream& operator <<(ostream &out, PiesaAuto &pa) {
	out << pa.denumire << " " << pa.id << endl;
	return out;
}

class Masina {
public:
	vector<PiesaAuto> pieseAuto;

	Masina() {

	}
	void adaugaPiesa(PiesaAuto pa);
	void afiseazaPiese();
	Masina& operator-=(PiesaAuto &p);
};

void Masina::adaugaPiesa(PiesaAuto pa) {
	this->pieseAuto.push_back(pa);
}

void Masina::afiseazaPiese() {
	vector<PiesaAuto>::iterator myIt;
	for (myIt = this->pieseAuto.begin(); myIt != this->pieseAuto.end(); myIt++) {
		cout << *myIt;
	}
}
Masina& Masina::operator-=(PiesaAuto &p1) {
	for (int i = 0; i < this->pieseAuto.size(); i++) {
		if (this->pieseAuto[i].id == p1.id) {
			this->pieseAuto.erase(this->pieseAuto.begin() + i);
		}
	}
	return *this;
}

class MasinaElectrica {
public:
	PiesaAuto* piese;
	int nrPiese;
	MasinaElectrica() {
		this->piese = NULL;
		this->nrPiese = 0;
	}
	MasinaElectrica(int nrPiese, PiesaAuto* piese) {
		this->nrPiese = nrPiese;
		this->piese = new PiesaAuto[this->nrPiese];
		for (int i = 0; i < this->nrPiese; i++) {
			this->piese[i] = piese[i];
		}
	}

	void afiseazaPiese() {
		for (int i = 0; i < this->nrPiese; i++) {
			cout << this->piese[i];
		}
	}

	MasinaElectrica& operator -=(PiesaAuto &pa) {
		int dimensiuneNoua = this->nrPiese;
		int indexElementCautat = 0;
		bool elementPrezent = false;
		PiesaAuto* vectorTemp = new PiesaAuto[this->nrPiese];
		for (int i = 0; i < this->nrPiese; i++) {
			if (this->piese[i].id == pa.id) {
				dimensiuneNoua = this->nrPiese - 1;
				indexElementCautat = i;
				elementPrezent = true;
			}
			vectorTemp[i] = this->piese[i];
		}
		this->piese = new PiesaAuto[dimensiuneNoua];
		for (int i = 0; i < this->nrPiese; i++) {
			if (elementPrezent) {
				if (i == indexElementCautat)
					continue;
			}
			if (indexElementCautat == 0 && elementPrezent) {
				this->piese[i-1] = vectorTemp[i];
			}
			else {
				this->piese[i] = vectorTemp[i];
			}
		}
		this->nrPiese = dimensiuneNoua;
		return *this;
		
	}
};

void main() {
	PiesaAuto p1("Motor", 1);
	PiesaAuto p2("CutieViteze", 2);
	Masina m1;
	m1.adaugaPiesa(p1);
	m1.adaugaPiesa(p2);
	
	cout << "Inainte de eliminare element " << endl;
	m1.afiseazaPiese();

	m1 -= p2;
	cout << "Dupa eliminare element " << endl;
	m1.afiseazaPiese();


	PiesaAuto p3("Piesa 1", 3);
	PiesaAuto p4("Piesa 2", 4);
	PiesaAuto p5("piesa 3", 5);
	PiesaAuto* pa = new PiesaAuto[2];
	pa[0] = p3;
	pa[1] = p4;

	MasinaElectrica m2(2, pa);

	cout << "Piese inainte de extragere"<<endl;
	m2.afiseazaPiese();

	m2 -= p5;
	cout << "Piese dupa  extragere" << endl;
	m2.afiseazaPiese();
	
}