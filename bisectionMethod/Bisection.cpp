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

  // Computing initial values of function to check if bisection can work
  double f_a{f(a)};
  double f_b{f(b)};

  // Checking for the contions for bisection to work
  if (a >= b) {
    std::cout << "Invalid bounds. a < b must be true.\n";
    return EXIT_FAILURE;
  }
  // checking if initial f_a & f_b not have the same sign
  else if (f_a > 0 && f_b < 0 || f_a < 0 && f_b < 0) {
    std::cout << "Invalid function in code, does not intersect with x-axis.\n";
    return EXIT_FAILURE;
  } else {

    // iterating a while loop to approach the root
    while (true) {

      // computing midpoints
      double mid{(a + b) / 2};

      if (f(mid) == 0) { // solution found
        std::cout << "Solution Found! \n Root is at (" << mid << ", " << f(mid)
                  << ").\n";
        return 0;
      } else if (fabs(a - b) < tol) { // Solution beyond tolerance
        std::cout << "Tolerance contition reached! \n Approximate "
                     "Root is at ("
                  << mid << ", " << f(mid) << ").\n";
        return 0;
      }
      // defining the new interval
      else if (f(mid) * f_a < 0) {
        b = mid;
      } else {
        a = mid;
      }

      // computing and printing some useful info
      n++;
      std::cout << "i: " << n << " | f(mid): " << f(mid) << '\n';
    }
  }
  return 0;
}
