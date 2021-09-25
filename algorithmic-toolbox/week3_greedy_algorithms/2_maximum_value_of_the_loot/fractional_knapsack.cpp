#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxIndex(vector<int> weights, vector<int> values) {
  int maxIndex = 0;
  double max = 0;

  for (int i = 0; i < weights.size(); i++) {
    if (weights[i] != 0 && (double) values[i] / weights[i] > max) {
      max = (double) values[i] / weights[i];
      maxIndex = i;
    }
  }
  return maxIndex;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  for (int i = 0; i < weights.size(); i++) {
    if (capacity == 0) return value;
    int index = getMaxIndex(weights, values);
    int a = min(capacity, weights[index]);
    value += a * (double) values[index] / weights[index];
    weights[index] -= a;
    capacity -= a;
  }
  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << endl;
  
  return 0;
}

  // struct Item 
  // {
  //   int value;
  //   double weight;
  //   double density;
  // };

  // bool compare(const Item &i1, const Item &i2)
  // {
  //   return i1.density > i2.density;
  // }

  // int numOfEl = values.size();
  // int curWeight = 0;
  // int spaceLeft;

  // Item items[numOfEl];

  // for (int i = 0; i < numOfEl; i++)
  // {
  //   items[i].value = values[i];
  //   items[i].weight = weights[i];
  //   items[i].density = (double)values[i] / (double)weights[i];
  // }

  // sort(items, items+numOfEl, compare);

  // for (int i = 0; i < numOfEl; i++)
  // {
  //   if (curWeight == capacity)
  //   {
  //     return value;
  //   }
  //   if (curWeight + items[i].weight <= capacity)
  //   {
  //     curWeight += items[i].weight;
  //     value += items[i].value;
  //   }
  //   else
  //   {
  //     spaceLeft = capacity - curWeight;
  //     value += items[i].value * ((double)spaceLeft / (double) items[i].weight);
  //   }
  // }  
  // return value;
