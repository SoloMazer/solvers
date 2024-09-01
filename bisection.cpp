// Created by SoloMazer
// Bisection Method Implementation
//
// Refer:
// https://en.wikipedia.org/wiki/Bisection_method
// https://github.com/SoloMazer/solvers

#include <cmath>
#include <iostream>

// Define target function here
double f(double x) { return std::sin(x) + x * x - 1; }

int main() {

  // Setting the interval for root findng
  double a{}, b{};
  std::cout << "Enter lower bound of [a,b]: ";
  std::cin >> a;
  std::cout << "Enter upper bound of [a,b]: ";
  std::cin >> b;

  // using machine epsilon as tolerance
  double tol{std::numeric_limits<double>::epsilon()};
  uint n{0}; // iterating variable

  // checking if initial f_a & f_b not have the same sign
  if (f(a) > 0 && f(b) < 0 || f(a) < 0 && f(b) < 0) {
    std::cout << "Invalid function in code, does not intersect with x-axis.\n";
    return EXIT_FAILURE;
  } else {

    // iterating a while loop to approach the root
    while (true) {

      // computing midpoints
      double mid{(a + b) / 2};

      if (f(mid) == 0 || fabs(a - b) < tol) { // solution found
        std::cout << "Solution found at (" << mid << ", " << f(mid) << ").\n";
        return 0;
      }
      // defining the new interval
      else if (f(mid) * f(a) < 0) {
        b = mid;
      } else {
        a = mid;
      }

      // computing and printing some useful info
      n++;
      std::cout << "| i: " << n << " | mid: " << mid << " | f(mid): " << f(mid)
                << '\n';
    }
  }
  return 0;
}
