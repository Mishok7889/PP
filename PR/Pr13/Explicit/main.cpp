#include "functions.h"
#include <iostream>
using namespace std;

int main() {

  double x = -6, y = 1;
  double h = 0.05;
  double eps = 0.001;
  {
      R2 u{ -6, 1 };

      double (*f)(R2) = [](R2 u) -> double {
          return u.x() * u.x() + 3 * sin(u.y()); };

      R2(*g)(R2) = [](R2 u) -> R2 {
          return { 2 * u.x(), 3 * cos(u.y()) }; };

      cout << gradient_descent(u, h, eps, f, g)<<endl;
  }
  {
      R3 u{ -6, 1, 1 };

      double (*f)(R3) = [](R3 u) -> double {
          return u.x() * u.x() + 3 * sin(u.y()); };

      R3(*g)(R3) = [](R3 u) -> R3 {
          return { 2 * u.x(), 3 * cos(u.y()), 2 }; };

      cout << gradient_descent(u, h, eps, f, g)<<endl;
  }
  
  return 0;
}
