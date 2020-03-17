template<typename TYPE>
using FUNCTION = TYPE (*) (TYPE);

template<typename TYPE>
class fonction {
  TYPE epsilon;
  FUNCTION<TYPE> F;
public:

  fonction(FUNCTION<TYPE> F_) : F(F_), epsilon (1e-4) {}
  fonction() : F(nullptr), epsilon(1e-4) {}

  // virtual TYPE eval(TYPE x) = 0;
  virtual TYPE eval(TYPE x) {
    return F(x);
  }

  void set_epsilon(TYPE epsilon_) {
    epsilon = epsilon_;
  }

  TYPE derivate(TYPE x) {
    return (eval(x+epsilon) - eval(x-epsilon))/(2*epsilon);
  }
};


