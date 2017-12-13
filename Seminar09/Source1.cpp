#include <iostream>
#include <fstream>

using namespace std;

class Autovehicul {
private:
	char* tip;
	float capacitateMotor;
	const int serie;

public:
	Autovehicul();
	Autovehicul(int serie, char* tip, float capacitateMotor);

	void setTip(char* tip);
	void setCapacitateMotor(float capacitate);

	char* getTip();
	float getCapacitate();
	int getSerie();

};

Autovehicul::Autovehicul() :serie(0) {
	this->tip = new char[strlen("Necunoscut") + 1];
	strcpy(this->tip, "Necunoscut");
	this->capacitateMotor = 0;
}

Autovehicul::Autovehicul(int s, char* tip, float capacitateMotor) :serie(s) {
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



void main() {

	Autovehicul a1(1, "Masina", 2.2);

	cout << a1.getSerie() << " " << a1.getTip() << " " << a1.getCapacitate() << endl;

	ifstream in;
	ofstream out;
	out.open("autovehicule.txt", ios::out);
	if (out.is_open()) {
		out << a1.getSerie();
		out << endl;
		out << a1.getTip();
		out << endl;
		out << a1.getCapacitate();

	}
	out.close();

	in.open("autovehicule.txt", ios::in);
	if (in.is_open()) {
		int serie;
		char buffer[100];
		float capacitate;
		in >> serie;
		in >> buffer;
		in >> capacitate;

		char* tip = new char[strlen(buffer) + 1];
		strcpy(tip, buffer);

		Autovehicul a2(serie, tip, capacitate);
		cout << a2.getSerie() << " " << a2.getTip() << " " << a2.getCapacitate() << endl;
	}

	in.close();

	out.open("autovehicule2.txt", ios::out);
	if (out.is_open()) {
		out << a1.getSerie() << "," << a1.getTip() << "," << a1.getCapacitate() << endl;
	}
	out.close();

	in.open("autovehicule2.txt", ios::in);
	if (in.is_open()) {
		char buffer[1000];
		in >> buffer;

		char* token = strtok(buffer, ",");
		int serie1 = atoi(token);
		token = strtok(NULL, ",");
		char* tip1 = new char[strlen(token) + 1];
		strcpy(tip1, token);
		token = strtok(NULL, ",");
		float cap1 = atof(token);

		Autovehicul a3(serie1, tip1, cap1);
		cout << a3.getSerie() << " " << a3.getTip() << " " << a3.getCapacitate() << endl;

	}
	in.close();


}