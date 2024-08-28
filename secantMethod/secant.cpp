#include <cmath>
#include <iostream>

double f(double x) { return std::sin(x) + x * x - 1; }

int main() {

  double x_0{}, x_1{}, x{};
  std::cout << "Enter initial x_0: ";
  std::cin >> x_0;
  std::cout << "Enter initial x_1: ";
  std::cin >> x_1;

  // using machine epsilon as tolerance
  double tol{std::numeric_limits<double>::epsilon()};
  uint n{0}; // iterating variable

  while (fabs(f(x)) > tol) {

    // define the newton
    x = x - ((f(x) * (x_0 - x_1)) / (f(x_0) - f(x_1)));

    n++;
    // Printing useful data
    std::cout << "| i: " << n << " | x: " << x << " | f(x): " << f(x) << "\n";
  }

  std::cout << "Solution found at ( " << x << ", " << f(x) << ")\n";

  return 0;
}
