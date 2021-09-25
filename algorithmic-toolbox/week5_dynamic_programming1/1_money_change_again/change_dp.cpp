#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int get_change(int m) {
  //write your code here
  vector<int> coins = {1, 3, 4};
  vector<int> minNumCoins(m + 1);
  minNumCoins[0] = 0;
  int numCoins;

  for (int i = 1; i <= m; i++)
  {
    minNumCoins[i] = INT_MAX;
    for (int c = 0; c < coins.size(); c++)
    {
      if (i >= coins[c])
      {
        numCoins = minNumCoins[i - coins[c]] + 1;
        if (numCoins < minNumCoins[i])
        {
          minNumCoins[i] = numCoins;
        }
      }
    }
  }
  return minNumCoins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
