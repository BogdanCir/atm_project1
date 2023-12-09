

#ifndef LAB9_VALIDATOR_H
#define LAB9_VALIDATOR_H

#include <string>
#include <stdexcept>
#include <iostream>
#include "CodEntitateException.h"

class Validator {
public:
    static int validateCod(const std::string &cod) {
        if (!isdigit(cod[0]))
            throw CodEntitateException("The code needs to be a positive number.");
        else
            return stoi(cod);
    }
    static int validatePret(const std::string &cod) {
        if (!isdigit(cod[0]))
            throw CodEntitateException("The price needs to be a positive number.");
        else
            return stoi(cod);
    }
};

#endif //LAB9_VALIDATOR_H
