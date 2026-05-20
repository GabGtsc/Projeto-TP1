#pragma once

#include <string>

class Email {
private:
    std::string email_;
public:
    void ValidarEmail(const std::string& email);
    void setEmail(const std::string& email);
    std::string const getEmail() { return email_; }
    Email(const std::string& email) { setEmail(email); }
    bool AlfabetoMinusculoOuDigito(char c) const;
};

