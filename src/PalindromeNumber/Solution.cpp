// Solution by Imtiaz Ahmed (Github: tiazahmd)

#include <iostream>
#include <vector>

#include "../Test.h"

using namespace std;
using namespace leetcode;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x >= 0 && x < 10) {
      return true;
    } else if (x >= 10) {
      vector<int> vec;
      long div = 10;
      int num = 0;
      int temp = x;

      while (temp != 0) {
        num = temp % div;
        temp = temp / div;
        vec.push_back(num);
      }

      for (int i = 0; i < vec.size(); i++) {
        if (i == vec.size() - 1)
          return true;
        else if (vec[i] != vec[vec.size() - 1 - i])
          return false;
      }

    } else {
      return false;
    }

    return false;
  };
};

int main() {

  Solution s;

  test("Test case: ", s.isPalindrome(121), true);
  test("Test case: ", s.isPalindrome(120), false);
  test("Test case: ", s.isPalindrome(-121), false);
  test("Test case: ", s.isPalindrome(11), true);
  test("Test case: ", s.isPalindrome(9), true);
  test("Test case: ", s.isPalindrome(0), true);
  test("Test case: ", s.isPalindrome(10022001), true);
  test("Test case: ", s.isPalindrome(1001), true);
  
  return 0;
}
