#include <Rcpp.h>
#include <iostream>

class chatty {
private:
  int x;
  std::string s;

public:
  std::string me() {
    return "(" + s + "," + std::to_string(x) + ")";
  }

  // trois constructeurs
  chatty(int x_, std::string s_) : x(x_), s(s_) {
    Rcpp::Rcout << "Construit " << me() << "\n";
  }
  chatty(int x_) : x(x_), s(".") {
    Rcpp::Rcout << "Construit " << me() << "\n";
  }
  chatty() : x(0), s(".") {
    Rcpp::Rcout << "Construit " << me() << "\n";
  }

  // constructeur par copie
  chatty(const chatty & A) : x(A.x), s("copie de " + A.s) {
    Rcpp::Rcout << "Construit par copie " << me() << "\n";
  }

  // copy assignement
  chatty & operator=(const chatty & A) {
    Rcpp::Rcout << me() << " : ";
    x = A.x;
    s = A.s + "*";
    Rcpp::Rcout << "assigné à " << me() << "\n";
    return *this;
  }

  // destructeur
  ~chatty() {
    Rcpp::Rcout << "Détruit" << me() << "\n";
  }

  // Opérateur move. Le type 'chatty &&' peut être traité comme une référence.
  // L'opérateur move a le droit de modifier son argument.
  chatty(chatty && A) : x(A.x), s( std::move(A.s) ) {
    Rcpp::Rcout << "Déplace " << me() << "\n";
    A.x = 0;
  }
};
