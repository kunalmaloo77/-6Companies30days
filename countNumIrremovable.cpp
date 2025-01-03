#include <iostream>
#include <vector>

using namespace std;

bool isStrictlyIncreasing(vector<int> &temp) {
  for (int i = 1; i < temp.size(); ++i) {
    if (temp[i] <= temp[i - 1])
      return false;
  }
  return true;
}

int incremovableSubarrayCount(vector<int> &nums) {
  int count = 0;
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = i; j < nums.size(); ++j) {
      vector<int> temp = nums;
      temp.erase(temp.begin() + i, temp.begin() + j + 1);
      if (isStrictlyIncreasing(temp))
        count++;
    }
  }
  return count;
}

int main() {
  vector<int> arr = {1, 2, 3, 4};
  cout << incremovableSubarrayCount(arr);

  return 0;
}