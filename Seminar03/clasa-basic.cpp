#include <iostream>

using namespace std;

class Student {
private:
	int varsta;
	char *nume;

public: 
	Student();
	Student(int v, char* n);
	Student(Student &ref);
	~Student();
	void operator=(Student &ref);

	int getVarsta();
	void setVarsta(int v);
	char* getNume();
	void setNume(char* n);
	void afiseazaStudent();
};

Student::Student() {
	this->varsta = 0;
	this->nume = NULL;
}

Student::Student(int v, char* n) {
	this->varsta = v;
	if (n != NULL) {
		this->nume = new char[strlen(n) + 1];
		strcpy(this->nume, n);
	}
	else {
		this->nume = 0;
	}
}

Student::Student(Student &copie) {
	this->varsta = copie.varsta;
	if (copie.nume != NULL) {
		this->nume = new char[strlen(copie.nume) + 1];
		strcpy(this->nume, copie.nume);
	}
	else {
		this->nume = 0;
	}
}

Student::~Student() {
	this->varsta = 0;
	if (this->nume != NULL)
		delete[] this->nume;
	this->nume = 0;
}
void Student::operator=(Student &copie) {
	this->varsta = copie.getVarsta();
	if (this->nume != NULL) {
		delete[] this->nume;
	}
	if (copie.getNume() != NULL) {
		this->nume = new char[strlen(copie.getNume()) + 1];
		strcpy(this->nume, copie.getNume());
	}
	else {
		this->nume = 0;
	}
}

int Student::getVarsta() {
	return this->varsta;
}
void Student::setVarsta(int v) {
	this->varsta = v;
}
char* Student::getNume() {
	return this->nume;
}
void Student::setNume(char* n) {
	this->nume = new char[strlen(n) + 1];
	strcpy(this->nume, n);
}

void Student::afiseazaStudent() {	
	cout << this->nume << endl;
	cout << this->varsta << endl;
}

void main() {
	int v1 = 20; char* n1 = "Gigel";
	int v2 = 21; char* n2 = "Ana";
	Student s1;
	Student s2(v1, n1);
	Student s3(v2, n2);
	Student s4(s2); // apel explicit constructor copiere
	Student s5;
	
	s1 = s3; // suprascriere operator =  (constructor de copiere)
	
	
	s5.setVarsta(15);
	s5.setNume("Ionela");

	s1.afiseazaStudent();
	s2.afiseazaStudent();
	s3.afiseazaStudent();
	s4.afiseazaStudent();
	s5.afiseazaStudent();
}