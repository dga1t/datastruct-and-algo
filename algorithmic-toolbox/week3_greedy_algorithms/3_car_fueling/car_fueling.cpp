#include <iostream>
#include <vector>

using namespace std;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
  int stations = stops.size();
  int current = 0;
  int limit = tank;
  int count = 0;
  // int last = 0;

  while (limit < dist)
  {
    if ((current >= stations) || (stops[current] > limit)) return -1;
    while ((current < stations - 1) && stops[current + 1] <= limit)
      current++;
    count++;
    limit = stops[current] + tank;
    current++;
  }
  return count;

  // if ((stops[current] + tank) >= dist)
  //   return count;

  // while (current <= stations)
  // {
  //   last = current;

  //   while ((current <= stations - 1) && ((stops[current + 1] - stops[last]) <= tank))
  //     current++;

  //   if (current == last) 
  //     return -1;
    
  //   if (current <= stations)
  //     count++;
  // }
  // return count;
}

int main() {
  int d = 0;
  cin >> d;
  int m = 0;
  cin >> m;
  int n = 0;
  cin >> n;

  vector<int> stops(n);
  for (size_t i = 0; i < n; ++i)
    cin >> stops.at(i);

  cout << compute_min_refills(d, m, stops) << "\n";

  return 0;
}
