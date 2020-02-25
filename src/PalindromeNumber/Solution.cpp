// Solution by Imtiaz Ahmed (Github: tiazahmd)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x >= 0 && x < 10) {
      return true;
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

int stringToInteger(string input) { return stoi(input); }

string boolToString(bool input) { return input ? "True" : "False"; }

int main() {
  string line;
  while (getline(cin, line)) {
    int x = stringToInteger(line);

    bool ret = Solution().isPalindrome(x);

    string out = boolToString(ret);
    cout << out << endl;
  }
  return 0;
}