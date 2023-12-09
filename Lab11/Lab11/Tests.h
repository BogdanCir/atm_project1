

#ifndef LAB11_TESTS_H
#define LAB11_TESTS_H

#include <iostream>
#include <cassert>

#include "Entitate.h"
#include "EntitateRepository.h"
#include "EntitateService.h"

void Tests() {
    /// SERVICE TESTS
    cout << "SERVICE TEST\n";
    EntitateRepository entitateRepository;
    FileEntitateRepository fileEntitateRepository(entitateRepository,
                                                  "CitireFisier.txt",
                                                  "ScriereFisier.txt");

    fileEntitateRepository.addEntitate(1, "Nume1", 10);
    fileEntitateRepository.addEntitate(2, "Nume2", 20);
    fileEntitateRepository.addEntitate(2, "Nume2", 20);

    assert(fileEntitateRepository.getAllEntitati().size() == 2);
    assert(fileEntitateRepository.getAllEntitati()[0]->getCod() == 1);

    EntitateService entitateService(fileEntitateRepository);
    entitateService.addEntitate(3, "Produs3", 45);
    entitateService.addEntitate(3, "Produs3", 45);

//    assert(entitateService.getAllEntitati().size() == 3);
    cout << "TESTS PASSED SUCCESSFULLY\n";

}

#endif //LAB9_TESTS_H
