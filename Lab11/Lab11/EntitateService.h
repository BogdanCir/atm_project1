
#ifndef LAB9_ENTITATESERVICE_H
#define LAB9_ENTITATESERVICE_H


#include <utility>
#include <map>
#include <algorithm>

#include "EntitateRepository.h"
#include "FileEntitateRepository.h"

class EntitateService {
private:
    FileEntitateRepository *fileEntitateRepository;
//    EntitateRepository *fileEntitateRepository;
public:
    explicit EntitateService(FileEntitateRepository &entitateRepository);

    void addEntitate(int cod, string nume, int pret);

    void afisareEntitati();

    void cumparaProdus(map<int, int> &bancnote, map<int, int> &bancnote_bancomat, int cod_dat_de_user);

    void sortareProdusePret();

    vector<Entitate *> filtrareProdusePret(int pret);

    vector<Entitate *> getAllEntitati();
};

EntitateService::EntitateService(FileEntitateRepository &entitateRepository) {
    this->fileEntitateRepository = &entitateRepository;
}

void EntitateService::addEntitate(int cod, string nume, int pret) {
    this->fileEntitateRepository->addEntitate(cod, std::move(nume), pret);
}

vector<Entitate *> EntitateService::getAllEntitati() {
    return fileEntitateRepository->getAllEntitati();
}

void EntitateService::afisareEntitati() {
    if (this->getAllEntitati().empty()) {
        cout << "\nAll entities\n";
        return;
    }

    for (auto &entitateRepo: this->getAllEntitati()) {
        cout << entitateRepo->getCod() << " " << entitateRepo->getNume() <<
             " " << entitateRepo->getPret() << "\n";
    }
}

void EntitateService::cumparaProdus(map<int, int> &bancnote, map<int, int> &bancnote_bancomat, int cod_dat_de_user) {
    bool existaEntitate = false;

    int pretProdus;
    string numeProdus;

    for (auto &entitate: fileEntitateRepository->getAllEntitati())
        if (entitate->getCod() == cod_dat_de_user) {
            {
                existaEntitate = true;
                numeProdus = entitate->getNume();
                pretProdus = entitate->getPret();

//                cout << numeProdus << " " << pretProdus << "\n";

                break;
            }
        }
    if (!existaEntitate) {
        cout << "We don't have that type of product.\n";
        return;
    }

    bool sumaAcoperita = false;
    int suma = 0;
    for (auto bancnota: bancnote) {
        int ct = 1;
        while (suma + bancnota.first * ct <= pretProdus && ct < bancnota.second) {
            if (suma + bancnota.first * ct == pretProdus) {
                // N avem nevoie de rest
                cout << "We can buy the product\n";

                suma += ct * bancnota.first;
                bancnote[bancnota.first] = bancnota.second - ct;
                sumaAcoperita = true;
                break;
            } else {
                ct ++;
            }
        }
        if (sumaAcoperita)
            break;
        if (ct <= bancnota.second) {
            if (suma + bancnota.first * ct <= pretProdus) {
                if (suma + bancnota.first * ct == pretProdus) {
                    suma += bancnota.first * ct;
                    bancnote[bancnota.first] = bancnota.second - ct;
                    break;
                } else {
                    suma += ct * bancnota.first;
                    bancnote[bancnota.first] = bancnota.second - ct;
                }
            } else {
                cout << "We can buy the product\n";

                suma += ct * bancnota.first;
                bancnote[bancnota.first] = bancnota.second - ct;
                break;
            }
        }
    }
    cout << "Amount spent:\n";
    cout << suma << "\n";

    int rest = 0;
    int rest_de_dat = suma - pretProdus;
    bool restDat = false;

    for (auto bancnota_bancomat: bancnote_bancomat) {
        int ct = 1;
        while (rest + bancnota_bancomat.first * ct <= rest_de_dat && ct < bancnota_bancomat.second) {
            if (rest + bancnota_bancomat.first * ct == rest_de_dat) {
                // N avem nevoie de rest
                cout << "We can buy the product\n";

                rest += ct * bancnota_bancomat.first;
                bancnote_bancomat[bancnota_bancomat.first] = bancnota_bancomat.second - ct;
                restDat = true;
                break;
            } else {
                ct++;
            }
        }
        if (restDat)
            break;
        if (ct <= bancnota_bancomat.second) {
            if (rest + bancnota_bancomat.first * ct <= rest_de_dat) {
                if (rest + bancnota_bancomat.first * ct == rest_de_dat) {
                    rest += bancnota_bancomat.first * ct;
                    bancnote_bancomat[bancnota_bancomat.first] = bancnota_bancomat.second - ct;
                    break;
                } else {
                    rest += ct * bancnota_bancomat.first;
                    bancnote_bancomat[bancnota_bancomat.first] = bancnota_bancomat.second - ct;
                }
            } else {
                cout << "We can buy the product\n";

                rest += (ct * bancnota_bancomat.first);
                bancnote_bancomat[bancnota_bancomat.first] = bancnota_bancomat.second - ct;
                break;
            }
        }
    }
    cout << "Remaining change ";
    cout << rest_de_dat << " banknotes\n";
    cout << "Remaining change that can be given ";
    cout << rest << " banknotes\n";

    for (auto bancnota_bancomat: bancnote_bancomat)
        cout << bancnota_bancomat.first << " " << bancnota_bancomat.second << "\n";
}

void EntitateService::sortareProdusePret() {
    vector<Entitate *> deSortat = fileEntitateRepository->getAllEntitati();

    for (int i = 0; i < deSortat.size() - 1; i++) {
        for (int j = i + 1; j <= deSortat.size() - 1; j++)
            if (deSortat[i]->getPret() >= deSortat[j]->getPret())
                swap(deSortat[i], deSortat[j]);
    }
    for (auto produs: deSortat) {
        cout << produs->getCod() << " " << produs->getNume() << " " << produs->getPret() << "\n";
    }
}

vector<Entitate *> EntitateService::filtrareProdusePret(int pret) {
    vector<Entitate *> deFiltrat;

    for (auto produs: fileEntitateRepository->getAllEntitati()) {
        if (produs->getPret() >= pret)
            deFiltrat.push_back(produs);
    }

    for (auto produs: deFiltrat) {
        cout << produs->getCod() << " " << produs->getNume() << " " << produs->getPret() << "\n";
    }
    return deFiltrat;
}

#endif //LAB9_ENTITATESERVICE_H
