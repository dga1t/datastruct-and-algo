#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  int len = exp.size();
  int nums = (len + 1) / 2;
  long long minArr[nums][nums];
  long long maxArr[nums][nums];
  memset(minArr, 0, sizeof(minArr));
  memset(maxArr, 0, sizeof(maxArr));

  for (int i = 0; i < nums; i++)
  {
    minArr[i][i] = stoll(exp.substr(2*i, 1));
    maxArr[i][i] = stoll(exp.substr(2*i, 1));
  }

  for (int s = 0; s < nums - 1; s++)
  {
    for (int i = 0; i < nums - s - 1; i++)
    {
      int j = i + s + 1;
      long long minVal = LLONG_MAX;
      long long maxVal = LLONG_MIN;

      for (int k = i; k < j; k++)
      {
        long long a = eval(minArr[i][k],minArr[k + 1][j],exp[2 * k + 1]);
			  long long b = eval(minArr[i][k],maxArr[k + 1][j],exp[2 * k + 1]);
			  long long c = eval(maxArr[i][k],minArr[k + 1][j],exp[2 * k + 1]);
			  long long d = eval(maxArr[i][k],maxArr[k + 1][j],exp[2 * k + 1]);
			  minVal = min(minVal,min(a,min(b,min(c,d))));
			  maxVal = max(maxVal,max(a,max(b,max(c,d))));
      }

      minArr[i][j] = minVal;
      maxArr[i][j] = maxVal;
    }
  }

  return maxArr[0][nums - 1];
}

int main() {
  string s;
  cin >> s;
  cout << get_maximum_value(s) << '\n';
}
