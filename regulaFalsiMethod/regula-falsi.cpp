#include <cmath>
#include <iostream>

double f(double x) { return std::sin(x) + x * x - 1; }

int main() {

  double a{}, b{};
  std::cout << "Enter the lower bound of [a, b]: ";
  std::cin >> a;
  std::cout << "Enter the upper bound of [a, b]: ";
  std::cin >> b;

  uint n{0};
  double tol{std::numeric_limits<double>::epsilon()};

  if (f(a) * f(b) >= 0) {
    std::cout << "Invalid bounds, intersection with x-axis is not forced in "
                 "the interval.\n";
    return EXIT_FAILURE;
  } else {
    while (true) {

      double x{a - (f(a) * (a - b)) / (f(a) - f(b))};

      if (f(x) == 0) {
        std::cout << "Solution is: ( " << x << ", " << f(x) << ")\n";
        return 0;
      } else if (fabs(f(x)) < tol) {
        std::cout << "Approx solution is: ( " << x << ", " << f(x) << ")\n";
        return 0;
      } else if (f(a) * f(x) < 0) {
        b = x;
      } else {
        a = x;
      }
      n++;
      std::cout << "Iteration: " << n << "\n";
    }
  }
  return 0;
}
