// Solution by Imtiaz Ahmed (Github: tiazahmd)

#include <iostream>
#include <vector>

#include "../Test.h"

using namespace std;
using namespace leetcode;

class Solution {
public:
  string isPalindrome(int x) {
    if (x >= 0 && x < 10) {
      return "true";
    } else if (x >= 10) {
      vector<int> vec;
      long div = 10;
      long ct = 1;
      int num = 0;
      int digCount = 0;
      int temp = x;

      while (temp != 0) {
        temp /= 10;
        digCount++;
      }

      for (int i = 0; i < digCount; i++) {
        num = x % div;
        num /= ct;
        div *= 10;
        ct *= 10;
        vec.push_back(num);
      }

      for (int i = 0; i < vec.size(); i++) {
        if (i == vec.size() - 1)
          return "true";
        else if (vec[i] != vec[vec.size() - 1 - i])
          return "false";
      }

    } else {
      return "false";
    }

    return "false";
  };
};

int stringToInteger(string input) { return stoi(input); }

string boolToString(bool input) { return input ? "True" : "False"; }

int main() {

  Solution s;

  test("Test case: ", s.isPalindrome(121), "true");
  test("Test case: ", s.isPalindrome(120), "true");
  test("Test case: ", s.isPalindrome(-121), "true");
  test("Test case: ", s.isPalindrome(11), "true");
  test("Test case: ", s.isPalindrome(9), "true");
  test("Test case: ", s.isPalindrome(0), "true");
  test("Test case: ", s.isPalindrome(10022001), "true");
  
  // string line;
  // while (getline(cin, line)) {
  //   int x = stringToInteger(line);

  //   bool ret = Solution().isPalindrome(x);

  //   string out = boolToString(ret);
  //   cout << out << endl;
  // }
  return 0;
}