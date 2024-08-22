#include <iostream>
#include <cmath>

double function(double x) {
  return 1 + x + std::sin(x);
}

int main() {

  double a{}, b{};
  double tol{ std::numeric_limits<double>::epsilon() };
  uint n{ 0 };
  std::cout << "Enter lower bound of [a,b]: ";
  std::cin >> a;
  std::cout << "Enter upper bound of [a,b]: ";
  std::cin >> b;

  // Computing initial values of function
  double f_a{ function(a) };
  double f_b{ function(b) };

  // Checking for the contions for bisection to work
  if (a >= b)
  {
    std::cout << "Invalid bounds. a < b must be true.\n";
    return EXIT_FAILURE;
  }
  // checking if initial f_a & f_b not have the same sign
  else if (f_a > 0 && f_b < 0 || f_a < 0 && f_b < 0)
  {
    std::cout << "Invalid function in code, does not intersect with x-axis.\n";
    return EXIT_FAILURE;
  }
  // Possibility of provided bounds being root
  else if (f_a == 0) {
    std::cout << "\n (^_^) \n Solution Found! \n Root is at (" << a << ", " << f_a << ").\n";
    return 0;
  }
  else if (f_b == 0) {
    std::cout << "\n (^_^) \n Solution Found! \n Root is at (" << b << ", " << f_b << ").\n";
    return 0;
  }
  else {
    while (true)
    {
      // computing midpoints
      double mid{ (a + b) / 2 };
      double f_mid{ function(mid) };

      if (f_mid == 0)
      { //solution found
        std::cout << "\n (^_^) \n Solution Found! \n Root is at (" << mid << ", " << f_mid << ").\n";
        return 0;
      }
      else if (fabs(a - b) < tol)
      { // Solution beyond tolerance
        std::cout << "\n (^_^) \n Tolerance contition reached! \n Approximate Root is at (" << mid << ", " << f_mid << ").\n";
        return 0;
      }
      else if (f_mid * f_a < 0)
      {
        b = mid;
      }
      else
      {
        a = mid;
      }
      // counting no. of iterations
      n = n + 1;
      std::cout << "No. of iterations: " << n << '\n';
    }
  }
  return 0;
}
