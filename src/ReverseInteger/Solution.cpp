#include <climits>

#include "../Test.h"

using namespace std;
using namespace leetcode;

class Solution {
public:
  int reverse(int x) {
    int rev = 0;
    while (x != 0) {
      int pop = x % 10;
      x /= 10;
      if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
        return 0;
      if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
        return 0;
      rev = rev * 10 + pop;
    }
    return rev;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;

  test("case 1", s.reverse(123), 321);
  test("case 2", s.reverse(-123), -321);
  test("case 3", s.reverse(120), 21);

  return 0;
}
