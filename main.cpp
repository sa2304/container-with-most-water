#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int> &height) {
    int max_area = 0;
    int left = 0, right = height.size() - 1;
    while (left < right) {
      max_area = max(max_area, (right - left) * min(height[left], height[right]));
      if (height[left] < height[right]) { ++left; }
      else { --right; }
    }

    return max_area;
  }
};

void TestMaxArea() {
  Solution s;
  {
    vector<int> heights{1, 8, 6, 2, 5, 4, 8, 3, 7};
    assert(49 == s.maxArea(heights));
  }
  {
    vector<int> heights{1, 1};
    assert(1 == s.maxArea(heights));
  }
  {
    vector<int> heights{1, 2};
    assert(1 == s.maxArea(heights));
  }
  {
    vector<int> heights{1, 0, 0, 0, 0, 0, 0, 2, 2};
    assert(8 == s.maxArea(heights));
  }
  {
    vector<int> heights{2, 3, 10, 5, 7, 8, 9};
    assert(36 == s.maxArea(heights));
  }
  {
    vector<int> heights{1, 2, 4, 3};
    assert(4 == s.maxArea(heights));
  }
}

int main() {
  TestMaxArea();
  std::cout << "Ok!" << std::endl;
  return 0;
}
