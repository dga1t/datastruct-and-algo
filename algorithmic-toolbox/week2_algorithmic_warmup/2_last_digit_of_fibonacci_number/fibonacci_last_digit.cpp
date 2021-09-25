#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
  if (n <= 1)
    return n;

  long long previous = 0;
  long long current  = 1;

  for (int i = 0; i < n - 1; ++i) {
    long long tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
  }

  return current % 10;
}

// my version:

int get_fibonacci_last_digit_smart(int n) {
  if (n < 2)
    return n;

  int sequence[n];
  sequence[0] = 0;
  sequence[1] = 1;

  for (int i = 2; i <= n; ++i)
    sequence[i] = (sequence[i-1] + sequence[i-2]) % 10;
  
  return sequence[n];
}

int main() {
  int n;
  std::cin >> n;
  long long c = get_fibonacci_last_digit_smart(n);
  std::cout << c << '\n';
  return 0;
}
