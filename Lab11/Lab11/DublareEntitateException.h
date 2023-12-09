
#ifndef LAB9_DUBLAREENTITATEEXCEPTION_H
#define LAB9_DUBLAREENTITATEEXCEPTION_H

#include <string>

using namespace std;

class DublareEntitateException: public std::exception{
private:
    string message;
public:
    explicit DublareEntitateException(const char *msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif //LAB9_DUBLAREENTITATEEXCEPTION_H
