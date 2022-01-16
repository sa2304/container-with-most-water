#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    // FIXME
    return 0;
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
