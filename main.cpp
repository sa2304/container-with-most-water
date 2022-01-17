#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  auto getIntersections(const vector<int>& height) {
    unordered_map<int, vector<int>> intersections;
    for (int i = 0; i < height.size(); ++i) {
      int h = height[i];
      while (0 < h) {
        intersections[h--].push_back(i);
      }
    }

    return intersections;
  }

 public:
  int maxArea(vector<int>& height) {
    int max_area = 0;
    if (not height.empty()) {
      auto intersections = getIntersections(height);
      int waterline = *max_element(height.begin(), height.end());
      while (0 < waterline) {
        if (intersections.count(waterline)) {
          const auto& lines = intersections[waterline];
          if (1 < lines.size()) {
            int left = lines.front();
            int right = lines.back();
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
