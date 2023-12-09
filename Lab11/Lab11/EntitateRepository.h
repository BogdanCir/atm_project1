
#ifndef LAB9_ENTITATEREPOSITORY_H
#define LAB9_ENTITATEREPOSITORY_H


#include <utility>
#include <vector>
#include "Entitate.h"
#include "DublareEntitateException.h"

class EntitateRepository {
private:
    vector<Entitate *> entitati;
public:
    EntitateRepository();

    bool addEntitate(int cod, string nume, int pret);

    vector<Entitate *> getAllEntitati();

};

bool EntitateRepository::addEntitate(int cod, string nume, int pret) {

    bool existaEntitate = false;

    for (auto &entitate: entitati) {
//        cout << entitate->getCod() << " " << entitate->getPret() << " " << entitate->getNume() << "\n";

        if (entitate->getCod() == cod) {
            {
//                cout << "Cod deja existent\n";
                throw DublareEntitateException("Cod deja existent");
            }
        }
    }
    auto *entitate = new Entitate(cod, std::move(nume), pret);
    this->entitati.push_back(entitate);
    return true;
}

vector<Entitate *> EntitateRepository::getAllEntitati() {
    return this->entitati;
}

EntitateRepository::EntitateRepository() {
}


#endif //LAB9_ENTITATEREPOSITORY_H
