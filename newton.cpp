// Created by SoloMazer
// Newton-Raphson Method Implementation
//
// Refer:
// https://en.wikipedia.org/wiki/Newton%27s_method
// https://github.com/SoloMazer/solvers

#include <cmath>
#include <iostream>

double f(double x) { return x * x * x - x - 3; }

double f_prime(double x) { return 3 * x * x - 1; }

int main() {

  // User inputting initial point
  double a{}, x{};
  std::cout << "Enter initial point for newton-raphson: ";
  std::cin >> a;
  x = a;

  // using machine epsilon as tolerance
  double tol{std::numeric_limits<double>::epsilon()};
  uint n{1}; // iterating variable

  if (f_prime(a) == 0) {
    std::cout
        << "f'(x) is equating to zero, please choose alternate initial point.";
    return EXIT_FAILURE;
  } else {
    while (fabs(f(x)) > tol) {

      // Printing useful data
      std::cout << "| i: " << n << " | x: " << x << " | f(x): " << f(x) << "\n";

      // define the newton
      x = x - (f(x) / f_prime(x));

      n++;
    }

    std::cout << "Solution found at ( " << x << ", " << f(x) << ")\n";
    return 0;
  }
}
