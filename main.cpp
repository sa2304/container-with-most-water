#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int max_area = 0;
    if (not height.empty()) {
      int waterline = *max_element(height.begin(), height.end());
      while (0 < waterline) {
        int left = -1;
        for (int i = 0; i < height.size(); ++i) {
          if (waterline <= height[i]) {
            left = i;
            break;
          }
        }
        if (0 <= left) {
          int right = -1;
          for (int k = height.size() - 1; left < k; --k) {
            if (waterline <= height[k]) {
              right = k;
              break;
            }
          }
          if (0 < right) {
            max_area = max(max_area, (right - left) * waterline);
          }
        }
        --waterline;
      }
    }

    return max_area;
  }
};

void TestMaxArea() {
  Solution s;
  {
    vector<int> heights{1,8,6,2,5,4,8,3,7};
    assert(49 == s.maxArea(heights));
  }
  {
    vector<int> heights{1,1};
    assert(1 == s.maxArea(heights));
  }
}

int main() {
  TestMaxArea();
  std::cout << "Ok!" << std::endl;
  return 0;
}
