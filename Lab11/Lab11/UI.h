#ifndef LAB11_UI_H
#define LAB11_UI_H

#include "EntitateService.h"
#include "DublareEntitateException.h"

#include <iostream>
#include <map>

using namespace std;

class UI {
private:
    EntitateService *service;

    static void showMenu();

    void addEntitate();

    void afisareEntitati();

    static void afisareBancnote(map<int, int> &bancnote);

    static void afisareMonedeBancomat(map<int, int> &bancnote_bancomat);

    void cumparaProdusUI(map<int, int> &bancnote, map<int, int> &bancnote_bancomat);

    void filtrareProdusePret();

    void sortareProdusePret();

public:
    UI(EntitateService &service);

    void start(map<int, int> &bancnote, map<int, int> &monede_bancomat);
};

UI::UI(EntitateService &service) {
    this->service = &service;
}

void UI::showMenu() {

    cout << "\nChoose option: \n";
    cout << " 1. Add a product\n";
    cout << " 2. Display products\n";
    cout << " 3. Display your banknotes\n";
    cout << " 4. Display atm's banknotes\n";
    cout << " 5. Buy product\n"; /// <---- To do
    cout << " 6. Filter by price\n";
    cout << " 7. Sort by price\n";
    cout << " 0. Exit\n";
}

void UI::addEntitate() {
    try {
        /// Validators <---- To Do

//        int cod, pret;
        string cod, nume, pret;

        cout << "Code:";
        cin >> cod;

        cout << "Name:";
        cin >> nume;

        cout << "Price:";
        cin >> pret;

        int cod_, pret_;

        cod_ = Validator::validateCod(cod);
        pret_ = Validator::validatePret(pret);

        service->addEntitate(cod_, nume, pret_);
    }
    catch (DublareEntitateException &e) {
        std::cerr << "Double entity: " << e.what() << std::endl;
    }
    catch (CodEntitateException &e) {
        std::cerr << "Wrong code or price: " << e.what() << std::endl;
    }
}

void UI::afisareEntitati() {
    service->afisareEntitati();
}

void UI::afisareBancnote(map<int, int> &bancnote) {

    if (bancnote.empty())
        cout << "\n##########     No money :(    ########\n";

    for (auto bancnota: bancnote)
        cout << "Banknote in the amount of" << bancnota.first
             << " ron, having a number of " << bancnota.second << " pieces.\n";
}

void UI::afisareMonedeBancomat(map<int, int> &bancnote_bancomat) {
    if (bancnote_bancomat.empty())
        cout << "\n##########     Atm has no money    ########\n";

    for (auto bancnota_bancomat: bancnote_bancomat)
        cout << "Banknote in the amount of " << bancnota_bancomat.first
             << " bani, having a number of " << bancnota_bancomat.second << " pieces.\n";
}

void UI::cumparaProdusUI(map<int, int> &bancnote, map<int, int> &bancnote_bancomat) {
    cout << "Insert product code:";
    int cod_dat_de_user;
    cin >> cod_dat_de_user;

    service->cumparaProdus(bancnote, bancnote_bancomat, cod_dat_de_user);
}

void UI::filtrareProdusePret() {
    int pretIntrodus;
    cout << "Insert price:";
    cin >> pretIntrodus;

    service->filtrareProdusePret(pretIntrodus);
}

void UI::sortareProdusePret() {
    service->sortareProdusePret();
}

void UI::start(map<int, int> &bancnote, map<int, int> &bancnote_bancomat) {
    while (true) {
        this->showMenu();
        int optiune = 0;
        cin >> optiune;

        switch (optiune) {
            case 1:
                this->addEntitate();
                break;
            case 2:
                this->afisareEntitati();
                break;
            case 3:
                afisareBancnote(bancnote);
                break;
            case 4:
                afisareMonedeBancomat(bancnote_bancomat);
                break;
            case 5:
                cumparaProdusUI(bancnote, bancnote_bancomat);
                break;
            case 6:
                filtrareProdusePret();
                break;
            case 7:
                sortareProdusePret();
                break;
            case 0:
                cout << "Close the program.";
                /// Delete the file content
                ofstream fout("ScriereFisier.txt");
                return;
        }
    }

}


#endif //LAB9_UI_H
