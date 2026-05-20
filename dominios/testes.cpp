#include "Email.hpp"
#include "iostream"

int main(void) {
  Email teste("caioaraujo137@"); // Sem dominio

  std::cout << "O seu email: " << teste.getEmail() << std::endl;

  Email teste1("caioaraujo137@gmailcom"); // Dominio sem ponto

  std::cout << "O seu email: " << teste1.getEmail() << std::endl;

  Email teste2("caioaraujo137@gmail.com"); // Tudo certo

  std::cout << "O seu email: " << teste2.getEmail() << std::endl;

  Email teste3("@"); // Sem parte local, sem parte dominio, tudo errado

  std::cout << "O seu email: " << teste3.getEmail() << std::endl;

  
}