#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

// my version:

int gcd_smart_euclid(int a, int b)
{
  if (b == 0)
    return a;

  return gcd_smart_euclid(b, a % b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_smart_euclid(a, b) << std::endl;
  return 0;
}
