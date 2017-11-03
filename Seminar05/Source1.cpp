#include <iostream>

using namespace std;

class ServiceAuto {

public:
	char* nume;
	char* adresa;
	int locuriDisponibile;
	const bool mediuRural;
	static int nrMasini;

	ServiceAuto();
	ServiceAuto(char* n, char* a, int locuriDisp);
	~ServiceAuto();

	void inregistrareMasina();
	const int operator+(ServiceAuto &sa);
	friend ostream& operator<<(ostream &out, const ServiceAuto& sa);
	friend istream& operator >> (istream &in, ServiceAuto &sa);
};

void main() {

}