#include <Rcpp.h>
#include "chatty.h"
using namespace Rcpp;

//[[Rcpp::export]]
void demo_chatty1() {
  Rcout << "--- Constructeurs :\n";
  chatty a;
  chatty b(1);
  chatty c(2, "hop");
  chatty d(3, "bof");

  Rcout << "\n--- Constructeur par copie :\n";
  Rcout << "chatty u(c);\n";
  chatty u(c);
  Rcout << "c : " << c.me() << "\n";
  Rcout << "u : " << u.me() << "\n";

  Rcout << "chatty v = d;\n";
  chatty v = d;
  Rcout << "d : " << d.me() << "\n";
  Rcout << "v : " << v.me() << "\n";

  Rcout << "\n--- Assignation :\n";
  chatty x(4, "hu");
  x = c;
  Rcout << "c : " << c.me() << "\n";
  Rcout << "x : " << x.me() << "\n";

  Rcout << "\n--- Move :\n";
  chatty y(std::move(c));
  Rcout << "c : " << c.me() << "\n";
  Rcout << "y : " << y.me() << "\n";

  Rcout << "\n--- Fin de la fonction, appel des destructeurs\n";
}

// [[Rcpp::export]]
void demo_chatty2(int n) {
  Rcout << "Création de " << n << " objets de classe chatty dans une boucle\n";
  for(int i = 0; i < n; i++)
    chatty x(i, "blop");
}

// [[Rcpp::export]]
void demo_chatty3(int n) {
  chatty x(101, "blup");
  Rcout << "\nCréation de " << n << " objets de classe chatty dans une boucle, avec assignation\n";
  for(int i = 0; i < n; i++)
    x = chatty(i, "blop");
}


// [[Rcpp::export]]
void demo_chatty4(int n, bool reserve = true) {
  Rcout << "Remplir un vecteur de taille " << n << " avec push_back\n";
  std::vector<chatty> V;
  if(reserve)
    V.reserve(n);

  for(int i = 0; i < n; i++) {
    Rcout << "\n";
    chatty x(i, "arf");
    V.push_back(x);
  }
  Rcout << "\nFin de la fonction\n";
}

// [[Rcpp::export]]
void demo_chatty5(int n, bool reserve = true) {
  Rcout << "Remplir un vecteur de taille " << n << " avec push_back (move implicite)\n";
  std::vector<chatty> V;
  if(reserve)
    V.reserve(n);

  for(int i = 0; i < n; i++) {
    Rcout << "\n";
    V.push_back(chatty(i, "arf"));
  }
  Rcout << "\nFin de la fonction\n";
}

// [[Rcpp::export]]
void demo_chatty6(int n, bool reserve = true) {
  Rcout << "Remplir un vecteur de taille " << n << " avec emplace_back\n";
  std::vector<chatty> V;
  if(reserve)
    V.reserve(n);

  for(int i = 0; i < n; i++) {
    V.emplace_back(i, "arf");
  }
  Rcout << "\nFin de la fonction\n";
}

//[[Rcpp::export]]
void demo_chatty7(int n) {
  std::vector<chatty> V;
  V.reserve(n);
  for(int i = 0; i < n; i++) {
    V.emplace_back(i, "arf");
  }

  Rcout << "\n\nParcourir le vecteur avec auto x \n";
  for(auto x : V) {
    std::string s = x.me();
  }

  Rcout << "\n\nParcourir le vecteur avec auto & x \n";
  for(auto & x : V) {
    std::string s = x.me();
  }

  Rcout << "\nFin de la fonction\n";

}
