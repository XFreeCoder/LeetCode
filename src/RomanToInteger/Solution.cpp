#include <iostream>

#include "../Test.h"

using namespace std;
using namespace leetcode;

class Solution {
public:
  int romanToInt(string s) {
    int sum = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
      switch (s[i]) {
      case 'I':
        sum += (sum >= 5 ? -1 : 1);
        break;
      case 'V':
        sum += 5;
        break;
      case 'X':
        sum += (sum >= 50 ? -10 : 10);
        break;
      case 'L':
        sum += 50;
        break;
      case 'C':
        sum += (sum >= 500 ? -100 : 100);
        break;
      case 'D':
        sum += 500;
        break;
      case 'M':
        sum += 1000;
        break;
      }
    }
    return sum;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;

  test("case 1", s.romanToInt("III"), 3);
  test("case 2", s.romanToInt("IV"), 4);
  test("case 3", s.romanToInt("IX"), 9);

  return 0;
}
