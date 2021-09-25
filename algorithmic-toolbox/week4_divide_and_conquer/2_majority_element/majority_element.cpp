#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here

  int mid = left + (right - left) / 2;
  int leftEl = get_majority_element(a, left, mid);
  int rightEl = get_majority_element(a, mid, right);

  int lcount = 0;
  for (int i = left; i < right; i++)
    if (a[i] == leftEl) lcount++;
  
  if (lcount > (right - left) / 2) return leftEl;

  int rcount = 0;
  for (int i = left; i < right; i++)
    if (a[i] == rightEl) rcount++;

  if (rcount > (right - left) / 2) return rightEl;

  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
