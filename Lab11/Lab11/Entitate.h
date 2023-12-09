
#ifndef LAB9_ENTITATE_H
#define LAB9_ENTITATE_H

#include <string>

using namespace std;

class Entitate {
private:
    int cod;
    string nume;
    int pret;
public:
    Entitate();

    Entitate(int cod, string nume, int pret);

    int getCod();

    string getNume();

    int getPret();
};

Entitate::Entitate() {
    this->cod = 0;
    this->nume = "";
    this->pret = 0;
};

Entitate::Entitate(int cod, string nume, int pret) {
    this->cod = cod;
    this->nume = nume;
    this->pret = pret;
}

int Entitate::getCod() {
    return this->cod;
}

string Entitate::getNume() {
    return this->nume;
}

int Entitate::getPret() {
    return this->pret;
}


#endif //LAB9_ENTITATE_H
