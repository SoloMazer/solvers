#include <cmath>
#include <iostream>

// Define your target function here
double f(double x) { return std::sin(x) + x * x - 1; }

int main() {

  // setting the interval for root finding
  double a{}, b{};
  std::cout << "Enter the lower bound of [a, b]: ";
  std::cin >> a;
  std::cout << "Enter the upper bound of [a, b]: ";
  std::cin >> b;

  uint n{0}; // iterating variable
  // set tolerance level to machine epsilon
  double tol{std::numeric_limits<double>::epsilon()};

  // checking existance of root in given interval
  if (f(a) * f(b) >= 0) {
    std::cout << "Invalid bounds, intersection with x-axis is not forced in "
                 "the interval.\n";
    return EXIT_FAILURE;
  } else {

    // iterating a while loop to compute newer intervals
    while (true) {

      // Computing the regula-falsi points
      double x{a - (f(a) * (a - b)) / (f(a) - f(b))};

      if (f(x) == 0 || fabs(f(x)) < tol) {
        std::cout << "Solution found at ( " << x << ", " << f(x) << ")\n";
        return 0;
      }
      // Defining the newer intervals
      else if (f(a) * f(x) < 0) {
        b = x;
      } else {
        a = x;
      }

      // Printing some useful info
      n++;
      std::cout << "| i: " << n << " | x: " << x << " | f(x): " << f(x) << "\n";
    }
  }
  return 0;
}
