#include <iostream>
#include <fstream>

using namespace std;

class Autovehicul {
private:
	char* tip;
	float capacitateMotor;
	int serie;

public:
	Autovehicul();
	Autovehicul(int serie, char* tip, float capacitateMotor);

	void setTip(char* tip);
	void setCapacitateMotor(float capacitate);

	char* getTip();
	float getCapacitate();
	int getSerie();

	void afisare();
	void citireDateIntrare(char* numeFisier);
	void scrieFisierText(char* numeFisier);
	void scrieFisierCSV(char* numeFisier);
	void citesteDinFisierCSV(char* numeFisier);
	void serializareDate(char* numeFisier);
	void deserializareDate(char* numeFisier);

};

Autovehicul::Autovehicul(){
	this->serie = 0;
	this->tip = new char[strlen("Necunoscut") + 1];
	strcpy(this->tip, "Necunoscut");
	this->capacitateMotor = 0;
}

Autovehicul::Autovehicul(int s, char* tip, float capacitateMotor){
	this->serie = s;
	this->tip = new char[strlen(tip) + 1];
	strcpy(this->tip, tip);
	this->capacitateMotor = capacitateMotor;
}

void Autovehicul::setTip(char* tip) {
	this->tip = new char[strlen(tip) + 1];
	strcpy(this->tip, tip);
}
void Autovehicul::setCapacitateMotor(float capacitate) {
	this->capacitateMotor = capacitate;
}

int Autovehicul::getSerie() {
	return this->serie;
}

char* Autovehicul::getTip() {
	return this->tip;
}
float Autovehicul::getCapacitate() {
	return this->capacitateMotor;
}

void Autovehicul::afisare() {
	cout <<this->serie << " " << this->tip<< " " << this->capacitateMotor << endl;
}

void Autovehicul::citireDateIntrare(char* numeFisier) {
	ifstream in;
	in.open(numeFisier, ios::in); // deschidere fisier in modul de citire
	if (in.is_open()) {
		int serie;
		char buffer[100];
		float capacitate;
		in >> serie;
		this->serie = serie;
		
		in >> buffer;
		this->tip = new char[strlen(buffer) + 1];
		strcpy(this->tip, buffer);

		in >> capacitate;
		this->capacitateMotor = capacitate;
	}
	in.close();
	cout << "Datele au fost citite din " << numeFisier<<endl;
}
void Autovehicul::scrieFisierText(char* numeFisier) {
	ofstream out;
	out.open(numeFisier, ios::out); // deschidere fisier in modul scriere
	if (out.is_open()) {
		out << this->serie;
		out << endl;
		out << this->tip;
		out << endl;
		out << this->capacitateMotor;
		out << endl;
	}
	out.close();
	cout << "Fisierul " << numeFisier << " a fost generat"<<endl;
}
void Autovehicul::scrieFisierCSV(char* numeFisier) {
	ofstream out;
	out.open(numeFisier, ios::out);
	if (out.is_open()) {
		out <<this->serie << "," <<this->tip << "," << this->capacitateMotor<< endl;
	}
	out.close();
	cout << "Fisierul " << numeFisier << " a fost generat" << endl;
}

void Autovehicul::citesteDinFisierCSV(char* numeFisier) {
	ifstream in;
	in.open(numeFisier, ios::in);
	if (in.is_open()) {
		char buffer[1000];
		in >> buffer;

		char* token = strtok(buffer, ",");
		this->serie = atoi(token);
		token = strtok(NULL, ",");
		this->tip = new char[strlen(token) + 1];
		strcpy(this->tip, token);
		token = strtok(NULL, ",");
		this->capacitateMotor = atof(token);
	}
	in.close();
	cout << "Datele au fost citite din " << numeFisier << endl;
}

void Autovehicul::serializareDate(char* numeFisier) {
	ofstream out;
	out.open(numeFisier, ios::out | ios::binary); // deschidere fisier -> scriere in mod binar
		if (out.is_open()) {
			out.write((char*)&this->serie, sizeof(int));
			int nrCaractere = strlen(this->tip) + 1;
			out.write((char*)&nrCaractere, sizeof(int));
			out.write(this->tip, sizeof(char) * nrCaractere);
			out.write((char*)&this->capacitateMotor, sizeof(float));
		}
		out.close();
		cout << "Fisierul " << numeFisier << " a fost generat" << endl;
}

void Autovehicul::deserializareDate(char* numeFisier) {
	ifstream in;
	in.open(numeFisier, ios::in | ios::binary); // deschidere fisier -> citire in mod binar
	if (in.is_open()) {
		int nrCaractere;
		in.read((char*)&this->serie, sizeof(int));
		in.read((char*)&nrCaractere, sizeof(int));

		this->tip = new char[nrCaractere];
		in.read(this->tip, sizeof(char)*nrCaractere);

		in.read((char*)&this->capacitateMotor, sizeof(float));
	}
	in.close();
}
void main() {

	Autovehicul a1(1, "Masina", 2.2);

	
	
	Autovehicul a2;
	Autovehicul a3;
	Autovehicul a4;
	a2.citireDateIntrare("dateIntrare.txt");
	cout << a2.getSerie() << " " << a2.getTip() << " " << a2.getCapacitate() << endl;

	a2.scrieFisierText("autovehicule.txt");

	a2.scrieFisierCSV("autovehicule.csv");
	a3.citesteDinFisierCSV("autovehicule.csv");
	a3.afisare();
	a3.serializareDate("autovehicule.dat");
	a4.deserializareDate("autovehicule.dat");
	a4.afisare();


}