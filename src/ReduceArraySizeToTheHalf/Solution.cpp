#include <vector>

#include "../Test.h"

using namespace std;
using namespace leetcode;

class Solution {
public:
  int minSetSize(vector<int> &arr) { return 0; }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector input1({3, 3, 3, 3, 5, 5, 5, 2, 2, 7});
  vector input2({7, 7, 7, 7, 7, 7});

  test("case 1", s.minSetSize(input1), 2);
  test("case 2", s.minSetSize(input2), 1);

  return 0;
}
