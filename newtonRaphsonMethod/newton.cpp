#include <cmath>
#include <cstdlib>
#include <iostream>

double f(double x) { return std::sin(x) + x * x - 1; }

double f_prime(double x) { return std::cos(x) + 2 * x; }

int main() {

  // User inputting initial point
  double a{}, x{};
  std::cout << "Enter initial point for newton-raphson: ";
  std::cin >> a;

  // using machine epsilon as tolerance
  double tol{std::numeric_limits<double>::epsilon()};
  uint n{0}; // iterating variable

  if (f_prime(a) == 0) {
    std::cout
        << "f'(x) is equating to zero, please choose alternate initial point.";
    return EXIT_FAILURE;
  } else {
    while (fabs(f(x)) > tol) {

      // define the newton
      x{x - (f(x) / f_prime(x))};

      n++;
      // Printing useful data
      std::cout << "| i: " << n << " | x: " << x << " | f(x): " << f(x) << "\n";
    }

    std::cout << "Solution found at ( " << x << ", " << f(x) << ")\n";
    return 0;
  }
}
