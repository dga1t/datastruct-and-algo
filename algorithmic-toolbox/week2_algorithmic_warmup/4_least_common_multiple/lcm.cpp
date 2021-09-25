#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

// my version:

int gcd(int a, int b)
{
  if (b == 0)
    return a;

  return gcd(b, a % b);
}

long long lcm_smart(int a, int b)
{
 return (long long) a * b / gcd(a, b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_smart(a, b) << std::endl;
  return 0;
}
