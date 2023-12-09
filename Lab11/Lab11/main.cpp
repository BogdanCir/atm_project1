#include "Tests.h"
#include "EntitateService.h"
#include "UI.h"

int main() {
    string citireFisier = "CitireFisier.txt";
    string scriereFisier = "ScriereFisier.txt";

//    Tests();

    EntitateRepository entitateRepository;
    FileEntitateRepository fileEntitateRepository(entitateRepository, citireFisier, scriereFisier);

    EntitateService entitateService(fileEntitateRepository);
    UI ui(entitateService);

    map<int, int> bancnote;
    bancnote[1] = 10;
    bancnote[5] = 10;
    bancnote[10] = 10;

    map<int, int> bancnote_bancomat;
    bancnote_bancomat[1] = 100; /// Monede de 10 bani
    bancnote_bancomat[5] = 100; /// Monede de 50 bani

    cout << "Read from file\n";
    fileEntitateRepository.citireFisierMethod(citireFisier);

    ui.start(bancnote, bancnote_bancomat);

    return 0;
}
