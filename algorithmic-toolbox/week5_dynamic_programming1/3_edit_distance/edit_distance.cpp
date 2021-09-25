#include <iostream>
#include <string>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int len1 = str1.size();
  int len2 = str2.size();
  int ed[len1 + 1][len2 + 1];

  for (int i = 0; i <= len1; i++)
  {
    for (int j = 0; j <= len2; j++)
    {
      if (i == 0)
        ed[i][j] = j;
      else if (j == 0)
        ed[i][j] = i;
      else if (str1[i - 1] == str2[j - 1])
        ed[i][j] = ed[i - 1][j - 1];
      else
        ed[i][j] = min(ed[i - 1][j - 1], min(ed[i - 1][j], ed[i][j - 1])) + 1;
    }
  }  
  return ed[len1][len2];
}

int main() {
  string str1;
  string str2;
  cin >> str1 >> str2;
  cout << edit_distance(str1, str2) << endl;
  return 0;
}
