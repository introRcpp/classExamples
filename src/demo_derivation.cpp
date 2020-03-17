#include <Rcpp.h>
#include <cmath>
#include "fonction.h"
using namespace Rcpp;

class dum : public fonction<double> {
public:
  double eval(double x) {
    // return x*x*sin(1/x); // (torture test)
    return sin(x);
  }
};

//[[Rcpp::export]]
List demo_derivation_1(NumericVector x) {
  dum f;
  int n = x.size();
  NumericVector fx = no_init(n);
  NumericVector dfx = no_init(n);
  for(int i = 0; i < n; i++) {
    double a = x[i];
    fx[i] = f.eval(a);
    dfx[i]= f.derivate(a);
  }

  List L;
  L["f(x)"] = fx;
  L["df(x)"] = dfx;
  return L;
}

double sisi(double x) {
  return sin(x);
}

//[[Rcpp::export]]
List demo_derivation_2(NumericVector x) {
  // dum f;
  fonction<double> f(sisi);
  int n = x.size();
  NumericVector fx = no_init(n);
  NumericVector dfx = no_init(n);
  for(int i = 0; i < n; i++) {
    double a = x[i];
    fx[i] = f.eval(a);
    dfx[i]= f.derivate(a);
  }

  List L;
  L["f(x)"] = fx;
  L["df(x)"] = dfx;
  return L;
}
