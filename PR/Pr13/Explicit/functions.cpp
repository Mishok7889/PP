#include "functions.h"
#include <cmath>
using namespace std;

template <typename Value, typename T1, typename T2, typename F, typename G>
Value gradient_descent(Value u, T1 s, T2 eps, F f, G g)
{

  auto val = f(u), delta = val;
  do {
    u -= s * g(u);
    auto new_val = f(u);
    delta = abs(new_val - val);
    val = new_val;
  } while (delta > eps);
  return u;
}
template
R2 gradient_descent(R2 u, double s, double eps, double (*f)(R2), R2(*g)(R2));
template
R3 gradient_descent(R3 u, double s, double eps, double (*f)(R3), R3(*g)(R3));


