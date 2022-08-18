#include <unordered_map>
#include <vector>

#include "../Test.h"

using namespace std;
using namespace leetcode;

class Solution {
public:
  int minSetSize(vector<int> &arr) {
    unordered_map<int, int> count;
    for (int x : arr)
      ++count[x];

    int totalCount = arr.size();
    vector<int> counting(totalCount + 1);
    for (auto [_, freq] : count)
      ++counting[freq];

    int ans = 0, removed = 0, half = totalCount / 2, freq = totalCount;
    while (removed < half) {
      ++ans;
      while (counting[freq] == 0)
        --freq;
      removed += freq;
      --counting[freq];
    }
    return ans;
  };
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector input1({3, 3, 3, 3, 5, 5, 5, 2, 2, 7});
  vector input2({7, 7, 7, 7, 7, 7});

  test("case 1", s.minSetSize(input1), 2);
  test("case 2", s.minSetSize(input2), 1);

  return 0;
}
