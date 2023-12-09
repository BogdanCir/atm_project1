

#ifndef LAB9_CODENTITATEEXCEPTION_H
#define LAB9_CODENTITATEEXCEPTION_H

#include <exception>
#include <string>

class CodEntitateException: public std::exception{
private:
    std::string message;
public:
    explicit CodEntitateException(const char *msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif //LAB9_CODENTITATEEXCEPTION_H
