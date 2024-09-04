// Created by SoloMazer
// Fixed-Point iteration Method Implementation
//
// Refer:
// https://en.wikipedia.org/wiki/Fixed-point_iteration
// https://github.com/SoloMazer/solvers

#include <cmath>
#include <iostream>

double f(double x) { return std::sin(x) + x * x - 1; }
// Fix some g(x) = x for our f(x) = 0 problem.
double g(double x) { return std::sqrt(1 - std::sin(x)); }
// double g(double x) { return -1 * std::sqrt(1 - std::sin(x)); }
// double g(double x) { return std::asin(1 - x * x); }

int main() {

  double x_0{};
  std::cout << "Enter Initial guess: ";
  std::cin >> x_0;

  // using machine epsilon as tolerance
  // double tol{std::numeric_limits<double>::epsilon()};
  double tol{10e-16};

  uint n{1};
  double x_1{g(x_0)};

  while (fabs(x_1 - g(x_1)) > tol) {

    x_1 = g(x_1);

    std::cout << "| i: " << n << " | p: " << x_1
              << " | x - g(x): " << x_1 - g(x_1) << '\n';
    n++;
  }
  std::cout << "Solution found at ( " << x_1 << ", " << f(x_1) << ")\n";
  return 0;
}
