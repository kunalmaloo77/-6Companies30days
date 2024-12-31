#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>> &img) {
  int n = img.size();
  int m = img[0].size();
  vector<vector<int>> ans(n, vector<int>(m));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int cell_avg = img[i][j];
      int count = 1;

      if (i - 1 >= 0 && j - 1 >= 0) {
        cell_avg += img[i - 1][j - 1];
        count++;
      }
      if (i + 1 < n && j + 1 < m) {
        cell_avg += img[i + 1][j + 1];
        count++;
      }
      if (i - 1 >= 0 && j + 1 < m) {
        cell_avg += img[i - 1][j + 1];
        count++;
      }
      if (i + 1 < n && j - 1 >= 0) {
        cell_avg += img[i + 1][j - 1];
        count++;
      }

      if (i - 1 >= 0) {
        cell_avg += img[i - 1][j];
        count++;
      }
      if (j - 1 >= 0) {
        cell_avg += img[i][j - 1];
        count++;
      }
      if (j + 1 < m) {
        cell_avg += img[i][j + 1];
        count++;
      }
      if (i + 1 < n) {
        cell_avg += img[i + 1][j];
        count++;
      }
      ans[i][j] = cell_avg / count;
    }
  }
  return ans;
}
int main() {
  vector<vector<int>> img = {
      {2, 3, 4}, {5, 6, 7}, {8, 9, 10}, {11, 12, 13}, {14, 15, 16}};
  vector<vector<int>> ans = imageSmoother(img);
  for (int i = 0; i < ans.size(); ++i) {
    for (int j = 0; j < ans[i].size(); ++j) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}