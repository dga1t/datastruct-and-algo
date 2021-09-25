#include <iostream>

int get_change(int m) {
  //write your code here
  int change = m;
  int n = 0;
  int coins[3] = {1, 5, 10};

  while (change >= 10)
  {
    change = change - 10;
    n++;
  }
  while (change >= 5)
  {
    change = change - 5;
    n++;
  }
  while (change > 0)
  {
    change = change - 1;
    n++;
  }
  
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
