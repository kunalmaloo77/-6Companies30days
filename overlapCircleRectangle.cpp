#include <iostream>
using namespace std;

bool checkOverlap(int x_center, int y_center, int radius, int x1, int y1,
                  int x2, int y2) {

  x1 -= x_center;
  x2 -= x_center;
  y1 -= y_center;
  y2 -= y_center;

  if (x1 * x2 < 0 && y1 * y2 < 0)
    return true;

  int minX = x1 * x2 > 0 ? min(x1 * x1, x2 * x2) : 0;
  int minY = y1 * y2 > 0 ? min(y1 * y1, y2 * y2) : 0;

  return minX + minY <= radius * radius;
}

int main() {
  int radius = 1;
  int x_center = 0;
  int y_center = 0;
  int x1 = 1;
  int y1 = -1;
  int x2 = 3;
  int y2 = 1;

  bool overlap = checkOverlap(x_center, y_center, radius, x1, y1, x2, y2);
  if (overlap) {
    cout << "Overlap" << endl;
  } else {
    cout << "No overlap" << endl;
  }
  return 0;
}