
#ifndef LAB9_FILEENTITATEREPOSITORY_H
#define LAB9_FILEENTITATEREPOSITORY_H

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Entitate.h"
#include "EntitateRepository.h"
#include "DublareEntitateException.h"
#include "Validator.h"

class FileEntitateRepository : public EntitateRepository {
private:
//    vector<Entitate *> entitati;
    string citireFisier;
    string scriereFisier;
public:
    FileEntitateRepository(EntitateRepository &entitateRepository, string citireFisier, string scriereFisier);

    void addEntitate(int cod, string nume, int pret);

    vector<Entitate *> getAllEntitati();

    void citireFisierMethod(string citireFisier);

    void scriereFisierMethod(vector<Entitate *> entitati, string scriereFisier);
};

FileEntitateRepository::FileEntitateRepository(EntitateRepository &entitateRepository, string citireFisier,
                                               string scriereFisier) {
    this->citireFisier = citireFisier;
    this->scriereFisier = scriereFisier;
}

void FileEntitateRepository::addEntitate(int cod, string nume, int pret) {
    try {
        EntitateRepository::addEntitate(cod, nume, pret);
        ofstream fout(scriereFisier, ios::app);
        fout << cod << " " << nume << " " << pret << "\n";
    }
    catch (DublareEntitateException &e) {
        cout << "Exception, double entity " << e.what() << "\n";
    }
}

vector<Entitate *> FileEntitateRepository::getAllEntitati() {
    return EntitateRepository::getAllEntitati();
//    return this->entitati;
}

void FileEntitateRepository::citireFisierMethod(string citireFisier) {

    cout << "read\n";
    int cod, pret;
    string nume;

    string attr1, attr2, attr3;

    ifstream fin(citireFisier);

    /// Ar trebui citim fiecare linie ca un string,
    /// apoi luat fiecare atribut cu un separator, si verificat daca e de tipul dorit.

    while (fin >> attr1 >> attr2 >> attr3) {
        try {
            cod = Validator::validateCod(attr1);
            nume = attr2;
            pret = Validator::validateCod(attr3);
            addEntitate(cod, nume, pret);
        }
        catch (CodEntitateException &e) {
            cout << "Code inserted incorrectly " << e.what() << "\n";
        }
        cout << "READ FROM FILE\n";
    }
    fin.close();

}


#endif //LAB9_FILEENTITATEREPOSITORY_H
